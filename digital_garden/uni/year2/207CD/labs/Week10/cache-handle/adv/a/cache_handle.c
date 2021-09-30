#define _GNU_SOURCE
#include "cache_handle.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//http://www.phim.unibe.ch/comp_doc/c_manual/C/SYNTAX/struct.html
//http://vergil.chemistry.gatech.edu/resources/programming/c-tutorial/structs.html


int bufferCache_refill(bufferCacheStruct* buff){
  //Refills a buffer-cache
  //Only works when completely used buffer-cache
  if(buff->alongBufferCache!=buff->bufferCacheLength) //Checks if we're at the end of the buffer or not. (if(position!=Length of buf))
    return 0;
  else{
    buff->alongBufferCache=0; //Set position in cache to the start
    int len=read(buff->file, buff->bufferCache, buff->bufferCacheLength);//Read in new chunk on data into the cache
    if(len<buff->bufferCacheLength)
      for(int i=len;i<buff->bufferCacheLength;i++)	//If not enough data to fill the cache, fil with EOF
	buff->bufferCache[i]=EOF;  //Accessing like an array!
    return len;
  }
  
}

void file_close(bufferCacheStruct* buff){
  free(buff->bufferCache);
  close(buff->file);
}


bufferCacheStruct* file_open(char * filename, int bufferCacheSize){
  //Info on malloc
  //http://www.space.unibe.ch/comp_doc/c_manual/C/FUNCTIONS/malloc.html
  int f;
  if ((f = open(filename, O_RDONLY)) == -1){
    fprintf(stderr, "Cannot open %s\n", filename);
    return 0;
  }

  bufferCacheStruct* initBufferCache=(bufferCacheStruct*)malloc(sizeof(bufferCacheStruct));
  initBufferCache->file=f;
  initBufferCache->bufferCacheLength=bufferCacheSize;
  initBufferCache->alongBufferCache=bufferCacheSize; //Start off with no characters, so refill will work as expected
  initBufferCache->bufferCache=(char*)malloc(sizeof(char)*bufferCacheSize);

  bufferCache_refill(initBufferCache);
  return initBufferCache;
}
//------------------------------------------------------------------
char return_character(bufferCacheStruct* buff){
  char character; //Initialise character variable
  bufferCache_refill(buff); //Check if buffer needs to be refilled
  character = buff->bufferCache[buff->alongBufferCache]; //Sets character to the current character in the buffer according to alongBufferCache
  buff->alongBufferCache++; //Set position to the next character
  return character; //Return current character
}

