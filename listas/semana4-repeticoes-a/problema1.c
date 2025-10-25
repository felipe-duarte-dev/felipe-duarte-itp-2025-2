#include <stdio.h> // Inclui biblioteca de entrada e saída

int main() { // Função principal do código

    float comprimento, largura, bolso; // Declaração de variáveis do tipo float
    int dobras = 0; // Declaração e atribuição de valor da variável do tipo int

    printf("Digite o comprimento da folha: \n"); // Instrução para o usuário
    scanf("%f", &comprimento); // Lê e armaezena a entrada do usuário
    printf("Digite a largura da folha: \n");
    scanf("%f", &largura);
    printf("Digite a largura do bolso: \n");
    scanf("%f", &bolso);

    while (comprimento >= bolso && largura >= bolso) { // Looping que só acaba quando a largura ou o comprimento forem menores que a largura do bolso
        if (comprimento > largura) { // Condição para caso o comprimento da folha seja maior que a largura da folha
            comprimento = comprimento / 2; // Realiza a operação de dobra na folha, divindo o comprimento por dois
            dobras++; // Incrementa o número de dobras
        } else { // Para caso a largura seja maior que o comprimento
            largura = largura / 2; // Divide a largura por 2
            dobras++; // Incrementa o número de dobras
        }
    }

    printf("Foram necessarias %d dobras", dobras); // Mostra o resultado de dobras necessárias

    return 0; // Retorna sem erros
}