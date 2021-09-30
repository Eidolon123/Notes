#include <fcntl.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 500 //Setting the buffer size to 500 bytes
#define OUTPUT_MODE 0700 //Setting the permissions of the output file


int main(int argc, char *argv[])
{
    int in_file, out_file; //Initialising input and output files as integers
    int read_size = 1, write_size; //Setting read and write size to 1 to make sure the program goes into the while loop at line 45 and avoids tripping line 84/90 on the first run and 
    char buf[BUF_SIZE]; //Initialising a character array of the same size as buf_size to store the characters from the input file
    if (argc != 3) //Checks to see if correct number of arguments entered, exits with statement if caught
    {
        cout << "Please enter 3 arguments into the command line." << endl;
        exit(1);
    }

    in_file= open(argv[1], O_RDONLY); // Reading first argument given as input file in read only mode
    if (in_file  < 0) //If the file cannot be opened this statement exits the program
    {
        cout << "Error opening the designated file." << endl;
        exit(2);
    }

    out_file = creat(argv[2], OUTPUT_MODE);
    if (out_file < 0) //See above, with output file instead
    {
        cout << "Error creating the output file." << endl; 
        exit(3);
    }

    int vowel_count = 0; //Initialising the 4 counters used to track the stats of the inputted file
    int total_chars = 0;
    int const_wordstart = 0;
    int times_filled = 0;
    while (read_size > 0) //Only run this loop while there is still data being read from the file
    {
    read_size = read(in_file, buf, BUF_SIZE); //Fills the buffer as far as it can from input file and gets the size
    cout << "Characters read from buffer: " << read_size << endl; //Outputs no. of characters read into the buffer
    if(read_size != 0) //Increments the total times filled variable if the read size is not 0
    {
        times_filled++; 
    }
    for(int i=0; i<read_size; i++) //Iterating through each character stored in the buffer one by one
    {     
        if(buf[i] != ' ') //If the character being read isn't a space, inc the total chars counter
        {
            total_chars++;
        }
        if(buf[i]== 'a' | buf[i]=='e' | buf[i]=='i' | buf[i]=='o' | buf[i]=='u') //If the character being read is a vowel, inc vowel count
        {
            vowel_count++;
        }
        if(buf[i+1] == ' ') //Reading one character ahead to see if the current character is the end of a word
        {
            auto word_start = buf[i+2]; //Storing the start of the next word
            if(word_start != 'a' & word_start != 'e' & word_start != 'i' & word_start != 'o' & word_start != 'u' ) //Checking if word start is not a vowel, inc const_wordstart if it isn't
            {
                const_wordstart++;
            }
        }
    }

    if (read_size <0) //Checking to see if the file can be read, exiting if it cant
    {
        cout << "Error reading data from file." << endl;
        exit(4);
    }
    write_size = write(out_file, buf, read_size); //Writes the contents of the buffer to the output file
    if (write_size<=0) //When the write size is 0 the program has reached the end of the input file
    {
        close(in_file); //Closing both files
        close(out_file);
        cout<<"Reading and writing from and to files is complete"<<endl; //Outputting all stats collected on the input file, then exiting
        cout << "Total vowels: " << vowel_count << endl;
        cout << "Consonents at the start of a word: " << const_wordstart << endl;
        cout << "Total characters excluding spaces: " << total_chars << endl;
        cout << "Times the buffer was filled: " << times_filled << endl;
        exit(5);
    }
    }

}
