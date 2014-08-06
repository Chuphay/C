#include <stdio.h>
#include <stdlib.h>

#define NUM 19
#define DEPTH 20

typedef struct route{
  char *name1, *name2;
  int length;
} route;

route create(char *name1, char *name2, int length){
  route out;
  out.name1 = name1;
  out.name2 = name2;
  out.length = length;
  return out;
}

int depth = 0;
int depth2 = 0;
char *stack[DEPTH]={};
char *stack2[DEPTH]={};

int in_stack(route *map, char *name){
  int flag = 0;
  int i;
  printf("being checked\n");
  for(i=0;i<depth;i++){
    printf("checking: %s and %s\n",name,stack[i]);
    if(name == stack[i]){
      printf("flagging, because of repeat of: %s\n",name);
      flag+=1;
    }
  }
  return flag;
}

int push_stack(route *map,char *name){
  printf("pushing stack: %s\n",name);
  int i;
  int out=0;
  for(i=0;i<NUM;i++){
    if(name == map[i].name1){

      if(depth<DEPTH){
	if(in_stack(map, map[i].name2) == 0){
          printf("name2 = %s\n",(map[i]).name2);
	  stack[depth] = map[i].name2;
	  out++;
	  depth++;
	}
      } else {
	printf("went over the depth limit...\n");
	exit(1);
      }
    }
   if(name == map[i].name2){

      if(depth<DEPTH){
	if(in_stack(map, map[i].name1) == 0){
      printf("name1 = %s\n",(map[i]).name1);
	  stack[depth] = map[i].name1;
	  depth++;
	  out++;
	}
      } else {
	printf("went over the depth limit...\n");
	exit(1);
      }
    }
  }
  return out;
}

char *pop_stack(route *map){
  char *out;
  if(depth>0){
    out = stack[depth-1];
    depth--;
  } else {
    printf("popping an empty stack...\n");
    exit(2);
  }
  return out;
}
int get_length(route *map, char *start, char *end){
  int out = -1;
  int flag = 0;
  int i;
  for(i=0;i<NUM;i++){
    if((start == map[i].name1) || (start == map[i].name2)){
      if((end == map[i].name1) || (end == map[i].name2)){
	out = map[i].length;
	flag = 1;
      }
    }
  }
  if(flag == 0){
    printf("didn't find %s and %s...\n",start,end);
    exit(3);
  }
  return out;
}



void DFS(route *map, int max_length, char *start, char *target){
  int distance = 0;
  char *location = start;

  //these flags, and the memory, is just a bunch of hacking
  //to go backwards on absolute failure
  //I'd try to improve my stack data structure next time
  //or just use recursion

  //this is broken...
  //but too late to fix now
  stack2[depth2] = start;
  // depth2++;
  int flag = 1;
  int mem_flag = 0;
  int mem_distance = 0;
  char *memory = start;

  push_stack(map, location);
  while (depth>0){
    printf("    Location: %s, memory %s, distance: %d\n",location,memory, distance);
    if(location == target){
      printf("congratulations!... distance: %d\n",distance);
      break;
    }
    flag--;
    char *temp = pop_stack(map);
    //printf("popped: %s\n",temp);
    int tent = get_length(map,location, temp);

    if(distance + tent > max_length){
      printf("too long... distance + tent = %d+ %d\n",distance,tent);
      //depth2--;
      //flag--;
    } else {


      mem_distance = distance;
      distance += tent;
      memory = location;
  
     depth2++;
      stack2[depth2] = temp;
 
      printf("stack2[%d] = %s\n",depth2,temp);
  
      location = temp;
      mem_flag = flag;
      flag += push_stack(map,location);
      //printf("flag: %d\n",flag);
    }
    if(flag == mem_flag){
      printf("minus\n");
      depth2--;
      location = stack2[depth2];
      printf("stack2[%d] = %s\n",depth2,location);
      distance = mem_distance;

      flag = 1;
    }
    printf("    Location: %s, memory %s, flag: %d depth: %d\n",location,memory, flag,depth2);
  }
}
  






int main(){

  route map[NUM] = {create("Arad","Zerind",75),
 		    create("Oradea","Zerind",71),
		    create("Sibiu","Oradea",151),
		    create("Arad","Sibiu",140),
		    create("Arad","Timisoara",118),
		    create("Timisoara","Lugoj",111),
		    create("Lugoj","Mehadia",70),
		    create("Mehadia","Drobeta",75),
		    create("Drobeta","Craiova",120),
		    create("Craiova","Rimnicu Vilcea",146),
		    create("Rimnicu Vilcea","Sibiu",80),
		    create("Rimnicu Vilcea","Pitesti",97),
		    create("Craiova","Pitesti",138),
		    create("Sibiu","Fagaras",99),
		    create("Bucharest","Fagaras",211),
		    create("Bucharest","Pitesti",101),
		    create("Bucharest","Giurgiu",90),
		    create("Bucharest","Urziceni",85),
		    create("Urziceni","Arad",600)};
  //push_stack(map,"Sibiu");
  //char *out = pop_stack(map);
  //printf("popped: %s\n",out);
  DFS(map, 600, "Arad","Bucharest" );

  return 0;
}
