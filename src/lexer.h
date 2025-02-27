#ifndef LEXER_H
#define LEXER_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "stack.h"
typedef enum TOKEN_TYPE {
  PROGRAM_S,
  PROGRAM_E,
  ADD_OPERATION,
  SUB_OPERATION,
  LSHIFT_OPERATION,
  RSHIFT_OPERATION,
  INP_OPERATION,
  OUP_OPERATION,
  SLOOP_OPERATION,
  ELOOP_OPERATION, 
}TOKEN_TYPE;

typedef struct TOKEN{
  TOKEN_TYPE tok_t;
  char tok_val;
}TOKEN;

typedef struct AST_node{
  struct AST* left;
  struct AST* right;
  TOKEN* token;
}AST_node;

typedef struct AST{
  struct AST* root;
}AST;

AST_node* AST_node_create(TOKEN* token_val){
  AST_node* buff = (AST_node* )malloc(sizeof(AST_node));
  buff->left=NULL;
  buff->right=NULL;
  buff->token=token_val;
  return buff;
}
 

TOKEN* tokenizer(char* program_stream,size_t size_of_stream){

  TOKEN* tok_arr =(TOKEN*) malloc(sizeof(TOKEN)*size_of_stream); 
  if (tok_arr == NULL) {exit(-1);}
  for (int i=0;i<size_of_stream-1;i++){
  switch(program_stream[i]){
    case '>':
      tok_arr[i].tok_t = RSHIFT_OPERATION;
      break;
    case '<':
      tok_arr[i].tok_t = LSHIFT_OPERATION;
      break;
    case '-':
      tok_arr[i].tok_t = SUB_OPERATION;
      break;
    case '+':
      tok_arr[i].tok_t = ADD_OPERATION; 
      break;
    case '.':
      tok_arr[i].tok_t = OUP_OPERATION; 
      break;
    case ',':
      tok_arr[i].tok_t = INP_OPERATION; 
      break;
    case '[':
      tok_arr[i].tok_t = SLOOP_OPERATION;
      break;
    case ']':
      tok_arr[i].tok_t = ELOOP_OPERATION;
      break;
    default:
      fprintf(stderr,"[ERROR] Unexpected token! '%c' [%d]\n",tok_arr[i].tok_val,i);
      exit(-1);
      break;
     }
    tok_arr[i].tok_val = program_stream[i];
  }

  return tok_arr;

}

int parser(TOKEN* token_arr,long token_size){

    STACK node_buf;
    initStack(&node_buf);
    for (int i=0;i<token_size-1;i++){

      if(token_arr[i].tok_t == SLOOP_OPERATION ){
        push(&node_buf,'[');
      }
      if(token_arr[i].tok_t == ELOOP_OPERATION){
        int rc = pop(&node_buf);
        if (rc==-1) {
          fprintf(stderr,"[ERROR] Isolated ']'\n");
          exit(-1);
        }
      }
    }

    if (!isEmpty(&node_buf)){
      fprintf(stderr,"[ERROR] Missing ']'\n");
    } // Loop Integrity Check
      //
    AST ast_val;
    TOKEN program_start;
    program_start.tok_val='\x0';
    program_start.tok_t=PROGRAM_S;

    TOKEN program_end;
    program_end.tok_val='\x0';
    program_end.tok_t=PROGRAM_E;


    STACK program_stack;
    initStack(&program_stack);
    
    AST_node_create(&token_arr[0]); 
    
    
    
}
#endif // !
