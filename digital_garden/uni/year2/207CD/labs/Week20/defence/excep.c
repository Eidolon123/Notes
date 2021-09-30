
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main (int argc, char *argv[])
{
int reactor_value = 0;
  while(1)
  {
reactor_value = rand()%10;
printf("reactor readings = %i \n", reactor_value);
}
  return 0;
}
