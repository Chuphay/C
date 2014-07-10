#ifndef _queue_h
#define _queue_h


#define size 8

typedef struct que{
  int length;
  int position;
  int value[size]; 
}que;

que *Queue_create();
void Queue_destroy(que *q);
void Queue_add(que *q, int new_value);
int Queue_peek(que *q);
int Queue_serve(que *q);



#endif
