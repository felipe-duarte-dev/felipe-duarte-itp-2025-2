#include <stdio.h>

int main() {

    int melhor_x = 0, melhor_y = 0;
    float p, q, melhor_razao = 0;

    printf("Digite o preco de venda do produto: \n");
    scanf("%f", &p);
    printf("Digite o preco de producao do produto: \n");
    scanf("%f", &q);

    for (int y = 1; y <= 10; y++) { // Laço de repetição exterior
        for(int x = 1; x <= 10; x++) { // Laço de repetição interior
            if (y * p >= x * q && x > y) { // Verifica se a promoção não gera prejuízo e se x > y
                if ((((float)x) / y) > melhor_razao) { // Caso a função não gere prejuízo verifica se a razão x/y é melhor que a iteração anterior
                melhor_razao = ((float)x) / y; // Caso a razão conferida seja melhor que a anterior o programa atribui a nova razão como a melhor
                melhor_x = x; // Guarda o melhor valor de x para a promoção
                melhor_y = y; // Guarda o melhor valor de y para a promoção
                }
            }
        }
    }

    printf("A melhor promocao eh: pague %d leve %d", melhor_y, melhor_x); // Mostra a melhor promoção

    return 0;
}