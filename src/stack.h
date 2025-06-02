#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

/**
 * Generic pointer stack to hold any kind of data.
 */

typedef struct {
    void* items[50];  // Array to hold void* (generic pointers)
    int ptr;          // Index of the top element
} STACK;

/**
 * Initializes the stack.
 */
void initStack(STACK* s) {
    s->ptr = -1;
}

/**
 * Checks if the stack is empty.
 * @return 1 if empty, 0 otherwise.
 */
int isEmpty(STACK* s) {
    return (s->ptr == -1);
}

/**
 * Pushes a generic pointer onto the stack.
 * @param value Pointer to push.
 */
void push(STACK* s, void* value) {
    if (s->ptr == 49) {
        fprintf(stderr, "Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->ptr)] = value;
}

/**
 * Pops the top pointer from the stack.
 * @return Popped pointer or NULL on underflow.
 */
void* pop(STACK* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->items[(s->ptr)--];
}

/**
 * Peeks at the top of the stack without popping.
 * @return Top pointer or NULL on underflow.
 */
void* stackTop(STACK* s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->ptr];
}

/**
 * Prints the stack addresses (for debugging).
 */
void printStack(STACK* s) {
    for (int i = 0; i <= s->ptr; ++i) {
        printf("%p\n", s->items[i]);
    }
}

/**
 * Test and pop method with underflow flag.
 * @param uf Pointer to int to set underflow flag.
 * @return Popped pointer or NULL if underflow occurs.
 */
void* testAndPop(STACK* s, int* uf) {
    if (isEmpty(s)) {
        *uf = 1;
        return NULL;
    } else {
        *uf = 0;
        return s->items[(s->ptr)--];
    }
}

#endif // STACK_H
