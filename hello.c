#include <stdio.h>

#define MAX 20

double power(double x, int y){
  double temp = x;
  int i;
  for(i=1;i<y;i++){
    temp *= x;
  }
  return temp;
}



main(){
  printf("hello\n");
  int i = 0;
  for(i=0;20*i<31;i++){
    printf("%d\t%d\n",20*i,(int)((5.0/9.0)*(20*i-32)));
  }
  int c;
  int count=0;
  int word_length[MAX]={};
  printf("EOF: %d\n",EOF);
  while((c=getchar()) != EOF){
    /*if(c == 'q'){
      printf("quiting... \n");
      break;
      }*/
    //printf("c: %d\n",c);

    putchar(c);
    count++;
    if(c == '\n'){
      //printf("count: %d\n",count);
      word_length[count-1]++;
      count = 0 ;
    }
    if(c == ' '){
      // printf("\nspace\n");
      word_length[count-1]++;
      count = 0 ;
    }
  }
  // printf("power: %.0f\n", pow(10,3));
  for(i=0; i< MAX; i++){
    if(word_length[i]>0){
      int temp = word_length[i];
      //double temp = pow(10,temp2/4.0);
      printf("%d\t",i);
      int k;
      for(k=0;k<temp;k++){
	//printf("*");
	putchar('*');
      }
      printf ("\n");
    }
  }

  printf("power: %.1f\n",power(3.0,4));
}
