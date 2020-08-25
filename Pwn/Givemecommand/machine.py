#!/usr/bin/python3

from collections import defaultdict
from binascii import hexlify
import os
import socket
import threading
import random
import subprocess


class MAC:

    BLOCK = 6
    cool_commands = ["cowsay I am a very secure MACHINE",
                     "ps -aux",
                     "ls -laF",
                     "wc /bin/bash",
                     "which python",
                     ]

    def __init__(self):
        self.key = os.urandom(self.BLOCK)

    @staticmethod
    def _xor(a, b):
        return bytes([i ^ j for i, j in zip(a, b)])

    def _gen_tag(self, string):
        string.rjust(self.BLOCK, '0')
        while len(string) % self.BLOCK != 0:
            string += '0'
        blocks = [string[i:i+self.BLOCK] for i in range(0, len(string), self.BLOCK)]
        tag = self.key
        for b in blocks:
            tag = self._xor(tag, b.encode())

        return hexlify(tag).decode()

    def get_tag(self, c):
        command = random.choice(self.cool_commands)
        string = (
                  "Command: {}\n"
                  "Tag: {}\n"
                  ).format(command, self._gen_tag(command))
        c.send(string.encode())
        return 0

    def execute_arbitrary(self, c):
        c.send("Please input your desired command: \n".encode())
        command = c.recv(128).decode().strip()
        c.send("Please enter the corresponding tag (in hex): \n".encode())
        try:
            tag = c.recv(128).decode().strip()
        except TypeError:
            c.send("Invalid tag length (must be multiple of two)\n")
            return 0

        if self._gen_tag(command) == tag:
            shell_output = subprocess.check_output(command.split())
            output = "Tag is correct! Here is your output:\n{}\n".format(
                    shell_output.decode()
            )

            c.send(output.encode())
        else:
            c.send("Sorry, wrong tag\n".encode())

        return 0


class Server:

    def __init__(self, host='0.0.0.0', port=1337):
        self.s = socket.socket()
        self.s.bind((host, port))

    def listen(self):
        self.s.listen(5)
        while True:
            c, addr = self.s.accept()
            threading.Thread(target=self.puzzle, args=(c,)).start()

    def _invalid_choice(self, c):
        c.send("Please select a choice from 1 to 3\n".encode())

    def _goodbye(self, c):
        c.send("Have a nice day!\n".encode())

    def puzzle(self, conn):
        mac = MAC()
        choices = defaultdict(lambda: self._invalid_choice)
        choices[1] = mac.get_tag
        choices[2] = mac.execute_arbitrary
        choices[3] = self._goodbye

        c = conn
        number = 0
        outgoing = 'Welcome to the Machine\n'
        c.send(outgoing.encode('UTF-8'))
        while number <= 10:
            message = (
                "\nWhat would you like to do today?\n"
                "1) Get a random command tag\n"
                "2) Execute command (we only execute commands with a valid tag)\n"
                "3) exit\n"
                "--------------\n"
            )
            c.send(message.encode())
            selection = c.recv(32).decode()
            try:
                sel = int(selection.strip())
            except ValueError:
                c.send("Please select a valid choice\n".encode())
            else:
                choices[sel](c)
            number += 1

        c.shutdown(1)
        c.close()


if __name__ == '__main__':
    server = Server()
    server.listen()
