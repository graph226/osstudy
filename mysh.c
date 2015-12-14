#include<stdio.h>
int main(){
  char s[100];
  printf("mysh> ");
  scanf("%s",&s);
  int i;
  for(i=0;i<10;i++){
    printf("%s\n",s);
  }

  return 0;
}
