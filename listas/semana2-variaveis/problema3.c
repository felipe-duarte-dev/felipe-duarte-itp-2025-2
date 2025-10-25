#include <stdio.h> // Inclui biblioca stdio.h (Entrada e Saída)
#include <math.h> // Inclui biblioteca math.h para utilizar a função pow()

int main() { // Função principal do código

    float montante, capital, taxa_juros; // Declaração das variáveis do tipo float
    int tempo; // Declaração das variáveis do tipo int

    printf("Digite o capital inicial:\n"); // Imprime texto de instrução para o usuário
    scanf("%f", &capital); // Leitura da entrada do usuário
    printf("Digite a taxa de juros em porcentagem:\n"); // Imprime texto de instrução para o usuário
    scanf("%f", &taxa_juros); // Leitura da entrada do usuário
    printf("Digite o periodo de tempo em anos:\n"); // Imprime texto de instrução para o usuário
    scanf("%d", &tempo); // Leitura da entrada do usuário

    taxa_juros = taxa_juros / 100.0; // Calcula previamente a taxa de juros para decimais, garantindo mais precisão no cálculo final
    montante = capital * pow((1 + taxa_juros), tempo); // Cálculo do montante utilizando a fórmula padrão de juros compostos

    printf("O montante final: %.2f\n", montante); // Imprime o montante
    printf("O total de juros a ser pago: %.2f\n", montante - capital); // Imprime os juros

    return 0; // Retorna 0
}