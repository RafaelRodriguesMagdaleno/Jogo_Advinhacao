#include <stdio.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int chute;

    printf("Qual vai ser o seu chute? ");
    scanf("%i", &chute);
    printf("Você chutou o número %i", chute);
}
