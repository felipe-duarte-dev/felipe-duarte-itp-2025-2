#include <stdio.h>

int main() { // Função principal do código

    int n, controle = 0, distancia = 0, maior_altura = 0; // Variáveis do tipo inteiro
    int alturas[31] = {0}; // Vetor que vai armazenar as alturas digitadas pelo usuário

    printf("Digite o valor de n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // Laço de repetição para a leitura e armazenamento das alturas

        int altura; // Variável temporária que vai possuir o valor da altura digitada
        scanf("%d", &altura); // Lê altura
        alturas[i] = altura; // Armazena a altura no índice i do vetor
        if (altura > maior_altura) { // Condicional para armazenar o valor de altura mais alto
            maior_altura = altura;
        }
    }

    for (int i = 0; i < n; i++) { // Laço de repetição que vai percorrer o vetor e contar a distância da ponte

        if (alturas[i] == maior_altura) { // Caso o valor armazenado no índice i seja a maior altura ele vai incrementar a variável de controle em 1 unidade
            controle += 1;
        }

        if (controle == 1) { // Enquanto a variável de controle for 1 a variável que armazena a distância vai sendo incrementada
            distancia += 1;
        }
    }

    printf("A distancia da ponte e: %d", distancia - 1); // Mostra a distância -1, pois a contagem da distância considera o índice de maior altura como válido

    return 0; // Retorna 0, sem erros
}