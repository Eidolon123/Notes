## Week 2 - Eyeballing code

### Task 1 - launch.c

> c code contained in launch.c
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
		
	https://www.file.io/download/bY302HGKjBmrif (allowaccess) {                                               
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
Here the canary is being generated and stored in memory space canary. This happens towards the start of the program.

![[324-canarie2.png]]
Here we can see the check towards the end of the program to see if the canary has been written over in any capacity. The original canary value is subtracted from the stored value in canary, if this results in anything but 0 the canary has been altered and **__stack_chk_fail** is called, this can be seen below.

![[324-canarie3.png]]

If the subtraction results in 0 the canary has not been altered and **__stack_chk_fail** is jumped over so the program may continue to execute normally.

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

Launch.c presents a few issues made worse by the context of the program. The most obvious being the "secret" phrase needed to launch missiles from this program is hard-coded and stored in plaintext. In reference to the CIA triad this practice eliminates confidentiality where in this scenario confidentiality is assumed to be absolutely top priority. Due to the very low skill barrier required to extract this information from the compiled binary and the amount of control over the program it allows attackers, the severity of this vulnerability is astronomical.
The second issue of being vulnerable to buffer overflow attacks stems from the use of outdated and redundant functions. This requires a simple solution of making sure developers are always using the latest stack, running static analysis and fuzzing tools on code to catch these issues. As the impact of the vulnerability is extremely high but requires a highly skilled attack to exploit, the severity of this buffer overflow would be less than the plaintext password issue.

For input_form.php the XSS vulnerability introduced by the lack of sanitisation can present a wide array of risks depending on how the form is implemented. These risks are mainly focused around privacy and data security. The issue is less focused on this specific program and more on sanitisation as a whole. Any input taken from a user should never be trusted to contain only expected data. Not implementing sanitisation in these situations opens up the application to abuse from bad actors with minimal skill or knowledge requirements. Depending on the use case this input form could be harmless as it was just hosted on a localhost server, or devastating if implemented in a real world public facing web app.

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


### Thoughts on visual inspection

Visual inspection as a concept is a good practice for a developer to have but can be vastly improved through the use of tools and automation. Having a constant awareness of security issues and possible vulnerabilities in code will improve the overall security of code written in this way. It can be hard to look over code that has just been written and pick it apart, this is why visual inspection is good for small or less complex security issues but should always be backed up by automated and impartial tools to complete the testing.

## Week 3 - Static analysis tools for C/C++

### Task 1 - Splint

#### What does splint do?

Splint is a static analysis tool used to check for basic security vulnerabilities in the form of logic, runtime and syntax errors in code without running it. It is based on the lint tool but makes improvements, allowing the user to make annotations to source code to enable more advanced linting. For example if a chunk of code is constantly generating false positive errors, it can be placed between /\*@ignore@\*/ and /\*@end@\*/ tags to suppress warnings generated from this region. 

#### Using it on code

```c
main(void) {
   int i;
   for (i = 0; i < 10l; i++) {
      printf("%d\n",i); 
   }
}
```
> source code contained in provided toy_code.c

This code is designed to print out the numbers 0-9 in order to the terminal. It compiles and runs without any modifications but does generate a splint report as can be seen below, the binary and source code have been named count and count.c respectively.

![[count-splint.png]]

This specific report only returns two syntactic errors that could be classed as false positive as they pose no logical errors or security issues. These issues can both be cleared up by implementing the changes below.

```c
int main(void) {
  int i;
  for (i = 0; i < 10; i++) {
    printf("%d\n", i);
  }
  return 0;
}
```

Running Splint on this modified code generates a clean report from splint as seen below.

![[324-new-count-splint.png]]

When comparing using splint to eyeballing code it depends on who is eyeballing the code. Experienced developers and diligent professionals may notice the issues being thrown up by splint. Even experienced professionals will miss security issues in code occasionally and that is why using any sort of tool along side eyeballing code will always be the best solution. The use of an automated tool removes the human error factor and allows the process of securing code to be automated.

This discrepancy between what a human can eyeball and what a tool can pick up is highlighted if Splint is used on the launch.c code from week 2. When eyeballing the code the 2 most glaring security issues were picked up on. This splint report for this code pictured below provides a much more granular look at the issues in the code including syntactic errors that can easily slip past developers less experienced with a specific language.

![[324-launch-splint.png]]

### Task 2 - Alternate static analysis tools

An alternative to Splint for static analysis in C code is cppcheck.


![[324-launch-cppcheck.png]]

As we can see from the cppcheck report for launch.c above, it has returned some different errors than what splint managed to pick up. The main difference that can be seen is that cppcheck will use style checking to find possible mistakes and redundancies within the code. While both tools pick up on how gets() is obsolete and provide an safer alternative, cppcheck does a better job at explaining why using gets() is an error in the first place. Finding the gets() function is accomplished in much the same way as in Splint where there is a list of depreciated functions and the tool will just match them syntactically.

## Week 5 - Fuzzers and protocol analysis

### Task 1 - Compare and contrast Fuzzers

#### Evolutionary

Evolutionary fuzzing tools analyse how their input affects the code it's working on. For example if a body of code had multiple branching if statements, the fuzzer would store inputs that reach through multiple branches and base further inputs off of those. As this is a model of fuzzing in which the tool could be said to be learning about the code as it runs, this opens opportunities to integrate systems such as machine learning. Using this approach a evolutionary fuzzing tool could analyse a code base, move onto a new code base and recognise snippets of code that are more likely to be vulnerable and then generate input for that code based on these vulnerable snippets. 


#### Mutational

Mutation based fuzzing tools operate on a basis of taking some form of input data and mutating it in either a random or planned way. For example, a web fuzzing tool named Ffuf uses mutation fuzzing to brute force directories, in this case mutating from a known list of common directories would be used to keep the input valid.

The advantage of using mutation based fuzzing is that it can provide a program with unexpected inputs that developers are unlikely to test.
Quantum computing will greatly increase the speed at which something can be fuzzed in this way. Developments in this field will increase mutational fuzzing's value as a security tool and could result in huge code bases being fuzzed and analysed in seconds.

#### Generational

Generational fuzzers work based on prior knowledge of the internal workings of the protocol (Harper et al., 2018). Being able to convert protocols and structures into a usable data model for the fuzzer is a very time consuming task and is likely to be made harder by the lack of availability of these protocols and structures used in a program. This however means that if a solid and valid data model can be made, then using generational fuzzing is much more efficient than mutational as almost all inputs are likely to be valid and more targeted errors or vulnerabilities can be found within the code.

### Task 2 - Security Protocol Analysis

Assuming the adversary in the network is a Dolev-Yao attacker has many benefits for security. A Dolev-Yao attacker is a worse case scenario for anyone communicating on the network they're attacking. Assuming the worst case scenario allows the security protocols to be built in a way to counter this, by countering the worse case scenario it is more than likely that adversaries of a lower caliber will be caught in the same web. This has the effect of lowing the complexity of protocols that would have to factor in each kind of adversary other wise.
In the specific case of parties communicating over a public network assuming a Dolev-Yao adversary is likely to be the right choice, security implementations are often weaker and attackers have much more free reign over these networks.

Situations where a weaker adversary model would be used would have to take into account the type and value of a given network. High security military networks are unlikely to be breached in this manner so a less severe adversary model could be used. Even in such a case, creating protocols around a Dolev-Yao adversary would make sense in terms of strengthening security practices.

## Week 6 - Basic analysis of malware

### datura and hello_32

The binary hello_32 seems to just print the string "Hello, world!" to terminal when ran. The binary datura does not have a clear function at first as no feedback is given to the user. As datura does not have a clear function this binary will be focused on during analysis.

#### Initial investigations

Output of `strings` command on the datura file, note worthy output has been numbered.

![[324-strings-d.png]]

1. setuid
	- setuid is used to change the user ID, in the case of this program is likely to be setting the UID to the UID of the owner of the file.
2. execl
	- `execl` is used to run system commands such as `ls` or `cat` from within a compiled program. At a point during execution the program is expected to use a system command.
3. __isoc99_scanf
	- This means the program will be taking input from the user at some point. 
4. puts
	- The `puts` function will print text to the screen. At some point in the program execution data is meant to be relayed to the user. 
5. __stack_chk_fail
	- This is a function called when a canary has been found to be changed in someway, ending the program to avoid buffer overflows. It can be concluded that the binary was compiled with canaries.
6. setgid
	- This is the same concept as setuid but will change the group ID of the user instead.
7. strcmp
	- Comparison of two strings, returns 0 if the strings are the same. In this program this is likely to be comparing user input to the 
8. /bin/sh
	- As `execl` is also being called in the program it could be safe to assume that `/bin/sh` is the argument for that call. This indicates that the purpose of this code could be to spawn a shell.

Overall impression from the initial investigation is that this a binary that checks for a password, if that password is correct then a shell is spawned with the permissions of the file owner.

#### System library routines

![[324-objump-dynamic-d.png]]

Dumping the library routines used by the program shows much of the same information as the strings command.

#### Disassembly

The following images are the disassembly of the main function from the datura program in radare2, objdump and ghidra respectively.

![[324-disass-radare2.png]]

![[324-disass-objump.png]]

![[324-disass-ghidra.png]]

Radare2 and objdump both display the opcodes of instructions where as ghidra does not display them. Radare2 and Ghidra offer a quick translation from hex to ASCII characters that renders the password for the program in plaintext. Due to ghidra using memory name spaces the user can easily confirm the presence of stack canaries.
Overall Ghidra offers the most complete, user friendly disassembly with comments stating arguments used in functions.

#### Information from disassembly

The called functions strcmp, puts, setuid, setgid and execl are all functions available in C so this program is highly likely to be written in C. 
It can be seen from the disassembled main function that a string comparison takes place between the variables `s1` and `s2`. `s1` being the stored password, `s2` being our input. If this comparison fails a large portion of the code is skipped over and the program is terminated after a canary check. This comparison takes place in the following code snippet.

```assembly
lea rdx, [s2]
lea rax, [s1]
mov rsi, rdx
mov rdi, rax
call strcmp
test eax, eax
jne 0x40079a
```

If this check succeeds the program tries to spawn a shell using this snippet.

```assembly
mov edi, 0
call sym.imp.setuid
mov edi, 0
call sym.imp.setgid
mov edx, 0
mov edi, 0x4008b1
mov edi, str.bin_sh
mov eax, 0
call execl
```

This assembly attempts to set the UID and GID to 0 (root), then execute a shell with root permissions using `execl("/bin/sh")`.

For an unknown reason the password that is discovered during disassembly "jimsonweed" is short a single character that is not displayed in any of the disassembly reports. 

As can be seen in the assembly below, the password of the program is being compared to our input using the registers RDI and RSI:

```assembly
mov rsi, rdx
mov rdi, rax
call strcmp
```

By monitoring the registers RDI and RSI during execution, the full password can be discovered: "jimsonweed@".

![[324-password-d.png]]

##### Attempt to manually decompile

```c
#include <stdio.h>    
#include <string.h>    
#include <unistd.h>    
    
int main(void) {    
  int compResult;    
  char input[30];    
  char password[12] = "j";    
    
  strcat(password, "i");    
  strcat(password, "m");    
  strcat(password, "s");    
  strcat(password, "o");    
  strcat(password, "n");    
  strcat(password, "w");    
  strcat(password, "e");    
  strcat(password, "e");    
  strcat(password, "d");    
  strcat(password, "@");    
      
  scanf("%s", input);    
      
  compResult = strcmp(password, input);    
  if (compResult == 0) {      
    puts(".\n");    
    setuid(0);      
    setgid(0);    
    execl("/bin/sh", "", NULL);    
  }    
}      
```
> decompiled version of datura from information gained during disassembly.

![[324-decomp-self.png]]

In the above image the source code is being compiled and ran. The behavior for wrong and correct passwords is the same as the provided `datura` binary.

#### Decompilation

![[324-decomp.png]]
> Ghidra decompilation of provided datura binary

![[324-decomp-hello.png]]
> Ghidra decompilation of provided hello_32 binary, confirms that it is a very simple binary with one function.

##### Thoughts

The act of decompiling the datura binary doesn't reveal any previously unknown information. All function calls and variable information was available during the initial investigation and disassembly stages. Decompilation however provides a much more readable format than pure assembly instructions.

Decompiling the hello_32 binary works very well due to it being a very simple program. The difference in clarity between these decompiled examples suggests that as programs scale in complexity and length the decompiled versions will also become a lot more complex and harder to read.

Further analysis in the form of dynamic analysis could lead to more information becoming available. Dynamic analysis could be used to try and find vulnerabilities such as buffer overflows. 


## Personal Reflection

The process of keeping a portfolio of tasks current and up to a standard was hard for me to grasp during the first weeks of the module. Getting behind caused a large build up of work. Learning to take one task at a time, not leaving them to pile up has helped me maintain the portfolio without it dragging other projects down. To further improve in this area I should aim to complete tasks with time to spare. This would be to enable myself to invest that spare time into further reading into subjects that caught my interest, such as dynamic analysis.

Getting in practice using disassembly and decompilation tools has increased my proficiency with assembly language. Before the start of this module I knew basic commands and syntax for assembly. As the module has progressed I have felt more comfortable looking at assembly and following the data/logic flow of the program. This is a skill that will make me an overall better red/blue team member and general cyber security professional as having a better understanding of how a system works means it's easier to break it or stop others breaking it. To further improve in this area I should start to move into dynamic analysis and live patching as this will be a valuable tool in an arsenal.

I have a habit of only reading into subject areas that I'm already knowledgeable on. For example, the first few weeks that involved security by design and security/design principles did not catch my interest. This meant that I didn't invest much time into learning those materials. In the future I should take the time to read into the materials and discover how this subject I'm less interested in links to the other subjects that do interest me a lot. Learning about system security design and principles would allow me to better understand these systems when I'm performing static/dynamic analysis.

Learning to use new tools or familiar tools in new ways was a big takeaway from this module for me. Usually I will find one tool that works, such as gobuster for directory busting, then stick with that tool until it stops being developed. Running through labs and checking the output of different tools against each other has shown me that I need to do more research into the tools I use and practice with them to see what works for me. Through the module weeks 4/5/6 I used several different tools and made my own workflow using the tools I found best suited me. This is a practice I will take into other areas with me and use to improve my overall effectiveness as a security engineer. 

## References

Harper, A., Regalado, D., Linn, R., Sims, S., Spasojevic, B., & Martinez, L. et al. (2018). _Gray hat hacking_ (5th ed.). McGraw-Hill Education.