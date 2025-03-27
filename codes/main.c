#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    Lista *lista = malloc(sizeof(Lista));
    lista->qtde = 0;

    int opcao;
    do {
        opcao = menu();

        if (opcao == 1) {
            Tarefa *nova = cria_tarefa();
            inserir_tarefa(lista, nova);
        } else if (opcao == 2) {
            gerenciar_tarefa(lista);  //Nova função que eu botei 
        } else if (opcao == 3) {
            mostra_tarefas(lista);
        } else if (opcao == 4) {
            ler_arquivo(lista);
        } else if (opcao == 5) {
            gravar_arquivo(lista);
        }

    } while (opcao != 6);

    for (int i = 0; i < lista->qtde; i++) {
        free(lista->vetor[i]);
    }
    free(lista);  

    return 0;
}
