#include <stdio.h> // Inclui biblioteca de entrada e saída

int main() { // Função principal

    int precoA, precoB, dinheiro, resto; // Declaração de variáveis do tipo int

    printf("Digite o preco do primeiro fornecedor: \n"); // Instrução para o usuário
    scanf("%d", &precoA); // Lê e armazena os dados
    printf("Digite o preco do primeiro fornecedor: \n");
    scanf("%d", &precoB);
    printf("Digite a quantia disponivel: \n");
    scanf("%d", &dinheiro);

    for (int i = 0; i <= 10000; i++) { // Laço de repetição para o fornecedor A
        for (int j = 0; j <= 10000; j++) { // Laço de repetição para o fornecedor B
            resto = dinheiro - ((precoA * i) + (precoB * j)); // Calcula o valor restante após as compras
            if (resto < 0) { // Verifica se o resto é negativo
                break; // Em caso do resto ser negativo o laço é interrompido 
            } else { // Em caso do resto ser positivo o programa continua
                printf("Comprando %d do primeiro e %d do segundo resta: %d \n", i, j, resto); // Exibe a quantidade de compras e o resto
            }
        }
    }

    return 0; // Retorna 0, sem erros
}