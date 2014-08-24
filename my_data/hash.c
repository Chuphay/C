#include <stdio.h>
#include <stdlib.h>
#include "myData.h"
#include "stack.h"

#define BINS 3

int table_count[BINS] = {};


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
    table[i] = create_stack();
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

data *create_data(char *key, double value){
  data *out = malloc(sizeof(data));
  out->key = key;
  out->value = value;
  return out;
}


void input(data **table, char *key, double value){
  data *new = create_data(key,value);
  int place = horner(key)%BINS;
  push(table[place], new);
  table_count[place]++; 
}

void print(data **table){
  int i;
  for(i=0;i<BINS;i++){
    if(table_count[i] > 0){
      printf("table[%d]:\n",i);
      int j;
      data *temp = table[i];
      for(j=1;j<table_count[i]+1;j++){
	temp = temp->ptr;
	printf("key: \"%s\" value: %f\n",temp->key,temp->value);	
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
      printf("found it! key: \"%s\" value: %f\n",temp->key,temp->value);
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
  //delete(table,"this");
  printf("table_count[1]: %d\n",table_count[1]);

  print(table);
  //delete(table,"yo");
  printf("table_count[1]: %d\n",table_count[1]);
  //delete(table,"not here");
  print(table);
  //delete(table,"that");
  //delete(table,"what");
  print(table);


  destroy_table(table);

  printf("table: %d\n",table==NULL);
  return 0;
}
