#ifndef SISTEMA_CAPTACAO_INTERFACE_H
#define SISTEMA_CAPTACAO_INTERFACE_H

#include "lista_dupla.h"
#include "fila.h"
#include "pilha.h"

void limpar_buffer(void);
void cadastrar_cliente(ListaDupla* aguardando);
void realizar_contato(ListaDupla* aguardando, Fila* compradores, Pilha* arquivados);
void menu_relatorios(ListaDupla* aguardando);

#endif
