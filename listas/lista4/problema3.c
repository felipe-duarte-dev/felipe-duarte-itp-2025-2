#include <stdio.h>
#include <math.h>

float altura(float x, float y) { // Função para calcular a altura em determinada coordenada

    float ponto = sin(cos(y) + x) + cos(y + sin(x)); // Calcula o valor da altura com base nas coordenadas

    return ponto; // Retorna o valor da altura
}

int altura_segura(float h) { // Função que define se a altura é segura ou não
    
    if (h <= 2 && h >= 0) { // Caso a altura esteja dentro do intervalo [0, 2] a função retorna 1 (True)
        return 1;
    } else { // Caso não seja segura retorna 0 (False)
        return 0;
    }
}

int verificar_pontos(float x, float y) { // Função que valida os 4 pontos adjacentes ao de pouso central

    if (altura_segura(altura(x, y)) == 0) { // Altura fora do intervalo retorna 0
        return 0;
    }

    int alturas_seguras = altura_segura(altura(x + 0.2, y + 0.2)) + altura_segura(altura(x - 0.2, y - 0.2)) + altura_segura(altura(x + 0.2, y - 0.2)) + altura_segura(altura(x - 0.2, y + 0.2));
    // Para o pouso ser possível a variável de ter o valor 4, soma dos valores verdadeiros ou falsos da validação das alturas

    if (alturas_seguras == 4) {
        return 1;
    } else {
        return 0;
    }
    
}

int main() {

    float x, y;
    int pontos_seguros = 0, ponto_inicial;

    printf("Digite as coordenadas x e y: \n");
    scanf("%f %f", &x, &y);

    ponto_inicial = verificar_pontos(x, y); // Verifica o ponto central de pouso

    if (ponto_inicial == 0) { // Em case de pouso em altura insegura ele manda um aviso de alerta
        printf("Troque de coordenada!\n");
    } else { // Caso o pouso seja seguro o código vai calcular agora os pontos mais afastados para verificar condição de pouso
        pontos_seguros = altura_segura(altura(x + 2, y)) + altura_segura(altura(x - 2, y)) + altura_segura(altura(x, y + 2)) + altura_segura(altura(x, y - 2));
    }

    if (ponto_inicial != 0) { // Condição de pouso seguro

        switch (pontos_seguros) { // Classifica o pouso em três categorias com base na verificação dos pontos mais afastados
            case 0:
            case 1:
                printf("Inseguro\n");
                break;
            case 2:
            case 3:
                printf("Relativamente seguro\n");
                break;
            case 4:
                printf("Seguro\n");
                break;
        }
    }

    return 0;
}