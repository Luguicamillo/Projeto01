
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inserir_tarefa(Lista *lista, Tarefa *tarefa) {
    if (lista->qtde >= 100) {
        return 0;
    }
    lista->vetor[lista->qtde++] = tarefa;
    return 1;
}

Tarefa *cria_tarefa() {
    Tarefa *nova = malloc(sizeof(Tarefa));
    if (!nova) {
        printf("Erro ao alocar memória para a tarefa.\n");
        exit(1);
    }

    printf("Digite o nome da tarefa: ");
    scanf("%19s", nova->nome);
    printf("Digite a prioridade da tarefa: ");
    scanf("%d", &nova->prioridade);
    printf("Digite a duração da tarefa: ");
    scanf("%d", &nova->duracao);

    return nova;
}

void mostra_tarefas(const Lista *lista) {
    if (lista->qtde == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < lista->qtde; i++) {
        printf("--------------------------\n");
        printf("Nome: \t\t%s\n", lista->vetor[i]->nome);
        printf("Prioridade: \t%d\n", lista->vetor[i]->prioridade);
        printf("Duração: \t%d\n", lista->vetor[i]->duracao);
    }
    printf("--------------------------\n");
}

int menu() {
    int opcao;
    printf("--------------------------\n");
    printf("1 - Inserir tarefa\n");
    printf("2 - Remover tarefa\n");
    printf("3 - Consultar tarefa\n");
    printf("4 - Mostrar tarefas\n");
    printf("5 - Ler arquivo\n");
    printf("6 - Gravar arquivo\n");
    printf("7 - Sair\n");
    printf("--------------------------\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int buscar_tarefa(const Lista *lista, const char *nome) {
    for (int i = 0; i < lista->qtde; i++) {
        if (strcmp(lista->vetor[i]->nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void remover_tarefa(Lista *lista) {
    char nome[20];
    printf("Digite o nome da tarefa a ser removida: ");
    scanf("%19s", nome);

    int i = buscar_tarefa(lista, nome);
    if (i == -1) {
        printf("Tarefa não encontrada.\n");
        return;
    }

    free(lista->vetor[i]);
    memmove(&lista->vetor[i], &lista->vetor[i + 1], (lista->qtde - i - 1) * sizeof(Tarefa *));
    lista->qtde--;

    printf("Tarefa removida com sucesso!\n");
}

void consultar_tarefa(const Lista *lista) {
    char nome[20];
    printf("Digite o nome da tarefa a ser consultada: ");
    scanf("%19s", nome);

    int i = buscar_tarefa(lista, nome);
    if (i == -1) {
        printf("Tarefa não encontrada.\n");
        return;
    }

    printf("--------------------------\n");
    printf("Nome: \t\t%s\n", lista->vetor[i]->nome);
    printf("Prioridade: \t%d\n", lista->vetor[i]->prioridade);
    printf("Duração: \t%d\n", lista->vetor[i]->duracao);
    printf("--------------------------\n");
}

void escrever_tarefa(FILE *arquivo, Tarefa *tarefa) {
    fprintf(arquivo, "%s\n%d\n%d\n", tarefa->nome, tarefa->prioridade, tarefa->duracao);
}

void gravar_arquivo(const Lista *lista) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    for (int i = 0; i < lista->qtde; i++) {
        escrever_tarefa(arquivo, lista->vetor[i]);
    }

    fclose(arquivo);
    printf("Tarefas gravadas com sucesso!\n");
}

Tarefa *ler_tarefa(FILE *arquivo) {
    Tarefa *tarefa = malloc(sizeof(Tarefa));
    if (!tarefa || fscanf(arquivo, "%19s %d %d", tarefa->nome, &tarefa->prioridade, &tarefa->duracao) != 3) {
        free(tarefa);
        return NULL;
    }
    return tarefa;
}

void ler_arquivo(Lista *lista) {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (lista->qtde < 100) {
        Tarefa *tarefa = ler_tarefa(arquivo);
        if (!tarefa) break;
        inserir_tarefa(lista, tarefa);
    }

    fclose(arquivo);
    printf("Tarefas lidas do arquivo.\n");
}

void liberar_lista(Lista *lista) {
    for (int i = 0; i < lista->qtde; i++) {
        free(lista->vetor[i]);
    }
    free(lista);
}
