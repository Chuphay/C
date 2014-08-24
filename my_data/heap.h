#ifndef _heap_h
#define _heap_h

data **create_heap(void);

void destroy_heap(data ** heap);

void print_heap(data **heap);

void bubble(data **heap, data *data);
 
data *extract(data **heap);

#endif
 
