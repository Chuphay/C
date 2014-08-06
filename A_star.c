#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int main(){

  data **heap = create_heap();
  data *d = create_data(2,"yo","blood");
  data *b = create_data(31,"this","that");
  data *r = create_data(32,"this","that");
  data *t = create_data(33,"this","that");
  data *y = create_data(34,"this","that");
 
  data *u = create_data(1,"this","that");
  data *i = create_data(35,"this","that");
  bubble(heap,d);

  bubble(heap,b);
  bubble(heap,r);
  bubble(heap,t);
  bubble(heap,y);
  bubble(heap,u);
  bubble(heap,i);
  data *f = extract(heap);
  printf("f: %s, %s\n",f->value1, f->value2);
  destroy(heap);
  free(f);
 
 
  return 0;
}

