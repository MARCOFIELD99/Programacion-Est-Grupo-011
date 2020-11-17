#include<stdio.h>
#include<stdlib.h>

/*fac = factorial              
  num = numero */


int fac(int number){
  if(number <= 1){
    return 1;
  }else{
    return number * fac(number - 1);
  }
}

int main(int argc, char **argv){
  int num = atoi(argv[1]);
  int resp;
  resp = fac(num);
  printf("EL factorial del numero %d es: %d\n",num,resp);
  return 0;
}
