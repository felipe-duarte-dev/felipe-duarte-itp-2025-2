#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int n) { // Função para alocação dinâmica de um vetor

    return malloc(n * sizeof(int)); // Retorna o vetor alocado dinamicamente
}

int *somaVetores(int n1, int n2, int *vetor_um, int *vetor_dois) { // Função para soma de dois vetores

    if (n1 != n2) { // Verifica se os vetores possuem dimensões diferentes
        return 0;
    }

    int *vetor_resultado = malloc(n1 * sizeof(int)); // Declara e inicializa um vetor com alocação dinâmica

    for (int i = 0; i < n1; i++) { // Soma os elementos de mesmo índice dos vetores um e dois
        vetor_resultado[i] = vetor_um[i] + vetor_dois[i];
    }

    free(vetor_um); // Libera a memória do vetor 1
    free(vetor_dois); // Libera a memória do vetor 2

    return vetor_resultado; // Retorna o vetor resultado
}   

int main() {

    int n1, n2, i, *u, *v;

    scanf("%d %d", &n1, &n2); // Lê a dimensão dos dois vetores

    u = alocarVetor(n1); // Aloca dinamicamente o vetor u
    v = alocarVetor(n2); // Aloca dinamicamente o vetor u

    for (i = 0; i < n1; i++) { // Lê os elementos do vetor u
        int temp;
        scanf("%d", &temp);
        u[i] = temp;
    }

    for (i = 0; i < n2; i++) { // Lê os elementos do vetor u
        int temp;
        scanf("%d", &temp);
        v[i] = temp;
    }

    int *vetor_resultado = somaVetores(n1, n2, u, v); // Declara e inicializa o vetor resultado

    if (vetor_resultado == 0) { // Verifica se as dimensões são compatíveis com base na saída da função somaVetores
        printf("Dimensoes incompativeis");
    } else { // Caso eles sejam compatíveis exibe os elementos do vetor um a um
        for (i = 0; i < n1; i++) {
            printf("%d ", vetor_resultado[i]);
        }
        printf("\n");
        free(vetor_resultado); // Libera a memória do vetor resultante
    }

    return 0;
}