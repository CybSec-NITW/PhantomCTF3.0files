import string
import random

from flask import Flask, request

app = Flask(__name__)


def generate_random_captcha():
    global captcha
    captcha = ''.join(random.choice(string.ascii_uppercase) for _ in range(6))


@app.route('/', methods=["GET", "POST"])
def try_password():
    if request.method == 'GET':
        return html_string.replace('${captcha}', captcha)
    if request.method == 'POST':
        _captcha = request.form.get("captcha")
        if captcha != _captcha:
            generate_random_captcha()
            return "Wrong Captcha", 403
        _key = request.form.get("key")
        if key != int(_key):
            generate_random_captcha()
            return "Wrong Key", 403
        return ctf, 200


if __name__ == '__main__':
    with open('index.html', 'r') as file:
        html_string = file.read()
    ctf = 'pCTF{Th4t_1s_h0w_y0u_byp4ss_c4p7cha}'
    captcha = ''
    key = random.randint(0, 1000)
    print('Generated key', key)
    generate_random_captcha()
    app.run(port=8000)
