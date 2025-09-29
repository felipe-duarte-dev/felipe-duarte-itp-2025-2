#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <math.h> // Inclui biblioteca com funções matemáticas

int primo(int valor) { // Função para verificar se um determinado número é primo

    int controle = 1; // Variável de controle

    for (int j = 2; j <= sqrt(valor); j++) { // Laço de repetição para realizar as divisões do valor, indo de 2 até a raiz quadrada do valor
        if (valor % j == 0) { // Verifica se o resto da divisão é 0
            controle = 0; // Caso o resto seja 0 a variável de controle recebe o valor 0 (Falso)
            break; // Interrompe o laço
        }
    }

    if (controle == 0) { // Verifica se o número não é primo (Variável de controle = 0)
        return 0; // Retorna 0
    } else { // Caso o número não seja não primo, então ele é primo
        return 1; // Retorna 1
    }
}

void trio_primo() { // Função para exibir os trios primos de 5 a 50000

    for (int i = 5; i <= 50000; i++) { // Laço de repetição para verificar os valores desejados, começa do 5 pois o primeiro trio de primos começa em 5
        
        if (primo(i) == 1) { // Verifica se o índice é primo
            if (primo(i + 2) == 1) { // Verifica se o índice + 2 é primo
                if (primo(i + 6) == 1) { // Verifica se o índice + 6 é primo
                    printf("(%d, %d, %d)\n", i, i + 2, i + 6); // Em caso afirmativo dos três casos então o programa exibe os trio de primos
                }
            }
        }
    }
}

int main() { // Função principal

    trio_primo(); // Executa função

    return 0; // Retorna 0, sem erros
}
