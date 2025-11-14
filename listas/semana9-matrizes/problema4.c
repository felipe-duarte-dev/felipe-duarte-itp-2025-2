#include <stdio.h>

int main() {

    int matriz, i, j, partida, destino, rota_inter = -1, menor_custo = 100000000; 

    printf("Digite o numero de cidades: \n");
    scanf("%d", &matriz); // Lê e armazena o número de cidades

    int passagens[matriz][matriz]; 

    for (i = 0; i < matriz; i++) { // Estrutura de repetição aninhada para construção da matriz
        for (j = 0; j < matriz; j++) {
            scanf("%d", &passagens[i][j]);
        }
    }

    printf("Digite a cidade de partida e de destino: \n"); 
    scanf("%d %d", &partida, &destino); // Lê e armazena a cidade de partida e de destino

    menor_custo = passagens[partida][destino]; // Calcula o valor da passagem da viagem direta

    for (i = 0; i < matriz; i++) { // Laço de repetição para conferir os preços com rota intermediária

        int custo_temp = 0; // Variável temporária que armazena o valor da viagem com a inclusão da rota intermediária

        if (i == partida || i == destino) // Caso a cidade intermediária "i" seja a de partida ou a de destino a iteração é pulada
            continue;

        custo_temp = passagens[partida][i] + passagens[i][destino]; // Armazena o valor da viagem com a inclusão da rota intermediária

        if (menor_custo > custo_temp) { // Verifica se o valor encontrado na iteração atual é menor que o menor valor encontrada em iterações anteriores
            rota_inter = i; // Caso verdadeiro armazena o destino intermediário
            menor_custo = custo_temp; // Armazena o valor de menor custo encontrado
        }
    }

    if (rota_inter == -1) // Caso o valor da rota intermediária seja -1 podemos concluir que não houve melhor rota intermediária encontrada
        printf("%d-%d R$%d", partida, destino, menor_custo); // É exibido o valor da viagem direta, o menor valor
    else 
        printf("%d-%d-%d R$%d", partida, rota_inter, destino, menor_custo); // Em caso contrário, é exibido a rota com cidade intermediária e o valor

    return 0;
}