#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inserir_tarefa(Lista *lista, Tarefa *tarefa){
    if(lista->qtde == 100){
        return 0;
    }
    lista->vetor[lista->qtde] = tarefa;
    lista->qtde++;
    return 1;
}

Tarefa *cria_tarefa(){
    Tarefa *nova = malloc(sizeof(Tarefa));
    printf("Digite o nome da tarefa: ");
    scanf("%s", nova->nome);
    printf("Digite a prioridade da tarefa: ");
    scanf("%d", &nova->prioridade);
    printf("Digite a duração da tarefa: ");
    scanf("%d", &nova->duracao);
    return nova;
}

void mostra_tarefas(Lista *lista){
    for(int i = 0; i < lista->qtde; i++){
        printf("--------------------------\n");
        printf("Nome: \t\t%s\n", lista->vetor[i]->nome);
        printf("Prioridade: \t%d\n", lista->vetor[i]->prioridade);
        printf("Duração: \t%d\n", lista->vetor[i]->duracao);
        printf("--------------------------\n");
    }
}

int menu(){
    int opcao;
    
    printf("--------------------------\n");
    printf("1 - inserir tarefa\n");
    printf("2 - remover tarefa\n");
    printf("3 - consultar tarefa\n");
    printf("4 - mostrar tarefas\n");
    printf("5 - ler arquivo\n");
    printf("6 - gravar arquivo\n");
    printf("7 - sair\n");
    printf("--------------------------\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void remover_tarefa(Lista *lista){
    char tarefa[20];
    int i;
    printf("--------------------------\n");
    printf("Digite o nome da tarefa a ser removida: ");
    scanf("%s", tarefa);
    for(i = 0; i < lista->qtde; i++){
        if(strcmp(lista->vetor[i]->nome, tarefa) == 0){
            break;
        }
    }

    if(i == lista->qtde){
        printf("--------------------------\n");
        printf("Tarefa não encontrada\n");
        printf("--------------------------\n");
        return;
    }

    free(lista->vetor[i]);

    for(int j = i; j < lista->qtde - 1; j++){
        lista->vetor[j] = lista->vetor[j + 1];
    }
    lista->qtde--;

    printf("\nTarefa removida com sucesso\n");
    printf("--------------------------\n");

}

void consultar_tarefa(Lista *lista){
    char tarefa[20];
    int i;
    printf("--------------------------\n");
    printf("Digite o nome da tarefa a ser consultada: ");
    scanf("%s", tarefa);
    for(i = 0; i < lista->qtde; i++){
        if(strcmp(lista->vetor[i]->nome, tarefa) == 0){
            printf("--------------------------\n");
            printf("Nome: \t\t%s\n", lista->vetor[i]->nome);
            printf("Prioridade: \t%d\n", lista->vetor[i]->prioridade);
            printf("Duração: \t%d\n", lista->vetor[i]->duracao);
            printf("--------------------------\n");
            break;
        }
    }

    if(i == lista->qtde){
        printf("--------------------------\n");
        printf("Tarefa não encontrada\n");
        printf("--------------------------\n");
        return;
    }

}

void gravar_arquivo(Lista *lista) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    for (int i = 0; i < lista->qtde; i++) {
        fprintf(arquivo, "%s\n", lista->vetor[i]->nome);
        fprintf(arquivo, "%d\n", lista->vetor[i]->prioridade);
        fprintf(arquivo, "%d\n", lista->vetor[i]->duracao);
    }

    fclose(arquivo);
    printf("Tarefas gravadas com sucesso no arquivo tarefas.txt.\n");
}

void ler_arquivo(Lista *lista) {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (!feof(arquivo)) {
        Tarefa *tarefa = malloc(sizeof(Tarefa));
        if (fscanf(arquivo, "%19s", tarefa->nome) != 1) break;
        fscanf(arquivo, "%d", &tarefa->prioridade);
        fscanf(arquivo, "%d", &tarefa->duracao);
        inserir_tarefa(lista, tarefa);
    }

    fclose(arquivo);
    printf("Tarefas lidas do arquivo tarefas.txt.\n");
}