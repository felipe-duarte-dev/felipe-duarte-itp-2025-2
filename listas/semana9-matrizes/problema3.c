#include <stdio.h>

int main() { // Função principal do código

    int matriz, i, j, empates = 0; 

    printf("Digite o numero de times participantes: \n");
    scanf("%d", &matriz); 

    int campeonato[matriz][matriz]; // Inicializa a matriz quadrada

    for (i = 0; i < matriz; i++) { // Estrutura de repetição aninhada para construção da matriz
        for (j = 0; j < matriz; j++) {
            scanf("%d", &campeonato[i][j]);
        }
    }

    for (i = 0; i < matriz; i++) { // Varredura na matriz para encontrar empates
        for (j = 0; j < matriz; j++) {
            if (campeonato[i][j] == campeonato[j][i]) // Verifica se a partida entre i e j foi um empate
                empates++; // Em caso afirmativo a variável empates é incrementada
        }
    }

    printf("Houveram %d empates", empates / 2); // A variável deve ser dividida por 2 devido a varredura contabilizar o mesmo empate duas vezes

    return 0;
}