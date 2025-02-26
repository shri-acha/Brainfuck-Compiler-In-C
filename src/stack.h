#ifndef STACK_H
#define STACK_H

#include <stdlib.h> // For exit function
#include <stdio.h>  // For printf function

/**
 * Structure to represent a stack.
 * - `items`: Array to store stack elements (fixed size: 50).
 * - `ptr`: Index of the top element in the stack (-1 when empty).
 */

typedef struct {
    char items[50]; // Array to hold stack elements
    int ptr;       // Stack pointer, points to the top of the stack
} STACK;

/**
 * Checks if the stack is empty.
 * @param s Pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(STACK *s) {
    if (s->ptr == -1)
        return 1; // Stack is empty
    else
        return 0; // Stack is not empty
}

/**
 * Pushes an element onto the stack.
 * @param s Pointer to the stack.
 * @param value The value to push onto the stack.
 * Exits with an error if the stack is full (overflow).
 */
void push(STACK *s, int value) {
    if (s->ptr == 49) { // Check for overflow (stack size is 50)
        printf("Data overflow.\n");
        exit(1); // Exit program on overflow
    } else {
        (s->ptr)++;           // Increment the stack pointer
        s->items[s->ptr] = value; // Add the new value to the stack
    }
}

/**
 * Pops an element from the stack.
 * @param s Pointer to the stack.
 * @return The top element of the stack.
 * Exits with an error if the stack is empty (underflow).
 */
int pop(STACK *s) {
    if (isEmpty(s) == 1) { // Check for underflow
        return -1;
    } else {
        int v = s->items[s->ptr]; // Get the top element
        (s->ptr)--;              // Decrement the stack pointer
        return v;                // Return the popped value
    }
}

/**
 * Retrieves the top element of the stack without removing it.
 * @param s Pointer to the stack.
 * @return The top element of the stack.
 * Exits with an error if the stack is empty (underflow).
 */
int stackTop(STACK *s) {
    if (isEmpty(s) == 1) { // Check for underflow
        printf("Data underflow.\n");
        exit(1); // Exit program on underflow
    } else {
        return s->items[s->ptr]; // Return the top element
    }
}

/**
 * Prints all elements of the stack from bottom to top.
 * @param s Pointer to the stack.
 */
void printStack(STACK *s) {
    int i;
    for (i = 0; i <= s->ptr; i++) { // Traverse from the bottom to the top
        printf("%d\n", s->items[i]); // Print each element
    }
}

/**
 * Initializes the stack by setting the pointer to -1.
 * @param s Pointer to the stack.
 * This makes the stack empty.
 */
void initStack(STACK *s) {
    s->ptr = -1; // Initialize stack pointer to -1 (empty state)
}

/**
 * Tests if the stack is empty and optionally pops the top element.
 * @param s Pointer to the stack.
 * @param uf Pointer to an integer to store the underflow flag.
 * @return The top element of the stack if not empty.
 * Sets *uf to 1 if the stack is empty; otherwise, *uf is set to 0.
 */
int testAndPop(STACK *s, int *uf) {
    if (isEmpty(s) == 1) { // Check for underflow
        *uf = 1; // Set underflow flag
        return -1; // Return a default value (optional)
    } else {
        int v = s->items[s->ptr]; // Get the top element
        *uf = 0;                 // Reset underflow flag
        (s->ptr)--;              // Decrement the stack pointer
        return v;                // Return the popped value
    }
}

#endif // End of STACK_H
