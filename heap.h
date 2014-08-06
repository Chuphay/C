#ifndef _heap_h
#define _heap_h

typedef struct data{
  int value;
  char *value1;
  char *value2;
} data;

data *create_data(int value, char *value1, char *value2);

data **create_heap(void);

void destroy(data ** heap);

void print(data **heap);

void bubble(data **heap, data *data);
 
data *extract(data **heap);

#endif
 
