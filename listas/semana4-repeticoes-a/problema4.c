#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <math.h> // Inclui biblioteca para funções matemáticas de potenciação e raiz quadrada

int main() { // Função principal do código

    float x, y, dist_euclidiana, dist_anterior, x_anterior, y_anterior; // Declaração de variáveis do tipo float
    int pontuacao_principal, pontuacao_bonus, pontuacao_total = 0, contador = 1; // Declaração de variáveis do tipo int

    do { // O código inicialmente roda o programa e ao final verifica se a condição é verdadeira ou falsa
        printf("Jogada %d: \n", contador); // Mostra o jogador o número da jogada
        scanf("%f", &x); // Lê e armazena a jogada
        scanf("%f", &y); // Lê e armazena a jogada

        pontuacao_bonus = 0; // Zera a pontuação bônus no início de cada jogada
        dist_euclidiana = sqrt((pow(x - 0, 2) + pow(y - 0, 2))); // Calcula da distância da jogada até o centro

        if (dist_euclidiana >= 0 && dist_euclidiana <= 1) { // Verifica a distância euclidiana da jogada até o centro
            pontuacao_principal = 10; // Atribui pontuação
        } else if (dist_euclidiana > 1 && dist_euclidiana <= 2) {
            pontuacao_principal = 6;
        } else if (dist_euclidiana > 2 && dist_euclidiana <= 3) {
            pontuacao_principal = 4;
        } else {
            pontuacao_principal = 0; // Esse caso está aqui apenas para ilustrar que caso a distância euclidiana for maior que 3 a pontuação é nula
        }

        pontuacao_total += pontuacao_principal; // Adiciona os pontos da distância euclidiana da jogada até o centro

        if (contador > 1) { // Essa condição estabelece que a pontuação bônus só pode ser alcançada após o primeiro lançamento
            dist_anterior = sqrt((pow(x - x_anterior, 2) + pow(y - y_anterior, 2))); // Distância euclidiana entre o lançamento atual e o anterior 

            if (dist_anterior >= 0 && dist_anterior <= 1) { // Caso a DE esteja dentro do intervalo [0,1] o lançamento ganha pontuação bônus
            pontuacao_bonus = pontuacao_principal / 2; // Definie a pontuação bônus com base na pontuação principal 
            }
        }

        pontuacao_total += pontuacao_bonus; // Atribui pontuação bônus a pontuação total
        x_anterior = x; // Atribui lançamento atual ao lançamento anterior para a próxima rodada
        y_anterior = y; // Atribui lançamento atual ao lançamento anterior para a próxima rodada
        contador += 1; // Incrementa o contador

    } while (contador <= 10); // Condição para o laço continuar ativo

    printf("A pontuacao total foi de: %d \n", pontuacao_total); // Mostra pontuação total

    return 0; // Retorna 0, sem erros
}