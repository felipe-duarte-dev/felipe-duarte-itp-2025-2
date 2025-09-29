#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <string.h> // Inclui biblioteca com funções para strings

typedef struct { // Estrutura que servirá de molde para as informações pertinentes a um aluno, atuando como no dicionário em python, atuando como par chave-valor
    char nome[50]; // Todo aluno possui com nome com tamanho de até 50 caracteres
    int idade; // Todo aluno possui uma idade inteira
    int serie_escolar; // Todo aluno está em uma série escolar
    char matricula[12]; // Todo aluno recebe uma matrícula do tipo: Ano-Perído-Classe_escolar-Serie_escolar-Número_identificador, ex: 20251033001
    int ativo; // A varíavel ativo serve para definir se o cadastro do aluno está ativo (1) ou inativo (0)
} Aluno; // O exemplo de matrícula descreve um aluno do período 2025.1, ensino médio: 03, 3 ano: 3, número identificador: 001

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
    scanf("%12s", lista[indice].matricula); // Utilizei o scanf pois a entrada da matrícula não contém espaços, a legibilidade do código com scanf é mais simples
    limpar_buffer(); // Mesmo sendo a última pergunta a limpeza do buffer se faz necessária para continuar utilizando o loop do menu

    lista[indice].ativo = 1; // Atribui o valor 1, ativo para o cadastro do aluno

    (*total_alunos)++; // Incrementa a variável que guarda o número de alunos cadastrados

    printf("Aluno cadastrado!\n"); // Exibe mensagem de sucesso
}

void consultar_alunos(Aluno lista[], int total_alunos) { // Função para a listagem de alunos

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    int alunos_ativos = cadastros_ativos(lista, total_alunos); // Recebe o número de aluno ativos

    if (alunos_ativos == 0) { // Verifica se há cadastro de alunos ativos
        printf("\nNao ha alunos cadastro de alunos ativo!\n"); // Imprime aviso caso não haja cadastros ativos
        return; // Retorna a função
    }

    int opcao_listagem, indice_listagem; // Declaração de variáveis do tipo inteiro

    do { // Laço de repetição para a execução da opção de listagem escolhida

        printf("Digite a opcao de listagem: \n 1 - Listar todos\n 2 - Listar individualmente\n 3 - Sair\n"); // Opções de listagem
        scanf("%d", &opcao_listagem); // Lê opção de listagem
        limpar_buffer(); // Limpa buffer de entrada

        if (opcao_listagem != 1 && opcao_listagem != 2 && opcao_listagem != 3) { // Verifica se a opção escolhida está dentro das opções existentes
            opcao_listagem = -1; // Caso não esteja atribui o valor -1 a variável que guarda o valor da opção
        }

        switch (opcao_listagem) { // Verifica a opção escolhida
            case 1: // Lista todos os usuários cadastrados

                for (int i = 0; i < total_alunos; i++) { // Laço de repetição que vai listar todos os alunos por ordem com base no índice do vetor

                    if (lista[i].ativo == 0) { // Verifica se o cadastro da iteração está ativo
                        continue; // Caso esteja inativo laço pula para a próxima iteração sem exibir os dados do aluno inativo
                    }

                    printf("\n == Aluno %d ==\n", i + 1); // Mostra os dados do aluno armazenado na posição i do vetor, segue iterando com base no valor de i
                    printf("Nome: %s\n", lista[i].nome); // Imprime nome
                    printf("Idade: %d\n", lista[i].idade); // Imprime idade
                    printf("Serie escolar: %d\n", lista[i].serie_escolar); // Imprime série escolar
                    printf("Matricula: %s\n", lista[i].matricula); // Imprime matrícula
                }
                break;
            case 2: // Lista apenas um usuário escolhido

                printf("Digite o indice do aluno a ser consultado: \n"); // Pergunta ao usuário qual aluno ele deseja consultar
                scanf("%d", &indice_listagem); // Lê e armazena o número do aluno a ser consultado
                indice_listagem -= 1; // A variável é decrementada para representar o índice real do aluno no vetor, ex: O aluno de cadastro 01 está no índice 0 do vetor
                limpar_buffer(); // Limpa o buffer de entrada

                if (indice_listagem < 0 || indice_listagem >= total_alunos || lista[indice_listagem].ativo == 0) { // Verifica se o indice digitado está dentro dos índices existentes e ativos
                    printf("Aluno inexistente ou cadastro inativo!"); // Exibe mensagem de erro
                    break;
                }

                printf("\n == Aluno %d ==\n", indice_listagem + 1); // Mostra o número do aluno a ser exibido
                printf("Nome: %s\n", lista[indice_listagem].nome); // Imprime nome
                printf("Idade: %d\n", lista[indice_listagem].idade); // Imprime idade
                printf("Serie escolar: %d\n", lista[indice_listagem].serie_escolar); // Imprime série escolar
                printf("Matricula: %s\n", lista[indice_listagem].matricula); // Imprime matrícula
                break;
            case 3: // Encerra a função
                return; // Retorna a função
            default: // Caso a opção não esteja dentro das 3 acima caímos nesse caso, que mostra que a opção é inválida
                printf("Opcao invalida! Tente novamente\n"); // Exibe mensagem de erro
        }

    } while (opcao_listagem != 3); // Só encerra o laço quando opção escolhida for a 3

}

void alterar_aluno(Aluno lista[], int total_alunos) { // Função para alterar cadastro

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    int alunos_ativos = cadastros_ativos(lista, total_alunos); // Recebe o número de aluno ativos

    if (alunos_ativos == 0) { // Verifica se há cadastro de alunos ativos
        printf("\nNao ha alunos cadastro de alunos ativo!\n"); // Imprime aviso caso não haja cadastros ativos
        return; // Retorna a função
    }

    int opcao_alterar, indice_alterar, nova_idade, nova_serie; // Declaração de variáveis do tipo inteiro
    char novo_nome[50]; // Declaração de variável do tipo string (cadeia de caracteres)
    char nova_matricula[12]; // Declaração de variável do tipo string (cadeia de caracteres)

    printf("Digite o numero do cadastro a ser alterado: \n"); // Instrução para o usuário
    scanf("%d", &indice_alterar); // Lê e armazena o número do cadastro
    indice_alterar = indice_alterar - 1; // Decrementa a variável em 1 unidade para refletir o índice real no vetor, já que o primeiro índice é o 0
    limpar_buffer(); // Limpa o buffer de entrada

    if (indice_alterar < 0 || indice_alterar >= total_alunos || lista[indice_alterar].ativo == 0) { // Verifica se o indice digitado está dentro dos índices existentes e ativos
        printf("Aluno inexistente ou cadastro inativo, digite um numero entre 1 e %d para uma alteracao valida!", total_alunos); // Exibe mensagem de erro
        return; // Retorna a função sem nada
    }

    do { // Laço de repetição das opções

        printf("Qual campo deseja alterar: \n 1 - Nome\n 2 - Idade\n 3 - Serie\n 4 - Matricula\n 5 - Sair\n"); // Opções de alteração
        scanf("%d", &opcao_alterar); // Lê e armazena a opção de alteração
        limpar_buffer(); // Limpa buffer de entrada

        if (opcao_alterar != 1 && opcao_alterar != 2 && opcao_alterar != 3 && opcao_alterar != 4 && opcao_alterar != 5) { // Condição que verifica se a opção é válida
            opcao_alterar = -1; // Caso não seja válida o valor -1 é atribuído a variável de opção
        }

        switch (opcao_alterar) { // Executa a opção correspondente a escolhida pelo usuário
            case 1:
                printf("Digite o novo nome: \n"); // Instrução para o usuário
                fgets(novo_nome, 50, stdin); // Lê a entrada do usuário, incluindo espaços em branco
                novo_nome[strcspn(novo_nome, "\n")] = 0; // Retira do final o "\n" que o fgets adiciona
                strcpy(lista[indice_alterar].nome, novo_nome); // Utiliza a função strcpy para alterar o valor da chave nome do cadastro escolhido
                printf("Novo nome: %s\n", lista[indice_alterar].nome); // Imprime o novo nome para o usuário conferir
                break;
            case 2:
                printf("Digite a nova idade: \n"); // Instrução para o usuário
                scanf("%d", &nova_idade); // Lê nova idade
                limpar_buffer(); // Limpa o buffer de entrada
                lista[indice_alterar].idade = nova_idade; // Altera o valor da chave idade do cadastro escolhido
                printf("Nova idade: %d\n", lista[indice_alterar].idade); // Imprime nova idade
                break;
            case 3:
                printf("Digite a nova serie escolar: \n"); // Instrução para o usuário
                scanf("%d", &nova_serie); // Lê a nova série escolar
                limpar_buffer(); // Limpa buffer de entrada
                lista[indice_alterar].serie_escolar = nova_serie; // Altera o valor da chave série escolar do cadastro escolhido
                printf("Nova serie escolar: %d\n", lista[indice_alterar].serie_escolar); // Imprime nova série escolar
                break;
            case 4:
                printf("Digite a nova matricula: \n"); // Instrução para o usuário
                scanf("%12s", nova_matricula); // Lê nova matrícula
                limpar_buffer(); // Limpa o buffer de entrada
                strcpy(lista[indice_alterar].matricula, nova_matricula); // Utiliza a função da lib string.h para alterar o valor da chave matricula do cadastro escolhido
                printf("Nova matricula: %s\n", lista[indice_alterar].matricula); // Imprime nova matrícula
                break;
            case 5: // Caso para sair
                return; // Retorna a função sem nada
            default: // O -1 cai nesse caso
                printf("Opcao invalida! Tente novamente\n"); // Exibe mensagem de erro
        }

    } while (opcao_alterar != 5); // O laço se repete até que a opção 5 seja escolhida

}

void deletar_aluno(Aluno lista[], int total_alunos) {

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    int opcao_deletar, indice_operacao; // Declaração de variáveis do tipo inteiro

    printf("Digite o numero do cadastro a ser deletado/reativado: \n"); // Instrução para o usuário
    scanf("%d", &indice_operacao); // Lê e armazena o número do cadastro
    indice_operacao = indice_operacao - 1; // Decrementa a variável em 1 unidade para refletir o índice real no vetor, já que o primeiro índice é o 0
    limpar_buffer(); // Limpa o buffer de entrada

    if (indice_operacao < 0 || indice_operacao >= total_alunos) { // Verifica se o indice digitado está dentro dos índices existentes
        printf("Aluno inexistente, digite um numero entre 1 e %d para uma alteracao valida!", total_alunos); // Exibe mensagem de erro
        return; // Retorna a função sem nada
    }

    do { // Laço de repetição que apresenta as opções disponíveis

        printf("Qual a opcao desejada: \n 1 - Deletar cadastro\n 2 - Reativar cadastro\n 3 - Sair\n"); // Opções de deletar/reativar
        scanf("%d", &opcao_deletar); // Lê e armazena a opção de deletar/reativar
        limpar_buffer(); // Limpa buffer de entrada

        if (opcao_deletar != 1 && opcao_deletar != 2 && opcao_deletar != 3) { // Condição que verifica se a opção é válida
            opcao_deletar = -1; // Caso não seja válida o valor -1 é atribuído a variável de opção
        }

        switch (opcao_deletar) { // Estrutura condicional que vai executar o código correspondente a opção escolhida
            case 1:
                if (lista[indice_operacao].ativo == 0) { // Verifica se o aluno já está inativo
                    printf("O cadastro ja se encontra inativo\n"); // Exibe mensagem de aviso ao usuário
                    return; // Retorna a função
                } else { // Condição para caso o aluno esteja ativo
                    lista[indice_operacao].ativo = 0; // Altera o valor da variável para 0 (falso) tornando o aluno inativo
                    printf("Cadastro deletado com sucesso!\n"); // Exibe mensagem de sucesso
                    return;
                }
            case 2:
                if (lista[indice_operacao].ativo == 1) { // Verifica se o aluno já está ativo
                    printf("O cadastro ja se encontra ativo\n"); // Exibe mensagem de aviso
                    return;
                } else {
                    lista[indice_operacao].ativo = 1; // Altera o valor da variável para 1 (verdadeiro) tornando o aluno ativo
                    printf("Cadastro reativado com sucesso!\n"); // Exibe mensagem de sucesso
                    return;
                }
            case 3:
                return; // Retorna a função
            default:
                printf("Opcao invalida! Tente novamente\n"); // Exibe mensagem de erro
        }

    } while (opcao_deletar != 3); // Condição para o laço de repetição continuar

}

int cadastros_ativos(Aluno lista[], int total_alunos) { // Função para calcular o número de cadastros ativos

    int alunos_ativos = 0; // Declaração de variável do tipo inteiro

    for (int i = 0; i < total_alunos; i++) { // Laço de repetição para contabilizar os alunos ativos
        if (lista[i].ativo == 1) { // Verifica se o aluno está ativo
            alunos_ativos++; // Caso esteja ativo a variável é incrementada
        }
    }

    return alunos_ativos; // Retorna o número de alunos ativos
}

int main() { // Função principal

    Aluno lista_alunos[100]; // Vetor de dados do tipo Aluno, utilizando struct, possui o tamanho máximo de 100 elementos
    
    int opcao_menu, total_alunos = 0; // Declaração e atribuição de valores de variáveis do tipo inteiro

    do { // Laço de repetição do menu

        int alunos_ativos = cadastros_ativos(lista_alunos, total_alunos);

        printf("ALUNO CADASTRADOS: %d / ALUNOS ATIVOS: %d", total_alunos, alunos_ativos);
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
                consultar_alunos(lista_alunos, total_alunos); // Chama a função de listagem de usuários
                break;
            case 3: // Opção de atualização de usuário
                alterar_aluno(lista_alunos, total_alunos); // Chama a função para a alteração de alunos
                break;
            case 4: // Opção de deletar um usuário
                deletar_aluno(lista_alunos, total_alunos); // Chama a função para deletar/reativar um cadastro de aluno
                break;
            case 5: // Opção para encerrar o programa
                printf("Encerrando sistema... \n"); // Mensagem de encerramento
                break;
            default: // Opções inválidas caem no caso padrão, reinicia o laço de repetição até a opção ser válida
                printf("Opcao invalida!\n"); // Exibe mensagem ao usuário
        }

    } while (opcao_menu != 5); // Enquanto a opção não for igual a 5 (Encerrar sistema) o laço de repetição continua

    return 0; // Retorna 0, sem erros
}