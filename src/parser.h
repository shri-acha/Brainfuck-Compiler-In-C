#ifndef PARSER_H
#define PARSER_H
#include "stack.h"
#include "tokens_and_structures.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

AST_node *parse_block(TOKEN **token);

AST_node *parse_loop(TOKEN **token) {

  (*token) = (*token)->next; // Skip the first token [

  AST_node *loop_node = (AST_node *)malloc(sizeof(AST_node));
  loop_node->scope = LOOP;
  loop_node->body = parse_block(token);
  loop_node->next = NULL;

  if ((*token)->tok_t !=
      ELOOP_OPERATION) { // End of recursion must be at ELOOP_OPERATION
    fprintf(stderr, "[ERROR] Unmatched brackets []\n");
    return NULL;
  }
  (*token) = (*token)->next; // Skipping ]
  return loop_node;
}

AST_node *parse_block(TOKEN **token) {
  // *note to myself*: DOUBLE POINTER here used for convenience.
  AST_node *head = NULL;
  AST_node **tail = &head;

  while (*token != NULL && (*token)->tok_t != ELOOP_OPERATION) {
    AST_node *node = NULL;
    switch ((*token)->tok_t) {
    case ADD_OPERATION:
    case SUB_OPERATION:
    case INP_OPERATION:
    case OUP_OPERATION:
    case LSHIFT_OPERATION:
    case RSHIFT_OPERATION:
      node = (AST_node *)malloc(sizeof(AST_node));
      node->token = (*token);
      node->scope = OP;
      node->next = NULL;
      (*token) = (*token)->next;
      break;
    case SLOOP_OPERATION:
      node = parse_loop(token);
      break;
    default:
      fprintf(stderr, "[ERROR] invalid token!");
      exit(-1);
    }
    *tail = node;
    tail = &node->next;
  }
  return head;
}
AST_node *parser(TOKEN *token) {

  // This generates the IR, based on the below grammar
  /*
     Brainfuck Grammar :
     Instructions -> > < + - . ,
     Block ->  Instructions* | Loop
     Loop -> '[' Block ']'
     */

  // So, have a series of tokens with instructions
  // while i < size of token stream
  // check if loop count exists if it does,
  //  pointer = body_pointer
  // else
  //  pointer = head_pointer
  // if [ encountered, increment the loop count
  // if ( + | - | > | < )
  //  append to head
  return parse_block(&token);
}
#endif
