#include <stdio.h>
#include <locale.h>
#define NUMERO_DE_TENTATIVAS 3

void main() {
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;
    int numero_secreto = 42;
    int tentativas = 1;

    while(1) {
        printf("Qual vai ser o seu %i° chute ? ", tentativas);
        scanf("%i", &chute);
        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            continue;
        }
        printf("Seu %i° chute foi %i\n", tentativas ,chute);

        int acertou = chute == numero_secreto;
        int maior = chute > numero_secreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            break;
        }else if(maior){
            printf("Seu chute foi maior do que o número secreto!\n");
        }else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        tentativas ++;
    }

    printf("Fim do Jogo!\n");
    printf("Obrigado por jogar!\n");


}
