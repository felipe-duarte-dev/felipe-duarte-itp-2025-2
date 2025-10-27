#include <stdio.h>

int main() { // Função principal do código

    int num_sorteados, num_apostas, acertos = 0; 
    int sorteados[30]; // Vetor que armazena os números sorteados
    int apostados[50]; // Vetor que armazena os números apostados

    printf("Digite o numero de numeros sorteados e de apostados: \n");
    scanf("%d %d", &num_sorteados, &num_apostas);

    for (int i = 0; i < num_sorteados; i++) { // Laço de repetição para a leitura dos números sorteados
        int numero;
        scanf("%d", &numero);
        sorteados[i] = numero;
    }

    for (int i = 0; i < num_apostas; i++) { // Laço de repetição para a leitura dos números apostados
        int numero;
        scanf("%d", &numero);
        apostados[i] = numero;
    }

    for (int i = 0; i < num_sorteados; i++) { // Laço de repetição para verificação do número de acertos
        for (int j = 0; j < num_apostas; j++) {
            if (apostados[j] == sorteados[i]) { // Verifica se o elemento de índice j do vetor dos números apostados é igual ao elemento de índice i dos sorteados
                acertos++; // Caso a igualdade seja verdadeira então é contabilizado um acerto
            }
        }
    }

    printf("O numero de acertos foi: %d", acertos);

    return 0;

}