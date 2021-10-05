-----------------------------------------------
# Nmap
Tags:  #Tools  #Cheatsheet #Hacking 
Creation date: 2021-10-05

-----------------------------------------------


A scanning tool used for [[Recon]].

## Useful commands

### Check for vulnerabilities with scan

```nmap -sV -vv --script="vuln" <ip>```

### Enumerate SMB shares

```nmap -p <port> --script=smb-enum-shares.nse,smb-enum-users.nse <ip>```

### List mounts available on a NFS

```nmap -p <port> --script=nfs-ls,nfs-statfs,nfs-showmount <ip>```

### Bruteforce SSH with script engine

`nmap <host> -p 22 --script ssh-brute --script-args userdb=users.txt,passdb=passwords.txt`
