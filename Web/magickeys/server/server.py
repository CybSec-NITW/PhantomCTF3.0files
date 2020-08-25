from flask import Flask, jsonify, make_response
from flask import request
import sqlite3

app = Flask(__name__)


def get_user(username, password):
    conn = sqlite3.connect('example.db')
    c = conn.cursor()
    sql = "SELECT * FROM USER WHERE password = " + "'" + password + "' AND username = '" + username + "'"
    c.execute(sql)
    user = c.fetchone()
    conn.close()
    return user


@app.route('/login', methods=["POST"])
def hello():
    try:
        user = get_user(request.form.get('username'), request.form.get('password'))
        response, status = (make_response(), 403) if user is None else (jsonify({"ctf": user[2]}), 200)
    except Exception as e:
        response, status = jsonify({"error": e.__str__()}), 500
    response.headers.add('Access-Control-Allow-Origin', '*')
    return response, status


if __name__ == '__main__':
    app.run(port=8001)
