#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



int main(void){
    que *queue = Queue_create();
    printf("%d \n", queue->length);
    Queue_destroy(queue);
    queue = Queue_create();
    Queue_peek(queue);
   
    Queue_add(queue,1);
    Queue_peek(queue);
 
    Queue_add(queue,2);
    Queue_peek(queue);
    //printf("%d %d\n",queue[0],queue[1]);
    Queue_add(queue,3);
    //printf("%d %d\n",queue[0],queue[1]);
    Queue_add(queue,4);
    //printf("%d %d\n",queue[0],queue[1]);
    Queue_add(queue,5);
    Queue_serve(queue);
    //Queue_serve(queue);
   int i;
   for(i=0;i<3;i++){
    Queue_add(queue,i);
    Queue_serve(queue);
   }
    return 0;
}
