#include <stdio.h>
#include <stdlib.h>

typedef struct data{

  int value;
  void *data;
} data;


void sort(data * array,int length){
  //I think this is called bubble sort
  //but not sure
  int i,j,temp;
  for(i=0;i<length;i++){
    temp = array[i].value;
    for(j=i;j<length;j++){
      if(array[j].value<temp){
	temp = array[j].value;
	void *ptr = array[j].data;
	array[j].value = array[i].value;
	array[j].data = array[i].data;
	array[i].value = temp;
	array[i].data  = ptr;
      }
    }
  }
}


int main(){

  int *s = malloc(sizeof(int));
  s[0] = 3;
  void *ptr = malloc(sizeof(void));
  char *str = "hello";
  ptr = s;

  int *l = ptr;
  printf("on\n");
  printf("%d\n",s[0]);
  printf("%d\n",l[0]);
  printf("%d\n", ((int *)ptr)[0]);
  ptr = str;
  char *str2 = ptr;
  printf("%s\n",str2);

  data d;
  d.value = 45;
  d.data = str;


  printf("\ndata d\n");
  printf("%d\n",d.value);
  printf("%s\n",(char *)d.data);
  /* int ddd[3]  = {1,2,3};
  d.data = ddd;
  printf("%d, %d, %d\n\n",((int *)d.data)[0],((int *)d.data)[1],((int *)d.data)[2]);*/
  data e;
  e.value = 21;
  e.data = str;
  data f;
  f.value = 2;
  str2 = "world!";
  f.data = str2;
  //int length = 3;
  data z[3] = {d,e,f};
  sort(z,3);
  int i;
  printf("sorted\n");
  for(i=0; i <3; i++){
    printf("%d\n",z[i].value);
    printf("%s\n",(char *)z[i].data);
 
  }




  return 0;
}
