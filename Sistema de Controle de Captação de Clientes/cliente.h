#ifndef CLIENTE_H
#define CLIENTE_H

#include <time.h>

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
    time_t data_captacao;
    
    // Dados adicionais caso o cliente compre:
    char data_nascimento[15];
    char rua[100];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[15];
    char cpf[15];
} Cliente;

// Funcoes utilitarias
int calcular_dias_aguardando(time_t data_captacao);
void ler_string(char* destino, int tamanho);

#endif
