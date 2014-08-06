#include <stdio.h>
#include <stdlib.h>



int main(){
  srand(91347);
  double myRand = rand()/(RAND_MAX +1.0);
  printf("myRand: %f\n",myRand);
  printf("sizeof(char): %X\n",'l');
  printf("16*16= %d\n",16*16);
  int data[]= {1,1,
	       1,0,
	       0,1,
	       0,0};
  int and[] = {1,0,0,0};
 


  return 0;
}
