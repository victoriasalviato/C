#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include "cliente.h"

// Estrutura de Nó Duplo
typedef struct NoDuplo {
    Cliente cliente;
    struct NoDuplo* ant;
    struct NoDuplo* prox;
} NoDuplo;

// Estrutura de Lista Duplamente Encadeada (Aguardando contato)
typedef struct {
    NoDuplo* inicio;
    NoDuplo* fim;
    int tamanho;
} ListaDupla;

void inicializar_lista_dupla(ListaDupla* l);
void inserir_lista_dupla(ListaDupla* l, Cliente c);
void remover_no_lista_dupla(ListaDupla* l, NoDuplo* no);
NoDuplo* buscar_cliente_nome(ListaDupla* l, const char* nome);

// Relatorios e Utilitários
int quantidade_aguardando(ListaDupla* l);
void listar_aguardando(ListaDupla* l);

#endif
