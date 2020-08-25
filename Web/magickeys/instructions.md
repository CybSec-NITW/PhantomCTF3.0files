# run it on server.
##original question
Go to server folder
```
user@linux server : sudo pip3 install flask
user@linux server : sudo python3 server.py
```

Go to client folder
```
user@linux client : python3 -m http.server
```

Open http://127.0.0.1:8000 to check.

It needs to have some background photo and other stuffs

to access database and modify it
Go to server in terminal
```
user@linux server : sqlite3 example.db
```
To see db
```
sqlite > SELECT * FROM USER;
```
to edit something, suppose flag,

```
sqlite > UPDATE USER SET ctf = 'your_newflag_with_inverted_comma' WHERE username = 'FFgGxF0NBK';
```
##in ctf index file was not given intentionally
