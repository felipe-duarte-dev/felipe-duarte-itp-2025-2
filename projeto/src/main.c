#include <stdio.h> // Inclui biblioteca de entrada e saída

int main() { // Função principal
    
    int opcao_menu; // Declaração de variável do tipo inteiro

    do { // Laço de repetição do menu

        printf("Digite a opcao desejada:\n 1 - Cadastro\n 2 - Consulta\n 3 - Atualizar Cadastro\n 4 - Deletar Cadastro\n 5 - Sair\n"); // Imprime opções ao usuário
        scanf("%d", &opcao_menu); // Lê e armazena opção

        if (opcao_menu != 1 && opcao_menu != 2 && opcao_menu != 3 && opcao_menu != 4 && opcao_menu != 5) { // Condição que verifica se a opção é válida
            opcao_menu = -1; // Caso não seja válida o valor -1 é atribuído a variável de opção
        }

        switch (opcao_menu) { // Laço condicional para verificar a opção escolhida
            case 1: // Opção de criação de usuário
                break;
            case 2: // Opção de consulta de usuário
                break;
            case 3: // Opção de atualização de usuário
                break;
            case 4: // Opção de deletar um usuário
                break;
            case 5: // Opção para encerrar o programa
                printf("Encerrando sistema! \n"); // Mensagem de encerramento
                break;
            default: // Opções inválidas caem no caso padrão, reinicia o laço de repetição até a opção ser válida
                printf("Opcao invalida!\n"); // Exibe mensagem ao usuário
        }

    } while (opcao_menu != 5); // Enquanto a opção não for igual a 5 (Encerrar sistema) o laço de repetição continua

    return 0; // Retorna 0, sem erros
}