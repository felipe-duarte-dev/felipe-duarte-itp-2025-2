#include <stdio.h>
#include <stdlib.h>

int * buscaNoVetor(int *v, int n, int valor, int *qtd) { // Função que vai realizar busca no vetor
    *qtd = 0;

    for (int i = 0; i < n; i++) { // Verifica o número de ocorrências do valor no vetor 
        if (v[i] == valor) {
            (*qtd)++;
        }
    }

    if (*qtd == 0) { // Retorna nulo caso o número de ocorrências de valor no vetor seja 0
        return NULL;
    }

    int *indices = malloc((*qtd) * sizeof(int)); // Aloca dinamicamente o vetor que vai armazenar os índices encontrados

    int j = 0;

    for (int i = 0; i < n; i++) { // Faz uma varredura no vetor para verificar os índices de ocorrência do valor no vetor
        if (v[i] == valor) {
            indices[j++] = i;
        }
    }

    return indices; // Retorna o vetor com os índices encontrados
}

int main() {

    int i, n, valor, qtd;
    scanf("%d", &n); // Lê e armazena o número de posições do vetor

    int *vetor = malloc(n * sizeof(int)); // Aloca o vetor dinamicamente

    for (i = 0; i < n; i++) { // For para lê e armazenar os valore no vetor
        int temp;
        scanf("%d", &temp);
        vetor[i] = temp;
    }

    scanf("%d", &valor); // Lê e armazena o valor para verificação de ocorrências

    int *indices = buscaNoVetor(vetor, n, valor, &qtd); // Chama a função para busca no vetor

    if (indices == NULL) { // Caso a função retorne NULL é imprimido na tela a mensagem de nenhuma ocorrência
        printf("Nenhuma ocorrencia\n"); 
    } else { // Caso a função retorne um valor não nulo é imprimido o número de ocorrências com os respectivos valores de índice
        printf("%d\n", qtd);

        for (i = 0; i < qtd; i++) {
            printf("%d ", indices[i]);
        }
        printf("\n");

        free(indices); // Libera a memória alocada pra o vetor índices
    }

    free(vetor);  // Libera a memória alocada para o vetor inicial

    return 0;
}