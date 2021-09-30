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

