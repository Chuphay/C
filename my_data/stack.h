#ifndef _stack_h
#define _stack_h

data *create_stack();

void push(data *stack, data *input);

data *pop(data *stack);

void print_stack(data *head);

#endif
