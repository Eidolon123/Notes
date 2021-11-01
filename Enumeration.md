-----------------------------------------------
# Enumeration
Tags: #Hacking #Cheatsheet   
Creation date: 2021-10-18

-----------------------------------------------


## Find plane text passwords in files

```shell
find . -name "*.php" -print0 | xargs -0 grep -i -n "password"
```

## Find IP addresses in IP range

```shell
find . -name "*.php" -print0 | xargs -0 grep -i -n "192.168.1"
```

## Windows

We will usually use [[Power Shell]] to enumerate windows systems.