#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 2

typedef struct stack{
  int length;
  int array[MAXSIZE];
} stack;

stack *stack_create(){
  stack *stk = malloc(sizeof(stack));
  stk->length = 0;
  return stk;
}

void stack_destroy(stack *stk){
  free(stk);
}
void stack_push(stack *stk, int value){
  // printf("stack length: %d\n",stk->length);
  if(stk->length<MAXSIZE){
    stk->array[stk->length] = value;
    printf("Pushed: %d\n", stk->array[stk->length]);
    stk->length++;
  } else {
    printf("error push\n");
    exit(1);
  }
}

int stack_pop(stack *stk){
  int out;
  if(stk->length>0){
    out = stk->array[stk->length-1];
    printf("poped: %d\n",out);
    stk->length--;
  } else {
    printf("drunk...something happened\n");
    exit(1);
  }
  return out;
}
    

int main(void){

  stack *stk = stack_create();
  stack_push(stk,1);
  stack_push(stk,2);
 
  stack_pop(stk);
 stack_push(stk,3); 
 stack_destroy(stk);
  return 0;
}
