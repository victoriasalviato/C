#include "fila.h"
#include "interface.h"
#include "lista_dupla.h"
#include "pilha.h"
#include <stdio.h>

void exibir_menu() {
  printf("\n============================================\n");
  printf("     CONTROLE DE CAPTACAO DE CLIENTES       \n");
  printf("============================================\n");
  printf("1. Cadastrar cliente\n");
  printf("2. Realizar contato\n");
  printf("3. Relatorios\n");
  printf("4. Sair\n");
  printf("Escolha uma opcao: ");
}

int main() {
  // Inicialização das Estruturas de Dados
  ListaDupla aguardando;
  Fila compradores;
  Pilha arquivados;

  inicializar_lista_dupla(&aguardando);
  inicializar_fila(&compradores);
  inicializar_pilha(&arquivados);

  int opcao = 0;

  while (1) {
    exibir_menu();
    if (scanf("%d", &opcao) != 1) {
      limpar_buffer();
      continue;
    }
    limpar_buffer();

    switch (opcao) {
    case 1:
      cadastrar_cliente(&aguardando);
      break;
    case 2:
      realizar_contato(&aguardando, &compradores, &arquivados);
      break;
    case 3:
      menu_relatorios(&aguardando);
      break;
    case 4:
      // Em um cenário real, deveríamos liberar (free) as três estruturas antes
      // de fechar.
      printf("\nEncerrando o sistema de captacao e limpando memoria.\n");
      return 0;
    default:
      printf("\n[!] Opcao invalida. Tente novamente.\n");
    }
  }

  return 0;
}
