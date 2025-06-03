#ifndef LEXER_H
#define LEXER_H
#include "stack.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tokens_and_structures.h"

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
  for (int i=0;i<size_of_stream-2;i++) {
    tok_arr[i].next = &tok_arr[i+1];
  }
  tok_arr[size_of_stream-2].next = NULL; // size_of_stream-2 is the boundary

  return tok_arr;
}

AST_node *add_tree_body(AST_node *temp_node, TOKEN *token) {
  while (temp_node->body != NULL) {
    temp_node->body = temp_node->body->next;
  }
  temp_node->body = AST_node_create(token);
}

#endif // !lexer_h
