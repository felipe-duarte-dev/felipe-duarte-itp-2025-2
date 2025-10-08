#include <stdio.h> 

int main() {

    int ilhas[10]; // Vetor que armazena a sugestão dos nativos 
    int visitado[10] = {0}; // Vetor para marcar quais ilhas já foram visitadas 
    int atual = 0; // Variável que guarda a ilha atual 

    for (int i = 0; i < 10; i++) { // Laço de repetição para ler e armazenar as sugestões dos nativos
        scanf("%d", &ilhas[i]); 
    }

    while (1) { // Laço de repetição infinita, ele só vai parar quando a ilha for visitada pela segunda vez

        if (visitado[atual] == 10) { // Verifica se a ilha atual já foi visitada
            printf("%d\n", atual); 
            break;                
        }

        visitado[atual] = 10; // Marca a ilha atual como visitada
        atual = ilhas[atual]; // Segue para a próxima ilha
    }

    return 0; // Retorna 0, sem erros
}

