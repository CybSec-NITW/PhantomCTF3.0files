'use strict';

const express = require('express');
const bodyParser = require('body-parser')

// Constants
const PORT = 8080;
const HOST = '0.0.0.0';

// App
const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.raw());

app.get('/', (req, res) => {
  res.sendfile('./index.html');
});

app.post('/get_flag', (req, res) => {
  console.log(req.body)
  if(req.body.flag == 'hacker')
    res.send('pCTF{cyb3rc0ps_pl4n_d1d_n0t_w0rk}')
  else if(req.body.flag =='yes')
    res.sendfile('./burp.html')
  else res.send("you have to ask for the flag");
});

app.listen(PORT, HOST);
console.log(`Running on http://${HOST}:${PORT}`);
