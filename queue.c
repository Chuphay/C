#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

que *Queue_create(){
  que *q = malloc(sizeof(que));

  q->length = 0;
  q->position = 0;

  return q;
}

void Queue_destroy(que *q){
  free(q);
}

void Queue_add(que *q, int new_value){
  if (q->length>=size){
    printf("sorry out of memory :(\n");
  } else {
    q->value[(q->length+q->position)%size] = new_value;
    printf("adding : %d\n" , q->value[(q->length+q->position)%size]);
    q->length++;
  }
}
int Queue_peek(que *q){
  int first; 
  
  if(q->length>0){

    first = q->value[q->position];
    printf("first: %d\n",first);
  } else {
    printf("mild error... nothing is in the list\n");
    //first = NULL;
  }
  return first;
}
int Queue_serve(que *q){
  int out;
  if(q->length>0){
    out = q->value[q->position];
    printf("serving: %d \n",out);
    if(q->position<size-1){
      q->position++;
    } else {
      q->position = 0;
    }
    q->length--;
  } else {
    printf("nothing is in the list :( ");
  }
  return out;
}


