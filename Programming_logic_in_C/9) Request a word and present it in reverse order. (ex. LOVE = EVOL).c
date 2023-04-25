#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
  char word[15];
  int x;
  setlocale(LC_ALL,"portuguese");


    printf("INSERT A WORD:\n ");
    gets(word);

    x=strlen(word);
  
     while (x>=0){
      printf("%c",word[x]);
      x--;
     }
     
   printf("\n");
    system("pause");
    return 0;
}
