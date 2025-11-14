#include <stdio.h>

int main() {

    int i, j, num_pilotos, maior_ultrapassagem = -21, empate = 0, melhor_piloto = 0;

    printf("Digite o numero de pilotos na corrida: \n");
    scanf("%d", &num_pilotos); // Lê e armazena o número de pilotos na corrida

    int inicio[num_pilotos]; 
    int fim[num_pilotos];
    int ultrapassagens[num_pilotos];

    for (int i = 0; i < num_pilotos; i++) { // Laço de repetição para construir o vetor com a posição inicial dos pilotos
        int piloto;
        scanf("%d", &piloto);
        inicio[i] = piloto;
    }

    for (int i = 0; i < num_pilotos; i++) { // Laço de repetição para construir o vetor com a posição final dos pilotos
        int piloto;
        scanf("%d", &piloto);
        fim[i] = piloto;
    }

    for (i = 0; i < num_pilotos; i++) { // Laço de repetição aninhada para verificação das ultrapassagens
        int auxiliar = 0;

        for (j = 0; j < num_pilotos; j++) { 

            if (inicio[i] == fim[j]) { // Localiza a posição inicial do piloto com a posição final
                auxiliar = i - j; // Calcula o número de ultrapassagens daquele piloto

                ultrapassagens[i] = auxiliar; // Armazena o número de ultrapassagens de cada piloto em um vetor

                if (auxiliar > maior_ultrapassagem) { // Verifica se o número de ultrapassagens atual é maior que o maior número de ultrapassagens global
                    maior_ultrapassagem = auxiliar; // Atualiza a variável com o novo maior valor
                    melhor_piloto = inicio[i]; // Armazena o número do piloto detentor do maior número de ultrapassagens
                }
            }
        }
    }

    for (i = 0; i < num_pilotos; i++) { // Verifica se o maior número de ultrapassagens é único

        if (maior_ultrapassagem == ultrapassagens[i]) // Caso seja único o valor da variável empates será 1
            empate++;
    }

    if (maior_ultrapassagem > 0 && empate > 1) { // Caso o valor da variável empate seja maior que 1 então temos um empate
        printf("Empate!");
    } else {
        printf("O piloto com mais ultrapassagens foi: %d", melhor_piloto);
    }

    return 0;
}