
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[20];
    int prioridade;
    int duracao;
} Tarefa;

typedef struct {
    Tarefa *vetor[100];
    int qtde;
} Lista;

int inserir_tarefa(Lista *, Tarefa *);
Tarefa *cria_tarefa();
void mostra_tarefas(const Lista *);
int menu();
void remover_tarefa(Lista *);
void consultar_tarefa(const Lista *);
void gravar_arquivo(const Lista *);
void ler_arquivo(Lista *);
int buscar_tarefa(const Lista *, const char *);
void liberar_lista(Lista *);

#endif
