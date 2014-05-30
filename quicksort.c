#include <stdio.h>
#include <stdlib.h>


int *q_sort(int *list, int count){
  int i = 1;
  int j = 0;
 
  if (count <= 1){
    return list;
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
 
  q_sort(list+i,count-i);
  q_sort(list,i);
  return list;
  }
}

int main(){
  //float crazy = rand()/(RAND_MAX+1.0);
  int list[]={6,3,7,5,1,8,4,9,2,-6,-3,10,33,-2};
  int *list_ptr = malloc(sizeof(list));
  int count = sizeof(list)/sizeof(int);
  //int crazy2 = (int)(3*crazy);
  //printf("%d \n",crazy2);
  
  list_ptr = list; 
  int *x = q_sort(list_ptr,count);
  int i = 0;
  
 
 
  for(i=0;i<count;i++){
    printf("%d \n",x[i]);
  }
  printf("\n");
  return 0;
}  

