#include <fcntl.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 500 //Setting the buffer size to 500 bytes
#define OUTPUT_MODE 0700 //Setting the permissions of the output file

void removeStops(int file) // Function for removing stop words from the file passed to it
{
    int read_size = 1, write_size; //Initialising read and write size to be > 0
    char buf_new[BUF_SIZE]; //Setting up a new buffer to avoid any errors in printing
    while(read_size > 0)
    {
        read_size = read(file, buf_new, BUF_SIZE);
        for(int j=0; j<read_size; j++) //Reading each character in buffer one by one
        {
            /* 
                Each time a space is read by the program it checks to see if the next word is a stop word
                If the next word is a stop word the counter 'j' is skipped forward over the word to avoid printing it to display
            */
            if(buf_new[j]==' ' & buf_new[j+1]=='a' & buf_new[j+2]==' ') 
            {
                j = j+2;
            }
            if(buf_new[j]==' ' & buf_new[j+1]=='t' & buf_new[j+2]=='h' & buf_new[j+3]=='e' & buf_new[j+4]==' ')
            {
                j = j+4;
            }
            if(buf_new[j]==' ' & buf_new[j+1]=='a' & buf_new[j+2]=='n' & buf_new[j+3]==' ')
            {
                j = j+3;
            }
            if(buf_new[j]==' ' & buf_new[j+1]=='t' & buf_new[j+2]=='o' & buf_new[j+3]==' ')
            {
                j = j+3;
            }
            
            else
            {
                cout << buf_new[j]; //If current character is not a space followed by a stop word, print to display current character in buff
            }
        }
    }
    cout << "=======================================================" << endl << endl << endl;
    close(file);
}

int main(int argc, char *argv[])
{
    int in_file1, in_file2, out_file; //Initialising both input files and the output file as integers
    int read_size = 1, write_size;
    int read_size2 = 1, write_size2;
    char buf[BUF_SIZE]; //Creating two buffers, one for each input file
    char buf2[BUF_SIZE];

    //There are 5 error checks in this code: the correct amount of arguments, open and read tests on the input files and a creation test for the output file
    if (argc != 4)
    {
        cout << "Please enter 4 arguments into the command line." << endl;
        exit(1);
    }

    in_file1= open(argv[1], O_RDONLY);
    if (in_file1  < 0)
    {
        cout << "Error opening the designated file." << endl;
        exit(2);
    }

    in_file2 = open(argv[2], O_RDONLY);
    if (in_file2  < 0)
    {
        cout << "Error opening the designated file." << endl;
        exit(3);
    }

    out_file = creat(argv[3], OUTPUT_MODE);
    if (out_file < 0)
    {
        cout << "Error creating the output file." << endl; 
        exit(4);
    }

    bool diff = false; //Stays false until the program detects the files are different
    while (read_size > 0 | read_size2 > 0)
    {
        if(diff == true) //If diff is set to false break out of the while loop
        {
            break;
        }
        read_size = read(in_file1, buf, BUF_SIZE); // Filling both buffers with each input file
        read_size2 = read(in_file2, buf2, BUF_SIZE);
        int char_pos = 0; //Tracking the number of the character the code is currently reading
        for(int i=0; i<read_size; i++) //Iterate through each character in the buffer one by one
        {
            char_pos++;
            if(buf[i] == buf2[i])  //Checks to see if the characters in the same position in the two files are the same
            {
                continue;
            }
            else //Catches when the characters differ
            {
                cout << "Character mismatch at character: " << char_pos << endl;
                cout << "File 1 contained: " << buf[i] << endl;
                cout << "File 2 contained: " << buf2[i] << endl;
                diff = true; //Set diff to true so we can break out of while loop 
                break; //Exit for loop
            }
        }

        if (read_size <0)
        {
            cout << "Error reading data from file." << endl;
            exit(6);
        }

        write_size = write(out_file, buf, read_size); //If files are identical execute normal function of copying input file to output file

        if (write_size<=0)
        {
            close(in_file1);
            close(in_file2);
            close(out_file);
            cout<<"Reading and writing from and to files is complete"<<endl;
            exit(7);
        }
    }
    //When the program detects the files are different this code is executed
    //Closing and reopening each file eliminated some errors I was having with incomplete outputs
    close(in_file1);
    in_file1= open(argv[1], O_RDONLY);
    removeStops(in_file1); //Calling removeStops for the first input file
    close(in_file2);
    in_file2 = open(argv[2], O_RDONLY);
    removeStops(in_file2); //See above, with second input file
    exit(8);
}

