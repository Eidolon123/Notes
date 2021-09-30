#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6

int main()
{
    char *email;
    int i;

    email = malloc (SIZE);
    printf ("Please enter your full email address: ");
    scanf ("%s", email);
int email_length;
email_length = strlen(email);
    for (i=0; i<email_length; i++)
       printf ("%c", email[i]);
    printf ("\n");
    return 0;
}


