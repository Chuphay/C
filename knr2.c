#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int get_line(char s[]){
  int c;
  int i =0 ; 
  while((c = getchar())!='\n'&& c !=EOF){
    if(i<MAX){    
      s[i] = c;
      i++;
    } else {
      printf("Ran over MAX\n");
      exit(1);
    }
    putchar(c);
  }
  s[i] = '\0';
  putchar('\n');
  return i;
}

int math(char s,int a, int b){
  if(s == '+'){
      return a + b;
  } else if (s == '-'){
      return a - b;
  } else if (s == '*'){
      return a * b;
  } else if (s == '/'){
      return a / b;
  } else {
    printf("fail... exiting\n");
    exit(1);
  }
}

int  parser(char c[], int length){
  if( c[length] != '\0'){
    printf("trouble... exiting\n");
    exit(1);
  }
  int stack[MAX]={};
    int n = 0;
    int i = 0;
    int flag =0;
  while(length>0){


    if(c[length-1] == ' '){
      if (flag == 0){
        i=0;
        n++;
        flag = 1;
      }
    
    } else if (c[length-1]>'0' && c[length-1]<'9'){
      flag = 0;
      int temp = 1;
      int j = 0;
      for(j=0;j<i;j++){
	temp *= 10;
      }
      //printf("temp: %d\n",temp);
      stack[n] += temp * ((int)(c[length-1]-'0'));
      //printf("stack: %d\n", stack[n]);
      i++;
    } else if((c[length-1] == '+')||(c[length-1] == '-')||(c[length-1] == '*')||(c[length-1] == '/')){
      if(flag==0){
	//printf("flags\n");
	i=0;
	n++;
	flag = 1;
      }
      if(n<2){
	printf("n is less than 2. exiting\n");
	exit(1);
      }
      int temp = math(c[length-1],stack[n-1],stack[n-2]);
      //printf("n: %d\n", n);
      //printf("answer: %d\n",temp);
      stack[n-1] = 0;
      stack[n-2] = temp;
      n--;

    } else {
      printf("we seem to have fallen off the map...\n");
      exit(1);
    }


    //printf("character: %c\n", c[length-1]);
    length--;
  } 


  return stack[0];
}





int main(){
  char c[MAX];// = getchar();
  int length = get_line(c); 
  //char s[MAX]={'+','2','3','\0'};
  //int answer = math(c);
  int ans = parser(c,length);
  printf("answer: %d\n", ans);
  //putchar(c);
  return 0;
}
