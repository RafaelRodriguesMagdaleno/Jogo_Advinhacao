#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define PONTOS_INICIAIS 1000
#define TENTATIVAS_MODO_FACIL 20
#define TENTATIVAS_MODO_MEDIO 15
#define TENTATIVAS_MODO_DIFICIL 6

void main() {

    setlocale(LC_ALL,"Portuguese");

    //Começando o cabeçalho
   printf("\n\n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
	printf("\n\n");

	int jogar_novamente = 1;
	int escolha_jogo;

	while(jogar_novamente == 1){
        //Declarando as variáveis
        int chute;
        double pontos = PONTOS_INICIAIS;
        //Use quando for usar o While int tentativas = 1;
        int segundos = time(0);
        int intervalo_inicial;
        int intervalo_final;
        int nivel;
        int total_de_tentativas;
        int acertou = 0;


        //interação com o usuário
        printf("Digite o começo do intervalo de escolha dos números : ");
        scanf("%i", &intervalo_inicial);
        printf("Digite o número final de até aonde vai o intervalo : ");
        scanf("%i", &intervalo_final);

        srand(time(0));
        int tamanho = intervalo_final - intervalo_inicial + 1;
        int numero_secreto = intervalo_inicial + rand() % tamanho;

        printf("Qual o nível de dificuldade?\n");
        printf("(1) Fácil (2) Médio (3) Difícil\n\n");
        printf("Escolha: ");
        scanf("%i", &nivel);

        //Condições para a dificuldade
        switch(nivel) {
            case 1:
                total_de_tentativas = TENTATIVAS_MODO_FACIL;
                break;
            case 2:
                total_de_tentativas = TENTATIVAS_MODO_MEDIO;
                break;
            default:
                total_de_tentativas = TENTATIVAS_MODO_DIFICIL;
                break;

        }

        //Começou o jogo
        for(int i = 1; i<= total_de_tentativas; i++) {
            printf("Tentativa %i de %i\n", i, total_de_tentativas);
            printf("Qual vai ser o seu %i chute? ", i);
            scanf("%i", &chute);
            if(chute < 0) {
                printf("Você não pode chutar números negativos\n");
                i--;
                continue;
            }
            printf("Seu %i° chute foi %i\n", i, chute);

            acertou = chute == numero_secreto;
            int maior = chute > numero_secreto;

            double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
            pontos = pontos - pontos_perdidos;

            //Caso ele acerte o jogo
            if(acertou) {
                break;
            //Se não for o caso, o jogo continua
            }else if(maior){
                printf("Seu chute foi maior do que o número secreto!\n");
            }else{
                printf("Seu chute foi menor do que o número secreto!\n");
            }
        }

         printf("************************************\n");

        if(acertou){
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("************************************\n");
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            printf("Você fez %.2f pontos\n", pontos);
            printf("************************************\n");

        }else {
            printf("       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");
            printf("************************************\n");
            printf("Você perdeu! Tente novamente\n");

        }
        printf("Obrigado por jogar!\n");
        printf("************************************\n");
        printf("Deseja jogar novamente ? \n");
        printf("[1] - Sim [2] - Não\n");
        printf("Escolha : ");
        scanf("%i", &escolha_jogo);
        if(escolha_jogo == 1) {
            jogar_novamente = 1;
        }else {
            break;
        }
	}
}
