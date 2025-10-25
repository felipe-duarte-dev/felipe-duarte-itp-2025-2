#include <stdio.h> // Inclu biblioteca de entrada e saída

int main() { // Função principal do código
    int questoes_gabarito[20]; // Declaração do vetor que vai armazenar o gabarito correto
    int questoes_aluno[20]; // Declaração do vetor que vai armazenar o gabarito do aluno
    int acertos, gabarito_mec, gabarito_aluno, num_questoes; // Declaração de variáveis do tipo inteiro

    scanf("%d", &num_questoes); // Lê e armazena o número de questões

    for (int i = 0; i < num_questoes; i++) { // Laço de repetição para a construção do vetor gabarito correto
        gabarito_mec = scanf("%d", &questoes_gabarito[i]); // Lê cada número separado por espaço e guarda ele no vetor gabarito correto, no índice i

        if (gabarito_mec != 1) { // Verifica o fim da entrada de dados
            break;
        }

    }

    for (int i = 0; i < num_questoes; i++) { // Laço de repetição para a construção do vetor gabarito do aluno
        gabarito_aluno = scanf("%d", &questoes_aluno[i]); // Lê cada número separado por espaço e guarda ele no vetor gabarito correto, no índice i

        if (gabarito_aluno != 1) { // Verifica o fim da entrada de dados
            break;
        }

    }

    acertos = 0; 

    for (int i = 0; i < num_questoes; i++) { // Laço de repetição para calcular os acertos, itera sobre os itens dos vetores gabarito
        if (questoes_gabarito[i] == questoes_aluno[i]) { // Caso o gabarito correto e do aluno sejam iguais é computado um acerto
            acertos++;
        }
    }

    if (acertos == 1) { // Para 1 acerto
        printf("1 acerto");
    } else { // Para mais de 1 acerto
        printf("%d acertos", acertos);
    }

    return 0;
}