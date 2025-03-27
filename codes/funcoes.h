#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct 
{
    char nome[20];
    int prioridade;
    int duracao;
} Tarefa;

typedef struct 
{
    Tarefa *vetor[100];
    int qtde;
} Lista;

int inserir_tarefa(Lista *, Tarefa *);

Tarefa *cria_tarefa();

void mostra_tarefas(Lista *);

int menu();

void gerenciar_tarefa(Lista *);

void gravar_arquivo(Lista *);

void ler_arquivo(Lista *);

#endif
