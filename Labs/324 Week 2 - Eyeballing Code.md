-----------------------------------------------
# 324 Week 2 - Eyeballing Code
Tags:  #TODO #Coding #Lab 
Creation date: 2021-10-07

-----------------------------------------------

```ad-question
title: launch.c

Look at the code and identify the security issues. Compile and run the program but note that gcc will attach canaries in respect of exploitable code.

Try:
`gcc launch.c -o launch`

Investigate security behaviours. How does buffer overrun protection (canaries) work? Try compiling the code without canaries:

`gcc launch.c -o launch -fno-stack-protector.`
```

Launch.c:
```c
#include <stdio.h>
#include <stdbool.h>

// Seriously dodgy code courtesy of Olve Maudal
//slideshare.net/olvemaudal/insecure-coding-in-c-and-c

void launch_missiles(int n)
{
	printf("Launching %d missiles\n", n);
}


void authenticate_and_launch(void)
{
	int n_missiles = 2;
	bool allowaccess = false;
	char response[8];

	printf("Secret: ");
	gets(response);

	if (strcmp(response, "Joshua") == 0)
		allowaccess = true;

	if (allowaccess) {
		puts("Access granted");
		launch_missiles(n_missiles);
	}

	if (!allowaccess)
		puts("Access denied");
}

int main(void)
{
	puts("Wargames MissileLauncher v0.1");
	authenticate_and_launch();
	puts("Operation complete");
}

```

The password is in plaintext: "Joshua". This means that even is the binary was shipped without the source code, a simple `strings` command would reveal the *'secret'* to the user.

Strings:
![[324 strings.png]]

Compilation with stack canaries:
![[324 launch.png]]

Compilation without stack canaries:
![[324 launch no can.png]]

Overflow:
![[324 overflow.png]]

How canaries work:


---

```ad-question
title: PHP

Look at the code and identify the security issues. Test the program code. You will need to set up a PHP friendly webserver e.g. lighttpd and you may find that your browser protects against exploits. If this is the case, try using a different browser

```

```php
<!doctype html>
<html lang="en">
<!-- courtesy of http://learnwebtutorials.com/php-is-insecure-by-default -->
   <head>
      <meta charset="utf-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <title>PHP Input Output Security</title>
   </head>
<body>
<?php
if ( isset($_POST['user'])  ) {
   echo "Hello " . $_POST['user'];
} else {
?>
   <form method="post">
   Enter your name:
   <input type="text" name="user">
   <input type="submit">
   </form>
<?php
}
?>
   </body>
</html>
```

Edit:
```php
<!doctype html>
<html lang="en">
<!-- courtesy of http://learnwebtutorials.com/php-is-insecure-by-default -->
   <head>
      <meta charset="utf-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <title>PHP Input Output Security</title>
   </head>
<body>
<?php
if ( isset($_POST['user'])  ) {
   $test = strip_tags($_POST['user']);
   echo "Hello " . $test;
} else {
?>
   <form method="post">
   Enter your name:
   <input type="text" name="user">
   <input type="submit">
   </form>
<?php
}
?>
   </body>
</html>
```

Stripping tags stops user inputting code to the website

- filter input
- HTML special characters