#include <stdio.h> // Inclui biblioteca stdio.h (Entrada e Saída)

int main() { // Função principal do código
    
    float nota1, nota2, nota3, recuperacao, media; // Declaração de variáveis do tipo float

    printf("Digite a primeira nota:\n"); // Imprime instrução para o usuário
    scanf("%f", &nota1); // Lê e armazena entrada do usuário
    printf("Digite a segunda nota:\n");
    scanf("%f", &nota2);
    printf("Digite a terceira nota:\n");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3; // Calcula a média aritmética entre as 3 notas

    if (media < 4) { // Verifica se a média é menor do que 4
        printf("Voce foi reprovado!\n"); // Caso a nota seja menor que 4 exibe a seguinte mensagem
    } else if (media >= 4 && media < 7) { // Verifica se a média está dentro do intervalo [4,7)
        recuperacao = 10 - media; // Calcula a nota de recuperação necessária para a aprovação
        printf("Voce esta na recuperacao, a nota minima necessaria para voce passar e: %.2f\n", recuperacao); // Exibe a nota de recuperação necessária para a aprovação
    } else { // O código executa este bloco em caso dos dois últimos casos não serem verdadeiros
        printf("Voce foi aprovado!\n"); // Exibe mensagem de aprovação
    }

    return 0; // Retorna 0
}