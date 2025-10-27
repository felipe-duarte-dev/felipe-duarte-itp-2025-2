#include <stdio.h>

int main() { // Função principal do código

    char placa[9]; // Vetor que vai armazenar os dígitos da placa
    int controle = 0; // variável de controle

    printf("Digite a placa do carro: \n");
    scanf("%s", placa);

    if (placa[3] == '-') { // Verifica se a placa possui um "-", caso possua ela vai ser verificada no padrão brasileiro

        for (int i = 0; i < 3; i++) { // Loop que vai percorrer as letras da placa
            if (placa[i] >= 65 && placa[i] <= 90) { // Verifica se o caractere de índice i está dentro do intervalo númerico das letras maiúsuclas na tabela ASCII
                controle++;
            }
        }

        for (int i = 4; i < 8; i++) { // Loop que vai percorrer os números da placa
            if (placa[i] >= 48 && placa[i] <= 57) { // Verifica se o caractere de índice i está dentro do intervalo númerico dos algarismos na tabela ASCII
                controle++;
            }
        }

        if (controle == 7) { // Verifica se a variável de controle armazena o número 7, que corresponde a todas as verificações corretas
            printf("brasileiro");
        } else {
            printf("invalido");
        }
        
    } else { // O bloco de código para verificação da placa do mercosul apresenta a mesma estrutura do padrão brasileiro

        for (int i = 0; i < 5; i++) { 
            
            if (i == 3) { // A única diferença está aqui, como as letras não estão todas juntas é necessário pular a verificação do caractere de índice 3
                continue;
            }

            if (placa[i] >= 65 && placa[i] <= 90) {
                controle++;
            }
        }

        for (int i = 3; i < 7; i++) {

            if (i == 4) { // A única diferença está aqui, como os números não estão todos juntos é necessário pular a verificação do caractere de índice 4
                continue;
            }

            if (placa[i] >= 48 && placa[i] <= 57) {
                controle++;
            }
        }

        if (controle == 7) {
            printf("mercosul");
        } else {
            printf("invalido");
        }

    }

    return 0;
}