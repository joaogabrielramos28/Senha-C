#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define TAM 4

int main(void)
{
        
        char senha[TAM],senha_inserida[TAM];
        int i, j, tentativa, flag = 0;
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
            senha[i] = (rand() % (7)) + 48;

            for (j = 0; senha[j] != '\0'; j++)
            {
                if ((senha[j] == senha[i]) && (i != j) && (flag == 0))
                {
                    i--;
                    break;
                }
            }
        }
        printf("%s\n", senha);
    printf("senha:****\n");

/*Recebe a tentativa do usuario*/
    scanf("%s\n",senha_inserida);
    for (j = 0; j < TAM; j++)
    {
        


        if (senha_inserida[j] == senha[j])
        {
            
            /*Verificar se o caracter está na senha e na posição correta*/
        }
        else if ((senha_inserida[j] == senha[0]) ||
                (senha_inserida[j] == senha[1]) ||
                (senha_inserida[j] == senha[2]) ||
                (senha_inserida[j] == senha[3]))
        {
            printf("%s esta na posicao correta \n",senha_inserida[j]);
        }

           
        
            /*Verifica se o caracter está na senha, porém na posição incorreta*/
        
        return 0;
    }

}
