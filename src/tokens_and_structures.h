#ifndef TOKENS_AND_STRUCTURES_H
#define TOKENS_AND_STRUCTURES_H

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

typedef enum AST_TYPE {
  LOOP,
  OP,
}ast_type;

typedef struct TOKEN {
  TOKEN_TYPE tok_t;
  char tok_val;
  struct TOKEN* next;
} TOKEN;
// Tokens are the intermediate representation.

typedef struct AST_node {
  TOKEN *token;
  struct AST_node *next;
  struct AST_node *body;
  ast_type scope; 

} AST_node;
// Linked List but may have a child LL for body tree instructions '[]'
// AST_node is the node in which the next node is defined.
// AST of brainfuck is linear as the operations in the language are atomic.

AST_node *AST_node_create(TOKEN *token_val) {
  AST_node *buff = (AST_node *)malloc(sizeof(AST_node));
  buff->next = NULL;
  buff->token = token_val;
  buff->body = NULL;
  return buff;
}

typedef struct ASM_INSTRUCTION {
  char* operation;
  char** operands;
}ASM_INSTRUCTION;

ASM_INSTRUCTION* asm_instruction_create(char* instruction, char** operands){
  ASM_INSTRUCTION* instruction_buf = (ASM_INSTRUCTION*) malloc(sizeof(ASM_INSTRUCTION));
  instruction_buf->operation = instruction;
  instruction_buf->operands = operands;
  return instruction_buf;
}

// ASM 
// Initial global mutable value 
// int strip [ MAX_SIZE ]
// variable global value 
// int* strip_ptr;
// instructions:
//
// ADD 
//
//
//
//
//

#endif
