#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
  char word[15];

    setlocale(LC_ALL,"portuguese");



 printf("INSERT A WORD: ");
 gets(word);
  system("pause");

  for(int x=0;word[x];x++){
    
    word[x]= toupper(word[x]);
   
  
  }
  printf("%s \n",word);
   system("pause");
    return 0;
}

