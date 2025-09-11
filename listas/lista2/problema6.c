#include <stdio.h> // Inclui biblioteca stdio.h

int main() { // Função principal do código

    char febre, dor_cabeca, dor_corpo, tosse; // Declaração de variáveis do tipo caractere

    printf("Voce sente febre? (S/N)\n"); // Instrução para o usuário
    scanf(" %c", &febre); // Lê e armazena resposta do usuário
    printf("Voce sente dor de cabeca? (S/N)\n");
    scanf(" %c", &dor_cabeca);
    printf("Voce sente dor no corpo? (S/N)\n");
    scanf(" %c", &dor_corpo);
    printf("Voce tosse com frequencia? (S/N)\n");
    scanf(" %c", &tosse);

    if (febre == 'S' && dor_cabeca == 'S' && dor_corpo == 'S' && tosse == 'N') { // Condicional responsável por conferir os sintomas
        printf("Possivel gripe \n"); // Imprime a possível doença com base nos sintomas
    } else if (febre == 'S' && dor_cabeca == 'N' && dor_corpo == 'N' && tosse == 'S') {
        printf("Possivel resfriado \n");
    } else if (febre == 'N' && dor_cabeca == 'S' && dor_corpo == 'N' && tosse == 'N') {
        printf("Possivel enxaqueca \n");
    } else if (febre == 'S' && dor_cabeca == 'N' && dor_corpo == 'N' && tosse == 'N') {
        printf("Consulte um medico \n");
    } else if (febre == 'N' && dor_cabeca == 'N' && dor_corpo == 'N' && tosse == 'N') {
        printf("Voce parece estar bem \n");
    } else {
        printf("Consulte um medico para avaliacao \n");
    }

    return 0; // Retorna 0
}

/* Optei por utilizar uma condicional tão grande pois caso eu utilizasse apenas as que são "S" teria problemas, por exemplo, caso eu escrevesse "S" para todos os sintomas
e verificasse apenas as variáveis que eu marquei "S" eu imprimiria na tela todos resultados exceto o que todos os sintomas são marcados como "N", é um conceito de lógica 
de primeira ordem e lógica proposicional
*/