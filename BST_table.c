#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  int value;
  char *string;
  int count;
  void *data;
  struct node *big;
  struct node *small;
} node;



void put(node *root, int value, char *string){
  //printf("root->value: %d\n",root->value);
  
  root->count++;

  //printf("root->count: %d, value: %d\n",root->count, value);
  if(root->value == value){
    root->string = string;
    root->count--;
  }
  if(root->value > value){
    if(root->small == NULL){
      node *new_node = malloc(sizeof(node));
      new_node->value = value;
      new_node->string = string;
      root->small = new_node;
    } else {
      put(root->small,value,string);
    }
  }
  if(root->value < value){
    if(root->big == NULL){
      node *new_node = malloc(sizeof(node));
      new_node->value = value;
      new_node->string = string;
      root->big = new_node;
    } else {
      put(root->big,value,string);
    }   
  } 
}

char *get(node *root, int value){
  if(root->value == value){
    return root->string;
  } 
  else if(root->value > value){
    if(root->small == NULL){
      return NULL;
    } else {
      return get(root->small, value);
    }
  }
  else if(root->value < value){
    if(root->big == NULL){
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
 
node *make_root(int value, char *string){ 
  node *root = malloc(sizeof(node));
  root->value = value;
  root->string = string;
  root->count = 1;
  return root;
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



int main(){
  node *root = make_root(2,"two");
  put(root, 6, "sex");
  put(root, 9, "nine");
  put(root, 7, "seven");
  printf("get: %s\n",get(root,0));
  put(root, 1, "one");
  put(root, 4, "four");
  put(root, 5, "five");
  put(root, 6, "six");
  printf("get: %s\n",get(root,6));
  printf("get: %s\n",get(root,4));
  printf("get: %s\n",get(root,2));
  print_tree(root);
  

  return 0;
}
