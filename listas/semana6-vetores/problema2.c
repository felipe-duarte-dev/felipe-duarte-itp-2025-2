#include <stdio.h>

int main() {

    int m, n;
    printf("Digite quantas figurinhas ha no algum e quantas voce possui: \n");
    scanf("%d %d", &m, &n); // Lê o número de figurinhas do álbum e quantas o usuário possui

    int figurinhas[1001] = {0}; // Defini um vetor com 1000 elementos, todos 0

    for (int i = 0; i < n; i++) { // Laço de repetição para marcar as figurinhas que o usuário possui
        int numero; // Variável auxiliar que armazena temporariamente o número de uma figurinha possuída
        scanf("%d", &numero); // Lê essa figurinha uma a uma
        figurinhas[numero] = 1; // Altera o valor armazenado no índice da figurinha possuída, mudando para 1, para representar que ela se encontra na coleção
    }

    for (int i = 1; i <= m; i++) { // Laço de repetição que mostra as figurinhas faltantes
        if (figurinhas[i] == 0) // Condição para verificar se a figurinha está presente no álbum (1) ou não (0)
            printf("%d ", i); // Mostra o índice da figurinha que o usuário não possui
    }

    return 0; // Retorna 0, sem erros
}