#include <stdio.h>

#define MAX 10

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}



int main(){

  int x=2;
  int *p;
  p = &x;
  *p = *p +10;
  printf("*p = %d\n", *p);
  printf("p = %p\n", p);
  int y = 3;
  int *q = &y;
  swap(p,q);
  printf("Swapped. p = %d, q = %d\n",*p,*q);
  int a[MAX] = {2,1,4,5};
  printf("a[0] = %d\n", a[0]);
  p = &(a[1]);
  printf("pointer: %d\n", *p);
  p++;
  printf("pointer: %d\n", *p);
  return 0;
}

 
