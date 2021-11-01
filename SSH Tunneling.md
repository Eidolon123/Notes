-----------------------------------------------
# [[SSH]] Tunneling
Tags:  #Hacking 
Creation date: 2021-10-18

-----------------------------------------------


## Tunnel

```
ssh -L <myPort>:localhost:<remotePort> <user>@<target>
```

## Reverse Tunnel

```
ssh -R <remote port>:<local address>:<local port>  username@publicserver
```