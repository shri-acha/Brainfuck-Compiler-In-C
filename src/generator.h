#include "tokens_and_structures.h"
#include <stdio.h>

void optimizer(AST_node **head) {
  // Here the, optimizer optimizes the IR,
  // currently the AST generater is unoptmized
  // now to optmize the AST, common optimization patterns must be recognized,
  // these optmizations are usually restrictive to the language.
  // Here, the patterns optimized are.
  // [ - ] => mov rax, 0
}

char* asm_string_builder(ASM_INSTRUCTION* asm_instruction) {

}

ASM_INSTRUCTION* asm_mapping(TOKEN *token) {
  switch (token->tok_t) {
  case ADD_OPERATION:
    break;
  case SUB_OPERATION:
    printf("dec [my_array]\n");
    break;
  case LSHIFT_OPERATION:
    printf("dec my_array\n");
    break;
  case RSHIFT_OPERATION:
    printf("inc my_array\n");
    break;
  case INP_OPERATION:
    printf("gets [my_array]\n");
    break;
  case OUP_OPERATION:
    printf("puts [my_array]\n");
    break;
  default:
    printf("[ERROR] Broken input!");
    return NULL;
    break;
  }
}


void generator_asm(AST_node *head) {
  AST_node *temp = head;
  if (temp == NULL) {
    return;
  }
  if (temp->token != NULL) {
    asm_mapping(temp->token);
  } else if (temp->token == NULL) {
    printf("loop_start:\n");
    generator_asm(temp->body);
    printf("jmpz\n");
  }
  generator_asm(head->next);
}
