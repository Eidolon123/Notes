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
    if (argc != 4) //Checks to see if correct number of arguments entered, exits with statement if caught
    {
        cout << "Please enter 4 arguments into the command line." << endl;
        cout << "<./buffer <input file> <output file> <Sentences in output>" << endl;
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

    int total = 0;
    int count = 0;
    while (read_size > 0) //Only run this loop while there is still data being read from the file
    {
        char buf2[BUF_SIZE] = {}; //Empty buffer on each run to avoid duplicating outputs
        count = 0;
        read_size = read(in_file, buf, BUF_SIZE); //Fills the buffer as far as it can from input file and gets the size
        for(int i=0; i<read_size; i++) //Iterating through each character stored in the buffer one by one
        {
            if(total < 3) //Only want to grab 3 sentences so we dont exceed 50 words
            {
                if(buf[i] != '.' && count == 1) //If these are characters after the first fullstop in the buffer
                {
                    buf2[i] = buf[i]; //Add current character to our output buffer
                }
                if(buf[i] == '.' && count == 1)//Are we at the end of the sentence we want to output?
                {
                    buf2[i] = buf[i]; //Add last fullstop to output buffer so total output makes sense
                    count++;
                    total++; //Total sentences outputted has increased by one
                }
                if(buf[i] == '.' && count != 1) //Any other fullstops in the buffer also increase the count
                {
                    count++;
                }
            }
        }


        if (read_size <0) //Checking to see if the file can be read, exiting if it cant
        {
            cout << "Error reading data from file." << endl;
            exit(4);
        }
        write_size = write(out_file, buf2, read_size); //Writes the contents of the buffer to the output file
        if (write_size<=0) //When the write size is 0 the program has reached the end of the input file
        {
            close(in_file); //Closing both files
            close(out_file);
            cout<<"Reading and writing from and to files is complete"<<endl; //Outputting all stats collected on the input file, then exiting
            exit(5);
        }
    }
}
