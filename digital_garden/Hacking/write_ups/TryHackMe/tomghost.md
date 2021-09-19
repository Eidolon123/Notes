## Recon

### nmap scan

![[nmap_scan.png]]

nmap scan shows us that there is an SSH service on port 22, webserver on 8080 and a Jserv on 8009.

## Exploit

### metasploit

Searching metasploit for jserv exploits:

![[searchsploit.png]]

output of loot from metasploit attack:

![[meta_loot.png]]

## SSH into machine

home directory contains `credential.pgp` file and `tryahckme.asc`. the `.asc` file contains a private pgp key used to decrypt the `.gpg` file. Need to copy them to local machine using SCP to crack the passphrase attached to the `.asc` file.

![[home_contents.png]]

### cracking

john comes with a useful binary to convert the contents of the `.asc` file to something john can crack.

![[gpg2john.png]]

running the hash against rockyou.txt:

![[john_output.png]]

decrypting `credentials.pgp` file with new found password:

![[gpg_decrypt.png]]

user.txt is in merlin home folder

## root

sudo -l shows us we can run `zip` as root.

![[digital_garden/images/write_ups/tomghost/sudo-l.png]]

GTFObins give us an easy path to root.

![[digital_garden/images/write_ups/tomghost/rooted_and_booted.png]]

## Notes

skyfuck:8730281lkjlkjdqlksalks
merlin:asuyusdoiuqoilkda312j31k2j123j1g23g12k3g12kj3gk12jg3k12j3kj123j