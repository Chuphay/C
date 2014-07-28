#include <stdio.h>
#include <stdlib.h>

#define MAX 6


void print(int * lst){
  int i;
  printf("[");
  
  for(i=0;i<MAX+1;i++){
    if(i==MAX){
      printf("%d]\n",lst[i]);
    } else {
      printf("%d,",lst[i]);
    }
  }
}

int max(int a, int b){
  if(a>b){
    return a;
  } else {
    return b;
  }
}

int m_value(int *value, int *weight, int length){

  int array[MAX+1] = {};
  int temp[MAX+1] = {};

  int i;
  for (i = 0; i< length;i++){
    int j;
    for(j=0;j<MAX+1;j++){
      temp[j] = array[j];
      if(j-weight[i]>=0){
	array[j] = max(temp[j],temp[j-weight[i]]+value[i]);
      } else {
	array[i] = temp[j];
      }
    }
    //print(array);
    //getchar();
  }
  print(array);
  return array[MAX];
}

void read(char *name,int *value, int *weight){

  FILE *fp =fopen(name,"r");
  int c;
  char s[100];
  int i = 0;
  int j = 0;
  int flag = 0;
   while((c=fgetc(fp)) != EOF){
    if((char)c != '\n'){
      if((char)c != ' '){
      s[i]=c;
      }
      i++;
      if((char)c == ' '){
	s[i-1] = '\0';

	if(flag == 0){
	  value[j] = (int) strtol(s, (char **)NULL, 10);

	  flag = 1;
	} else {
	  printf("not sure...\n");
	}
	i = 0;
      }

    } else {
	s[i] = '\0';
	  weight[j] = (int) strtol(s, (char **)NULL, 10);
	  flag = 0;
      j++;
      i=0;
    }
   }
   printf("\nj: %d\n",j);
   for(i=0;i<j;i++){
     printf("value: %d, weight: %d\n",value[i],weight[i]);
   }
}    

int main(){

 /*
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]

10000 100
  */
    //
    //int value[10] = {10,10,10,10,10,10,10,10,10,10};
    //int weight[10] = {70,60,50,40,30,20,10,5,2,1};
    int value[10] = {500,
		     250,
		     1000,
		     5000,
		     2000,
		     7000,
		     3000,
		     4000,
		     125,
		     6000};
  int weight[10] = {1,1,1,1,1,1,1,1,1,1};
    // int value[100] = {};
  // int weight[100] = {};

  //  read("/host/D/C/knapsack.txt",value,weight);

  int answer = m_value(value,weight, 10);
  printf("answer: %d \n",answer);
  return 0;
}
