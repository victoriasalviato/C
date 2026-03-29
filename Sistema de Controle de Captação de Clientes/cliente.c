#include "cliente.h"
#include <stdio.h>
#include <string.h>

int calcular_dias_aguardando(time_t data_captacao) {
    time_t now;
    time(&now);
    // difftime retorna diferenca em segundos, dividir por (60*60*24) da os dias
    double segundos = difftime(now, data_captacao);
    return (int)(segundos / (60 * 60 * 24));
}

void ler_string(char* destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        size_t len = strlen(destino);
        if (len > 0 && destino[len-1] == '\n') {
            destino[len-1] = '\0';
        }
    }
}
