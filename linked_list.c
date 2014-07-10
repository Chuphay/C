#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int value;
  struct node *next;

} node;

node * find_last(node *first){
  node *temp = first;
  while(temp->next != NULL){
    //printf("working:\n");
    temp = temp->next;
  }
  return temp;
}

void append(node *first, int value){
  /* order n, puts on the back*/
  node * next_node = malloc(sizeof(node));
  node * last = find_last(first);
  next_node->value = value;
  printf("new value: %d\n",next_node->value);
  last->next = next_node;
  //return next_node;
}

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
  printf("%d\n---\n",temp->value);
}


int main(void){

  printf("on\n");

  node * start= malloc(sizeof(node));
  start->value = 3;
  printf("next is null: %d\n",start->next == NULL);
  append(start, 2);
  printf("next is null: %d\n",start->next == NULL);
  //printf("next's value: %d\n",second->value);
  append(start, 42);
  append(start, 41);
  append(start, 40);
  push(start,21);
  print_list(start);
  pop(start);
  print_list(start);

  return 0;
}
