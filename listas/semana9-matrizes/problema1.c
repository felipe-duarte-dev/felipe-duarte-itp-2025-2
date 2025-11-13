#include <stdio.h>

int main() { // Função principal do código

    int linhas, colunas, i, j, irrigados = 0, nao_irrigados = 0;

    printf("Digite as medidas do campo: \n");
    scanf("%d %d", &linhas, &colunas); // Lê e armazena o número de linhas e colunas

    int campo[linhas][colunas]; // Inicializa a matriz com o número de linhas e colunas especificado

    for (i = 0; i < linhas; i++) { // Estrutura de repetição aninhada para a construção da matriz com base na entrada do usuário
        for (j = 0; j < colunas; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    
    for (i = 0; i < linhas; i++) { // Estrutura de repetição aninhada para varredura da matriz
        for (j = 0; j < colunas; j++) {
            if (campo[i][j] == 2) { // Verifica se o índice iterado da matriz é um irrigador
                if (campo[i - 1][j] == 1) { // Verifica o índice ao norte do irrigador
                    irrigados += 1; // Caso seja uma terra fértil contabiliza ela como irrigada
                    campo[i - 1][j] = 0; // Altera seu valor para zero para impossibilitar contagem duplicada nas próximas iterações da varredura
                }
                if (campo[i + 1][j] == 1) { // Verifica o índice a sul do irrigador
                    irrigados += 1;
                    campo[i + 1][j] = 0;
                }
                if (campo[i][j - 1] == 1) { // Verifica o índice a oeste do irrigador
                    irrigados += 1;
                    campo[i][j - 1] = 0;
                }
                if (campo[i][j + 1] == 1) { // Verifica o índice a leste do irrigador
                    irrigados += 1;
                    campo[i][j + 1] = 0;
                }    
            }
        }
    }

     
    for (i = 0; i < linhas; i++) { // Varredura para contabilizar o número de terras férteis não irrigadas
        for (j = 0; j < colunas; j++) {
            if (campo[i][j] == 1)
            nao_irrigados += 1;
        }
    }

    printf("%d %d", irrigados, nao_irrigados); // Mostra o número de terras férteis irrigadas e não irrigadas

    return 0;
}