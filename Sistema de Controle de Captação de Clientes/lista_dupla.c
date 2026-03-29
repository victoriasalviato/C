#include "lista_dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_lista_dupla(ListaDupla* l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

void inserir_lista_dupla(ListaDupla* l, Cliente c) {
    NoDuplo* novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    novo->cliente = c;
    novo->prox = NULL;
    novo->ant = l->fim;
    
    if (l->fim != NULL) {
        l->fim->prox = novo;
    } else {
        l->inicio = novo; // É o primeiro elemento inserido
    }
    l->fim = novo;
    l->tamanho++;
}

void remover_no_lista_dupla(ListaDupla* l, NoDuplo* no) {
    if (!no) return;
    
    if (no->ant != NULL) {
        no->ant->prox = no->prox;
    } else {
        l->inicio = no->prox;
    }
    
    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    } else {
        l->fim = no->ant;
    }
    
    free(no);
    l->tamanho--;
}

NoDuplo* buscar_cliente_nome(ListaDupla* l, const char* nome) {
    NoDuplo* atual = l->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

int quantidade_aguardando(ListaDupla* l) {
    return l->tamanho;
}

void listar_aguardando(ListaDupla* l) {
    NoDuplo* atual = l->inicio;
    if (atual == NULL) {
        printf("Nenhum cliente aguardando contato.\n");
        return;
    }
    
    while (atual != NULL) {
        int dias = calcular_dias_aguardando(atual->cliente.data_captacao);
        printf("- Nome: %s | Tempo de espera: %d dia(s)\n", atual->cliente.nome, dias);
        atual = atual->prox;
    }
}
