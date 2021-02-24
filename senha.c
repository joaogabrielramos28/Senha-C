#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 4

int main(void){
    int senha[TAM],i, senha_inserida[TAM], j;
    srand(time(NULL));
    for(i=0;i<TAM;i++){
        senha[i]=rand() % 7;
    }
    printf("senha:****\n");
    
    /*Recebe a tentativa do usuario*/
    scanf("%d%d%d%d", &senha_inserida[0], &senha_inserida[1], &senha_inserida[2], &senha_inserida[3]);
    for (j=0; j<TAM; j++){
        if (senha_inserida[j] == senha[j]){
            /*Verificar se o caracter está na senha e na posição correta*/
        } else if ((senha_inserida[j] == senha[0]) || 
        (senha_inserida[j] == senha[1]) || 
        (senha_inserida[j] == senha[2]) || 
        (senha_inserida[j] == senha[3]) ){
            /*Verifica se o caracter está na senha, porém na posição incorreta*/
        }
    }
    return 0;
}