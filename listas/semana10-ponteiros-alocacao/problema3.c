#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturarLetras(char *v, char *u, int n1, int n2) { // Função que mistura as strings

    char *vetor_resultado = malloc((n1 + n2 + 1) * sizeof(char)); // Aloca dinamicamente o vetor que conterá a mescla das strings
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) { // Compara o tamanho das strings com variáveis que estão sendo incrementadas, quando a variável for igual ao tamanho da string o programa para de mesclar elas
        vetor_resultado[k++] = v[i++];
        vetor_resultado[k++] = u[j++];
    }

    while (i < n1) { // Em caso do primeiro vetor ser maior que o segundo ele continua distribuindo os caracteres para o vetor resultado
        vetor_resultado[k++] = v[i++];
    }

    while (j < n2) { // Em caso do primeiro vetor ser maior que o segundo ele continua distribuindo os caracteres para o vetor resultado
        vetor_resultado[k++] = u[j++];
    }

    vetor_resultado[k] = '\0'; // Defini o último espaço do vetor com \0 significando que o vetor chegou ao fim
    return vetor_resultado; // Retorna o vetor com a mesclagem das duas strings
}

int main() {

    char *vetor_um, *vetor_dois, frase_temp[100];

    printf("Digite a primeira frase: \n");
    fgets(frase_temp, sizeof(frase_temp), stdin); // Lê e armazena a string em uma variável temporária
    frase_temp[strcspn(frase_temp, "\n")] = 0;
    vetor_um = malloc((strlen(frase_temp) + 1) * sizeof(char)); // Aloca dinamicamente o vetor um com o tamanho da string
    strcpy(vetor_um, frase_temp); // Copia o conteúdo da variável temporária para o vetor 

    printf("Digite a segunda frase: \n");
    fgets(frase_temp, sizeof(frase_temp), stdin);
    frase_temp[strcspn(frase_temp, "\n")] = 0;
    vetor_dois = malloc((strlen(frase_temp) + 1) * sizeof(char));
    strcpy(vetor_dois, frase_temp);

    char *vetor_resultado = misturarLetras(vetor_um, vetor_dois, strlen(vetor_um), strlen(vetor_dois)); // Declara e inicializa o vetor resultao utilizando a função misturarLetras

    printf("%s", vetor_resultado); // Imprime na tela o resultado
    printf("\n");

    free(vetor_um); // Libera a memória dos vetores
    free(vetor_dois);
    free(vetor_resultado);

    return 0;
}