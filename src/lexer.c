#include <unistd.h>
#include <stdio.h>
#include "vector.h"

vector generated_tokens;

char** tokenizer(char* program_stream,size_t size_of_stream){
  for (int i=0;i< size_of_stream;i++){
    printf("%s",program_stream[i]);
  }
  return NULL;
}
