#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    Lista *lista = malloc(sizeof(Lista));
    if (!lista) {
        printf("Erro ao alocar memória para a lista.\n");
        return 1;
    }
    lista->qtde = 0;

    int opcao;
    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                inserir_tarefa(lista, cria_tarefa());
                break;
            case 2:
                remover_tarefa(lista);
                break;
            case 3:
                consultar_tarefa(lista);
                break;
            case 4:
                mostra_tarefas(lista);
                break;
            case 5:
                ler_arquivo(lista);
                break;
            case 6:
                gravar_arquivo(lista);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 7);

    liberar_lista(lista);
    return 0;
}
