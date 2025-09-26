#include <stdio.h> // Inclui biblioteca de entrada e saída

int main() { // Função principal

    int precoA, precoB, dinheiro, resto_atual, resto_total, itensA, itensB; // Declaração de variáveis do tipo int

    printf("Digite o preco do primeiro fornecedor: \n"); // Instrução para o usuário
    scanf("%d", &precoA); // Lê e armazena os dados
    printf("Digite o preco do primeiro fornecedor: \n");
    scanf("%d", &precoB);
    printf("Digite a quantia disponivel: \n");
    scanf("%d", &dinheiro);

    resto_total = dinheiro;

    for (int i = 0; i <= 10000; i++) { // Laço de repetição para o fornecedor A
        for (int j = 0; j <= 10000; j++) { // Laço de repetição para o fornecedor B
            resto_atual = dinheiro - ((precoA * i) + (precoB * j)); // Calcula o valor restante após as compras
            if (resto_atual < 0) { // Verifica se o resto é negativo
                break; // Em caso do resto ser negativo o laço é interrompido 
            }
            if (resto_atual < resto_total) { // Verifica se o resto atual é menor que o resto total
                resto_total = resto_atual; // Em caso afirmativo o resto total é substituído pelo resto atual
                itensA = i; // Juntamente com o número de produtos do fornecedor A
                itensB = j; // E do fornecedor B
            }
        }
    }

    printf("A compra mais eficiente e %d produtos do fornecedor A e %d produtos do fornecdor B, com resto de R$: %d", itensA, itensB, resto_total);
    // Imprime a mensagem com a compra mais eficiente

    return 0; // Retorna 0, sem erros
}