#include <stdio.h> // Inclui biblioteca de entrada e saída
#include <string.h> // Inclui biblioteca com funções para strings

typedef struct { // Estrutura que servirá de molde para as informações pertinentes a um aluno, atuando como no dicionário em python, atuando como par chave-valor
    char nome[50]; // Todo aluno possui com nome com tamanho de até 50 caracteres
    int idade; // Todo aluno possui uma idade inteira
    int serie_escolar; // Todo aluno está em uma série escolar
    char matricula[12]; // Todo aluno recebe uma matrícula do tipo: Ano-Perído-Classe_escolar-Serie_escolar-Número_identificador, ex: 20251033001
    char materias_cursando[5][15]; // Todo aluno estará matriculado em 5 matérias padrão
    int notas[5][3]; // Todo aluno receberá 3 notas para cada matéria padrão, representando uma nota por trimestre
    int ativo; // A varíavel ativo serve para definir se o cadastro do aluno está ativo (1) ou inativo (0)
} Aluno; // O exemplo de matrícula descreve um aluno do período 2025.1, ensino médio: 03, 3 ano: 3, número identificador: 001

char materias_padrao[5][15] = {"Matemática", "Português", "História", "Geografia", "Ciências"}; // Vetor contendo as matérias padrão

void limpar_buffer() { // Função para limpar o buffer de entrada
    int c; // Variável que armazena temporariamente cada caractere lido
    while ((c = getchar()) != '\n' && c != EOF); // A função lê cada caractere, um por um, até encontrar o \n ou o End of File
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

    for (int i = 0; i < 5; i++) { // Laço de repetição para adicionar as matérias padrão ao vetor de matérias de cada aluno
        strcpy(lista[indice].materias_cursando[i], materias_padrao[i]); // Copia o valor do vetor padrão para o vetor de novo aluno cadastrado
    }

    for (int i = 0; i < 5; i++) { // Estutura de repetição aninhada para o preenchimento inicial da matriz de notas de cada aluno cadastrado
        for (int j = 0; j < 3; j++) {
            lista[indice].notas[i][j] = -1; // A matriz será preenchida com o valor -1 em todas posições, que representam a ausência de nota inicialmente
        }
    }

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

void alterar_deletar_notas(Aluno lista[], int total_alunos) { // Função para alteração de exclusão de notas

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    int opcao_nota, indice_aluno, materia_alterar;

    printf("Digite o numero do cadastro a ser alterado: \n"); 
    scanf("%d", &indice_aluno); // Lê e armazena o índice do aluno a ter suas notas alteradas
    indice_aluno = indice_aluno - 1; // O índice é atualizado para ser baseado em índices de ínicio 0
    limpar_buffer(); // Limpa o buffer de entrada

    if (indice_aluno < 0 || indice_aluno >= total_alunos) { // Verifica se o aluno existe 
        printf("Aluno inexistente, digite um numero entre 1 e %d para uma alteracao valida!\n", total_alunos); 
        return; 
    }

    if (lista[indice_aluno].ativo == 0) { // Verifica se o cadastro do aluno está ativo
        printf("O aluno nao possui cadastro ativo!\n");
        return;
    }

    do { // Laço de repetição que apresenta as opções disponíveis

        printf("Qual a opcao desejada: \n 1 - Atribuir nota\n 2 - Deletar nota\n 3 - Sair\n"); 
        scanf("%d", &opcao_nota); // Lê e armazena a opção escolhida
        limpar_buffer(); 

        if (opcao_nota != 1 && opcao_nota != 2 && opcao_nota != 3) { // Verifica se a opção está dentro das opções existentes
            opcao_nota = -1; 
        }

        switch (opcao_nota) { // Estrutura condicional que executa a opção escolhida
            case 1:
                printf("Selecione a materia: \n 1 - Matematica\n 2 - Portugues\n 3 - Historia\n 4 - Geografia\n 5 - Ciencias\n");
                scanf("%d", &materia_alterar); // Lê e armazena a matéria a ser alterada
                limpar_buffer();

                if (materia_alterar < 1 || materia_alterar > 5) { // Verifica se a matéria escolhida está dentro das existentes
                    printf("Materia invalida!\n");
                    break; // Retorna a tela de opções
                }

                for (int i = 0; i < 3; i++) { // Laço de repetição para a alteração das notas da unidades da matéria escolhida
                    int nota_temp; // Variável temporária que armazenará a nota

                    printf("Nota da unidade %d:\n", i + 1); // Pergunta a nota a ser atribuida na unidade
                    scanf("%d", &nota_temp); // Lê e armazena a nota
                    limpar_buffer();

                    if (nota_temp < 0 || nota_temp > 100) { // Verifica se a nota está entre 0 e 100
                        printf("Nota invalida!");
                        i--; // Decrementa a variável de iteração 
                        continue; // Vai para a próxima iteração do for, que será a mesma pois a variável foi decrementada
                    }

                    lista[indice_aluno].notas[materia_alterar - 1][i] = nota_temp; // Altera na matriz de notas a nota da unidade da matéria escolhida
                }

                printf("Notas cadastradas com sucesso! \n"); // Mensagem de sucesso
                break; // Retorna ao menu de opções
            case 2:
                printf("Selecione a materia: \n 1 - Matematica\n 2 - Portugues\n 3 - Historia\n 4 - Geografia\n 5 - Ciencias\n");
                scanf("%d", &materia_alterar); // Lê e armazena a matéria a ser alterada
                limpar_buffer();

                if (materia_alterar < 1 || materia_alterar > 5) { // Verifica se a matéria escolhida está dentro das existentes
                    printf("Materia invalida!\n");
                    break;
                }

                int unidade_deletar;

                printf("Selecione a unidade: \n 1 - 2 - 3\n"); 
                scanf("%d", &unidade_deletar); // Lê e armazena a unidade a ter a nota deletada
                limpar_buffer();

                if (unidade_deletar < 1 || unidade_deletar > 3) { // Verifica se a unidade escolhida está dentro das existentes
                    printf("Unidade invalida!\n");
                    break;
                }

                lista[indice_aluno].notas[materia_alterar - 1][unidade_deletar - 1] = -1; // Atribui o valor de nota inexistente

                printf("Nota deletada com sucesso!\n"); // Mensagem de sucesso
                break; // Retorna ao menu de opções
            case 3:
                return; // Retorna a função
            default:
                printf("Opcao invalida! Tente novamente\n"); // Exibe mensagem de erro
        }

    } while (opcao_nota != 3); // Condição para o laço de repetição continuar

}

void consultar_notas(Aluno lista[], int total_alunos) {

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    int opcao_consultar, indice_aluno;

    printf("Digite o numero do cadastro a ser consultado: \n"); 
    scanf("%d", &indice_aluno); // Lê e armazena o índice do aluno a ser consultado
    indice_aluno = indice_aluno - 1; // O índice é atualizado para ser baseado em índices de ínicio 0
    limpar_buffer(); // Limpa o buffer de entrada

    if (indice_aluno < 0 || indice_aluno >= total_alunos) { // Verifica se o aluno existe 
        printf("Aluno inexistente, digite um numero entre 1 e %d para uma consulta valida!\n", total_alunos); 
        return; 
    }

    if (lista[indice_aluno].ativo == 0) { // Verifica se o cadastro do aluno está ativo
        printf("O aluno nao possui cadastro ativo!\n");
        return;
    }

    do { // Laço de repetição que apresenta as opções disponíveis

        printf("Qual a opcao desejada: \n 1 - Consulta Geral\n 2 - Consulta Específica\n 3 - Sair\n"); 
        scanf("%d", &opcao_consultar); // Lê e armazena a opção escolhida
        limpar_buffer(); 

        if (opcao_consultar != 1 && opcao_consultar != 2 && opcao_consultar != 3) { // Verifica se a opção está dentro das opções existentes
            opcao_consultar = -1; 
        }

        switch (opcao_consultar) { // Estrutura condicional que executa a opção escolhida
            case 1:
                for (int i = 0; i < 5; i++) { // Laço de repetição exterior, itera sobre as linhas
                    printf("%s: \n", lista[indice_aluno].materias_cursando[i]); // Mostra a matéria que são exibidas as notas

                    for (int j = 0; j < 3; j++) { // Laço de repetição interior, itera sobre as colunas
                        printf("Unidade %d: ", j + 1); // Mostra a unidade que a nota foi atribuida

                        if (lista[indice_aluno].notas[i][j] == -1) { // Verifica se a nota foi atribuida ou não
                            printf("Nota nao atribuida\n");
                        } else {
                            printf("%d\n", lista[indice_aluno].notas[i][j]); // Em caso afirmativo a nota é exibida
                        }
                    }
                }

                return; // Retorna ao menu principal
            case 2:
                int materia_consultada;

                printf("Selecione a materia a ser consultada: \n 1 - Matematica\n 2 - Portugues\n 3 - Historia\n 4 - Geografia\n 5 - Ciencias\n");
                scanf("%d", &materia_consultada); // Lê e armazena a matéria específica a ser consultada
                limpar_buffer();

                if (materia_consultada < 1 || materia_consultada > 5) { // Verifica se a matéria escolhida está dentro das existentes
                    printf("Materia invalida!\n");
                    break; // Retorna a tela de opções
                }

                printf("%s: \n", lista[indice_aluno].materias_cursando[materia_consultada - 1]); // Mostra a matéria consultada

                for (int i = 0; i < 3; i++) { // Laço de repetição que itera sobre as colunas da matriz de notas
                    printf("Unidade %d: ", i + 1);
                    if (lista[indice_aluno].notas[materia_consultada - 1][i] == -1) { // Verifica se a nota foi atribuida na unidade
                        printf("Nota nao atribuida\n");
                    } else {
                        printf("%d\n", lista[indice_aluno].notas[materia_consultada - 1][i]); // Em caso afirmativo a nota é exibida
                    }
                }

                break; // O laço é encerrado, retornando ao menu de escolha de consulta, possibilitando novas consultas específicas ou uma consulta geral
            case 3:
                return; // Retorna a função
            default:
                printf("Opcao invalida! Tente novamente\n"); // Exibe mensagem de erro
        }

    } while (opcao_consultar != 3); // Condição para o laço de repetição continuar

}

void busca_textual(Aluno lista[], int total_alunos) { // Função para busca textual por matrícula ou nome do aluno

    if (total_alunos == 0) { // Verifica se há alunos cadastrados
        printf("\nNao ha alunos cadastrados!\n"); // Imprime aviso caso não haja alunos cadastrados
        return; // Retorna a função
    }

    char consulta_texto[50]; // Variável que vai armazenar a busca textual

    printf("\nCONSULTA TEXTUAL:\n Digite a matricula ou o nome:\n");
    fgets(consulta_texto, 50, stdin); // Lê e armazena a string de busca
    consulta_texto[strcspn(consulta_texto, "\n")] = 0; // Retira o \n no final da string e adiciona um \0 para indicar o fim dela

    if (strlen(consulta_texto) == 0) { // Verifica se a string de busca é válida, ou seja, se realmente possui algo para ser buscado
        printf("A consulta nao pode ser vazia!\n");
        return;
    }

    int resultados = 0; // Variável que irá armazenar o número de resultados obtidos na pesquisa

    for (int i = 0; i < total_alunos; i++) { // Itera sobre o número total de alunos

        if (lista[i].ativo == 0) { // Verifica se o aluno está ativo
            continue;
        }

        int nome_encontrado = strstr(lista[i].nome, consulta_texto); // A função strstr funciona buscando sub-strings na string desejada
        int matricula_encontrado = strstr(lista[i].matricula, consulta_texto); // Caso haja uma sub-string dentro da string que corresponda ela retorna uma valor numérico

        if (nome_encontrado != NULL || matricula_encontrado != NULL) { // Verifica se a função retornou um valor numérico ou nulo
            printf("\n== Aluno %d ==\n", i + 1); // Caso retorne um valor numérico é exibido o nome, matrícula e número de cadastro do aluno
            printf("Nome: %s\n", lista[i].nome);
            printf("Matricula: %s\n", lista[i].matricula);
            resultados++; // A variável resultado é incrementada
        }
    }

    if (resultados == 0) { // Verifica se o número de resultados encontrados é igual a 0
        printf("\n0 Resultados encontrados!\n");
    } else {
        printf("%d Resultados encontrados!", resultados);
    }

}

int main() { // Função principal

    Aluno lista_alunos[100]; // Vetor de dados do tipo Aluno, utilizando struct, possui o tamanho máximo de 100 elementos
    
    int opcao_menu, total_alunos = 0; // Declaração e atribuição de valores de variáveis do tipo inteiro

    do { // Laço de repetição do menu

        int alunos_ativos = cadastros_ativos(lista_alunos, total_alunos);

        printf("\nALUNO CADASTRADOS: %d / ALUNOS ATIVOS: %d\n", total_alunos, alunos_ativos);
        printf("Digite a opcao desejada:\n1 - Cadastro\n2 - Consulta\n3 - Atualizar Cadastro\n4 - Deletar Cadastro\n5 - Alterar Notas\n6 - Consultar Notas\n7 - Busca Textual\n8 - Sair\n");
        scanf("%d", &opcao_menu); // Lê e armazena opção
        limpar_buffer(); // Limpa o buffer após a escolha da opção

        if (opcao_menu != 1 && opcao_menu != 2 && opcao_menu != 3 && opcao_menu != 4 && opcao_menu != 5 && opcao_menu != 6 && opcao_menu != 7 && opcao_menu != 8) { // Condição que verifica se a opção é válida
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
            case 5: // Opção de alterar e deletar notas
                alterar_deletar_notas(lista_alunos, total_alunos); // Chama a função para alterar/deletar as notas de um aluno
                break;
            case 6: // Opção de consulta de notas
                consultar_notas(lista_alunos, total_alunos); // Chama a função para consultar as notas de um aluno
                break;
            case 7: // Opção de busca textual
                busca_textual(lista_alunos, total_alunos); // Chama a função para busca textual de nome ou matrícula
                break;
            case 8: // Opção para encerrar o programa
                printf("Encerrando sistema... \n"); // Mensagem de encerramento
                break;
            default: // Opções inválidas caem no caso padrão, reinicia o laço de repetição até a opção ser válida
                printf("Opcao invalida!\n"); // Exibe mensagem ao usuário
        }

    } while (opcao_menu != 8); // Enquanto a opção não for igual a 8 (Encerrar sistema) o laço de repetição continua

    return 0; // Retorna 0, sem erros
}