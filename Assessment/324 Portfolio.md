## Week 2 - Eyeballing code

### Task 1 - launch.c

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

#### What are the security issues?

The password is in plaintext in the source code. This can easily been seen if strings is used on the compiled file. This snippet of code shows that the program is comparing our input to the desired response of `Joshua`.

```c
if (strcmp(response, "Joshua") == 0)
	allowaccess = true;
```

The function `gets()` is used in the program, this is a dangerous and depreciated function. It is dangerous because it will keep reading data into the buffer and overflow it if the input data is larger than the buffer. This is due to the `gets()` function not doing any sort of testing of the bounds for the `response` char array and keeps reading until it sees a `\n` character.

```c
gets(response);
```

#### Canaries

The size of the buffer for the `response` is 8 bytes. With canaries when we try to input more than this stack smashing is detected and the program terminates. This can be seen in the image below when we try to input 9 'a's instead of 8.

![[launch-with-can.png]]

![[324-canarie1.png]]

![[324-canarie2.png]]

![[324-canarie3.png]]

When we remove the canaries from the program we can input 9 'a' characters again but with no error being thrown. Now when we try to overflow the buffer with a large amount of 'a' characters we see that the program behaves in a different manner and allows access then launches a large amount of missiles.

![[launch-without-can.png]]


### Task 2 - input_form.php

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

Running this code on a php server gives us a simple input form for a name.

![[php-form.png]]

Submitting this just generates a text message with the provided name.

![[php-result.png]]

#### What are the security issues?

As we can see from the source code, the `'user'` input is taken directly from the user field of the form and inserted into the body of the page.

```php
if ( isset($_POST['user'])  ) {    
   echo "Hello " . $_POST['user'];
}
```

Due to the lack of sanitisation in the code, script tags are left in and interpreted as valid PHP code. This can be seen when we provide the 'user' as `<script>alert("foo")</script>` and an alert pops up.

![[php-script.png]]

![[php-alert.png]]

This indicates that the input form is vulnerable to an XSS attack, therefor a malicious user can interact with the website possibly stealing other user sessions. The extent of damage possible depends on what webapp this form is used in.

Just in this simple form we can provide the input `<scipt>document.title='Foo Bar'</script>` to the form and we can see it directly affects the HTML of the page.

![[php-xss.png]]

![[php-title.png]]

### Task 3 - Comparison of security issues arising in each piece of code



### Task 4 - How can the code be improved?

#### launch.c

```c
#include <stdbool.h>    
#include <stdio.h>    

void launch_missiles(int n) { printf("Launching %d missiles\n", n); } 

/*
DJB2 hash function taken from http://www.cse.yorku.ca/~oz/hash.html and modified to run in this program.
*/
unsigned long hash(char *str) {    
    
  unsigned long hash = 5381;    
  int c;    
  while ((c = *str++))    
    hash = ((hash << 5) + hash) + c;    
  return (hash);    
}    
    
void authenticate_and_launch(void) {    
  int n_missiles = 2;    
  bool allowaccess = false;    
  char response[8];    
  unsigned long password = 229429894566553; // Hash of password
    
  printf("Secret: ");    
  fgets(response, 8, stdin);    
    
  if (hash(response) == password)    
    allowaccess = true;
	
  if (allowaccess) {    
    puts("Access granted");    
    launch_missiles(n_missiles);    
  }
  
  if (!allowaccess)    
    puts("Access denied");    
}    

int main(void) {    
  puts("Wargames MissileLauncher v0.1");    
  authenticate_and_launch();    
  puts("Operation complete");    
}    
```

As the function `gets()` has been depreciated since c99 we should replace it with `fgets()`. `fgets()` takes 3 arguments, firstly the array to write to (response), the maximum number of characters to read into the array (8) and the stream we are reading from (stdin). This negates the overflow vulnerability originally present in the code as even if we provide an input of more than 8 characters, the response variable will still only contain 8 characters.

The next issue to tackle is the plaintext password `"Joshua"` being present in the source code. This can be negated by using hash function to check the input against a predefined hash of `"Joshua"` instead. The implementation above uses the djb2 hashing algorithm for the sake of simplicity, in a full implementation of this program sha256 or something similar would be used.

#### input_form.php
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

### Task 5 - Security issues in other code

#### Other code security issues



#### Thoughts on visual inspection



## Week 3 - Static analysis tools for C/C++

### Task 1 - Splint

#### What does splint do?

#### Using it on code

```c
main(void) {
   int i;
   for (i = 0; i < 10l; i++) {
      printf("%d\n",i); 
   }
}
```

![[count-splint.png]]

#### What exactly does the code do?

This code is designed to print out the numbers 0-9 in order to the terminal.

#### Toy code

### Task 2 - Alternate static analysis tools

#### How does it work?

#### How effective is it?


## Week 5 - Fuzzers and protocol analysis

### Task 1 - Compare and contrast Fuzzers

### Task 2 - Security Protocol Analysis

## Week 6 - Basic analysis of malware

### datura_32 and hello_32

#### Initial investigations

#### System library routines

#### Disassembly

#### Information from disassembly

#### Decompilation

#### Thoughts

