/*- sortear uma matriz 25 X 25 contendo letras do alfabeto
- ler o arquivo de palavras e sortear uma palavra
- inserir palavra aleatoriamente na tabela (a ordem também deve ser aleatória)
- apresentar a matriz
- solicitar ao usuário uma palavra
- informar ao usuário caso a palavra digitada esteja na matriz ( a que foi sorteada)

obs. A proporção para sorteio dos caracteres na matriz deverá ser 2:3, ou seja, para cada 3 caracteres sorteados, 2 deles dever�o ser vogais

Parte do código está abaixo:
CREDITOS PELA ELABORAÇÃO DO ENUNCIADO: PROFº ALEXANDRE MORENO.
*/

//sorteia vogal x consoante x vogal para montar matriz
#include<locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>
#include <ctype.h>

#define tam 25
#define maxpal 100

FILE *arqpal;
int qpal=0;
char palavras[maxpal][20];
char palavrasorteada[20];
char palEscolhida[20];
int colum,row,aux,tamP,tamPES;//jpCriou-sorteiaDLC
char direction[10];//JpCriou-sorteiaDLC


bool abreArquivo();
void leArquivo();
void mostraPalavras();


char pal[tam][tam];
void sorteia();// feito
void SorteiaDLC();// feito
void ColocaPalavra();//em andamento
void perguntaPalavra(); // falta fazer
void rastreia(); // falta fazer
void mostra(); //feito
//---------------------------------------------
int main () {
 setlocale(LC_ALL, "portuguese");	
  srand(time(NULL));
    if (abreArquivo()==0)
     return 0;
        leArquivo();
 // mostraPalavras();
        strcpy(palavrasorteada,palavras[rand()%maxpal]);
        printf("%s \n",palavrasorteada);
  //system("pause");
  
 
  sorteia();
   SorteiaDLC();
    ColocaPalavra();
         mostra();
             perguntaPalavra();
              //rastreia(); 
  
}
//---------------------------------------------
bool abreArquivo(){
  arqpal = fopen("palavras.txt", "r"); //leitura
  if (arqpal == NULL)
  {  // Se houve erro na leitura do arquivo
     printf("Problemas na leitura do arquivo\n");
     system("pause");
     return 0; //n�o conseguiu abrir o arquivo
  }   
  else
  {
     fclose(arqpal);
     return 1; //conseguiu abrir o arquivo
  }   
}
//---------------------------------------------
void leArquivo(){
   arqpal = fopen("palavras.txt", "r"); //leitura
   qpal=0;

   while (!feof(arqpal))
   {
      //fgets(string,tamanho,arquivo)
      fgets(palavras[qpal],20,arqpal);
      palavras[qpal][strlen(palavras[qpal])-1]='\0';
      qpal++;
   }
   fclose(arqpal);
}

//---------------------------------------------
void sorteia(){
  char vog[6]="AEIOU";
  char con[22]="BCDFGHJKLMNPQRSTVXWYZ";
  int cont=1;
  //A=65   Z=90
    for (int x=0; x<tam; x++){ 
        for (int y=0; y<tam; y++){
            if (cont==1 || cont==3){ 
                pal[x][y]=vog[rand()%5];

            }else{
                 pal[x][y]=con[rand()%21];
                } 

            cont++;
            if (cont>3){
                    cont=1;
            }  
        }      
  }
    
}
//---------------------------------------------
void mostra(){
  for (int x=0; x<tam; x++){
     for (int y=0; y<tam; y++)
        printf("%c ",pal[x][y]);
     printf("\n");   
  }   
}

//---------------------------------------------

void mostraPalavras(){
for (int x=0; x<qpal; x++){
     printf("%s\n",palavras[x]);
  }    
  system("pause");
}

//--------------------------------------------

void SorteiaDLC(){
  	  
   aux=(rand()%3);
    colum=(rand()%24);
     row=(rand()%24);
      tamP=strlen(palavrasorteada);
   
   
	if(aux==0){
		strcpy(direction,"cima");
	
		}else if(aux==1){
			strcpy(direction,"direita");
			
				}else if(aux==2){
	     			strcpy(direction,"baixo");
	     			
						}else{
							 strcpy(direction,"esquerda");
	                         }
	
	
	if((aux==0)&&(tamP>row)){
	  row=(rand()%24);
	
		}else if((aux==2)&&((tamP+row)>24)){
		          row=(rand()%24);
		          
				  }else if((aux==1)&&((tamP+colum)>24)){
                       	 colum=(rand()%24);
                        
                         	}else if((aux==3)&&((tamP-colum)<0)){	
                              colum=(rand()%24);
	                             }	
	
    printf("Tamanho da palavra: %i, Direção:%s, Coluna:%i Linha:%i  \n\n\n",tamP, direction, colum, row);
	
}	
//--------------------------------------------------------

void ColocaPalavra(){
    int y=0,x=0;

    if (strcmp(direction, "cima") == 0) {
            x=row;

                while(y<tamP){
                    pal[x][colum]=palavrasorteada[y];
                    x--;
                    y++;
                }
            
            }else if (strcmp(direction, "baixo") == 0) {
                x=row;
                    
                    while(y<tamP){
                        pal[x][colum]=palavrasorteada[y];
                        x++;
                        y++;
                    }
                }else if (strcmp(direction, "direita") == 0) {
                    x=colum;
                
                        while(y<tamP){
                            pal[row][x]=palavrasorteada[y];
                            x++;
                            y++;
                        }
                    }else if (strcmp(direction, "esquerda") == 0) {
                            x=colum;
                        
                            while(y<tamP){
                                pal[row][x]=palavrasorteada[y];
                                x--;
                                y++;
                            }
                        }
         	 
}

	
//-----------------------------------------------------------------------		        
	        
void perguntaPalavra(){

	 printf("Qual palavra você encontrou?");
	 gets(palEscolhida);
     tamPES=strlen(palEscolhida);
     
     for(int i=0; i<tamPES; i++) {
        palEscolhida[i] = toupper(palEscolhida[i]);
    }
	   printf("%s",palEscolhida);	
}	
//-----------------------------------------------------------------------		        

void rastreia(){
  char rev_aux[tamPES];
  int linha,coluna;

  //fazer isso enquanto cont=2 ou palavra encontrada
  
  for(linha=0;linha==24;linha ++){   //procura para direita
        for(coluna=0;coluna==24;coluna ++){
            str1[coluna]=pal[linha][coluna];//coloca uma linha dentro de uma big string
        }

        char *aux=strstr(str1,palEscolhida);//confirma se a sub string palEscolhida está na big string.
        if (aux!=NULL){
            printf("Palavra escolhida");
            system("pause");
        }

          // se não estiver em nenhuma linha:
    }   if (linha==24 && aux==NULL){//inverte palavra

            for(int z=tamPES; z==0; z--){  //guarda a palavra escolhida em um aux.
                rev_aux[tamPES-z]=palEscolhida[z];
            }
             for(int y=0; y==tamPES; y++){ //inverte a palavra para fazer o esquema inverso.
                palEscolhida[y]=rev_aux[tamPES-y];
             } 

             linha=0;
        }


}