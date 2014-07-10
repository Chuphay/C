#include <stdio.h>
#include <stdlib.h>

#define MAX 16


typedef struct bit{
  char sum;
  char flag;
} bit;

bit * half_adder(char x, char y){
  bit * out  = malloc(sizeof(bit));
  if(x == '1' || y == '1'){
    if(x == '1' && y == '1'){
      out->sum = '0';
      out->flag = '1';
    } else {
      out->sum = '1';
      out->flag = '0';
    }
  } else {
    out->sum = '0';
    out->flag = '0';
  }
  return out;
}

bit * full_adder(char x, char y, char z){

  //printf("in: %c %c %c\n",x,y,z);
  bit * out = malloc(sizeof(bit)); 
  bit * temp1 = half_adder(x,y);
  //printf("temp1.sum: %c temp1.flag %c\n",temp1->sum, temp1->flag);
  bit * temp2 = half_adder(temp1->sum,z);
  out->sum = temp2->sum;
  out->flag = temp1->flag+temp2->flag-'0';
  free(temp2);
  free(temp1);
  return out;
}

char *addMAX(char x[MAX], char y[MAX]){
  int n = MAX-1;
  char *out = malloc((MAX+1)*sizeof(char));

  char carry = '0';
  for(n = MAX-1;n>=0;n--){
    // printf("n: %d x[n]: %c, y[n]: %c\n", n,x[n],y[n]);
    bit * temp1 = full_adder(x[n],y[n],carry);
    carry = temp1->flag; 
    out[n]=temp1->sum;
    free(temp1);

  }
  out[MAX] = '\0';
  return out;
}

char *andMAX(char x[MAX], char y[MAX]){
  int n = MAX-1;
  char *out = malloc((MAX+1)*sizeof(char));
  for(n = MAX-1;n>=0;n--){
    if((x[n] == y[n])&&(x[n] == '1')){
      // printf("here\n");
      out[n] = '1';
    } else {
      out[n] = '0';
    }
  }
  out[MAX] = '\0';
  return out;
}

void flip(char x[MAX]){
  //printf("flipping: %s\n",x);
  int i;
  for(i=0;i<MAX;i++){
    if(x[i]=='0'){
      x[i]='1';
    } else {
      x[i]='0';
    }
  }
  //printf("finished fliiping: %s\n", x);
}

void two_comp(char x[MAX]){

  //printf("two_comp in: %s\n",x);
  flip(x);
  // printf("two_comp in: %s\n",x);


  int n = MAX-1;
  char carry = '1';
  for(n = MAX-1;n>=0;n--){
    //printf("n: %d x[n]: %c\n", n,x[n]);
    bit * temp1 = half_adder(x[n],carry);
    carry = temp1->flag; 
    x[n]=temp1->sum;
    free(temp1);
  }
  // printf("two_comp in: %s\n",x);

}


struct ALU_state{
  char zx;   //zero the x input
  char nx;   //negate the x input
  char zy;   //zero the y input
  char ny;   //negate the y input
  char f;    //function code: 1 for add, 0 for and
  char no;   //negate the output (bitwise)
  char zr;   //true iff out == 0
  char ng;   // true iff out<0
};

char *ALU(struct ALU_state * state,char x[MAX], char y[MAX]){
  char *out = malloc((MAX+1)*sizeof(char));
  char zero1[MAX+1] = "0000000000000000";
  char zero2[MAX+1] = "0000000000000000";
  if(state->zx == '1'){x = zero1;}
  if(state->zy == '1'){y = zero2;}
  //printf("y: %s\n",y);
  if(state->nx == '1'){flip(x);}
  //printf("y: %s\n",y);
  if(state->ny == '1'){flip(y);}
  // printf("y: %s\n",y);

  printf("x: %s\n",x);
  printf("y: %s\n",y);
  if(state->f == '1'){
    out = addMAX(x,y);
  } else {
    //printf("state.f ==0\n");
    if(state->f != '0'){
      printf("error: state.f != 0\n");
      exit(1);
    }
    out = andMAX(x,y);

  }
  //printf("out: %s\n", out);
  if(state->no == '1'){flip(out);}
  state->zr = '1';
  int i;
  for(i=0;i<MAX;i++){
    if(out[i] == '1'){
      state->zr = '0';
      break;
    }
  }
  if(out[0] == '1'){
    state->ng = '1';
  } else {
    if(out[0] != '0'){
      printf("error: out[0]== %c",out[0]);
      exit(1);
    }
    state->ng = '0';
  }


  return out;
}
 





int main(void){
  printf("on\n");
  bit zee;
  zee.sum = '0';
  zee.flag = '1';
  printf("zee? %d\n",zee.flag);
 printf("zee.sum? %d\n",zee.sum);
  bit *l = half_adder('1','0');
  printf("l: %c\n", l->sum);
  l = half_adder('0','0');
  printf("l: %c\n", l->sum);
  printf("testing:\n");

	  bit *zed = full_adder('1','1','0');
printf("carry: %c, sum: %c\n",zed->flag,zed->sum);

 

  char five[MAX+1] = "0000000000000101";
  char seven[MAX+1] = "0000000000000111";
  two_comp(five);
  two_comp(five);
  char * zex = addMAX(five,seven);
  printf("zex: %s\n",zex);
  two_comp(zex);
  printf("zex: %s\n",zex);

  struct ALU_state *state = malloc(sizeof(struct ALU_state));
  state->zx = '0';
  state->nx = '1';
  state->zy = '0';
  state->ny = '0';
  state->f = '1';
  state->no = '1';
  state->zr = '0';
  state->ng = '0';
  printf("ALU\n\n");
  char * zeb = ALU(state,five,seven);
  printf("zeb: %s\n",zeb);
  printf("state.zr : %c state.ng: %c\n",state->zr,state->ng);
  free(state);
  //printf("here\n");
  return 0;
}
