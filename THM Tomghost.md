-----------------------------------------------
# THM Tomghost
Tags:  #Hacking #Writeup 
Creation date: 2021-10-04

-----------------------------------------------

## [[Recon]]

### [[Nmap]] scan

![[tom-nmap-scan.png]]

nmap scan shows us that there is an SSH service on port 22, webserver on 8080 and a Jserv on 8009.

## Exploit

### [[Metasploit]]

Searching metasploit for jserv exploits:

![[tom-searchsploit.png]]

output of loot from metasploit attack:

![[tom-meta-loot.png]]

## [[SSH]] into machine

home directory contains `credential.pgp` file and `tryahckme.asc`. the `.asc` file contains a private pgp key used to decrypt the `.gpg` file. Need to copy them to local machine using SCP to crack the passphrase attached to the `.asc` file.

![[tom-home-contents.png]]

### Cracking

[[John The Ripper]] comes with a useful binary to convert the contents of the `.asc` file to something john can crack.

![[tom-gpg2john.png]]

running the hash against rockyou.txt:

![[tom-john-output.png]]

decrypting `credentials.pgp` file with new found password:

![[tom-gpg-decrypt.png]]

user.txt is in merlin home folder

## Root

### Abusing [[sudo]]

`sudo -l` shows us we can run `zip` as root.

![[tom-sudo-l.png]]

GTFObins give us an easy path to root.

![[tom-rooted-and-booted.png]]

## Notes

skyfuck:8730281lkjlkjdqlksalks
merlin:asuyusdoiuqoilkda312j31k2j123j1g23g12k3g12kj3gk12jg3k12j3kj123j