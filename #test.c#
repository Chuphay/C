#include <stdio.h>
#include <stdlib.h>

int open(int *data,  char *name){
  /*data needs to be preallocated memory
name is the name of the file you need opened
returns the number of lines in the file
and hence in the data,
but otherwise it messes with data in place */



  char s[100];
  FILE *fp =fopen(name,"r");
  if (fp == NULL) {
    printf("Couldn't open %s for reading\n",name);
      exit(1);
  }

  int c;
  int j = 0;
  int k = 0;

  while((c=fgetc(fp)) != EOF){

    if((char)c != '\n'){
      s[j]=c;
      j++;
    }
    if((char)c == '\n'){
      data[k]= (int) strtol(s, (char **)NULL, 10);
      k++;
      j = 0; 
    }
    if(j>100){
      printf("something bad happened: line too long");
      exit(1);
}
  }
  printf("%d\n",k);
  printf("%d\n",data[0]);

 fclose(fp);
 return k;
}



int random_find(int target, int *list, int count){
  /*random find
    does all of its data stuff in place */

  int i = 1;
  int j = 0;
 
  if (count <= 1){
    //do nothing
  }
  else { 
    float crazy = rand()/(RAND_MAX+1.0);
    int rdm = (int)(count*crazy);
    int pivot = list[rdm];
    list[rdm] = list[0];
    list[0] = pivot;
 

    for(j=1;j<count;j++){

      if (pivot>list[j]){
        int temp =list[i];
        list[i]=list[j];
        list[j]=temp;
        i++;
      }
    }
 
    list[0]= list[i-1];
    list[i-1]=pivot;
    if(i == target){
      return pivot;
    }
    else if(i>target){
      return random_find(target, list , i);
    } else {
      return random_find(target-i,list+i,count-i);
    }
  }
}

int main(void){
  int *data = malloc(100000*sizeof(int));
  int length = open(data,"IntegerArray.txt");
  printf("%d\n",data[0]+data[9]);



  int answer = random_find(901,data, length);
  printf("%d\n",answer);
  int i;
  for (i=0;i<length;i++){
    // printf("%d\n",data[i]);
  }
 
  return 0;
}
