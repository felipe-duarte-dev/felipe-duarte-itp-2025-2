#include <stdio.h> // Inclui biblioca stdio.h (Entrada e Saída)

int main() { // Função principal do código

    float celsius, fahrenheit, kelvin; // Declaração das variáveis do tipo float

    printf("Digite a temperatura em graus Celsius:\n"); // Imprime texto de instrução para o usuário
    scanf("%f", &celsius); // Leitura da entrada do usuário

    fahrenheit = (celsius * 9 / 5) + 32; // Conversão de graus celsius para fahrenheit
    kelvin = celsius + 273.15; // Conversão de graus celsius para kelvin

    printf("%.1f graus Celsius para graus Fahrenheit: %.1f \n", celsius, fahrenheit); // Imprime a temperatura em convertida em fahrenheit
    printf("%.1f graus Celsius para graus Kelvin: %.1f \n", celsius, kelvin); // Imprime a temperatura em convertida em kelvin

    return 0; // Retorna 0
}