#include <stdio.h> // Inclui biblioteca stdio.h

int main() { // Função principal do código

    float valor_compra; // Declaração da variáveldo tipo float

    printf("Digite o valor da compra:\n"); // Instrução para o usuário
    scanf("%f", &valor_compra); // Lê e armazena dados de entrada

    if (valor_compra <= 100) { // Caso o valor da compra seja menor que 100 reais o valor fica o mesmo
        printf("O valor total da compra e: R$ %.2f", valor_compra);
    } else if (valor_compra > 100 && valor_compra <= 500) { // Caso seja entre 100 e 500 o programa aplica 10% de desconto
        valor_compra = valor_compra * 0.9; // Utilizei a mesma variável, é atribuído a ela o novo valor com desconto
        printf("O valor total da compra e: R$ %.2f", valor_compra); 
    } else if (valor_compra > 500 && valor_compra <= 1000) { // Funciona de forma análoga ao else if de cima
        valor_compra = valor_compra * 0.85;
        printf("O valor total da compra e: R$ %.2f", valor_compra); 
    } else { // Utilizei um else para valores acima de mil, caso não se encaixe em nenhuma das condições acima ela só poder ser maior que 1000
        valor_compra = valor_compra * 0.8;
        printf("O valor total da compra e: R$ %.2f", valor_compra); 
    }

    return 0; // Retorna 0, sem erros
}