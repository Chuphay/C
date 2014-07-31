#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  int value;
  char *string;
  int count;
  struct node *big;
  struct node *small;
} node;

node *make_root(int value, char *string){ 
  node *root = malloc(sizeof(node));
  root->value = value;
  root->string = string;
  root->count = 1;
  return root;
}



void put(node *root, int value, char *string){
  //printf("root->value: %d\n",root->value);
  
  root->count++;

  //printf("root->count: %d, value: %d\n",root->count, value);
  if(root->value == value){
    printf("replacing a value...\nroot count is probably messed up\n");
    root->string = string;
    root->count--;
  }
  if(root->value > value){
    if(root->small == NULL){
      node *new_node = make_root(value, string);
      root->small = new_node;
    } else {
      put(root->small,value,string);
    }
  }
  if(root->value < value){
    if(root->big == NULL){
      node *new_node = make_root(value, string);
      root->big = new_node;
    } else {
      put(root->big,value,string);
    }   
  } 
}

node *get(node *root, int value){
  if(root->value == value){

    return root;
  } 
  else if(root->value > value){
    if(root->small == NULL){
      printf("not there?\n");
      return NULL;
    } else {
      return get(root->small, value);
    }
  }
  else if(root->value < value){
    if(root->big == NULL){
      printf("not there?\n");
      return NULL;
    } else {
      return get(root->big, value);
    }
  }
  else {
    printf("weird... some kind of error\n");
    exit(1);
  }
}

void delete(node *root, int value){
  if(root->value == value){
  }
} 
 


void print_tree(node *root){
  if(root->small == NULL){
    printf("%s\n",root->string);
  } 
  if(root->small != NULL){
    print_tree(root->small);
    printf("%s\n",root->string);
  }
  if(root->big != NULL){
    print_tree(root->big);
  }

}

void del_min(node *root){
  //printf("root: %d, count: %d\n",root->value, root->count);
  root->count--;
  if(root->small == NULL){ 
    if(root->big == NULL){
      printf("weird...I'm going to exit\n");
      printf("but I'll try to delete %s first...\n",root->string);
      exit(1);
    }
    node * new_root = root->big;
    printf("deleting: %s\n",root->string);
    root->string = new_root->string;
    root->big = new_root->big;
    root->small = new_root->small;
    root->value = new_root->value;
    free(new_root);

  }
  else if(root->small != NULL){
    node *new_root = root->small;
    if(new_root->small == NULL){
      printf("deleting: %s\n",new_root->string);
      root->small = new_root->big;
      free(new_root);

    } else {
      del_min(new_root);
    }
  }
  else {
    printf("how on earth am I here\n");
  }	   
 
}

void del(node *root, int value){
  /*not implemented...*/
}



int main(){
  node *root = make_root(2,"two");
  put(root, 6, "sex");
  put(root, 9, "nine");
  put(root, 7, "seven");

  put(root, 1, "one");
  put(root, 4, "four");
  put(root, 5, "five");
  put(root, 6, "six");
  printf("get: %s\n",(get(root,6))->string);
  printf("get: %s\n",(get(root,4))->string);
  printf("get: %s\n",(get(root,2))->string);
  printf("get: %d\n",(get(root,0))==NULL);
  put(root,0,"zero");
  put(root,-2,"neg. two");
  put(root, -1, "neg. one");

  print_tree(root);
  del_min(root);
  del_min(root);
  del_min(root);
  del_min(root);
  del_min(root);
  del_min(root);
 del_min(root);
 del_min(root);
 del_min(root);
 del_min(root);
 del_min(root);
  

  return 0;
}
