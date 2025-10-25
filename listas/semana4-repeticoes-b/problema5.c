#include <stdio.h> // Inclui biblioteca de entrada e saída

int main() { // Função principal

    int n, numero_impresso = 1; // Declaração e atribuição de valores a variáveis do tipo int

    printf("Digite valor para n: \n"); // Instrução ao usuário
    scanf("%d", &n); // Lê e armazena a entrada do usuário

    for (int i = 1; i <= n; i++) { // For exterior
        for (int j = 1; j <= i; j++) { // For interior
            printf("%d ", numero_impresso); // Número impresso
            numero_impresso++; // Incremento do número a ser impresso
        }
        printf("\n"); // Pula a linha para a próxima iteração
    }

    return 0; // Retorna 0, sem erros
}