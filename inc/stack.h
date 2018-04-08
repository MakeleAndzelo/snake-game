#ifndef SNAKE_STACK_H
#define SNAKE_STACK_H

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

int isFull(struct Stack *stack);

int isEmpty(struct Stack *stack);

void push(struct Stack *stack, int item);

int pop(struct Stack *stack);

#endif //SNAKE_STACK_H
