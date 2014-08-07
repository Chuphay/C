#ifndef _myData_h
#define _myData_h

typedef struct data{
  double value;
  int value2;
  char *key;
  char *key2;
  struct data *ptr;
  struct data *ptr2;
  void *data;
} data;

void flip(data *a, data *b);

#endif


