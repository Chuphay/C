#include <stdio.h>
#include <stdlib.h>
#include "myData.h"

void flip(data *a, data *b){
  double value = a->value;
  int value2 = a->value2;
  char *key = a->key;
  char *key2 = a->key2;
  data *ptr = a->ptr;
  data *ptr2 = a->ptr2;
  void *data = a->data;

  a->value = b->value;
  a->value2 = b->value2;
  a->key = b->key;
  a->key2 = b->key2;
  a->ptr = b->ptr;
  a->ptr2 = b->ptr2;
  a->data = b->data;

  b->value = value;
  b->value2 = value2;
  b->key = key;
  b->key2 = key2;
  b->ptr = ptr;
  b->ptr2 = ptr2;
  b->data = data;
}


/*
void sort(data ** array,int length){
  //I think this is called bubble sort
  //but not sure
  int i,j;
  double temp;
  for(i=0;i<length;i++){
    temp = array[i]->value;
    for(j=i;j<length;j++){
      if(array[j]->value<temp){
	temp = array[j]->value;
	flip(array[j], array[i]);
      }
    }
  }
}

void push(data *head, data *input){
  //order 1, pushes to the front of the list
  flip(head, input);
  head->ptr = input;

}

data *pop(data *head){
  //order 1, pops the leading value
  //note you cannot pop the only element
  if(head->ptr == NULL){
    printf("last element in the list...\n");
    exit(1);
  }
  data * second = head->ptr;
  flip(head, second);
  return second;
}

void print_stack(data *head){
  data * temp = head;
  printf("stack: [%.2f", temp->value);
  while(temp->ptr != NULL){
   temp = temp->ptr;
  printf(", %.2f", temp->value);
 
  }
  printf("]\n");
}
 

data *create_data(int value, char *value1){
  data *out = malloc(sizeof(data));
  out->value = value;
  out->key = value1;
  return out;
}


int main(){

  data d;
  d.value = 45;
  d.data = "hello world";
  data e;
  e.value = 21;
  e.data = "this and that";
  data f;
  f.value = 2;
  f.data = "yo";
  data **z = malloc(3*sizeof(data*));
  z[0] = &d;
  z[1] = &e;
  z[2] = &f;

  sort(z,3);
  int i;
  printf("sorted\n");
  for(i=0; i <3; i++){
    printf("%d\n",(int)z[i]->value);
    printf("%s\n",(char *)z[i]->data);
  }
  printf("sizeof(data): %d\n",(int)sizeof(data));
  data *a = create_data(3,"hey");
  data *b = create_data(21,"more");
  data *c = create_data(11,"again");
  data *h = create_data(2,"#");
  data *m = create_data(-65,"ht");

  push(a,b);
  print_stack(a);
  push(a,c);
  push(a,h);
  print_stack(a);
  pop(a);
  push(a,m);
  print_stack(a);
  printf("a: %02f\n",a->value);


  return 0;
}
*/
