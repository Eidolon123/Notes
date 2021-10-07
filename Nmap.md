-----------------------------------------------
# Nmap
Tags:  #Tools  #Cheatsheet #Hacking 
Creation date: 2021-10-05

-----------------------------------------------


A scanning tool used for [[Recon]].

## Basic Usage

### SYN scan

`nmap <ip>` will perform a basic SYN scan on 1000 most common ports.

### Network sweeping

`nmap -p <ip range>` finds all machines running NetBIOS/SMB

### Ping scan

`nmap -sn <ip>`

### Find OS version

`nmap -O <ip>`

### Hail Mary

`nmap -A <ip>` will do a lot and be very loud

### Assume host is alive (no ping)

`nmap -Pn <ip>`

### Banner grabbing

`nmap -sV <ip>`

## Useful commands

### Check for vulnerabilities with scan

```nmap -sV -vv --script="vuln" <ip>```

### Enumerate SMB shares

```nmap -p <port> --script=smb-enum-shares.nse,smb-enum-users.nse <ip>```

### List mounts available on a NFS

```nmap -p <port> --script=nfs-ls,nfs-statfs,nfs-showmount <ip>```

### Bruteforce SSH with script engine

`nmap <host> -p 22 --script ssh-brute --script-args userdb=users.txt,passdb=passwords.txt`

### Perimeter Avoidance Scanning

- Ack -sA
- Fin
- Null
- Xmas tree