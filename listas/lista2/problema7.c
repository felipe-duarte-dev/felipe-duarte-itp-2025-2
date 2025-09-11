#include <stdio.h> // Inclui biblioteca stdio.h
#include <math.h> // Inclui biblioteca math.h

int main() { // Função principal do código

    float a, b, c, delta, raiz1, raiz2; // Declaração das variáveis do tipo float

    printf("Digite o coeficiente a:\n"); // Instrução para o usuário
    scanf("%f", &a); // Lê e armazena os dados de entrada
    printf("Digite o coeficiente b:\n");
    scanf("%f", &b);
    printf("Digite o coeficiente c:\n");
    scanf("%f", &c);

    delta = pow(b, 2) - 4 * a * c; // Cálculo do delta utilizando a função pow()

    if (delta < 0 && a != 0) { // Condição para a não existência de raízes reais
        printf("A equacao nao possui raizes reais");
    } else if (delta == 0 && a != 0) { // Condição para a existência de uma raiz real
        raiz1 = ( -1 * b) / 2 * a; // Cálculo da única raiz
        printf("A equacao possui apenas uma raiz real: %.2f", raiz1);
    } else if (delta >0 && a != 0) { // Condição para a existência de duas raízes reais
        raiz1 = ((-1 * b) - sqrt(delta)) / 2 * a; // Cálculo da primeira raiz
        raiz2 = ((-1 * b) + sqrt(delta)) / 2 * a; // Cálculo da segunda raiz
        printf("A equacao possui duas raizes distintas, sao elas: %.2f e %.2f", raiz1, raiz2);
    } else { // Caso o coeficiente a seja igual a 0
        printf("A equacao nao e do segundo grau");
    }

    return 0; // Retorna 0
}