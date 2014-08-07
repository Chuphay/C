#include <stdio.h>
#include <stdlib.h>
#include "myData.h"
#include "stack.h"

void push(data *stack, data *input){
  /*order 1, pushes to the front of the list*/
  if(stack->ptr == NULL){
    stack->ptr = input;
    stack->value = 1;
  } else {
    stack->value++;
    data *head = stack->ptr;
    flip(head, input);
    head->ptr = input;
  }
}

data *pop(data *stack){
  /*order 1, pops the leading value
  note you cannot pop the only element*/
  if(stack->ptr == NULL){
    printf("no elements in the list...\n");
    exit(1);
  }
  if(stack->value<2){
    printf("last value ...\n");
    stack->value--;
    return stack->ptr;
  } else { 
    stack->value--;
    data * head = stack->ptr;
    flip(head, head->ptr);
    return head->ptr;
  }
}

void print_stack(data *head){
  data * temp = head;
  printf("[");
  while(temp->ptr != NULL){
   temp = temp->ptr;
  printf("%.2f, ", temp->value);
 
  }
  printf("]\n");
}

data *create_stack(){
  data *out = malloc(sizeof(data));
  out->value = 0;
  out->ptr = NULL;
  return out;
}
 
/*
data *create_data(int value, char *value1){
  data *out = malloc(sizeof(data));
  out->value = value;
  out->key = value1;
  return out;
}

int main(){
  printf("sizeof(data): %d\n",(int)sizeof(data));
  data *a = create_data(3,"hey");
  data *b = create_data(21,"more");
  data *c = create_data(11,"again");
  data *h = create_data(2,"#");
  data *m = create_data(-65,"ht");
  data *stack = create_stack();
  push(stack,a);
  push(stack,b);
  print_stack(stack);
  push(stack,c);
  push(stack,h);
  print_stack(stack);
  pop(stack);
  push(stack,m);
  print_stack(stack);
  printf("a: %02f\n",stack->value);


  return 0;
}

*/
