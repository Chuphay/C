#include "union_find.h"
#include <stdio.h>
#include <time.h>

void graph(data ** zee){
  int i;
  for(i=0;i<25;i++){
    if(i%5 == 0){
      printf("\n");
    }
    if(*((int*) zee[i]->data) == 0){
      printf("X");
    } else {
      printf("O");
    }
  }
  printf("\n");
}

void newSite(data ** zee, int * True){

 int  myRand =  rand()%25;
 if(zee[myRand]->data == True){
   newSite(zee,True);
 } else {
   zee[myRand]->data = True;
   if(myRand/5>0){
     if(zee[myRand-5]->data == True){
       myUnion(zee,myRand,myRand-5);
     }
   }
   if(myRand+5<25){
     if(zee[myRand+5]->data == True){
       myUnion(zee,myRand,myRand+5);
     }
   }
   if(myRand%5>0){
     if(zee[myRand-1]->data == True){
       myUnion(zee,myRand,myRand-1);
     }
   }
   if(myRand%5<4){
     if(zee[myRand+1]->data == True){
       myUnion(zee,myRand,myRand+1);
     }
   }
 }
}





int main(){
  srand(time(NULL));


  int * False = calloc(1, sizeof(int));
  int * True = calloc(1, sizeof(int));
  *True = 1;
  int times =100000;
  int j;
  float critical = 0;
  for(j=0;j<times;j++){

  data **zee = init(27);
  int i;
  for(i=0;i<25;i++){
    //printf("zee: %d\n", zee[i]->value);
    zee[i]->data = False;

  } 
 
  myUnion(zee,0,26);
  myUnion(zee,1,26);
  myUnion(zee,2,26);
  myUnion(zee,3,26);
  myUnion(zee,4,26);
  myUnion(zee,24,25);
  myUnion(zee,23,25);
  myUnion(zee,22,25);
  myUnion(zee,21,25);
  myUnion(zee,20,25);

  //graph(zee);
  float count = 0;
  while(getNode(zee,25) != getNode(zee,26)){
    count ++;
    newSite(zee,True);
    // graph(zee);
  }
  //printf("critical point: %f\n",count/25);
  critical += count/25;
  free(zee);
}
  printf("critical: %f\n",critical/times);
  return 0;

}
