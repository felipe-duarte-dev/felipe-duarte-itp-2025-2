#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <string.h> // Inclui biblioteca com funções para strings

typedef struct { // Estrutura que servirá de molde para as informações pertinentes a um aluno, atuando como no dicionário em python, atuando como par chave-valor
    char nome[50]; // Todo aluno possui com nome com tamanho de até 50 caracteres
    int idade; // Todo aluno possui uma idade inteira
    int serie_escolar; // Todo aluno está em uma série escolar
    char matricula[11]; // Todo aluno recebe uma matrícula do tipo: Ano-Perído-Classe_escolar-Serie_escolar-Número_identificador, ex: 20251033001
} Aluno; // O exemplo acima descreve um aluno matriculado no período 2025.1, ensino médio: 03, 3 ano: 3, número identificador: 001

void limpar_buffer() { // Função para limpar o buffer de entrada
    int c; // Variável que armazena temporariamente cada caractere lido
    while ((c = getchar()) != '\n' && c != EOF); // A função lê cada caractere, um por um, até encontrar o \n ou o End of File
}

void cadastro_aluno(Aluno lista[], int *total_alunos) { // Função para cadastro dos alunos
    
    if (*total_alunos >= 100) { // Verifica se o número de alunos cadastrados atingiu o limite do vetor
        printf("O limite de alunos cadastrados foi atingido!"); // Imprime mensagem de erro para o usuário
        return; // A função não retorna nada
    }

    int indice = *total_alunos; // Atualiza o indice com o número total de alunos, logo o último aluno cadastrado estará na última posição do vetor

    printf("\n == Cadastro de Aluno %d ==\n", indice + 1); // Mostra o usuário o número do aluno cadastrado com base no índice, +1 pois o índice começa no 0
    printf("Digite o nome: \n"); // Instrução para o usuário
    fgets(lista[indice].nome, 50, stdin); // Lê a linha inteira e armazena o nome do aluno na chave nome do tipo criado Aluno
    lista[indice].nome[strcspn(lista[indice].nome, "\n")] = 0; // Retira o \n do final do nome adicionado pelo fgets

    printf("Digite a idade: \n"); // Instrução para o usuário
    scanf("%d", &lista[indice].idade); // Lê e armazena a idade do aluno no vetor de alunos cadastrados, na chave idade da posição que o cadastro ocupa
    limpar_buffer(); // Limpa o buffer para a próxima entrada, evitando que o programe pule a pergunta devido ao "\n" residual

    printf("Digite a serie escolar: \n"); // Instrução para o usuário
    scanf("%d", &lista[indice].serie_escolar); // Lê e armazena a série escolar do aluno
    limpar_buffer(); // Limpa o buffer para a entrada seguinte

    printf("Digite a matricula: \n"); // Instrução para o usuário
    scanf("%s", lista[indice].matricula); // Utilizei o scanf pois a entrada da matrícula não contém espaços, a legibilidade do código com scanf é mais simples
    limpar_buffer(); // Mesmo sendo a última pergunta a limpeza do buffer se faz necessária para continuar utilizando o loop do menu

    (*total_alunos)++; // Incrementa a variável que guarda o número de alunos cadastrados

    printf("Aluno cadastrado!\n"); // Exibe mensagem de sucesso
}

void consultar_alunos(Aluno lista[], int total_alunos) {

    if (total_alunos == 0) {
        printf("\nNao ha alunos cadastrados!\n");
        return;
    }

    int opcao_listagem, indice_listagem;

    printf("Digite a opcao de listagem: \n 1 - Listar todos\n 2 - Listar individualmente\n 3 - Sair\n");
    scanf("%d", &opcao_listagem);
    limpar_buffer();

    do {

        if (opcao_listagem != 1 && opcao_listagem != 2 && opcao_listagem != 3) {
            opcao_listagem = -1;
        }

        switch (opcao_listagem) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                return;
                break;
            default:
                printf("Opcao invalida! Tente novamente\n");
        }
    } while (opcao_listagem != 3);
}

int main() { // Função principal

    Aluno lista_alunos[100]; // Vetor de dados do tipo Aluno, utilizando struct, possui o tamanho máximo de 100 elementos
    
    int opcao_menu, total_alunos = 0; // Declaração e atribuição de valores de variáveis do tipo inteiro

    do { // Laço de repetição do menu

        printf("Digite a opcao desejada:\n 1 - Cadastro\n 2 - Consulta\n 3 - Atualizar Cadastro\n 4 - Deletar Cadastro\n 5 - Sair\n"); // Imprime opções ao usuário
        scanf("%d", &opcao_menu); // Lê e armazena opção
        limpar_buffer(); // Limpa o buffer após a escolha da opção

        if (opcao_menu != 1 && opcao_menu != 2 && opcao_menu != 3 && opcao_menu != 4 && opcao_menu != 5) { // Condição que verifica se a opção é válida
            opcao_menu = -1; // Caso não seja válida o valor -1 é atribuído a variável de opção
        }

        switch (opcao_menu) { // Laço condicional para verificar a opção escolhida
            case 1: // Opção de criação de usuário
                cadastro_aluno(lista_alunos, &total_alunos); // Chama a função de cadastro de alunos passando os parâmetros (vetor = lista de alunos, int = total de alunos)
                break; 
            case 2: // Opção de consulta de usuário
                consultar_alunos(lista_alunos, total_alunos);
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