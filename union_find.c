#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"



data ** init(int number){
  data **a = malloc(number*sizeof(data *));
  int i;
  for(i=0;i<number;i++){
    a[i] = malloc(sizeof(data));
    a[i]->value = i;
    a[i]->point = i;
    a[i]->size = 1;
  }
  return a;
}

int getNode(data ** data, int a){
  
  if(data[a]->value != a){
    printf("get node fail. data[%d] has incorrect value\n", a);
    exit(1);
  }

  if(data[a]->point == a){
    return data[a]->value;
  } else {
    return getNode(data,data[a]->point);
  }
}


void myUnion(data ** data, int a, int b){

  if(data[a]->value != a){
    printf("fail. data[%d] has incorrect value\n", a);
    exit(1);
  }
  if(data[b]->value != b){
    printf("fail. data[%d] has incorrect value\n", b);
    exit(1);
  }
  int a_prime = getNode(data, a);
  int b_prime = getNode(data, b);

  if(data[a_prime]->size > data[b_prime]->size){
    data[a_prime]->size ++;
    data[b_prime]->point = a_prime;
  } else {
    data[b_prime]->size ++;
    data[a_prime]->point = b_prime;
  }
}
/*
int main(){

  data **zee = init(10);
  int i;
  for(i=0;i<10;i++){
    printf("zee: %d\n", zee[i]->value);
  }


  getNode(zee, 3);
  myUnion(zee,2,5);
  myUnion(zee,3,4);
  myUnion(zee,4,2);
  myUnion(zee,7,3);
  for(i=0;i<10;i++){
    printf("%d points to %d\n", i, zee[i]->point);
  }

  return 0;

}
*/
