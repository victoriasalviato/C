#ifndef PILHA_H
#define PILHA_H

#include "cliente.h"

// Estrutura de Nó de Pilha
typedef struct NoPilha {
    Cliente cliente;
    struct NoPilha* prox;
} NoPilha;

// Estrutura de Pilha (Clientes Arquivados)
typedef struct {
    NoPilha* topo;
} Pilha;

void inicializar_pilha(Pilha* p);
void empilhar(Pilha* p, Cliente c);
int pilha_vazia(Pilha* p);

#endif
