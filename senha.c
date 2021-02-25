#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define TAM 4

int main(void)
{
    int senha[TAM],senha_inserida[TAM];
    int i, j, k, tentativa, flag, pos_certa, pos_errada = 0;
    srand((unsigned)time(NULL));

    /* Zerando vetores */
    senha[0] = 0;
    senha_inserida[0] = 0;
    senha[1] = 0;
    senha_inserida[1] = 0;
    senha[2] = 0;
    senha_inserida[2] = 0;
    senha[3] = 0;
    senha_inserida[3] = 0;

    /*Gerador de senha*/
    for (i = 0; i < 4; i++)
    {
        srand((unsigned int)time(NULL));
        senha[i] = (rand() % (7));
        for (j = 0; senha[j] < 4; j++)
        {
            if ((senha[j] == senha[i]) && (i != j))
            {
                i--;
                break;
            }
        }
    }
    printf("%d%d%d%d\n", senha[0], senha[1], senha[2], senha[3]);
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
        scanf("%d%d%d%d\n", &senha_inserida[0], &senha_inserida[1], &senha_inserida[2], &senha_inserida[3]);
        for (k = 0; k < TAM; k++)
        {
            /*Verificar se o caracter está na senha e na posição correta*/
            if (senha_inserida[k] == senha[k])
            {  
                printf("%d esta na posicao correta\n",senha_inserida[k]);
                pos_certa += 1;
            }
            /*Verifica se o caracter está na senha, porém na posição incorreta*/
            else if((senha_inserida[k] == senha[0]) ||
                    (senha_inserida[k] == senha[1]) ||
                    (senha_inserida[k] == senha[2]) ||
                    (senha_inserida[k] == senha[3]))
            {
                printf("%d esta na posicao incorreta, mas esta na senha\n",senha_inserida[k]);
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
        pos_certa = 0;
        pos_errada = 0;
        tentativa++;
    } 
    return 0;
}
