#include "pilha.h"
#include <stdlib.h>

void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}

void empilhar(Pilha* p, Cliente c) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->cliente = c;
    novo->prox = p->topo;
    p->topo = novo;
}

int pilha_vazia(Pilha* p) {
    return (p->topo == NULL);
}
