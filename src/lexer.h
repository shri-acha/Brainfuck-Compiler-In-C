#ifndef LEXER_H
#define LEXER_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef enum TOKEN_TYPE {
  OPERATOR,
  IO_OP,
  KEYWORD,
}TOKEN_TYPE;

typedef struct TOKEN{
  TOKEN_TYPE tok_t;
  char tok_val;
}TOKEN;

TOKEN* tokenizer(char* program_stream,size_t size_of_stream){
  TOKEN* tok_arr =(TOKEN*) malloc(sizeof(TOKEN)*size_of_stream); 
  for (int i=0;i<size_of_stream-1;i++){
  switch(program_stream[i]){
    case '>':
    case '<':
    case '-':
    case '+':
      tok_arr[i].tok_t = OPERATOR;
      break;
    case '.':
    case ',':
      tok_arr[i].tok_t = IO_OP;
      break;
    case '[':
    case ']':
      tok_arr[i].tok_t = KEYWORD;
      break;
     }
    tok_arr[i].tok_val = program_stream[i];
  }
  return tok_arr;
}
#endif // !
