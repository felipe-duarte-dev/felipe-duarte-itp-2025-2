#include <stdio.h> 

void horario_rondas(int hora, int minuto, int formato) { // Função para formatar o horário das rondas

    if (formato == 0) { // Condição para o formato 0

        if (minuto > 59) { // Caso os minutos ultrapassem 60 é realizada a subtração e a adição de 1 hora
            minuto = minuto - 60;
            hora++;
        }

        if (hora >= 24) { // Caso as horas passem de 24 é realizada a operação de módulo que retorna o resto da divisão por 24
            hora = hora % 24;
        }

        printf("%02d:%02d\n", hora, minuto); // Mostra o horário formatado conforme o especificado na questão
    }

    if (formato == 1) { // Condição para o formato 1

        
        if (minuto > 59) { // Caso os minutos ultrapassem 60 é realizada a subtração e a adição de 1 hora
            minuto = minuto - 60;
            hora++;
        } 

        int hora12 = hora % 12; // Declaração de variável do tipo inteiro que será o resto da divisão por 12
        if (hora12 == 0) { // Caso o resultado seja 0 então a variável será definida como 12
            hora12 = 12;
        }

        if (hora < 12 || hora > 24) { // AM caso a hora passada seja menor que 12 ou maior que 24
            printf("%02d:%02d AM\n", hora12, minuto);
        } else {
            printf("%02d:%02d PM\n", hora12, minuto);
        }
    }
    
}

int main() {

    int hora, minuto, formato;

    printf("Digite a hora da primeira ronda: \n");
    scanf("%d", &hora);
    printf("Digite a minutagem da primeira ronda: \n");
    scanf("%d", &minuto);
    printf("Digite o formato do horario: \n");
    scanf("%d", &formato);

    horario_rondas(hora, minuto, formato);
    horario_rondas(hora + 1, minuto, formato);
    horario_rondas(hora + 2, minuto + 10, formato);
    horario_rondas(hora + 4, minuto + 40, formato);
    horario_rondas(hora + 12, minuto + 5, formato);

    return 0;
}