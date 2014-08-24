#include <stdlib.h>
#include <stdio.h>
#include "myData.h"
#include "heap.h"

#define NUM 19

data *create_data(char *name1, char *name2, double length){
  data *out =malloc(sizeof(data));
  out->key = name1;
  out->key2 = name2;
  out->value = length;
  return out;
}


 

void push_heap(data **heap, data **map, char *name){
  int i;
  for(i=0;i<NUM;i++){
    if((name == map[i]->key) || (name == map[i]->key2)){
      printf("%s %s %02f\n",map[i]->key, map[i]->key2, map[i]->value);
      bubble(heap,(map[i]));
    }
  }  
}



int main(){

  data **heap = create_heap();
  data **map = malloc(NUM*sizeof(data*));

 map[0] = create_data("Arad","Zerind",75);
 map[1]	=  create_data("Oradea","Zerind",71);
 map[2]	=  create_data("Sibiu","Oradea",151);
 map[3]	=  create_data("Arad","Sibiu",140);
 map[4]	=  create_data("Arad","Timisoara",118);
 map[5]	=   create_data("Timisoara","Lugoj",111);
 map[6]	=   create_data("Lugoj","Mehadia",70);
 map[7]	=   create_data("Mehadia","Drobeta",75);
 map[8]	=  create_data("Drobeta","Craiova",120);
 map[9]	=  create_data("Craiova","Rimnicu Vilcea",146);

 map[10]= create_data("Rimnicu Vilcea","Sibiu",80);
 map[11]=  create_data("Rimnicu Vilcea","Pitesti",97);
 map[12]=  create_data("Craiova","Pitesti",138);
 map[13]= create_data("Sibiu","Fagaras",99);
 map[14]= create_data("Bucharest","Fagaras",211);
 map[15]= create_data("Bucharest","Pitesti",101);
 map[16]= create_data("Bucharest","Giurgiu",90);
 map[17]=  create_data("Bucharest","Urziceni",85);

 map[18]= create_data("Urziceni","Arad",600);
 
 push_heap(heap, map , "Arad");
 print_heap(heap);


	    /*

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
	    */
  destroy_heap(heap);
 
 
 
  return 0;
}

