# Writeup

Connect to the IP through nc.
```
user@linux : nc <IP> 1337
```

Choose 1st option to get random tag and command.

now run exploit.py.
```
user@linux : python3 exploit.py
```

Enter the command and tag you got previously.
You will get flag.

Exploit.py contains script to xor. Like we know 1 set of command and tag, with the help of this we can get other ones command's tag.
