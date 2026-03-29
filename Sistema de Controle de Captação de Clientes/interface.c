#include "interface.h"
#include <stdio.h>
#include <time.h>

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_cliente(ListaDupla* aguardando) {
    Cliente novo;
    printf("\n==== CADASTRO DE CLIENTE ====\n");
    printf("Nome: ");
    ler_string(novo.nome, 100);
    printf("Telefone: ");
    ler_string(novo.telefone, 20);
    printf("Email: ");
    ler_string(novo.email, 100);
    
    // Configura a data atual como data de captacao
    time(&novo.data_captacao);
    
    inserir_lista_dupla(aguardando, novo);
    printf("\n[Sucesso] Cliente '%s' cadastrado!\n", novo.nome);
}

void realizar_contato(ListaDupla* aguardando, Fila* compradores, Pilha* arquivados) {
    if (aguardando->inicio == NULL) {
        printf("\n[Aviso] Nao ha clientes aguardando contato.\n");
        return;
    }
    
    NoDuplo* atual = aguardando->inicio;
    int esc = 0;
    
    while (atual != NULL) {
        int dias = calcular_dias_aguardando(atual->cliente.data_captacao);
        printf("\n===================================\n");
        printf("         ATENDIMENTO ATUAL           \n");
        printf("===================================\n");
        printf("Nome: %s\n", atual->cliente.nome);
        printf("Telefone: %s\n", atual->cliente.telefone);
        printf("Email: %s\n", atual->cliente.email);
        printf("Dias Aguardando: %d\n", dias);
        printf("-----------------------------------\n");
        
        printf("Acoes:\n");
        printf("1. Exibir proximo cliente\n");
        printf("2. Exibir cliente anterior\n");
        printf("3. Buscar cliente por nome\n");
        printf("4. Finalizar atendimento\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha: ");
        
        if (scanf("%d", &esc) != 1) {
            limpar_buffer();
            continue;
        }
        limpar_buffer();
        
        if (esc == 1) {
            if (atual->prox != NULL) {
                atual = atual->prox;
            } else {
                printf("\n[!] Ja esta no ultimo cliente da lista.\n");
            }
        } 
        else if (esc == 2) {
            if (atual->ant != NULL) {
                atual = atual->ant;
            } else {
                printf("\n[!] Ja esta no primeiro cliente da lista.\n");
            }
        } 
        else if (esc == 3) {
            char nome_busca[100];
            printf("\nDigite o nome exato para busca: ");
            ler_string(nome_busca, 100);
            NoDuplo* res = buscar_cliente_nome(aguardando, nome_busca);
            if (res != NULL) {
                atual = res;
            } else {
                printf("\n[!] Cliente '%s' nao encontrado. Permanecendo no atual.\n", nome_busca);
            }
        } 
        else if (esc == 4) {
            int comprou = 0;
            printf("\nO cliente %s comprou o produto?\n", atual->cliente.nome);
            printf("1. Sim\n2. Nao\nEscolha: ");
            if (scanf("%d", &comprou) != 1) {
                limpar_buffer();
                comprou = 2; // padrao
            }
            limpar_buffer();
            
            if (comprou == 1) {
                printf("\n--- Dados Adicionais (Efetivacao de Venda) ---\n");
                printf("Data de nascimento (dd/mm/aaaa): ");
                ler_string(atual->cliente.data_nascimento, 15);
                printf("Rua: ");
                ler_string(atual->cliente.rua, 100);
                printf("Numero: ");
                scanf("%d", &atual->cliente.numero);
                limpar_buffer();
                printf("Bairro: ");
                ler_string(atual->cliente.bairro, 50);
                printf("Cidade: ");
                ler_string(atual->cliente.cidade, 50);
                printf("Estado (UF): ");
                ler_string(atual->cliente.estado, 3);
                printf("CEP: ");
                ler_string(atual->cliente.cep, 15);
                printf("CPF: ");
                ler_string(atual->cliente.cpf, 15);
                
                enfileirar(compradores, atual->cliente);
                printf("\n[Logistica] Cliente movido para FILA DE COMPRADORES! Venda fechada.\n");
                
            } else {
                int acao_recusa = 0;
                printf("\nDeseja arquivar os dados ou excluir definitivamente?\n");
                printf("1. Arquivar\n2. Excluir\nEscolha: ");
                if (scanf("%d", &acao_recusa) != 1) {
                    limpar_buffer();
                    acao_recusa = 2;
                }
                limpar_buffer();
                
                if (acao_recusa == 1) {
                    empilhar(arquivados, atual->cliente);
                    printf("\n[Historico] Cliente movido para PILHA DE ARQUIVADOS.\n");
                } else {
                    printf("\n[Lixeira] Dados do cliente excluidos defitivamente.\n");
                }
            }
            
            // Resolve o nó atual para remover da lista Aguardando
            NoDuplo* remover = atual;
            atual = atual->prox ? atual->prox : atual->ant; // tenta ir pro proximo, se nao houver, volta
            remover_no_lista_dupla(aguardando, remover);
            
            if (atual == NULL) {
                printf("\n--- Sem mais clientes aguardando. Voltando ao menu... ---\n");
                break;
            }
        }
        else if (esc == 5) {
            break; // Voltar menu principal
        } else {
            printf("\n[!] Opcao invalida.\n");
        }
    }
}

void menu_relatorios(ListaDupla* aguardando) {
    int esc = 0;
    while(1){
        printf("\n==== RELATORIOS ====\n");
        printf("1. Numero de clientes aguardando contato\n");
        printf("2. Lista de clientes aguardando contato (com dias)\n");
        printf("3. Voltar\n");
        printf("Escolha: ");
        if (scanf("%d", &esc) != 1) {
            limpar_buffer();
            continue;
        }
        limpar_buffer();
        
        if (esc == 1) {
            printf("\n[Relatorio] Numero de clientes aguardando: %d\n", quantidade_aguardando(aguardando));
        } else if (esc == 2) {
            printf("\n");
            listar_aguardando(aguardando);
        } else if (esc == 3) {
            break;
        } else {
            printf("\n[!] Opcao invalida.\n");
        }
    }
}
