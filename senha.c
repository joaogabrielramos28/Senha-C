#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 4

int showrules(void);
int playgame(void);
int main_menu(void);
int show_credits(void);

int main(void) {
    /*Arte de introdução do jogo*/
    printf("      ___           ___           ___           ___           ___     \n");
    printf("     /\\  \\         /\\  \\         /\\__\\         /\\__\\         /\\  \\    \n");
    printf("    /::\\  \\       /::\\  \\       /::|  |       /:/  /        /::\\  \\   \n");
    printf("   /:/\\ \\  \\     /:/\\:\\  \\     /:|:|  |      /:/__/        /:/\\:\\  \\  \n");
    printf("  _\\:\\~\\ \\  \\   /::\\~\\:\\  \\   /:/|:|  |__   /::\\  \\ ___   /::\\~\\:\\  \\ \n");
    printf(" /\\ \\:\\ \\ \\__\\ /:/\\:\\ \\:\\__\\ /:/ |:| /\\__\\ /:/\\:\\  /\\__\\ /:/\\:\\ \\:\\__\\\n");
    printf(" \\:\\ \\:\\ \\/__/ \\:\\~\\:\\ \\/__/ \\/__|:|/:/  / \\/__\\:\\/:/  / \\/__\\:\\/:/  /\n");
    printf("  \\:\\ \\:\\__\\    \\:\\ \\:\\__\\       |:/:/  /       \\::/  /       \\::/  / \n");
    printf("   \\:\\/:/  /     \\:\\ \\/__/       |::/  /        /:/  /        /:/  /  \n");
    printf("    \\::/  /       \\:\\__\\         /:/  /        /:/  /        /:/  /   \n");
    printf("     \\/__/         \\/__/         \\/__/         \\/__/         \\/__/    \n\n");
    main_menu();
    return 0;
}

int main_menu(){
    /*Essa função trabalha como um menu principal onde o usuário escolhe dentre algumas opções no jogo*/
    int input;
    printf("---- Bem vindo ao Menu Principal ----\n\n");
    printf("1 - Jogar\n2 - Regras\n3 - Creditos\n4 - Sair\n");
    printf("\nSelecione uma opcao entre 1 e 4: ");
    scanf("%d", &input);
    if ( input == 1 ) {
        system("cls");
        playgame();
    } 
    else if ( input == 2 ) {
        system("cls");
        showrules();
    } 
    else if ( input == 3 ){
        system("cls");
        show_credits();
    } 
    else if (input == 4) {
        printf("Obrigado por jogar e Volte sempre!");
        return 0;
    }
    return 0;
}

int showrules() {
    /*Aqui mostramos as regras do jogo*/
    printf("------ Regras ------\n");
    printf("1. O jogador possui 15 tentativas de ganhar o jogo.\n");
    printf("2. Cada tentativa deve entrar com uma senha de 4 algarismos\n");
    printf("3. Se o jogador acertar a senha dentro das 15 tentativas, ele ganha o jogo.\n");
    printf("4. A cada tentativa o jogo apresentara a quantidade de caracteres que estao na senha e na posicao correta.\n");
    printf("5. A cada tentativa o jogo apresentara a quantidade de caracteres que estao na senha, mas na posicao incorreta.\n");
    printf("6. Observacao: as senhas sempre tem os 4 algarismos distintos mas o jogador pode entrar com algarismos iguais caso queira.\n\n");
    main_menu();
    return 0;
}

int playgame() {
    char senha[TAM], senha_inserida[10];
    char jogar_novamente;
    int i, j, k, tentativa, pos_certa, pos_errada, bad_input = 0;
    int senha_tam;
    srand((unsigned)time(NULL));

    system("cls");

    /*Gerador de senha*/
    printf("------ Gerando senha ------\n");
    for (i = 0; i < TAM; i++)
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
    printf("------ Senha gerada com sucesso ------\n");
    tentativa = 0;
    pos_certa = 0;
    pos_errada = 0;
    bad_input = 0;
    printf("senha:****\n");

    /*Ciclo de jogo em 15 tentativas*/
    while(tentativa < 15)
    {   
        printf("Voce tem %d tentativas\n",(15-tentativa));
        printf("Digite sua tentativa: \n");
        /*Recebe a tentativa do usuario*/
        scanf("%s", senha_inserida);
        senha_tam = strlen(senha_inserida);
        senha_inserida[TAM] = '\0';
        for (k = 0; senha_inserida[k] != '\0'; k++)
        {   
            /*Aqui verificamos se a entrada do nosso usuário é valida, ou seja, 4 algarismos de 0 a 9*/
            if ( ((senha_inserida[k] < 48) || (senha_inserida[k] > 57)) || (senha_tam != TAM) ){
                bad_input += 1;
                break;
            } else {
                /*Verificar se o caracter está na senha e na posição correta*/
                if (senha_inserida[k] == senha[k]) {  
                    pos_certa += 1;
                }
                /*Verifica se o caracter está na senha, porém na posição incorreta*/
                else if((senha_inserida[k] == senha[0]) ||
                        (senha_inserida[k] == senha[1]) ||
                        (senha_inserida[k] == senha[2]) ||
                        (senha_inserida[k] == senha[3])) {
                    pos_errada += 1;
                }
                /*Caso onde o usuário não acertou nenhum caracter da senha, mesmo fora de ordem*/
                else if((k == 3) && (pos_certa == 0) && (pos_errada == 0)) {
                    printf("Nenhum dos caracteres inseridos esta na senha\n");
                }
                /*Caso onde todos os caracteres foram inseridos na posição correta*/
                if (pos_certa == 4) {
                    printf("Parabens voce acertou a senha!\n");
                    printf("Gostaria de jogar novamente? [s/n]\n");
                    scanf(" %c", &jogar_novamente);
                    if ( jogar_novamente == 's' ) {
                        playgame();
                    } else if ( jogar_novamente == 'n' ){
                        main_menu();
                    }  
                }
            }
        } 
        if (bad_input == 0) {
            /*Aqui mostramos a quantidade de algarismos que estão na posição certa, na tentativa atual.*/
            if( (pos_certa > 0) && (pos_certa > 1) ) {
                printf("ha %d algarismos da senha nas posicoes corretas\n", pos_certa);
            } 
            else if( pos_certa > 0 ) {
                printf("ha %d algarismo da senha na posicao correta\n", pos_certa);
            }
            /*Aqui mostramos a quantidade de algarismos que está na senha, mas na posição errada, na tentativa atual*/
            if( (pos_errada > 0) && (pos_errada > 1) ) { 
                printf("ha %d algarismos que estao na senha, porem em outras posicoes\n", pos_errada);
            } 
            else if ( pos_errada > 0 ) {
                printf("ha %d algarismo que esta na senha, porem em outra posicao\n", pos_errada);
            }
            tentativa++;
        } 
        else {
            printf("esta entrada e invalida por favor insira uma entrada com 4 digitos de 0 a 9\n");
        }
        pos_certa = 0;
        pos_errada = 0;
        bad_input = 0;
    } 
    if (tentativa >= 15) { 
        senha[4] = '\0';
        printf("Voce perdeu! A senha correta era: %s\n", senha);
    }
    printf("Gostaria de jogar novamente? [s/n]\n");
    scanf(" %c", &jogar_novamente);
    if ( jogar_novamente == 's' ) {
        playgame();
    } else if ( jogar_novamente == 'n' ){
        system("cls");
        main_menu();
    }  
    return 0;
}

int show_credits(){
    /*Função que mostra os participantes do trabalho e para que foi feito.*/
    printf("------ Creditos ------\n");
    printf("\nEste e um trabalho feito para Introducao a C/C++ com o professor Andre Brito\nMembros:\nJoao Gabriel Ramos\nVinicius Alves Pavani\n\nObrigado por jogar!\n\n");
    main_menu();
    return 0;
}










