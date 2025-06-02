#ifndef LEXER_H
#define LEXER_H
#include "stack.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum TOKEN_TYPE {
  PROGRAM_S,        // Start of program
  PROGRAM_E,        // End of program
  ADD_OPERATION,    // +
  SUB_OPERATION,    // -
  LSHIFT_OPERATION, // <
  RSHIFT_OPERATION, // >
  INP_OPERATION,    // ,
  OUP_OPERATION,    // .
  SLOOP_OPERATION,  // [
  ELOOP_OPERATION,  // ]
} TOKEN_TYPE;

typedef struct TOKEN {
  TOKEN_TYPE tok_t;
  char tok_val;
} TOKEN;
// Tokens are the intermediate representation.

typedef struct AST_node {
  TOKEN *token;
  struct AST_node *next;
  struct AST_node *body;
} AST_node;
// Linked List but may have a child LL for body tree instructions '[]'
// AST_node is the node in which the next node is defined.
// AST of brainfuck is linear as the operations in the language are atomic.

AST_node *AST_node_create(TOKEN *token_val) {
  AST_node *buff = (AST_node *)malloc(sizeof(AST_node));
  buff->next = NULL;
  buff->token = token_val;
  return buff;
}

TOKEN *tokenizer(char *program_stream, size_t size_of_stream) {

  //!! NOTE: The token array generates incomplete token array, ie
  //! lacks bounds of program PROGRAM_S AND PROGRAM_E.

  TOKEN *tok_arr = (TOKEN *)malloc(sizeof(TOKEN) * (size_of_stream));
  if (tok_arr == NULL) {
    exit(-1);
  }
  for (int i = 0; i < size_of_stream - 1; i++) {
    switch (program_stream[i]) {
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
      fprintf(stderr, "[ERROR] Unexpected token! '%c' [%d]\n",
              tok_arr[i].tok_val, i);
      exit(-1);
      break;
    }
    tok_arr[i].tok_val = program_stream[i];
  }
  return tok_arr;
}

AST_node* add_tree_body(AST_node* temp_node,TOKEN* token){
  while( temp_node->next != NULL) {
    temp_node = temp_node->next;
  } 
  temp_node->next = AST_node_create(token);
}

AST_node* parser(TOKEN *token_arr, long token_size) {

  // This generates the IR, based on the below grammar
  /*
     Brainfuck Grammar :
     Instructions -> > < + - . , [ ]
     Block ->  Instructions* | Loop
     Loop -> [ Instructions* ]
     */
  int i = 0;

  AST_node *head_node = AST_node_create(&token_arr[i]); 
  AST_node *temp_node = NULL;

  do {
    int loop_count = 0;
    printf("%d\n", token_arr[i].tok_t);
    if (token_arr[i].tok_t == SLOOP_OPERATION) {
      temp_node->next = AST_node_create(&token_arr[i]);
      loop_count++;
    }
    else if (token_arr[i].tok_t == ADD_OPERATION ||
        token_arr[i].tok_t == SUB_OPERATION ||
        token_arr[i].tok_t == LSHIFT_OPERATION ||
        token_arr[i].tok_t == RSHIFT_OPERATION ||
        token_arr[i].tok_t == INP_OPERATION ||
        token_arr[i].tok_t == OUP_OPERATION ) {
      if (loop_count > 0 ){
        add_tree_body(temp_node,&token_arr[i]);
      }else if (loop_count == 0 ) {
        temp_node->next = AST_node_create(&token_arr[i]);
      }
    }
    else if (token_arr[i].tok_t == ELOOP_OPERATION) {
      temp_node = AST_node_create(&token_arr[i]);
      loop_count--;
    }
    temp_node = temp_node->next; 
    i++;
  } while (i < token_size);
  return head_node;
}

#endif // !
