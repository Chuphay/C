#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8

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
    //printf("Pushed: %c\n", stk->array[stk->length]);
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
    // printf("poped: %c\n",out);
    stk->length--;
  } else {
    printf("drunk...something happened\n");
    exit(1);
  }
  return out;
}

int calculate(char *string){
  printf("\ncalculating: %s\n",string);
  stack *num = stack_create();
  stack *op = stack_create();
  stack *temp = stack_create();
  int i = 0;
  int j = 0;
  while (string[i] != '\0'){
    if((string[i]>='0') && (string[i]<='9')){
      //temp = stack_create();
      stack_push(temp,string[i]);
      j++;

    } else {
      if(j != 0){
	//printf("j: %d\n",j);
	int k = 0;
	int out = 0;
	for(k=0;k<j;k++){
	  int m = 1;
	  int n = 0;
	  for(n=0;n<k;n++){
	    m = m*10;
	  }
	  out += m*(stack_pop(temp)-'0');
	}
	// printf("int: %d\n",out);
	  stack_push(num,out);
      }
      j=0;
    }
    if((string[i] == '+') ||(string[i] == '-') ||(string[i] == '*') ||(string[i] == '/')){
      stack_push(op,string[i]);
    }
    if(string[i] == ')'){
      int num1 = stack_pop(num);
      int num2 = stack_pop(num);
      char operator = stack_pop(op);
      if(operator == '+'){
	printf("%d+%d\n",num1,num2);
	stack_push(num,num1+num2);
      }
      if(operator == '-'){
	printf("%d-%d\n",num1,num2);
	stack_push(num,num1-num2);
      }
      if(operator == '*'){
	printf("%d*%d\n",num1,num2);
	stack_push(num,num1*num2);
      }
      if(operator == '/'){
	printf("%d/%d\n",num1,num2);
	stack_push(num,num1/num2);
      }
    }



    // putchar(string[i]);
    i++;
  }
  putchar('\n');
  printf("final answer: %d\n",stack_pop(num));

  stack_destroy(num);
  stack_destroy(op);
  stack_destroy(temp);
  return 0;
}

int main(void){

  char myString[] = "(11+((20+3)*(4*5)))";
  calculate(myString);
  stack *stk = stack_create();
  stack_push(stk,'1');
  stack_push(stk,'2');
 
  stack_pop(stk);
 stack_push(stk,'3'); 
 stack_destroy(stk);
  return 0;
}
