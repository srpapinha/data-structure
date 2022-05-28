#ifndef _STACK_H
#define _STACK_H

#ifndef _LIMITS_H___
#include <limits.h>
#endif

#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

typedef struct Stack {
    int top;
    int * array;
    int capacity;
} Stack;

Stack * initStack(int capacity);
int stack_is_empty(Stack * stack);
int stack_is_full(Stack * stack);
int stack_push(Stack * stack, int data);
int stack_pop(Stack * stack);
int stack_peek(Stack * stack);
void stack_destroy(Stack * stack);
#endif