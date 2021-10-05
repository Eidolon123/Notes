-----------------------------------------------
# John The Ripper
Tags:  #Hacking #Tools #Cheatsheet 
Creation date: 2021-10-05

-----------------------------------------------

### gpg

`gpg2john <gpg_key_file> > hash`

`john --wordlist=/path/to/wordlist hash`

### ssh

`python /usr/share/john/ssh2john.py <ssh_key_file> > hash`

`john --wordlist=/path/to/wordlist hash`
