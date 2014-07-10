#include <stdio.h>
#include <stdlib.h>

#define bigN 13

typedef struct node{
  int value;
  struct node *next;
} node;

void push(node *first, int value){
  /*order 1, pushes to the fromt of the list*/
  node * next = malloc(sizeof(node));
  next->value = first->value;
  next->next = first->next;
  first->value = value;
  first->next = next;
}

int pop(node *first){
  /*order 1, pops the leading value*/
  int out = first->value;
  node * second = first->next;
  first->value = second->value;
  first->next = second->next;
  free(second);
  return out;
}

void print_list(node *first){
  node * temp = first;
  while(temp->next !=NULL){
    printf("%d,",temp->value);
    temp = temp->next;
  }
  printf("%d\n",temp->value);
}


  

node * basic[bigN];

int track[bigN] = {};

void input(int n){
  int index = n%bigN; 
  if(track[index]==0){
    basic[index]->value = n;
    track[index] +=1;
  } else {
    push(basic[index],n);
    track[index]+=1;
  }
}

int find(int n){
  /*not fully implemented yet*/
  return basic[n&bigN]->value;
}

int main(){
  int i=0;

  for(i=0;i<bigN;i++){
    basic[i] = malloc(sizeof(node));
  }


  input(1221);
  input(222);
  input(427);
  input('c');
  input(7891);
  input(1452);
  input(728);
  input(21311);
  input(67891);
  input(43432);
  input(121);
  input(4978);
  input(23433);
  i = 0;
  for(i=0;i<bigN;i++){
    print_list(basic[i]);
  }
  return 0;
}
 
