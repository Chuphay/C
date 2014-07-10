#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_SIZE 10

void graph(int data[MAX_SIZE][MAX_SIZE]){
  //printf("here\n");
  //printf(" %d %d %d\n",data[0][0],data[1][1],data[2][0]);
  int visited[MAX_SIZE]={};
  visited[0] = data[0][1];
  int i = 0;
  que *q = Queue_create();
  for(i=0;i<data[0][0];i++){
    //printf("%d \n",data[0][i+2]);
    Queue_add(q,data[0][i+2]);

  }
  //printf("length: %d\n",q->length);
  int index = 1;
  while(q->length>0){
    int node = Queue_serve(q);
    printf("Starting node: %d\n", node);
    if(index>MAX_SIZE){
      printf("error: index went over MAX SIZE\n");
      exit(1);
    }
 

    if(data[node-1][1]==node){
      int flag = 0;
      for (i=0;i<MAX_SIZE;i++){
	if(node == visited[i]){
	  //printf("getting flagged: %d\n",node);
	  flag = 1;
	}
      }

      if (flag == 1){
        printf("breaking!\n");
	continue;
      }
      for (i=0;i<data[node-1][0];i++){
	//printf("length: %d\n",data[node-1][0]);
	int new_node = data[node-1][i+2];
	printf("new node: %d\n",new_node);
	flag = 0;
	int j = 0;
        for (j=0;j<MAX_SIZE;j++){
	  if(new_node == visited[j]){
	    // printf("this node has already been visited: %d\n",new_node);
	    flag = 1;
	  }
        }
	if(flag == 0){
	  Queue_add(q,new_node);
	}
      }
 


    } else {
      printf("error, node is weird\n");
      exit(1);
    }
    printf("finished visiting: %d\n",node);
    visited[index] = node;
    index++;


  }
  Queue_destroy(q);
}
int global_position = 0;
int explored[MAX_SIZE]={};
void DFS(int data[MAX_SIZE][MAX_SIZE],int position){
  printf("DFS: NODE: %d\n",data[position][1]);
  explored[global_position] = data[position][1];
  int i =0;
  for(i=0;i<data[position][0];i++){
    //global_position++;
    // printf("DFS: %d\n",global_position);
    int new_node = data[position][i+2];
    printf("NEW NODE: %d\n",new_node);
    int flag = 0;
    int j = 0;
    for (j=0;j<MAX_SIZE;j++){
      if (new_node == explored[j]){
	flag = 1;
      }
    }
    if (flag == 0){
      global_position++;
      DFS(data,new_node-1);
    }
  }
}




int main(void){

  int data[MAX_SIZE][MAX_SIZE] = { {2,1,2,3},{2,2,1,4},{3,3,1,4,5},{4,4,2,3,5,6},{3,5,3,4,6},{2,6,4,5}};
 
    printf("main: %d %d %d\n", data[0][0],data[2][0],data[3][1]);
    graph(data);
    //int explored[MAX_SIZE]={};
    DFS(data,0);
    return 0;
}
