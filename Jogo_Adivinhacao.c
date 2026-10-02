#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;
    int numero_secreto = 42;

    for(int i = 1; i <= 3; i ++) {
        printf("Qual vai ser o seu chute ? ");
        scanf("%i", &chute);
        printf("Seu chute foi %i\n", chute);

        int acertou = chute == numero_secreto;

        if(acertou) {

            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");

        }else {

            int maior = chute > numero_secreto;

            printf("Você errou!\n");

            if(maior) {

                printf("Seu chute foi maior do que o número secreto!\n");

            }else {

                printf("Seu chute foi menor do que o número secreto!\n");

            }

            printf("Mas não desanime! Tente novamente!\n");

        }
    }

    printf("Fim do Jogo!\n");


}
