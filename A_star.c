#include <stdlib.h>
#include <stdio.h>
#include "heap.h"


#define NUM 19

data *create(char *name1, char *name2, int length){
  data *out =malloc(sizeof(data));
  out->value1 = name1;
  out->value2 = name2;
  out->value = length;
  return out;
}


 

void push_heap(data **heap, data **map, char *name){
  int i;
  for(i=0;i<NUM;i++){
    if((name == map[i]->value1) || (name == map[i]->value2)){
      printf("%s %s %d\n",map[i]->value1, map[i]->value2, map[i]->value);
      bubble(heap,(map[i]));
    }
  }  
}



int main(){

  data **heap = create_heap();
  data **map = malloc(NUM*sizeof(data*));

 map[0] = create("Arad","Zerind",75);
 map[1]	=  create("Oradea","Zerind",71);
 map[2]	=  create("Sibiu","Oradea",151);
 map[3]	=  create("Arad","Sibiu",140);
 map[4]	=  create("Arad","Timisoara",118);
 map[5]	=   create("Timisoara","Lugoj",111);
 map[6]	=   create("Lugoj","Mehadia",70);
 map[7]	=   create("Mehadia","Drobeta",75);
 map[8]	=  create("Drobeta","Craiova",120);
 map[9]	=  create("Craiova","Rimnicu Vilcea",146);

 map[10]= create("Rimnicu Vilcea","Sibiu",80);
 map[11]=  create("Rimnicu Vilcea","Pitesti",97);
 map[12]=  create("Craiova","Pitesti",138);
 map[13]= create("Sibiu","Fagaras",99);
 map[14]= create("Bucharest","Fagaras",211);
 map[15]= create("Bucharest","Pitesti",101);
 map[16]= create("Bucharest","Giurgiu",90);
 map[17]=  create("Bucharest","Urziceni",85);

 map[18]= create("Urziceni","Arad",600);
 
 push_heap(heap, map , "Arad");
 print(heap);


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
  destroy(heap);
 
 
 
  return 0;
}

