#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <string.h>
#define ROWCOUNT 10000000
#define COLUMNCOUNT 2




int open(int **data,  char *name){
  /*data needs to be preallocated memory
name is the name of the file you need opened
returns the number of lines in the file
and hence in the data,
but otherwise it messes with data in place
 */

  char s[100];
  FILE *fp =fopen(name,"r");
  if (fp == NULL) {
    printf("Couldn't open %s for reading\n",name);
      exit(1);
  }

  int c;
  int j = 0;
  int k = 0;
  int l = 0;
  int flag = 0;
  while((c=fgetc(fp)) != EOF){
    //printf("%c",(char)c);
    if((char)c != '\n'){
      flag = 0; 
      s[j]=c;
      j++;
    }
    if((char)c == '\n'){
      data[k][l] = (int) strtol(s, (char **)NULL, 10);
      // data[k][0]=l;
      k++;
      l = 0;
      j = 0; 
    } else if (isspace(c)){
      if(flag){
	printf("2 spaces.. exiting  %d \n", k);
	exit(1);      
      }
      flag = 1;
      data[k][l] = (int) strtol(s, (char **)NULL, 10);
      l++;
      j = 0; 
    }
    if(j>ROWCOUNT){
      printf("something bad happened: line too long\n");
      exit(1);
    }
    if(l>COLUMNCOUNT){
      printf("too many columns... exiting %d \n" ,k);
      exit(1);
    }
  }

  fclose(fp);
  //notice the k-1 here...???
  return k;
}

void reverse(int **data, int length){
  int i;
  printf("Last line is %d %d does that look right?\n",
      data[length-1][0], data[length-1][1]);
  for (i=0;i<length;i++){
    int temp = data[i][0];
    data[i][0] = data[i][1];
    data[i][1] = temp;
  }
}

int book[1000000]={};
int record[1000000] = {};
int counter = 1;
void DFS(int **data, int node, int length){
  if(record[node] == 0){
    //printf("node: %d\n",node);
    counter++;
    record[node] = 1;
    int i;
    for(i=0;i<length;i++){
      if(data[i][0] == node){
        int new_node = data[i][1];
        //printf("new node: %d\n",new_node);
        if(record[new_node] == 0){
	  DFS(data,new_node,length);
        }
      }
    }
    printf("end of for loop, node: %d counter: %d\n",node,counter);
    // counter++;
  }
}





int main(void){
  int i = 0;

 
  int **data = (int **)malloc(ROWCOUNT * sizeof(int*));
  for (i = 0;i < ROWCOUNT;i++){
    data[i] = (int *)malloc(COLUMNCOUNT * sizeof(int));

  }

  int length = open(data,"graph_test.txt"); // "SCC.txt"); // 
  reverse(data,length);


  int end = 9;
  for (end = 9;end>0;end--){
    printf("end: %d\n",end);
   DFS(data,end,length);
  }
 
  printf("length: %d info: %d %d\n",length,data[length-1][1],data[length-1][0]);
  
  return 0;
}
