#include <stdio.h>

int main() {
    int usuarios;
    scanf("%d", &usuarios); // Lê o número de usuários

    int amizade[100][100]; // Matriz de amizades 

    for (int i = 0; i < usuarios; i++) { // Lê e aloca os amigos dentro da matriz
        for (int j = 0; j < usuarios; j++) {
            scanf("%d", &amizade[i][j]);
        }
    }

    int usuario_sugerir;
    scanf("%d", &usuario_sugerir); // Usuário para quem será enviada as sugestões

    int sugestoes[100]; // Armazena as sugestões
    int contador = 0; // Quantidade de sugestões encontradas

    for (int i = 0; i < usuarios; i++) { // Percorre todos os usuários possíveis
        if (i == usuario_sugerir) { // Não sugere para ele mesmo
            continue; 
        }     
        if (amizade[usuario_sugerir][i] == 1) { // Verifica se já são amigos
            continue; 
        }        

        for (int k = 0; k < usuarios; k++) { // Verifica amizades em comum
            if (amizade[usuario_sugerir][k] == 1 && amizade[i][k] == 1) {
                sugestoes[contador++] = i; // Adiciona no vetor de sugestões
                break; 
            }
        }
    }

    for (int i = 0; i < contador; i++) { // Imprime os valores do vetor em ordem crescente
        printf("%d", sugestoes[i]);
        if (i < contador - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
