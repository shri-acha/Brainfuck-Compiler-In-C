#include <unistd.h>
#include <stdio.h>

char** tokenizer(char* program_stream,size_t size_of_stream){
  for (int i=0;i<size_of_stream-1;i++){
    printf("%c",program_stream[i]);
  }
  return NULL;
}
