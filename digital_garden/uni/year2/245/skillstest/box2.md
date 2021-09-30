# Machine 2

![]()

## Recon

![nmap_scan](https://i.imgur.com/yRu1Z6z.png)

see port 80 open, visit site

![landing](https://i.imgur.com/QNfZNvT.png)

nothing interesting, tried a few injection payloads on the input fields but came up with nothing, directory scan...

![dir_scan](https://i.imgur.com/qODjIhi.png)

admin.php should give us something...

![admin.php](https://i.imgur.com/Qkl6t4N.png)

Now we know the openemr version is 5.0.1.3, we can look up a cve or report.

According to a vulnerability report for 5.0.1.3 we have sql injection in a variety of php files, a method to access these php files without being an authenticated user and arbitrary file actions (read/write/delete) through import_template.php. (There are many more but these are the most interesting). https://www.open-emr.org/wiki/images/1/11/Openemr_insecurity.pdf

## Enum

trying to dump databases through sqli will probably make our lives easier by just authenticating as an admin on the openemr site. More access blah blah.

I chose to use add_edit_event_user.php because you can use the method to bypass being an authenticated user to access it.

this is done by navigating to 
```url
https://<host>/portal/account/register.php
```
After being redirected, we can access 

```url
https://<host>/portal/add_edit_event_user.php
```

According to the vulnerability report the parameters *eid*, *userid* and *pid* are unsanitised.

So we make a request to that page with parameter *eid*.

![url](https://i.imgur.com/j2Zruot.png)

Save it as a file

![request](https://i.imgur.com/r3V4MMv.png)

Use SQLMAP to enum databases:

![sql_db_enum](https://i.imgur.com/MYvzJVW.png)
>Here we see we have databases Information_Schema and openemr.

Using SQLMAP again to enum tables in openemr:

(For the sake of brevity I've only included the command used and tables of interest that were outputted)

```bash
sqlmap -r openemr.req -D openemr --threads=10 --tables

| user_settings                         |
| users                                 |
| users_facility                        |
| users_secure                          |
```

Dumping data from users_secure: 

```bash
sqlmap -r openemr.req -D openemr --threads=10 -T users_secure --dump
```
(output was hard to read so used dumped .csv instead)

![user_secure](https://i.imgur.com/TXreQn5.png)

admin and sysadmin password hashes (bcrypt).

using hashcat to test against rockyou.txt

![hashcat](https://i.imgur.com/dvKwxw3.png)

both come out to 'wolverine'


## Access

(At this point we can SSH into the box with creds sysadmin:wolverine as the passwords are being reused but writing a reverse shell to the box to get the user flag is more fun)

logging in to the website with sysadmin:wolverine gives us admin access to the openemr website.

if we catch and modify our request to import_template.php, we can write files into the /portal/ directory. Using this we can place a reverse shell file and read it to throw ourselves a shell.

![](https://i.imgur.com/pUsUCS6.png)
(Content of nice_file.php is just pentestmonkey's *php-reverse-shell.php*)

Navigating to the file in the browser:
![](https://i.imgur.com/niBlijy.png)

It hangs! 

here's a listener i set up earlier... we have a shell as www-data...

![](https://i.imgur.com/phm9D9K.png)

and user flag!

![](https://i.imgur.com/jPbk5Ab.png)

### User Flag
```
FLAG: 245_SKILLS{R3al_W0rld_Wr1teup}
```

## Root

Searching for SUID files came up with nothing of interest, running ```sudo -l ``` shows us we can run openssl with root privileges.

![](https://i.imgur.com/5AWydxN.png)

GTFObins gives us some nice 2-3 liners to get a shell on our box using sudo openssl on the target box. Played around with this and couldn't get it to behave so opted for rewriting /etc/shadow for an easy(ish) root.

reading /etc/shadow with openssl

![](https://i.imgur.com/tRhuhaQ.png)

Using openssl to generate hash for our new password

![](https://i.imgur.com/wvgXPr4.png)

Writing new hash to a copy of shadow on our local box

![](https://i.imgur.com/9ZzGnu8.png)

Sending modified shadow to target box with openssl

Local box:
![](https://i.imgur.com/ATHjTPD.png)

Target box:
![](https://i.imgur.com/YP90KjF.png)

Writing new shadow file over original

![](https://i.imgur.com/CNcCyQV.png)

Logging in with our new password and getting the flag!

![](https://i.imgur.com/PUX2cS8.png)

```
FLAG: 245_SKILLS{Acc3s_All_Ar3@s}
```

![SQL_Bypass page]()

- We can begin by inserting a correct response to the form.

![CorrectInput](https://i.imgur.com/whIefKq.png)

- We see that it outputs that no such user or pass exist

- Now it is time to try injection

![InitialInject](https://i.imgur.com/VxnSpGb.png)

- Here we see that the field requires type 'email'

![EmailZoomedIn](https://i.imgur.com/RQhcqNy.png)

- We can bypass this locally by accessing the inpsector tab and changing the field requirement.

![Type=text](https://i.imgur.com/PQQdrYs.png)

- This redirects us to an error page, indicating that we are on the right tracks.
- Now is time to break some logic (Assume from here that the type is always text) 

![InitialLogicBreak](https://i.imgur.com/mahR2wT.png)

- The error that it cannot process that many users tells us that the query is trying to bring back the whole table.
- Lets try to limit the results

![LIMITResults](https://i.imgur.com/qHOxIMQ.png)

- This is successful, and we can not begin to move around the table using offset.

![FLAGResult](https://i.imgur.com/arUqfBg.png)