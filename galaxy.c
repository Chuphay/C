#include <stdio.h>
#include <time.h>
#include "union_find.h"

#define MAX 1000

int absolute(int x){
  if(x>0){
    return x;
  } else {
    return -x;
  }
}



void cluster(data **zee){
  int i = rand()%MAX;
  int j = rand()%MAX;
  double myRand = rand()/(RAND_MAX+1.0);
  if((i>MAX-1) || (j>MAX-1)){
    printf("something bad happened...\n");
    exit(1);
  }
  int node_i = getNode(zee, i);
  int node_j = getNode(zee, j);
  if(node_i == node_j){
    //nothing happens
  } else {
    int size_i = zee[node_i]->size;
    int size_j = zee[node_j]->size;
    int difference = absolute(size_i-size_j);
    //printf("difference : %d\n", difference);
    if(difference< size_i/10.0){
      if(myRand<0.8){
	myUnion(zee,i,j);
      }
    } else {
      if(myRand<0.3){
	myUnion(zee,i,j);
      }
    }
  }
}

void print_cluster(data **zee){
  int memory[MAX];
  int size = 0;
  int i;
  for(i=0;i<MAX;i++){
    int temp = getNode(zee,i);
    int flag = 0;
    int j;
    for(j=0;j<size;j++){
      if(temp == memory[j]){
	flag = 1;
      }
    }
    if(flag == 0){
      memory[size] = temp;
      size ++;
    }
  }
  printf("[");
  for(i=0;i<size;i++){
    printf("%d,",zee[memory[i]]->size);
  }
  printf("]\n");
}
 

int main(){
  srand(time(NULL));
 
  data **zee = init(MAX);
  int i;
  for(i=0;i<5000;i++){
    cluster(zee);
  }
  print_cluster(zee);
  return 0;
}
