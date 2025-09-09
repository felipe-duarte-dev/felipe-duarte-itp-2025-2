#include <stdio.h> // Inclui a biblioteca stdio.h
#include <string.h> // Inclui a biblioteca string.h

int main() { // Função principal do código

    char oponente1[10], oponente2[10]; // Declara variáveis do tipo caractere, as varíaveis na verdade serão strings, um array de caracteres

    printf("Digite a sua jogada oponente 1:\n"); // Pergunta a jogada do oponente 1
    scanf("%s", oponente1); // Lê e armazena a jogada do oponente 1
    printf("Digite a sua jogada oponente 2:\n"); // Pergunta a jogada do oponente 2
    scanf("%s", oponente2); // Lê e armazena a jogada do oponente 2

    if (strcmp(oponente1, "Pedra") != 0 && strcmp(oponente1, "Papel") != 0 && strcmp(oponente1, "Tesoura") != 0) { // Verifica se a jogada do oponente 1 é válida
        printf("Jogo invalidado"); // Exibe a mensagem de jogo invalidado caso a jogada seja inválida
    } else if (strcmp(oponente2, "Pedra") != 0 && strcmp(oponente2, "Papel") != 0 && strcmp(oponente2, "Tesoura")) { // Verifica se a jogada do oponente 2 é válida
        printf("Jogo invalidado"); // Exibe a mensagem de jogo invalidado caso a jogada seja inválida
    } else if (strcmp(oponente1, oponente2) == 0) { // Verifica se as jogadas são iguais, caso seja o resultado é empate
        printf("Empate\n"); // Exibe mensagem de empate
    } else if (strcmp(oponente1, "Pedra") == 0) { // Verifica se o oponente 1 jogou pedra
        if (strcmp(oponente2, "Tesoura") == 0) { // Verifica se o oponente 2 jogou tesoura
            printf("Oponente 1 ganhou!\n"); // Mostra o vencedor com base nas regras do jogo
        } else if (strcmp(oponente2, "Papel") == 0) { // Verifica a jogada do oponente 2
            printf("Oponente 2 ganhou!\n"); // Mostra o vencedor com base nas regras do jogo
        }
    } else if (strcmp(oponente1, "Papel") == 0) { // Daqui para o último else if o código funciona da mesma forma que na explicação acima
        if (strcmp(oponente2, "Pedra") == 0) { 
            printf("Oponente 1 ganhou!\n");
        } else if (strcmp(oponente2, "Tesoura") == 0) {
            printf("Oponente 2 ganhou!\n");
        }
    } else if (strcmp(oponente1, "Tesoura") == 0) { 
        if (strcmp(oponente2, "Papel") == 0) {
            printf("Oponente 1 ganhou!\n");
        } else if (strcmp(oponente2, "Pedra") == 0) {
            printf("Oponente 2 ganhou!\n");
        }
    }

    return 0;
}