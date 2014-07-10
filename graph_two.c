#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <string.h>
//#define ROWCOUNT 10000000
//#define COLUMNCOUNT 2
#define NODESIZE 550
#define MAXSIZE 1000000


typedef struct node{
  int length;
  int next[NODESIZE];
} node;



int open(node *data,  char *name, int reverse){
  /*data needs to be preallocated memory
name is the name of the file you need opened
returns the number of lines in the file
and hence in the data,
but otherwise it messes with data in place
 */
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
       printf("temp: %d %d %d \n",temp[0],temp[1],data[temp[1]].length);
      if(data[temp[0+reverse]].length>NODESIZE-1){
	printf("went over the node limit :P \n");
	exit(1);
      }

      data[temp[0+reverse]].next[data[temp[0+reverse]].length] = temp[1-reverse];
      data[temp[0+reverse]].length+=1;
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
  node *data = malloc(MAXSIZE * sizeof(node));
  printf("here\n");

  int length = open(data,  "graph_test.txt", 1); // "SCC.txt",1); //

  data[0].length = 5;
  
  int end = 9;
  for (end = 9;end>0;end--){
    printf("end: %d\n",end);
   DFS(data,end);
  }
  
  
  int i = 0;
  for(i=1;i<length+1;i++){
    int j =0;
    for (j= 0 ; j<data[i].length; j++){
      printf("%d %d\n",i,data[i].next[j]);
    }
  }
  
  printf("length: %d info: \n",length);
  
  return 0;
}
