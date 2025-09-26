#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <stdlib.h> // Inclui biblioteca para utilizar a função de valor absoluto abs()

int main() { // Função principal do código

    int numero1, numero2, soma_div1 = 0, soma_div2 = 0; // Declaração e atribuição de valores das variáveis do tipo int

    printf("Digite o primeiro numero: \n"); // Instrução para o usuário
    scanf("%d", &numero1); // Lê e armazena os dados
    printf("Digite o segundo numero: \n");
    scanf("%d", &numero2);

    for (int i = 1; i <= numero1 / 2; i++) { // Laço for para realizar a soma dos divisores do número 1
        if (numero1 % i == 0) { // Verifica se o resto da divisão é 0, caso seja, o número i é divisor do número 1
            soma_div1 = soma_div1 + i; // Atualiza a variável da soma dos divisores
        }
    }

    for (int i = 1; i <= numero2 / 2; i++) { // Laço for para realizar a soma dos divisores do número 2
        if (numero2 % i == 0) { // Verifica se o resto da divisão é 0, caso seja, o número i é divisor do número 2
            soma_div2 = soma_div2 + i; // Atualiza a variável da soma dos divisores
        }
    }

    if (abs(soma_div1 - numero2) <= 2 && abs(soma_div2 - numero1) <= 2) { // Verifica se os valores absolutos estão dentro do intervalo inteiro [0,2]
        printf("Sao numeros colegas \n"); // Caso estejam o programa mostra que os números digitados são colegas
    } else {
        printf("Nao sao numeros colegas \n"); // Caso não estejam o programa mostra que os números digitados não são colegas
    }

     return 0; // Retorna 0, sem erros
}
