-----------------------------------------------
# THM Bounty Hacker
Tags:  #Hacking #Writeup
Creation date: 2021-10-04

-----------------------------------------------

## [[Recon]]

[[Nmap]] scan:

![[bounty-nmap.png]]

- ftp on 21
- ssh on 22
- http on 80

### HTTP server

![[bounty-web-landing.png]]

Nothing interesting in source code and directory scan shows nothing either. Assume dead-end.

### [[FTP]] server

has anon login

![[bounty-ftp.png]]

Contents of `locks.txt`:

```ascii
rEddrAGON
ReDdr4g0nSynd!cat3
Dr@gOn$yn9icat3
R3DDr46ONSYndIC@Te
ReddRA60N
R3dDrag0nSynd1c4te
dRa6oN5YNDiCATE
ReDDR4g0n5ynDIc4te
R3Dr4gOn2044
RedDr4gonSynd1cat3
R3dDRaG0Nsynd1c@T3
Synd1c4teDr@g0n
reddRAg0N
REddRaG0N5yNdIc47e
Dra6oN$yndIC@t3
4L1mi6H71StHeB357
rEDdragOn$ynd1c473
DrAgoN5ynD1cATE
ReDdrag0n$ynd1cate
Dr@gOn$yND1C4Te
RedDr@gonSyn9ic47e
REd$yNdIc47e
dr@goN5YNd1c@73
rEDdrAGOnSyNDiCat3
r3ddr@g0N
ReDSynd1ca7e
```

Content of `tasks.txt`:

```ascii
1.) Protect Vicious.
2.) Plan for Red Eye pickup on the moon.

-lin
```

Assume username for the system is `lin` and `locks.txt` is a list of possible passwords for SSH login.

## User

### Nmap bruteforce ssh

Can use nmap scripting engine to bruteforce SSH login.

![[bounty-nmap-ssh-brute.png]]

user/pass combo is: lin:RedDr4gonSynd1cat3

user flag in landing directory.

## Root

### Abusing [[sudo]]

Running `sudo -l` as lin shows us we can run `tar` as root user.

![[bounty-sudo-l.png]]

Grab exploit from GTFObins for sudo tar...

![[bounty-rooted.png]]

## Notes

Possible users:

-	spike
-	jet
-	ed
-	faye
-	lin:RedDr4gonSynd1cat3

