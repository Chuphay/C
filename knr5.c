#include <stdio.h>

#define MAX 100

static char buff[MAX];
static char *aptr = buff;

char *alloc(int size){
  if(buff+MAX-aptr >= size){
    aptr += size;
    return aptr-size;
  } else {
    return 0;
  }
}
void afree(char *p){
  aptr = p;
}

struct point{
  int x;
  int y;
};

struct point make(int x, int y){
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
}

struct key {
  char *word;
  int count;
} keytab[] = {
  {"auto",0},
  {"break",0}
};


int main(){

  struct point pt = {320,200};
  printf("max x: %d\n",pt.x);
  struct point mypoint = make(33,42);
  printf("mypoint.x: %d\n", mypoint.x);
  char *zee = alloc(55);
  printf("%p\n",&zee);
  char *zib = alloc(10);
  zib = "yo";
  printf("%s\n",zib);
  afree(zee);
  return 0;
}
