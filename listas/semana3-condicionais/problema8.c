#include <stdio.h> // Inclui biblioteca stdio.h
#include <math.h> // Inclui biblioteca math.h
#include <stdbool.h> // Inclui biblioteca stdbool.h

int main() { // Função principal do código

    float lado1, lado2, lado3; // Declaração de variáveis do tipo float
    bool triangulo, equilatero; // Declaração de variáveis do tipo bool (Verdadeiro e Falso)

    printf("Digite o primeiro lado (Maior lado):\n"); // Instrução para o usuário
    scanf("%f", &lado1); // Lê e armazena os dados de entrada
    printf("Digite o segundo lado:\n");
    scanf("%f", &lado2);
    printf("Digite o terceiro lado:\n");
    scanf("%f", &lado3);

    if (lado1 + lado2 < lado3 || lado1 + lado3 < lado2 || lado2 + lado3 < lado1) { // Verifica se a combinação dos lados gera um triângulo
        printf("Os lados descritos nao podem formar um triangulo \n");
        triangulo = false; // Caso não seja um triângulo a variável "triangulo" recebe o valor false, será importante na verificação do triângulo quanto aos seus ângulos
    } else {
        triangulo = true; // Caso seja um triângulo a variável recebe o valor true (Verdadeiro)
        if (lado1 == lado2 && lado2 == lado3) { // Verifica se todos os lados são iguais
            printf("Triangulo equilatero \n");
            equilatero = true; // Caso todos os lados sejam iguais a variável "equilatero" recebe o valor true, será importante na verificação quanto aos ângulos
        } else if (lado1 != lado2 && lado2 != lado3) { // Verifica se todos os lados são diferentes
            printf("Triangulo escaleno \n");
            equilatero = false;
        } else { // Caso todos os lados não sejam iguais entre si, ou diferentes entre si, caímos nesse caso (Triângulo Isósceles)
            printf("Triangulo isosceles \n");
            equilatero = false;
        }
    }

    if (triangulo == true && equilatero == false) { // Verica se o triângulo existe e não é equilátero
        if (pow(lado1, 2) == pow(lado2, 2) + pow(lado3, 2)) { // Verifica se é retângulo
            printf("Retangulo \n");
        } else if (pow(lado1, 2) < pow(lado2, 2) + pow(lado3, 2)) { // Verifica se é acuntângulo
            printf("Acutangulo \n");
        } else if (pow(lado1, 2) > pow(lado2, 2) + pow(lado3, 2)) { // Verifica se é obtusângulo
            printf("Obtusangulo \n");
        }
    }

    return 0; // Retorna 0
}