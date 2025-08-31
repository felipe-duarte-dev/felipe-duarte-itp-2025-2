#include <stdio.h> // Inclui biblioca stdio.h (Entrada e Saída)

int main() { // Função principal do código

    int numero1, numero2; // Declaração das variáveis do tipo int

    printf("Digite o primeiro numero (inteiro):\n"); // Imprime texto de instrução para o usuário
    scanf("%d", &numero1); // Leitura da entrada do usuário
    printf("Digite o segundo numero (inteiro):\n"); // Imprime texto de instrução para o usuário
    scanf("%d", &numero2); // Leitura da entrada do usuário

    printf("O resultado da soma entre %d e %d: %d\n", numero1, numero2, numero1 + numero2); // Soma as duas variáveis
    printf("O resultado da diferenca entre %d e %d: %d\n", numero1, numero2, numero1 - numero2); // Subtrai a primeira variável pela segunda
    printf("O resultado do produto entre %d e %d: %d\n", numero1, numero2, numero1 * numero2); // Multiplica as variáveis
    printf("O resultado da divisao entre %d e %d: %.2f\n", numero1, numero2, (float)numero1 / numero2); // Divide a primeira variável pela segunda, utilizei Casting para o resultado da divisão ser um float
    printf("O resto da divisao entre %d e %d: %d\n", numero1, numero2, numero1 % numero2); // Mostra o resto da divisão entre a primeira variável pela segunda
    printf("A media aritmetica entre %d e %d: %.2f\n", numero1, numero2, (float)(numero1 + numero2) / 2); // Mostra a média aritmética entre as duas variáveis, utilizei Casting novamente para o resultado ser um float


    return 0; // Retorna 0
}