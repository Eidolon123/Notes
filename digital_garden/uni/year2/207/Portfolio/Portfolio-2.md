# 207 Portfolio 2

- [207 Portfolio 2](#207-portfolio-2)
  - [Week 13](#week-13)
    - [Basic Task](#basic-task)
    - [Advanced Task a)](#advanced-task-a)
    - [Advanced Task b)](#advanced-task-b)
  - [Week 14](#week-14)
  - [Week 15](#week-15)
    - [Basic Task](#basic-task-1)
    - [Advanced Task a)](#advanced-task-a-1)
  - [Week 16](#week-16)
  - [Week 17](#week-17)
  - [References](#references)

## Week 13

### Basic Task

```c
#include <unistd.h>
#include <stdio.h>
#include "sys/types.h"
#include <sys/wait.h>
int main(){



for(int i=0; i<5; i++)
{
        int choice;
        pid_t pid_value;
        // Print menu structure, scanf takes user input and assigns it to variable 'choice'.
        printf("\n--------------------------------\n");
        printf("Menu\n");
        printf("Choices remaining: %i\n", 5-i);
        printf("--------------------------------\n");
        printf("1: Show processes (ps)\n");
        printf("2: Show todays date (date)\n");
        printf("3: List files and directories in current directory (ls)\n");
        printf("4: Display file system information\n");
        printf("Please enter option: ");
        scanf("%d", &choice);
        printf("--------------------------------\n");
        if(choice==1)
        {
                int status = 0; // Set status to 0 as that is 
                pid_value = fork(); // Fork and store child PID value
                if(pid_value != 0) // Parent
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value); // fork() returns child PID to parent so can use pid_value to get child PID, getpid() returns PID of current process.
                }
                else if(pid_value==0) // Child
                {
                        printf("I am the child, I'm running the ps command to list processes ran by the current user.\n");
                        printf("The Process ID of this process is %d\n", getpid()); // execl replaces the current process with the new one, so process ID of execl process will be the same as childs PID.
                        execl("/bin/ps", "ps", "-u", (char*)NULL); // execl needs the path to binary and binary name, additional arguments for the binary run by execl must be in separate strings. Mist also be terminated with a null pointer.
                }
                else if(pid_value == -1) // fork() returns -1 if error
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==2)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the date command to display the current date in format dd/mm/yy.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        printf("The current date is: \n");
                        int date = execl("/bin/date", "date", "+%d/%m/%Y", (char*)NULL);
                }
                else if(pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==3)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the ls command to list the files and directories in the current directory.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        execl("/bin/ls", "ls", "-lsa", (char*)NULL);
                }
                else if(pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==4)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the df command to list information about the file system.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        execl("/bin/df", "df", (char*)NULL);
                }
                else if (pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else
        {
                printf("Please enter a number from the menu...\n");
        }
}
return 0;
}
```

![menu1](https://imgur.com/yq1dSyf.png)
> Option 1 of the menu running the ps command.

![menu2](https://imgur.com/UzrAoqF.png)
> Option 2 of menu running date command.

![menu3](https://imgur.com/5bvsE9z.png)
> Option 3 of menu listing current directory contents.

![menu4](https://imgur.com/NSpAssg.png)
> Option 4 of menu running df command.

![menu5](https://imgur.com/tpVufiu.png)
> Catching incorrect input.

### Advanced Task a)

```c
else if(choice==5)
{
  int status = 0;
  pid_value = fork();
  if(pid_value != 0)
  {
    wait(&status); // waits until first child process terminates
    pid_value_1 = fork(); // Create a second child inside the parent
    if(pid_value_1 == 0)
    {
      printf("\nI'm the second child\n");
      printf("The process ID of this process is %d\n", getpid());
      execl("/bin/ping", "ping", "-c", "4", "www.imdb.com", (char*)NULL);
    }
    else if(pid_value_1 != 0)
    {
      wait(&status); // Wait for second child to finish
      printf("\nI am the parent, my Process ID is %d. My first child's Process ID is %d, my second child's PID is %d\n", getpid(), pid_value, pid_value_1);
    }
    else if(pid_value_1 == -1)
    {
      printf("Error: Could not fork.\n");
    }
  }
  else if(pid_value==0)
  {
    printf("I am the first child.\n");
    printf("The Process ID of this process is %d\n", getpid());
    execl("/bin/ping", "ping", "-c", "4", "www.bbc.co.uk", (char*)NULL);
  }
  else if (pid_value == -1)
  {
    printf("Error: Could not fork.\n");
  }               

}
```

### Advanced Task b)

```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // For exit call
#include "sys/types.h"
#include <sys/wait.h>
int main(){

for(int i=0; i<5; i++)
{
        int choice;
        pid_t pid_value;
        pid_t pid_value_1;
        // Print menu structure, scanf takes user input and assigns it to variable 'choice'.
        printf("\n--------------------------------\n");
        printf("Menu\n");
        printf("Choices remaining: %i\n", 5-i);
        printf("--------------------------------\n");
        printf("1: Show processes (ps)\n");
        printf("2: Show todays date (date)\n");
        printf("3: List files and directories in current directory (ls)\n");
        printf("4: Display file system information\n");
        printf("5: One child pings www.imdb.com and the other child pings www.bbc.co.uk\n");
        printf("6: The parent processes pauses the child and then it restarts the child.\n");
        printf("7: Exit\n");
        printf("Please enter option: ");
        scanf("%d", &choice);
        printf("--------------------------------\n");
        if(choice==1)
        {
                int status = 0; // Set status to 0 as that is 
                pid_value = fork(); // Fork and store child PID value
                if(pid_value != 0) // Parent
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value); // fork() returns child PID to parent so can use pid_value to get child PID, getpid() returns PID of current process.
                }
                else if(pid_value==0) // Child
                {
                        printf("I am the child, I'm running the ps command to list processes ran by the current user.\n");
                        printf("The Process ID of this process is %d\n", getpid()); // execl replaces the current process with the new one, so process ID of execl process will be the same as childs PID.
                        execl("/bin/ps", "ps", "-u", (char*)NULL); // execl needs the path to binary and binary name, additional arguments for the binary run by execl must be in separate strings. Must also be terminated with a null pointer.
                }
                else if(pid_value == -1) // fork() returns -1 if error
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==2)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the date command to display the current date in format dd/mm/yy.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        printf("The current date is: \n");
                        int date = execl("/bin/date", "date", "+%d/%m/%Y", (char*)NULL);
                }
                else if(pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==3)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the ls command to list the files and directories in the current directory.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        execl("/bin/ls", "ls", "-lsa", (char*)NULL);
                }
                else if(pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==4)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until child process terminates
                        printf("I am the parent, my Process ID is %d. My child's Process ID is %d\n", getpid(), pid_value);
                }
                else if(pid_value==0)
                {
                        printf("I am the child, I'm running the df command to list information about the file system.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        execl("/bin/df", "df", (char*)NULL);
                }
                else if (pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }
        }
        else if(choice==5)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value != 0)
                {
                        wait(&status); // waits until first child process terminates
                        pid_value_1 = fork(); // Create a second child inside the parent
                        if(pid_value_1 == 0)
                        {
                                printf("\nI'm the second child\n");
                                printf("The process ID of this process is %d\n", getpid());
                                execl("/bin/ping", "ping", "-c", "4", "www.imdb.com", (char*)NULL);
                        }
                        else if(pid_value_1 != 0)
                        {
                                wait(&status); // Wait for second child to finish
                                printf("\nI am the parent, my Process ID is %d. My first child's Process ID is %d, my second child's PID is %d\n", getpid(), pid_value, pid_value_1);
                        }
                        else if(pid_value_1 == -1)
                        {
                                printf("Error: Could not fork.\n");
                        }
                }
                else if(pid_value==0)
                {
                        printf("I am the first child.\n");
                        printf("The Process ID of this process is %d\n", getpid());
                        execl("/bin/ping", "ping", "-c", "4", "www.bbc.co.uk", (char*)NULL);
                }
                else if (pid_value == -1)
                {
                        printf("Error: Could not fork.\n");
                }               

        }
        else if(choice==6)
        {
                int status = 0;
                pid_value = fork();
                if(pid_value!=0)
                {
                        printf("Stopping the Child\n");
                        kill(pid_value, SIGSTOP);
                        sleep(1);
                        printf("Waiting for Child\n");
                        waitpid(pid_value, &status, WUNTRACED);
                        printf("giving birth again\n");
                        kill(pid_value, SIGCONT);
                        waitpid(pid_value, &status, 0);
                }
                else if(pid_value == 0)
                {
                        printf("I am the child, about to sleep.\n");
                        sleep(2);
                        printf("I am the child, about to exit\n");
                        return(2);
                }

        }
        else if(choice==7)
        {
                exit(0);
        }
        else
        {
                printf("Please enter a number from the menu...\n");
        }
}
return 0;
}
```

![killing_the_child](https://imgur.com/vBHCJVW.png)
## Week 14

## Week 15

### Basic Task

```c
//critical_example2.c
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ops_sems.h"

#define MAX_STRING_SIZE 200 // Max size of string in array
#define NUMBER_OF_LINES 4 // Number of elements in the array

int main(int argc, char argv[]){
  //Use our source file as the "key"
  int id=ops_semget("critical_example2.c",1);
  
  char hen_arr[NUMBER_OF_LINES][MAX_STRING_SIZE] = { // Char array of Henry's line
    "There's a hole in the bucket, dear Liza, dear Liza, there's a hole in the bucket, dear Liza, a hole.",
    "With what shall I fix it, dear Liza, dear Liza? With what shall I fix it, dear Liza, with what?",
    "The straw is too long, dear Liza, dear Liza, the straw is too long, dear Liza, too long.",
    "With what shall I cut it, dear Liza, dear Liza? With what shall I cut it, dear Liza, with what?"
  };

  char liza_arr[NUMBER_OF_LINES][MAX_STRING_SIZE] = { // Char array of Liza's lines
    "Then fix it, dear Henry, dear Henry, dear Henry, then fix  it, dear Henry, dear Henry, fix it.",
    "With straw, dear Henry, dear Henry, dear Henry, with straw, dear Henry, dear Henry, with straw.",
    "Then cut it, dear Henry, dear Henry, dear Henry, then cut it, dear Henry, dear Henry, cut it.",
    "With an axe, dear Henry, dear Henry, dear Henry, with an axe, dear Henry, dear Henry, an axe."
  };

  int pid=fork();
  if(pid){
    //P1
    int count = 0; // Track current line
    while(1){
      ops_wait(id);
      // I removed the excess outputs including critical sections and sleep timer. The output looked too cluttered and was hard to read
      rsleep();
      printf("Henry: ");
      printf(hen_arr[count]); // Print item in hen_arr corresponding to count
      printf("\n");
      count++;
      ops_signal(id);
      if(count==NUMBER_OF_LINES) // Check if all lines have been printed
      {
        rsleep(); // Sleeps before breaking to clean up output
        break; // Break from loop
      }
    }
  }else{
    //P2
    // See comments above
    int count = 0;
    while(1){
      ops_wait(id);
      rsleep();
      printf("Liza: ");
      printf(liza_arr[count]);
      printf("\n");
      count++;
      ops_signal(id);
      if(count==NUMBER_OF_LINES)
      {
        break;
      }
    }
    
  }
  
}


```

![sem_output](https://imgur.com/3K8rO9N.png)

### Advanced Task a)

## Week 16

## Week 17

## References
