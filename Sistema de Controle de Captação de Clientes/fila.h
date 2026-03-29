#ifndef FILA_H
#define FILA_H

#include "cliente.h"

// Estrutura de Nó de Fila
typedef struct NoFila {
    Cliente cliente;
    struct NoFila* prox;
} NoFila;

// Estrutura de Fila (Compradores aguardando envio)
typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

void inicializar_fila(Fila* f);
void enfileirar(Fila* f, Cliente c);
int fila_vazia(Fila* f);

#endif
