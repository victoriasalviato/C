
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"

// Calcula diferença de dias (formato esperado: dd/mm/aaaa)
int calcular_dias(char data[]) {
    struct tm tm_data = {0};
    int dia, mes, ano;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) return 0;

    tm_data.tm_mday = dia;
    tm_data.tm_mon = mes - 1;
    tm_data.tm_year = ano - 1900;

    time_t t_data = mktime(&tm_data);
    time_t agora = time(NULL);

    double diff = difftime(agora, t_data);
    return (int)(diff / (60 * 60 * 24));
}
