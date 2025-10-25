#include <stdio.h> // Inclui biblioteca stdio.h (Entrada e Saída)
#include <string.h> // Inclui biblioteca string.h para utilizar a função strcmp()

int main() { // Função principal do código

    char consumidor[20]; // Declara variável do tipo caractere, porém é um array de caracteres, uma string com limite de até 20 caracteres
    float consumo, conta_total; // Declara variáveis do tipo float

    printf("Digite o tipo de consumidor:\n"); // Imprime instrução para o usuário
    scanf("%s", consumidor); // Lê e armazena entrada do usuário
    printf("Digite o valor de KwH consumidos:\n"); // Imprime instrução para o usuário
    scanf("%f", &consumo); // Lê e armazena entrada do usuário

    if (strcmp(consumidor, "Residencial") == 0) { // Condicional que compara o valor da variável consumidor, utiliza a função srtcmp()
        conta_total = (consumo * 0.6) + 15; // Calcula o valor da conta total
        printf("O seu consumo esse mes foi de: R$ %.2f", conta_total); // Imprime o valor da conta total
    } else if (strcmp(consumidor, "Comercial") == 0) { // Condicional que compara o valor da variável consumidor, utiliza a função srtcmp()
        conta_total = (consumo * 0.48) + 15;
        printf("O seu consumo esse mes foi de: R$ %.2f", conta_total);
    } else if (strcmp(consumidor, "Industrial") == 0) { // Condicional que compara o valor da variável consumidor, utiliza a função srtcmp()
        conta_total = (consumo * 1.29) + 15;
        printf("O seu consumo esse mes foi de: R$ %.2f", conta_total);
    } else {
        printf("Consumidor invalido"); // Caso o valor da variável "consumidor" seja diferente das opções acima o programa exibe mensagem de consumidor inválido
    }

    return 0; // Retorna 0
}