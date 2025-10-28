#include <stdio.h>

typedef struct {
    char mes[15];
    int chuvas;
} DadosChuva;

int main() {

    DadosChuva chuva_meses[12] = {
        {"Janeiro", 0},
        {"Fevereiro", 0},
        {"Marco", 0},
        {"Abril", 0},
        {"Maio", 0},
        {"Junho", 0},
        {"Julho", 0},
        {"Agosto", 0},
        {"Setembro", 0},
        {"Outubro", 0},
        {"Novembro", 0},
        {"Dezembro", 0}
    };

    printf("Digite o numero de chuvas nos meses do ano: \n");
    for (int i = 0; i < 12; i++) { 
        int chuva;
        scanf("%d", &chuva);
        chuva_meses[i].chuvas = chuva;
    }

    for (int i = 0; i < 12; i++) {
        DadosChuva auxiliar;
        for (int j = 0; j < 11 - i; j++) {
            if (chuva_meses[j].chuvas > chuva_meses[j + 1].chuvas) {
                auxiliar = chuva_meses[j];
                chuva_meses[j] = chuva_meses[j + 1];
                chuva_meses[j + 1] = auxiliar;
            }
        }
    }

    for (int i = 11; i > -1; i--) {
        printf("%s: %d \n", chuva_meses[i].mes, chuva_meses[i].chuvas);
    }

    return 0;
}