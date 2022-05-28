#include "Stack.h"

Stack * initStack(int capacity) {
    Stack * stack = (Stack*) malloc(sizeof(Stack));
    stack->array = (int*) malloc(sizeof(int) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

int stack_is_empty(Stack * stack) {
    return stack->top == -1;
}

int stack_is_full(Stack * stack) {
    return stack->top + 1 == stack->capacity;
}

int stack_push(Stack * stack, int data) {
    if(!stack_is_full(stack)) {
        stack->array[++stack->top] = data;
        return 1;
    }   
    return 0;
}

int stack_pop(Stack * stack) {
    return !stack_is_empty(stack) ? stack->array[stack->top--] : INT_MIN;
}

int stack_peek(Stack * stack) {
    return !stack_is_empty(stack) ? stack->array[stack->top] : INT_MIN;
}

void stack_destroy(Stack * stack) {
    free(stack->array);
    free(stack);
}