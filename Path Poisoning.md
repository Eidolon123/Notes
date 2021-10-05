-----------------------------------------------
# Path Poisoning
Tags:  #Cheatsheet #Linux 
Creation date: 2021-10-05

-----------------------------------------------

Path poisoning is where we take a file a program is using, replace it with a file that will give us a shell or elevate privileges so that when to program is run it uses our file instead.

`export PATH=<directory_with_poison>:$PATH`
