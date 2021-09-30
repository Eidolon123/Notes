#include <stdio.h>
#include <stdlib.h>

//The internals of this struct aren't important
//from the user's point of view
typedef struct{
  int file;        //File being read
  int bufferCacheLength;  //Fixed buffer-cache length
  int alongBufferCache;    //Current point in the buffer-cache
  char* bufferCache;      //A pointer to a piece of memory
                     //  same length as "cacheLength"
} bufferCacheStruct;




//Open a file with a given size of cache with
bufferCacheStruct* file_open(char* filename, int bufferCacheSize);


//Close an open file
void file_close(bufferCacheStruct* buff);

//Read a byte.  Will return EOF if empty.
char return_character(bufferCacheStruct* buff);



//---------------------------------------------------------

//Refill an empty buffer.  Not intended for users
int bufferCache_refill(bufferCacheStruct* buff);


