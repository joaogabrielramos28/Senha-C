#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 4
int main(void){
    int senha[TAM],i;
    srand(time(NULL));
    for(i=0;i<TAM;i++){
        senha[i]=rand() % 7;
        
    }printf("senha:****\n");

    return 1;
}