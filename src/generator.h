#include "tokens_and_structures.h"
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *asm_value = {0};

void node_to_asm_map(FILE *f, AST_node *head);

void optimizer(AST_node **head) {
  // Here the, optimizer optimizes the IR,
  // currently the AST generater is unoptmized
  // now to optmize the AST, common optimization patterns must be recognized,
  // these optmizations are usually restrictive to the language.
  // Here, the patterns optimized are.
  // [ - ] => mov rax, 0
}

void emit(FILE *out, const char *str, ...) {
  va_list args;
  va_start(args, str);
  vfprintf(out, str, args);
  va_end(args);
}

int lab_c = 0;

void emit_header(FILE *out) {
  emit(out, "SECTION .bss\n"
            "tape resb 30000\n"
            "\n"
            "SECTION .text\n"
            "GLOBAL _start\n"
            "_start:\n"
            "mov edi, 0\n");
}

void emit_footer(FILE *out) {
  emit(out, "mov eax, 1\n"
            "xor ebx, ebx\n"
            "int 0x80\n");
}

void generator_asm(FILE *f, AST_node *head) {
  AST_node *temp = head;
  if (temp == NULL) {
    return;
  }
  if (temp->token == NULL) {
    int current_label = ++lab_c;
    emit(f, "label_start_%d:\n", current_label);
    emit(f, "cmp byte [tape+edi],0\n");
    emit(f, "jz label_end_%d\n",current_label);
    generator_asm(f, temp->body);
    emit(f, "jnz label_start_%d\n", current_label);
    emit(f, "label_end_%d:\n", current_label);
  } else {
    node_to_asm_map(f, temp);
  }
  generator_asm(f, temp->next);
}

void generate_asm(FILE *f, AST_node *head) {
  emit_header(f);
  generator_asm(f, head);
  emit_footer(f);
}

void node_to_asm_map(FILE *f, AST_node *head) {
  AST_node *temp;
  if (head->token != NULL) {
    switch (head->token->tok_t) {
    case ADD_OPERATION:
      emit(f, "inc edi\n");
      break;

    case SUB_OPERATION:
      emit(f, "dec edi\n");
      break;

    case LSHIFT_OPERATION:
      emit(f, "dec byte [tape+edi]\n");
      break;

    case RSHIFT_OPERATION:
      emit(f, "inc byte [tape+edi]\n");
      break;

    case INP_OPERATION:
      emit(f, "mov eax, 3\n%s%s%s%s", "mov ebx, 0\n", "lea ecx, [tape+edi]\n",
           "mov edx, 1\n", "int 0x80\n");
      break;

    case OUP_OPERATION:
      emit(f, "mov eax, 4\n%s%s%s%s", "mov ebx, 1\n", "lea ecx, [tape+edi]\n",
           "mov edx, 1\n", "int 0x80\n");
      break;
    }
  }
  return;
}
