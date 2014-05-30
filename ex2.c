#include <stdio.h>
#include <stdlib.h>

void increment (int *p){
  *p += 1;
}

void init_array(int a[], int count)
{
    int i;

    /* for each element, set it equal to its index number times 10: */

    for(i = 0; i < 100000*count; i++){
        a[i] = i;
	printf("%d\n",a[i]);}
}

int main(void)
{
  int counter;  
  int halt;
  scanf("%d", &halt);
  int *p = malloc(halt*sizeof(int));
  for (counter = 0 ; counter<halt; counter ++){
    scanf("%d", p);
    p++;
  }





int my_data[10];

    init_array(my_data, 10);  /* note lack of [] notation */

  int i = 10;
  increment(&i);
  printf("%d\n",i);
  //return 0;
  //int i = 0;

scanf("%d", &i);        /* pretend you typed "12" */
printf("i is %d\n", i);




 return 0;
}
 
