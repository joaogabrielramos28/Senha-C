#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

int main(void)
{
    char senha[TAM],senha_inserida[TAM];
    int i, j, k, tentativa, pos_certa, pos_errada = 0;
    srand((unsigned)time(NULL));

    /*Gerador de senha*/
    for (i = 0; i < 4; i++)
    {
        srand((unsigned int)time(NULL));
        senha[i] = ( (rand() % (7)) + 48 );
        for (j = 0; senha[j] != '\0'; j++)
        {
            if ((senha[j] == senha[i]) && (i != j))
            {
                i--;
                break;
            }
        }
    }
    printf("%s\n", senha);
    printf("senha:****\n");

    tentativa = 0;
    pos_certa = 0;
    pos_errada = 0;
    /*Ciclo de jogo em 15 tentativas*/
    while(tentativa < 16)
    {   
        printf("Voce tem %d tentativas\n", (15-tentativa));
        printf("Digite sua tentativa: \n");
        /*Recebe a tentativa do usuario*/
        scanf("%s", senha_inserida);
        for (k = 0; senha_inserida[k] != '\0'; k++)
        {   
            /*Verificar se o caracter está na senha e na posição correta*/
            if (senha_inserida[k] == senha[k])
            {  
                pos_certa += 1;
            }
            /*Verifica se o caracter está na senha, porém na posição incorreta*/
            else if((senha_inserida[k] == senha[0]) ||
                    (senha_inserida[k] == senha[1]) ||
                    (senha_inserida[k] == senha[2]) ||
                    (senha_inserida[k] == senha[3]))
            {
                pos_errada += 1;
            }
            /*Caso onde o usuário não acertou nenhum caracter da senha, mesmo fora de ordem*/
            else if((k == 3) && (pos_certa == 0) && (pos_errada == 0))
            {
                printf("Nenhum dos caracteres inseridos esta na senha\n");
            }
            /*Caso onde todos os caracteres foram inseridos na posição correta*/
            if (pos_certa == 4)
            {
                printf("Parabens voce acertou a senha!");
                return 1;
            }
        } 
        /*Aqui mostramos a quantidade de algarismos que estão na posição certa, na tentativa atual.*/
        if( (pos_certa > 0) && (pos_certa > 1) ){
            printf("ha %d algarismos da senha nas posicoes corretas\n", pos_certa);
        } else if( pos_certa > 0 ) {
            printf("ha %d algarismo da senha na posicao correta\n", pos_certa);
        }
        /*Aqui mostramos a quantidade de algarismos que está na senha, mas na posição errada, na tentativa atual*/
        if( (pos_errada > 0) && (pos_errada > 1) ){ 
            printf("ha %d algarismos que esta na senha, porem em outras posicoes\n", pos_errada);
        } else if ( pos_errada > 0 ){
            printf("ha %d algarismo que esta na senha, porem em outra posicao\n", pos_errada);
        }
        pos_certa = 0;
        pos_errada = 0;
        tentativa++;
    } 
    return 0;
}
