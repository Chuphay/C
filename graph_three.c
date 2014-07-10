#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NODESIZE 650
#define MAXSIZE 1000000


typedef struct node{
  int length;
  int next[NODESIZE];
} node;



int open(node *data,  char *name, int reverse){
 
  int temp[2];
  char s[100];
  FILE *fp =fopen(name,"r");
  if (fp == NULL) {
    printf("Couldn't open %s for reading\n",name);
      exit(1);
  }
  int length = 0;
  int c;
  int j = 0;
  int k = 0;
  int l = 0;
  int flag = 0;
  //int counter = 0;
  while((c=fgetc(fp)) != EOF){
    //printf("%c",(char)c);
    if((char)c != '\n'){
      flag = 0; 
      s[j]=c;
      j++;
    }
    if((char)c == '\n'){
      // printf("\n ---- \n");
 
      if(data[temp[0+reverse]].length>NODESIZE-1){
	printf("went over the node limit :P %d %d \n", temp[0],temp[1]);
	//data[0].next[data[0].length] = temp[1-reverse];
      //data[0].length+=1;
      exit(1);
      } else {

      data[temp[0+reverse]].next[data[temp[0+reverse]].length] = temp[1-reverse];
      data[temp[0+reverse]].length+=1;
      //printf("temp: %d %d %d \n",temp[0],temp[1],data[temp[reverse]].length);
      }
      k++;
      l = 0;
      j = 0; 
    } else if (isspace(c)){
      if(flag){
	printf("2 spaces.. exiting  %d \n", k);
	exit(1);      
      }
      flag = 1;
      //printf("l: %d\n", l);
      temp[l] = (int) strtol(s, (char **)NULL, 10);
      if(temp[l]>length){
	length = temp[l];
      }   

      l++;
      j = 0; 
    }
    if(j>100){
      printf("something bad happened: line too long\n");
      exit(1);
    }
    if(l>NODESIZE){
      printf("too many columns... exiting %d \n" ,k);
      exit(1);
    }
    if(length>MAXSIZE){
      printf("catching stuff... yay! %d \n" ,length);
      exit(1);
    }
  }

  fclose(fp);
  //notice the k-1 here...???
  return length;
}


int book[MAXSIZE]={};
int record[MAXSIZE] = {};
int counter = 1;
void DFS(node *data, int old_node){
  if(record[old_node] == 0){
    //printf("node: %d\n",old_node);
    record[old_node] = 1;
    int i;
    for(i=0;i<data[old_node].length;i++){
 
      int new_node = data[old_node].next[i];
      //printf("new node: %d\n",new_node);
      if(record[new_node] == 0){
	DFS(data,new_node);
      }
      
    }
    //printf("end of for loop, node: %d counter: %d\n",old_node,counter);
    counter++;
  }
}





int main(void){


  printf("node size: %ld\n",sizeof(node));
  //node **data = malloc(MAXSIZE * sizeof(node));
  node * data = malloc(MAXSIZE * sizeof *data);
  if (data == NULL){
    printf("null data pointer\n");
      }
  int x = 0;
   for(x = 0; x < MAXSIZE; x++){

    data[x].length = 0;
    data[x].next[0] = 0;
}

  printf("here\n");

  //int length = 
  open(data, "SCC.txt",1); // "graph_test.txt", 0); // 

  data[0].length = 5;
  /*
  int end = 9;
  for (end = 9;end>0;end--){
    printf("end: %d\n",end);
    //DFS(data,end);
  }
  
  
  int i = 0;
  for(i=1;i<length+1;i++){
    int j =0;
    for (j= 0 ; j<data[i].length; j++){
        printf("%d %d\n",i,data[i].next[j]);
    }
    }
  
  printf("length: %d info: \n",length);
  */
  return 0;
}
