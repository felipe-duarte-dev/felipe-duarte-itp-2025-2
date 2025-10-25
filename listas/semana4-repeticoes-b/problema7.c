#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <math.h> // Inclui biblioteca para utilizar a função matemática de raiz quadrada

int main() { // Função principal

    int a, b; // Declaração de variáveis do tipo int

    printf("Digite um numero: \n"); // Instrução para o usuário
    scanf("%d", &a); // Lê e armazena a entrada
    printf("Digite outro numero: \n");
    scanf("%d", &b);

    if (a < b) { // Verifica se o primeiro número digitado é menor que o segundo
        for (int i = a; i <= b; i++) { // Laço de repetição que vai atuar dentro do intervalo [a,b]
            int primo = 1; // Declaração e atribuição de valor a uma variável de controle
            if (i <= 1) { // 1 não é primo
                primo = 0; // Defini a variável de controle para 0 (Falso)
            } else { // Caso i seja diferente de 1
                for (int j = 2; j <= sqrt(i); j++) { // Laço de repetição para realizar as divisões do i, indo de 2 até a raiz quadrada de i
                    if (i % j == 0) { // Verifica se o resto da divisão é 0
                        primo = 0; // Caso seja atribui o valor 0 a variável de controle (Falso)
                        break; // Interrompe o laço interior
                    }
                }
            }

            if (primo == 1) { // Verifica a variável de controle, caso ela seja 1 o número é primero
                printf("%d \n", i); // Imprime na tela o número primo
            }
        }
    }

    return 0; // Retorna 0, sem erros

}