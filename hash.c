#include <stdio.h>
#include <stdlib.h>

#define BINS 3

int table_count[BINS] = {};

typedef struct data{
  char *key;
  int value;
  struct data *ptr;
} data;



void push(data *first, char *key, int value){
  /*order 1, pushes to the front of the list*/
  data * next = malloc(sizeof(data));

  next->key = first->key;
  next->value = first->value;
  next->ptr = first->ptr;
 
  first->key = key;
  first->value = value;
  first->ptr = next;
}

void pop(data *first){
  /*order 1, pops the leading value
  note you cannot pop the only element*/
  data * second = first->ptr;
  first->key = second->key;
  first->value = second->value;
  first->ptr = second->ptr;
  free(second);
  second = NULL;
}

unsigned int horner(char *s){
  unsigned int hash = 0;
  int i = 0;
  while(s[i] != '\0'){
    hash = s[i] + 31*hash;
    i++;
    if(i>9){
      printf("long input key... \nhopefully everything will work fine\n");
      break;
    }
  }
  return hash;
}

data **create_table(){
  data **table = malloc(BINS*sizeof(data*));
  int i;
  for(i=0;i<BINS;i++){
    table[i] = malloc(sizeof(data));
  }
  return table;
}

void destroy_table(data **table){
  int i;
  for(i=0;i<BINS;i++){
    int j;
    for(j=0;j<table_count[i]-1;j++){
      pop(table[i]);
    }
    free(table[i]);
    table[i] = NULL;
  }
  free(table);
  table = NULL;
}

void input(data **table, char *key, int value){

  int place = horner(key)%BINS;
  if(table_count[place] == 0){
    table[place]->key = key;
    table[place]->value = value;
    table_count[place]++;
  } else {
    push(table[place], key, value);
    table_count[place]++;
  }
}

void print(data **table){
  int i;
  for(i=0;i<BINS;i++){
    if(table_count[i] > 0){
      printf("table[%d]:\n",i);
      int j;
      data *temp = table[i];
      for(j=0;j<table_count[i];j++){

	printf("key: \"%s\" value: %d\n",temp->key,temp->value);
	temp = temp->ptr;
      }

    }
  }
}

int get(data **table, char *key){
  int place = horner(key)%BINS;
  int i;
  int out;
  int flag = 0;
  data *temp = table[place];
  for(i=0;i<table_count[place];i++){
    if(temp->key == key){
      printf("found it! key: \"%s\" value: %d\n",temp->key,temp->value);
      out = temp->value;
      flag = 1;
      break;
    } else {
      temp = temp->ptr;
    }
  }
  if(flag == 0){
    printf("didn't find it...\n");
  } 
  return out;
}

void delete(data **table, char *key){
  int place = horner(key)%BINS;

  int i;
  int flag = 0;
  data *temp = table[place];
  for(i=0;i<table_count[place];i++){
    if(temp->key == key){
      printf("deleting key: \"%s\" value: %d\n",temp->key,temp->value);
      flag = 1;
      if(i == table_count[place]-1){
	table_count[place]--;
	temp->key = NULL;
	temp->value = 0;
      } else {
	pop(temp);
      }
      break;
    } else {
      temp = temp->ptr;
    }
  }
  if(flag == 0){
    printf("didn't find it...\n");
  } 
}


int main(){
 
  data **table = create_table();
  input(table,"yo",33);
  input(table,"this",41);
  input(table,"that",1);
  input(table,"what",37);
  print(table);
  printf("table_count[1]: %d\n",table_count[1]);
  get(table,"that");
  get(table,"where");
  delete(table,"this");
  printf("table_count[1]: %d\n",table_count[1]);

  print(table);
  delete(table,"yo");
  printf("table_count[1]: %d\n",table_count[1]);
  delete(table,"not here");
  print(table);
  delete(table,"that");
  delete(table,"what");
  print(table);


  destroy_table(table);

  printf("table: %d\n",table==NULL);
  return 0;
}
