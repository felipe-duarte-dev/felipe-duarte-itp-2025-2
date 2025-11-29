#include <stdio.h>
#include <string.h>

int main() {

    char entrada[1000];

    fgets(entrada, sizeof(entrada), stdin); // Lê e armazena a string
    entrada[strcspn(entrada, "\n")] = 0; 

    char *nome = strtok(entrada, " "); // Separa o nome a ser verificado
    char *frequencia = strtok(NULL, ""); // Armazena a string restante em uma variável

    int separador_data = 0;

    for (int i = 0; frequencia[i] != '\0'; i++) { // Laço de repetição que conta o número de / na string, presentes em todas as datas, assim contabilizando o número de aulas
        if (frequencia[i] == '/') {
            separador_data++;
        }
    }  
    
    int faltas_aluno = 0;
    char *ponteiro = frequencia; // Declara um ponteiro que aponta para a o endereço da variável contendo a frequência
    while ((ponteiro = strstr(ponteiro, nome)) != NULL) { // Laço de repetição para verificar as faltas
        faltas_aluno++;
        ponteiro += strlen(nome); 
    }

    if (separador_data - faltas_aluno != 1) { // Mensagem para faltas no plural
        printf("%s faltou %d vezes", nome, separador_data - faltas_aluno);
    } else { // Mensagem para faltas no singular
        printf("%s faltou 1 vez", nome);
    }

    return 0;

    
}