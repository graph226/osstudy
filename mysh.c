#include<stdio.h>
int main(){
  while(1){
    char s[100];
    printf("mysh> ");
    fgets(s,sizeof(s),stdin);
  }
  return 0;
}
