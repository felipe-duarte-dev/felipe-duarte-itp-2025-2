#include <stdio.h> // Inclui biblioca stdio.h (Entrada e Saída)
#include <math.h> // Inclui biblioteca math.h para utilizar a função pow()

int main() { // Função principal do código

    float peso, altura, imc; // Declaração de variáveis de peso, altura e imc do tipo float (Números reais)

    printf("Digite o seu peso em quilogramas:\n"); // Texto de instrução ao usuário
    scanf("%f", &peso); // Leitura da entrada do usuário, atribuindo o valor para a variável peso
    printf("Digite a sua altura em metros:\n"); // Texto de instrução ao usuário
    scanf("%f", &altura); // Leitura da entrada do usuário, atribuindo o valor para a variável altura

    imc = peso / (pow(altura, 2)); // Cálculo do IMC

    printf("O seu IMC (Indice de Massa Corporal) e: %.2f\n", imc); // Imprime na tela o resultado do IMC, com duas casas decimais de aproximação

    return 0; // Retorna 0
}