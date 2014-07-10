#include <stdio.h>
#include <stdlib.h>

#define MAX 1220


int get_line(char s[]){
  int c;
  //char s[MAX] = malloc(MAX*sizeof(char));
  int i =0 ; 
  while((c = getchar())!='\n'&& c !=EOF){
    if(i<MAX){    
      s[i] = c;
      i++;
    } else {
      printf("Ran over MAX\n");
      exit(1);
    }

    //putchar(c);
  }
  s[i] = '\0';
  putchar('\n');
  return i;
}

int contains(char s[],char t[]){
  int out = 0;
  int i=0;
  int flag =0;
  int n;
  while(s[i] != '\0'){
    if(flag){
      if(t[i-n] == '\0'){ 
	out = 1;
	break;
      }
      if(t[i-n] != s[i]){
	flag = 0;
      }
    }

    if(s[i] == t[0]){
      flag = 1;
      n=i;
    }
    i++;
  }
  return out;
}




void copy(char from[],char to[]){
  int i = 0;
  while ((to[i] = from[i]) != '\0'){
    i++;
  }
}
 

int main(void){
  char c[MAX];
  char out[MAX];
  int length = 0;
  int temp = 0;
  while((temp = get_line(c))>0){
    char s[4] = {'1','\0'};
    int ans = contains(c,s);
    printf("ans: %d\n",ans);
    if(temp>length){
      printf("length: %d\n",temp);
      length = temp;
      copy(c,out);
    }
  }


  //putchar(c[0]);
  return 0;
}
