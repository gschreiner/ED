/*
 * Proposta de solucao para o exercicio 1 sobre filas.
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elemFila {
    Item item;
    struct elemFila *proximo;
} ElemFila;

typedef struct {
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;

void inicializaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int filaVazia(Fila *fila) {
    return (fila->primeiro == NULL);
}

void insereFila(Fila *fila, Item item) {
    ElemFila *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(ElemFila));
    aux->item = item;
    aux->proximo = NULL;

    // Insere o novo elemento no fim da lista encadeada que representa a fila
    if (fila->primeiro == NULL) { // Se a fila esta vazia
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else { // Se a fila nao esta vazia
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}

void removeFila(Fila *fila, Item *item) {
    ElemFila *aux;

    if (fila->primeiro == NULL) {
        printf("Erro na operacao removeFila: fila vazia!\n");
        return;
    }

    // Armazena o item a ser removido da fila
    *item = fila->primeiro->item; // ATENCAO: Depende da definicao do tipo do
                                  // item

    // Armazena o primeiro elemento da lista encadeada que representa a fila e
    // remove este primeiro elemento da lista
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);
}

void liberaFila(Fila *fila) {
    ElemFila *aux;

    while (fila->primeiro != NULL) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
    fila->ultimo = NULL;
}

// A funcao abaixo esta implementada respeitando o seguinte:
// O conteudo da fila recebida como parametro e alterado durante a execucao da
// funcao, mas esta restaurado ao fim da execucao da funcao
int qtdItensFila(Fila *f) {
    Fila fAux;
    Item item;
    int qtdItens;

    inicializaFila(&fAux);

    qtdItens = 0;
    while (filaVazia(f) == 0) { // Enquanto a fila nao esta vazia
        removeFila(f, &item);
        insereFila(&fAux, item);

        qtdItens++;
    }

    while (filaVazia(&fAux) == 0) { // Enquanto a fila nao esta vazia
        removeFila(&fAux, &item);
        insereFila(f, item);
    }

    liberaFila(&fAux); // Sem efeito se a fila ja esta vazia

    return qtdItens;
}

int main() {
    Fila fila;
    int nItens;
    int i;
    Item item;

    inicializaFila(&fila);

    printf("Digite o numero de itens a serem inseridos na fila: ");
    scanf("%d", &nItens);

    for (i = 1; i <= nItens; i++) {
        printf("Digite o item %d: ", i);
        scanf("%d", &item);

        printf("Inserindo na fila o item %d.\n", item);
        insereFila(&fila, item);
    }

    printf("Quantidade de itens presentes na fila: %d\n",
        qtdItensFila(&fila));

    while (filaVazia(&fila) == 0) { // Enquanto a fila nao esta vazia
        removeFila(&fila, &item);
        printf("Item %d removido da fila.\n", item);
    }

    liberaFila(&fila); // Sem efeito se a fila ja esta vazia

    return 0;
}

