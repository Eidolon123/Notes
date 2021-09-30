# CTF_RCE

  - [1. Recon](#1-recon)
  - [2. Accessing Webserver](#2-accessing-webserver)
  - [3. Gobuster](#3-gobuster)
  - [4. The Quiz](#4-the-quiz)
  - [5. RCE and User.txt](#5-rce-and-usertxt)
  - [6. Upgrading the shell and switching user](#6-upgrading-the-shell-and-switching-user)
  - [7. Getting Root](#7-getting-root)

## 1. Recon

<img src ="https://i.imgur.com/iMF0nwV.png">

Nmap scan finds port 22 and 80 open, with an SSH and HTTP server running on them respectively.

## 2. Accessing Webserver

<img src =https://i.imgur.com/e1nZArP.png>

Index.html landing page is empty, better scan for additional directories.

## 3. Gobuster

<img src =https://i.imgur.com/r5wmXas.png>

Scanning using the common.txt wordlist, when we access the Moodle directory we can login with provided credentials to access the teacher account.

## 4. The Quiz

<img src =https://i.imgur.com/JpRcXBV.png>

the calculated question on moodle allows the teacher to input a formula with variables ({x}) that are then populated by moodle with random values. The questiontype.php uses the eval function which takes a string and evaluates it as PHP code which provides us with an opportunity to execute arbitrary code. A function called **qtype_calculated_find_formula_errors** uses preg_match just before eval() to match our input in the formula box with a regular expression. But before this it runs str_replace, replacing the placeholders ({x}) in the variable with '1'. As the placeholders aren't restricted we can place our PHP code in a placeholder and have it reach the eval call intact. Once the eval function runs the code, _get[0] grabs the data we pass to the 0 variable in the URL, shown in the image below when we run ls -l.

## 5. RCE and User.txt

Now that we have injected our code into the questiontype.php file, if the code has been evaluated correctly we should have RCE by adding a variable to the end of the URL, test this by outputting the directory listing to a txt file.

<img src =https://i.imgur.com/VUhQcyp.png>

Writing to the question directory we're in is forbidden so will have to write to a the parent directory.

<img src =https://i.imgur.com/BlqMdWd.png>

Now we need a listener set up on our machine to catch the shell we will throw from the webserver.

<img src =https://i.imgur.com/MZk947d.png>

Let's change the command we're running through the URL into a netcat command to connect to our listener and run /bin/bash to give us our shell.

<img src =https://i.imgur.com/LEU9N2g.png>

Access! We get a www-data shell on the webserver and can access user.txt for our first flag 

<img src =https://i.imgur.com/oa6rTIs.png>

## 6. Upgrading the shell and switching user

The shell we've been given is pretty crummy and there's no python on the box to give ourselves something better. In the home directory is an id_rsa file though, we can copy this to our machine and use it to log back in through SSH as hollister with a much nicer shell.

<img src =https://i.imgur.com/qBfV7rs.png>

## 7. Getting Root

Searching for SUID bit files in the system reveals a file in our home directory called checkfile. 

<img src =https://i.imgur.com/WPn5Jfj.png>

Trying to read the contents is useless as it is a binary file, running it shows us that it just outputs the contents of user.txt.

<img src =https://i.imgur.com/7rD706j.png>


The odds are this file is using the cat command to output the contents of the file. This means we can create our own version of cat, add it to the $PATH variable and checkfile should use ours instead.

As checkfile is run with root privileges, so will our version of cat, therefor all we need is /bin/sh in the cat file to be given a root shell and access root.txt for the final flag. 

<img src =https://i.imgur.com/OLKBYzM.png>
