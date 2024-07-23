#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *shift_string(char *str);

int main(){

  char p[10];

  printf("Digite uma palavra:\n");
  scanf("%s", p);
  shift_string(p);

  printf("String deslocada: %s\n", p);
  printf("String anterior %s\n", p);

  return 0;
}

char *shift_string(char *str){

  char *srt1 = str;

  while(*str){
    if(*str == 'z'){
      *str = 'a';
    }
    else if(*str == 'Z'){
      *str = 'A';
    }
    else{
      (*str)++;
    }
    str++;
  }
  return str1;
}