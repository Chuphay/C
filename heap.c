#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

#define MAX 30


void flip(data *a, data *b){
   int temp1 = a->value;
   char *temp2 = a->value1;
   char *temp3 = a->value2;
   a->value = b->value;
   a->value1 = b->value1;
   a->value2 = b->value2;
   b->value = temp1;
   b->value1 = temp2;
   b->value2 = temp3;
}

data *create_data(int value, char *value1, char *value2){
  data *out = malloc(sizeof(data));
  out->value = value;
  out->value1 = value1;
  out->value2 = value2;
  return out;
}

data **create_heap(void){
  data **out = malloc((MAX)*sizeof(data *));
  int i;  
  for(i=0;i<MAX;i++){
    // out[i] = malloc(sizeof(data));
  }
  out[0] = malloc(sizeof(data));
  out[0]->value = 0; //this is to take care of the length of the heap
  return out;
}

void destroy(data ** heap){
  int i;
  for(i=1;i<heap[0]->value+1;i++){
    free(heap[i]);
  }
  free(heap[0]);
  free(heap);
}



void print(data **heap){
    int j;
    printf("heap: [");
    for(j=1;j<heap[0]->value+1;j++){
      printf("%d,",heap[j]->value);
    }
    printf("]\n");
}



void bubble(data **heap, data *data){
   if(heap[0]->value+4>MAX){
     /*I guess this is just to be safe...
       but maybe I'm covering up a bug?*/
     printf("the heap is over the max\n");
     exit(1);
   }
   heap[0]->value++;
   int length = heap[0]->value;
   heap[length] = data;

   while((heap[length]->value<heap[length/2]->value) && (length>1)){
     flip(heap[length],heap[length/2]);
     length = length/2;
   }
}


data *extract(data **heap){
  if (heap[0]->value<1){
    printf("heap is empty\n");
    exit(1);
  }
 
  flip(heap[1],heap[heap[0]->value]);
  data *out = heap[heap[0]->value];
  heap[0]->value--;
  int i = 1;
  while(2*i<heap[0]->value+1){ 
    int compare =  heap[2*i]->value; 
    int flag = 0;
    if(2*i+1<=heap[0]->value){
      if(heap[2*i+1]->value<compare){
	flag = 1;
	compare = heap[2*i+1]->value;
      }
    }
    if(heap[i]->value<=compare){
      break;
    } else {
      flip(heap[i],heap[2*i+flag]);
      i = 2*i + flag;
    }
  }
  return out;
} 


void heapify(int *array){
  /* not implemented */

  /*array[0] should be the length of the rest of the array
  for example, array[4] = {3,2,1,3}
  heapify will sort the array in place.
  */
  int length = array[0];
  int twice = 0;
  for (twice = 0; twice<2;twice++){
    /*we do it twice so we don't have any crazy calculations
    still order n like this
    but probably could be made quicker*/
    for (length = array[0];length>1;length--){
      if(array[length]<array[length/2]){
	int temp = array[length];
	array[length] = array[length/2];
	array[length/2] = temp;
      }
    }
  }
}
