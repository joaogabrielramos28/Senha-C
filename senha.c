#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TAM 4

int main(){
    char senha[TAM],senha_inserida[TAM];
    int i,j,tentativa;
    
    senha[0] = 0;
    senha[1] = 0;
    senha[2] = 0;
    senha[3] = 0;
    senha[4] = '\0';
    for ( i = 0; i < 4; i++ )
        {
            srand( (unsigned int) time( NULL ) );
            senha[i] = ( rand() % (7) ) + 48;

            
            for ( j = 0; senha[j] !='\0'; j++ )
            {
                if ( ( senha[j] == senha[i] ) && ( i != j ) )
                {
                    i--;
                    break;
                }
            }

        }printf("%s\n\n",senha);
        
        for(tentativa = 1 ; tentativa < 15 ; tentativa++){
            
            
            
            printf("Tentativa numero %d\n",tentativa);
            
            printf("Digite sua tentativa de 4 digitos\n");
            fflush(stdin);
            scanf("%s",senha_inserida);
            
          
            
            
                
                  if(senha_inserida[0] == senha[0] && senha_inserida[1] == senha[1] && senha_inserida[2] == senha[2] && senha_inserida[3] == senha[3]){
                      printf("Ganhou, parabens!!\n");
                      break;
                      
                      
                  }else if(senha[0] == senha_inserida[0] && senha[1] == senha_inserida[1] && senha[2]==senha_inserida[2]){
                      printf("%c esta na posicao correta\n",senha_inserida[0]);
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                  }
                  else if(senha[0] == senha_inserida[0] && senha[1] == senha_inserida[1]){
                       printf("%c esta na posicao correta\n",senha_inserida[0]);
                       printf("%c esta na posicao correta\n",senha_inserida[1]);
                  }
                  else if(senha[0] == senha_inserida[0] && senha[2] == senha_inserida[2]){
                       printf("%c esta na posicao correta\n",senha_inserida[2]);
                       printf("%c esta na posicao correta\n",senha_inserida[0]);
                  }
                  else if(senha[0] == senha_inserida[0] && senha[3] == senha_inserida[3]){
                       printf("%c esta na posicao correta\n",senha_inserida[0]);
                       printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  else if(senha[1] == senha_inserida[1] && senha[3] == senha_inserida[3] && senha[2]==senha_inserida[2]){
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  else if(senha[1] == senha_inserida[1] && senha[2]==senha_inserida[2]){
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                  }
                  else if(senha[1] == senha_inserida[1] && senha[3] == senha_inserida[3]){
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  else if(senha[0] == senha_inserida[0] && senha[2] == senha_inserida[2] && senha[3] == senha_inserida[3]){
                    printf("%c esta na posicao correta\n",senha_inserida[0]);
                    printf("%c esta na posicao correta\n",senha_inserida[2]);
                    printf("%c esta na posicao correta\n",senha_inserida[3]);
                  } 
                  
                  else if(senha[0] == senha_inserida[0] && senha[1] == senha_inserida[1] && senha[3] == senha_inserida[3]){
                      printf("%c esta na posicao correta\n",senha_inserida[0]);
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                    }
                  else if(senha[0] == senha_inserida[0] && senha[2] == senha_inserida[2] && senha[3] == senha_inserida[3]){
                      printf("%c esta na posicao correta\n",senha_inserida[0]);
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  
                  else if(senha[3] == senha_inserida[3] && senha[2] == senha_inserida[2]){
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  else if(senha[0] == senha_inserida[0]){
                      printf("%c esta na posicao correta\n",senha_inserida[0]);
                  }
                  else if(senha[1] == senha_inserida[1]){
                      printf("%c esta na posicao correta\n",senha_inserida[1]);
                  }
                  else if(senha[2] == senha_inserida[2]){
                      printf("%c esta na posicao correta\n",senha_inserida[2]);
                  }
                  else if(senha[3] == senha_inserida[3]){
                      printf("%c esta na posicao correta\n",senha_inserida[3]);
                  }
                  
                  else{
                      for(j = 0; j < TAM ;j++){
                          if(senha[j] == senha_inserida[0] ||
                          senha[j] == senha_inserida[1] ||
                          senha[j] == senha_inserida[2]||
                          senha[j] == senha_inserida[3]){
                              
                            printf("%c esta na posicao incorreta, mas esta na senha\n",senha[j]);
                          }
                      }
                  }
                  
                  
                  
        }
                  
                
               
               printf("Fim de jogo! \n\n");
        
    
    return 0;
}






