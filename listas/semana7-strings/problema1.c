#include <stdio.h>

int main() { // Função principal do código

    char campo[20]; // Vetor (Cadeia de caracteres) que contém a string
    int indice, bombas = 0;

    printf("Digite o campo minado: \n");
    scanf("%s", campo);
    printf("Digite o indice: \n");
    scanf("%d", &indice);

    if (campo[indice] == 'x') { // Condição que verifica se há uma bomba no índice escolhido
        printf("bum!\n");
    } else { // Caso não haja uma bomba se parte para a verificação das adjacências
        if (indice != 19) // Verifica se o último digito foi escolhido
            if (campo[indice + 1] == 'x') { // Caso não tenha, então o programa verifica o índice de posição +1 ao índice escolhido
                bombas += 1; // Caso haja uma bomba no índice ele contabiliza +1 na variável bombas
        } 
        if (indice != 0) { // O mesmo funciona para esse caso, só que para o início do vetor
            if (campo[indice - 1] == 'x') {
                bombas += 1;
            }
        }

        printf("%d", bombas); // Mostra a quantidade de bombas existentes nas adjacências (no máximo duas)
    }

    return 0; 
}