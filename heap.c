#include <stdio.h>
#include <stdlib.h>
#define MAX 8

/*not sure if this actually works
check schedule program for better stuff
*/


int *create(void){
  int *out = malloc((MAX+1)*sizeof(int));
  out[0] = 0;
  return out;
}

void bubble(int *heap, int value){
  if(heap[0]>=MAX){
    printf("the heap is over the max\n");
    exit(1);
  }
  heap[0]++;
  int length = heap[0];
  heap[length] = value;
  
 
    while((heap[length]<heap[length/2]) && (length>1)){
      int temp = heap[length];
      heap[length] = heap[length/2];
      heap[length/2] = temp;
      // printf("temp: %d %d\n",temp, heap[length]);
      length = length/2;
      }
  

    //printf("length of heap: %d %d %d %d\n",heap[0], length,heap[length],heap[heap[0]]); 
}

int extract(int * heap){
  if (heap[0]<1){
    printf("heap is empty\n");
    exit(1);
  }
  int out = heap[1];
  heap[1] = heap[heap[0]];
  heap[0]--;
  //printf("out: %d length: %d top: %d\n", out, heap[0], heap[1]);
  int i = 1;
  while(i<heap[0]){
    //printf ("i : %d  heap: %d next: %d \n", i, heap[i], heap[i+1]);
    int compare =  heap[2*i];
    int flag = 0;
    if(2*i+1<heap[0]){
      printf("ok\n");
      if(heap[2*i+1]<compare){
	//printf("comparing...\n");
	flag = 1;
	compare = heap[2*i+1];
      }
    }
    if(heap[i]<=compare){
      //printf("breaking\n");
      break;
    } else {
      int temp = heap[i];
      heap[i] = heap[2*i+flag];
      heap[2*i+flag] = temp;
      i = 2*i + flag;
    }
  }
  return out;
} 

int check(int *heap){
  /*checks whete=her the heap property is being maintained
    returns 1 if ok, hopefully 0 otrherwise */
  if(heap[0] == 0){
    printf("minor error, nothing in the heap\n");
      return 0;
  }  
if(heap[0] == 1){
  printf("length is one? I guess it's true\n");
    return 1;
  }
 int i = 2;
 int flag = 1;
 for (i = 2; i< heap[0]+1;i++){
   if(heap[i]>=heap[i/2]){
     flag++;
   }
 }
 //printf("length: %d flag : %d\n", heap[0], flag);
 if(flag == heap[0]){
   printf("True\n");
   return 1;
 }
 printf("False\n");
  return 0;
}

void heapify(int *array){
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



int main(void){
  printf("on\n");
   int *heap = create();
  bubble(heap,7);
  check(heap);
  extract(heap);
  check(heap);
  bubble(heap,5);
  check(heap);
  bubble(heap, 4);
  check(heap);
  bubble(heap, 6);
  check(heap);
  bubble(heap,3);
  bubble(heap,1);
  check(heap);
  extract(heap);

  check(heap);
  extract(heap);
  check(heap);

  int array[7] = {6,8,2,4,3,1,5};
  heapify(array);
  check(array);


  return 0;
}
