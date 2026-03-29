#include "fila.h"
#include <stdlib.h>

void inicializar_fila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila* f, Cliente c) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->cliente = c;
    novo->prox = NULL;
    
    // Inserção O(1) no Fim da Fila
    if (f->fim != NULL) {
        f->fim->prox = novo;
    } else {
        f->inicio = novo;
    }
    f->fim = novo;
}

int fila_vazia(Fila* f) {
    return (f->inicio == NULL);
}
