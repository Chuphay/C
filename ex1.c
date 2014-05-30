#include <stdio.h>

struct foo {int a; char b; int c; char *d;};


int main(void){

  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(char));
  printf("%zu\n", sizeof(struct foo));

  int input;
  scanf("%d", &input);
  while(input>0){
    int i = 0;
    for(i=0;i<input;i++){
      printf("%d\n",i+1);
    }
    scanf("%d", &input);
  } 

  return 0;
} 

