#include <stdio.h> // Inclu biblioteca de entrada e saída
#include <math.h> // Inclu biblioteca para usar função matemática e potenciação

int main() { // Função principal

    for (int a = 2; a < 1000; a++) { // For exterior
        for (int b = 2; b < 1000; b++) { // For intermediário
            for (int c = 2; c < 1000; c++) { // For interior
                if (pow(a, 2) == pow(b, 2) + pow(c, 2)) { // Verifica se o triângulo é pitagórico
                    printf("%d %d %d \n", a, b, c); // Exibi na tela os lados do triângulo pitagórico
                }
            }
        }
    }

    return 0; // Retorna 0, sem erros
}