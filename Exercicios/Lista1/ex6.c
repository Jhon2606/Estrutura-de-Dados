#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void shift_string(char *str);

int main(){

  char p[10];

  printf("Digite uma palavra:\n");
  scanf("%s", p);
  shift_string(p);

  printf("String deslocada: %s\n", p);

  return 0;
}

void shift_string(char *str){
  while(*str){

    if (isalpha(*str)) {
    if(*str == 'z'){
      *str = 'a';
    }
    else if(*str == 'Z'){
      *str = 'A';
    }
    else{
      (*str)++;
    }
  }
  str++;
}
}