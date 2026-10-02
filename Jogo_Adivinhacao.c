#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 3

void main() {

    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;
    //Use quando for usar o While int tentativas = 1;
    double pontos = 1000;
    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    int numero_secreto = numero_grande % 100;
    int nivel;
    int total_de_tentativas;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%i", &nivel);

    switch(nivel) {
        case 1:
            total_de_tentativas = 20;
            break;
        case 2:
            total_de_tentativas = 15;
            break;
        case 3:
            total_de_tentativas = 6;
            break;
    }

    for(int i = 1; i <= total_de_tentativas; i ++) {
        printf("Tentativa %i de %i\n", i,total_de_tentativas);
        printf("Qual vai ser o seu %i° chute ? ", i);
        scanf("%i", &chute);
        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }
        printf("Seu %i° chute foi %i\n", i ,chute);

        int acertou = chute == numero_secreto;
        int maior = chute > numero_secreto;

        double pontos_perdidos = abs((double)chute - (double)numero_secreto) / 2.0;
        pontos = pontos - pontos_perdidos;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            break;
        }else if(maior){
            printf("Seu chute foi maior do que o número secreto!\n");
        }else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }
    }

    printf("Fim do Jogo!\n");
    printf("Você fez %.2f pontos\n", pontos);
    printf("Obrigado por jogar!\n");


}
