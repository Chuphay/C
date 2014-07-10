#include <stdlib.h>
#include <stdio.h>

#define MAX 1220
#define MAXI 30



typedef struct data{
  float value;
  int value1;
  int value2;
} data;


data **create(void){
  data **out = malloc((MAXI+1)*sizeof(data *));
  int i;  
  for(i=0;i<MAXI;i++){
    out[i] = malloc(sizeof(data));
  }
  return out;
}
void destroy(data **heap){
  free(heap);
}


int tot_length = 0;
void bubble(data **heap, data data){
  // printf("tot_length: %d\n",tot_length);
  if(tot_length+4>MAXI){
    printf("the heap is over the maxi\n");
    exit(1);
  }
  tot_length++;
  int length = tot_length;
  *heap[length] = data;

  //printf("heap[tot_length]: %d\n",heap[tot_length]->value);

    while((heap[length]->value<heap[length/2]->value) && (length>1)){
      float temp1 = heap[length]->value;
      int temp2 = heap[length]->value1;
      int temp3 = heap[length]->value2;
      heap[length]->value = heap[length/2]->value;
      heap[length]->value1 = heap[length/2]->value1;
      heap[length]->value2 = heap[length/2]->value2;
      heap[length/2]->value = temp1;
      heap[length/2]->value1 = temp2;
      heap[length/2]->value2 = temp3;
      length = length/2;
      }

    int j;
    printf("heap: [");
    for(j=1;j<tot_length+1;j++){
      printf("%f,",heap[j]->value);
    }
    printf("]\n");


 
}
void print(data **heap){
 int j;
    printf("heap: [");
    for(j=1;j<tot_length+1;j++){
      printf("%f,",heap[j]->value);
    }
    printf("]\n");
}


struct data extract(data **heap){
  if (tot_length<1){
    printf("heap is empty\n");
    exit(1);
  }

  // print(heap);
  data out = *heap[1];
  // printf("tot. length: %d\n", tot_length);
  heap[1]->value = heap[tot_length]->value;
  heap[1]->value1 = heap[tot_length]->value1;
  heap[1]->value2 = heap[tot_length]->value2;
  // printf("heap[1]: %d\n",heap[1]->value);
  tot_length--;
  int i = 1;
  //print(heap);
  while(2*i<tot_length+1){
    //printf("i: %d\n",i);
    // print(heap);
     //printf("here\n");
    float compare =  heap[2*i]->value;
    //printf("compare: %d\n", compare); 
    int flag = 0;
    if(2*i+1<=tot_length){
      // printf("there\n");
      if(heap[2*i+1]->value<compare){
	//printf("then\n");
	flag = 1;
	compare = heap[2*i+1]->value;
      }
    }
    if(heap[i]->value<=compare){
      //printf("break\n");
      break;
    } else {
      // printf("finally\n");
      float temp1 = heap[i]->value;
      int temp2 = heap[i]->value1;
      int temp3 = heap[i]->value2;
      heap[i]->value = heap[2*i+flag]->value;
     heap[i]->value1 = heap[2*i+flag]->value1;

     heap[i]->value2 = heap[2*i+flag]->value2;

      heap[2*i+flag]->value = temp1;
      heap[2*i+flag]->value1 = temp2;
      heap[2*i+flag]->value2 = temp3;
      i = 2*i + flag;
    }
    // print(heap);
  }


  //print(heap);
  
  return out;
} 

int get_line(char s[]){
  int c;
  int i =0 ; 
  while((c = getchar())!='\n'&& c !=EOF){
    if(i<MAX){    
      s[i] = c;
      i++;
    } else {
      printf("Ran over MAX\n");
      exit(1);
    }
  }
  s[i] = '\0';
  return i;
}

int time(int weight[MAX],int length[MAX], int l){
  if(l>MAX){
    printf("length bigger than MAX. Aborting.\n");
    exit(1);
  }
  int out = 0;
  int time = 0;
  int i =0;

  data **heap = create();
  for(i=0;i<l;i++){
    printf("here. value: %d\n", length[i]-weight[i]);
    data d;
    //d.value = (float)(length[i]-weight[i]);
    d.value = -((float)weight[i]/length[i]);
    d.value1 = weight[i]; 
    d.value2 = length[i];
    printf("array: %d %d\n",d.value1,d.value2);
    bubble(heap,d);
  }

  int mem1 = 0;
  int mem2 = 0;
  int mem3  = 0;
  for(i=0;i<l;i++){

    data e = extract(heap);
    printf("e.value: %f\n",e.value);
    //printf("e.array: %d %d\n", e.value1,e.value2);
    if(mem1 == e.value){
      printf("double: %f\n",e.value);
    }

    //printf("time: %d\n",time);
    //printf("out: %d\n",out);
    if((mem1 == e.value)&&(e.value1>mem2)){
      printf("double: %f\n",e.value);
      out = out - time*mem2;
      time = time - mem3;
      time += e.value2;
      out += time*e.value1;
      time += mem3;
      out+= time*mem2;

    } else {
      mem1 = e.value;
      mem2 = e.value1;
      mem3 = e.value2;

      time += e.value2;
      out += time*e.value1;
    }
    // printf("time: %d\n",time);
    // printf("out: %d\n",out);

  }
  destroy(heap);
  return out;
}






int main(){
  /*
  char c[MAX];
  int temp = 0;
  while((temp = get_line(c))>0){
    printf("%s\n",c);
  }
  */
  /*
50	18
10	44
94	8
30	26
98	68
78	6
2	56
54	20
30	40
56	62
60	22
92	10
98	52
4	52
80	36
12	88
32	86
8	88

   */

  //int a[MAX] = {48,4,64,54,46};
  //int b[MAX] = {14,90,22,66,6};
  int a[MAX] = {50,10,94,30,98,78,2,54,30,56,60,92,98,4,80,12,32,8};
  int b[MAX] = {18,44,8,26,68,6,56,20,40,62,22,10,52,52,36,88,86,88};

  int c = time(a,b,18);
  printf("time: %d \n",c);
  /*
  data **heap = create();
  data d;
  data e;
  d.value = 45;
  d.array = b; 
  printf("d->value: %d\n",d.value);
  bubble(heap,d);
  e.value  = 33;
  e.array = a;
  bubble(heap, e);
  //bubble(heap,d);
  data f = extract(heap);
  printf("extracted: %d\n",f.array[1]);
  f = extract(heap);
  printf("extracted: %d\n",f.array[1]);
  */
  return 0;
}

