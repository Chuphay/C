#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ROWCOUNT 200
#define COLUMNCOUNT 200

/*
The file contains the adjacency list representation of a simple undirected 
graph. There are 200 vertices labeled 1 to 200. The first column in the file 
represents the vertex label, and the particular row (other entries except the 
first column) tells all the vertices that the vertex is adjacent to. So for 
example, the 6th row looks like : "6	155	56	52	120	......".
This just means that the vertex with label 6 is adjacent to (i.e., shares an
 edge with) the vertices with labels 155,56,52,120,......,etc

Your task is to code up and run the randomized contraction algorithm for the 
min cut problem and use it on the above graph to compute the min cut. (HINT: 
Note that you'll have to figure out an implementation of edge contractions. 
Initially, you might want to do this naively, creating a new graph from the 
old every time there's an edge contraction. But you should also think about
 more efficient implementations.) (WARNING: As per the video lectures, please 
make sure to run the algorithm many times with different random seeds, and 
remember the smallest cut that you ever find.) Write your numeric answer in 
the space provided. So e.g., if your answer is 5, just type 5 in the space 
provided.
*/

int open(int **data,  char *name){
  /*data needs to be preallocated memory
name is the name of the file you need opened
returns the number of lines in the file
and hence in the data,
but otherwise it messes with data in place
note, the first column, tells how many columns there are in that row
(maybe minus one, maybe not. use at your own discretion)

 */



  char s[400];
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
    if((char)c != '\n'){
      flag = 0; 
      s[j]=c;
      j++;
    }
    if((char)c == '\n'){
      data[k][l+1] = (int) strtol(s, (char **)NULL, 10);
      data[k][0]=l;
      k++;
      l = 0;
      j = 0; 
    } else if (isspace(c)){
      if(flag){
	printf("2 spaces.. exiting  %d \n", k);
	exit(1);      
      }
      flag = 1;
      data[k][l+1] = (int) strtol(s, (char **)NULL, 10);
      l++;
      j = 0; 
    }
    if(j>300){
      printf("something bad happened: line too long");
      exit(1);
    }
    if(l>40){
      printf("too many columns... exiting %d \n" ,k);
      exit(1);
    }
  }

  fclose(fp);
  return k;
}


int cut(int length, int **data){
  if (length == 2){
    printf("length 2?... exiting\n");
    exit(1);
  }
  int used[length];
  int num_of_merge = 0;
  while(num_of_merge<length-2){
    int l = 0;
    /*
    //this code block prints my data
    printf("here's what's been killed:\n");

    for (l=0; l<num_of_merge;l++){
      printf("%d ",used[l]);
 
    }
    printf("\n");
    printf("here's my data: \n");
    //int l = 0;
    for (l=0; l<length;l++){
      int zed = 0;
      for(zed = 0; zed<data[l][0]+2;zed++){
	printf("%d ",data[l][zed]);
      }
      printf("\n");
    }*/



    int flag = 0;
    float crazy;
    int rdm;
    int flag2 = 0;
    //this code block gets me new random numbers
    //checking to make sure they're not already used
    while(flag == 0){
      crazy = rand()/(RAND_MAX+1.0);
      rdm = (int)(length*crazy);
      if(num_of_merge == 0){
	flag = 1;
      } else {
        int j = 0;
        for(j=0;j<num_of_merge;j++){
	  if (rdm + 1 == used[j]){
	    flag2 = 1;
	  }
	}
      }
      if(flag2 == 0){
	  flag = 1;
      } else {
	flag = 0;
	flag2 = 0;
      }
    } 

    // this code block interprets the random numbers
    int num_of_conn = data[rdm][0];
    float crazy2 = rand()/(RAND_MAX + 1.0);
    int rdm2 = (int)(num_of_conn*crazy2);
    int node_num = data[rdm][rdm2+2]; 
    printf("num: %d  rand: %d rand2: %d\n",num_of_merge, rdm,rdm2);
    used[num_of_merge] = node_num;

    
    //this code block initializes a new column
    //and inserts the first row into it
    int temp_row[2*ROWCOUNT]// = malloc(2*ROWCOUNT*sizeof(int));
    int i = 0;
    flag = 0;
    for(i = 0; i<num_of_conn; i++){
      if(data[rdm][i+2] == data[rdm][rdm2+2]){
	flag += 1;
      } else {
	temp_row[i-flag] = data[rdm][i+2];
      }
    }
    
    //this code block gets the data from the second node
    int count = 0;
    for(i = 0; i <data[node_num - 1][0]; i++){
      int number = data[node_num - 1][i+2];
      //printf("number: %d\n", number);
      if(number == data[rdm][1]){
	//here we are checking for self-referencing
      } else {
	temp_row[num_of_conn + count - flag] = number;
	count++;
      }
    }
 

    //this code reinserts the new data into the row
    if(count+num_of_conn+1>COLUMNCOUNT){
      printf("count: %d num_of_conn: %d\n", count, num_of_conn); 
      printf("error combining the lists\n");
      exit(1);
    } else {
      data[rdm][0] = num_of_conn+count-flag; 
      for(i=0;i<num_of_conn+count-1;i++){
	data[rdm][i+2]=temp_row[i];
      }
    }
    //free(temp_row);

    //this code block changes all used numbers into their new value
    for (l=0; l<length;l++){
      int zed = 0;
      for(zed = 0; zed<data[l][0];zed++){
	if(data[l][zed+2] == used[num_of_merge]){
	  data[l][zed+2] = rdm+1;
	}
      }
    }

    //this code block changes the used number into a zero
    data[node_num - 1][1] = 0;
    data[node_num - 1][0] = 0;



    num_of_merge++;
}
  /*
   //this code block prints my data
    printf("here's my data: \n");
    int l = 0;
    for (l=0; l<length;l++){
      int zed = 0;
      for(zed = 0; zed<data[l][0]+2;zed++){
	printf("%d ",data[l][zed]);
      }
      printf("\n");

    }*/

    //finally we check to see who is alive
    //and find out how many nodes they have left
    int last;
    int answer = 1000;
    for(last = 0; last<length;last++){
      //printf("last: %d %d\n",last,length);
      if(data[last][0] != 0){
	//printf("final answer: %d\n", data[last][0]);
	answer = data[last][0];
      } 
    }
    return answer;
}



int main(void){
  int i = 0;

 
  int **data = (int **)malloc(ROWCOUNT * sizeof(int*));
  for (i = 0;i < ROWCOUNT;i++){
    data[i] = (int *)malloc(COLUMNCOUNT * sizeof(int));
  }

  int length = open(data,"kargerMinCut.txt");    //"kargerMinCut.txt"); 
  

  for(i = 0 ; i < 10;i++){
    printf("i == %d\n",i);
  int **temp_data = (int **)malloc(ROWCOUNT * sizeof(int*));
  int temp_i;
  for (temp_i = 0;temp_i < ROWCOUNT;temp_i++){
    temp_data[temp_i] = (int *)malloc(COLUMNCOUNT * sizeof(int));
  }
  //int **temp_data = malloc(ROWCOUNT*COLUMNCOUNT*sizeof(int));
    int j = 0;
    int k = 0;
    for (j  = 0; j < length; j++ ) {
        for (k = 0; k < data[j][0]+2; k++ ){
	  //printf("%d \n",data[j][k]);
            temp_data[j][k] = data[j][k];
        }   
    } 
    //memcpy(temp_data, data, ROWCOUNT*COLUMNCOUNT*sizeof(int));
    int answer = cut(length, temp_data);
    printf("answer: %d\n",answer);
    free(temp_data);
  }
  return 0;
}
