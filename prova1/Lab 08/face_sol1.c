/*
 * Tarefa de laboratorio 08 - Avaliacao 1 - Parte 1 - Brinde FACE
 *
 * GEX605 AB 2020/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letra1;
    char letra2;
    char letra3;
    char letra4;
} Item;

typedef struct elemPilha {
    Item item;
    struct elemPilha *proximo;
} ElemPilha;

typedef struct {
    ElemPilha *topo;
} Pilha;

void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void inserePilha(Pilha *pilha, Item item) {
    ElemPilha *aux;

    // Cria um novo elemento da lista encadeada que representa a pilha e
    // armazena neste novo elemento o item a ser inserido na pilha
    aux = malloc(sizeof(ElemPilha));
    aux->item = item;

    // Insere o novo elemento no inicio da lista encadeada que representa a
    // pilha
    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void removePilha(Pilha *pilha, Item *item) {
    ElemPilha *aux;

    if (pilhaVazia(pilha) != 0) {
        printf("Erro na operacao removePilha: pilha vazia!\n");
        return;
    }

    // Armazena o item a ser removido da pilha
    *item = pilha->topo->item;

    // Armazena o primeiro elemento da lista encadeada que representa a pilha
    // e remove este primeiro elemento da lista
    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    // Libera a memoria alocada para o elemento removido
    free(aux);
}

void liberaPilha(Pilha *pilha) {
    ElemPilha *aux;

    while (pilha->topo != NULL) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // pilha e remove este primeiro elemento da lista
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
}

int main() {
    Pilha pilha;
    int N;
    int nBrindes;
    int i;
    Item item;
    Item ultimoItem;

    Item itemFACE = { 'F', 'A', 'C', 'E' };

    inicializaPilha(&pilha);

    scanf("%d", &N);

    nBrindes = 0;
    for (i = 0; i < N; i++) {
        if (pilhaVazia(&pilha) != 0) { // Se a pilha esta vazia
            inserePilha(&pilha, itemFACE);
        }

        scanf("\n");
        scanf("%c %c %c %c", &item.letra1, &item.letra2, &item.letra3,
                &item.letra4);

        removePilha(&pilha, &ultimoItem);
        if ((item.letra1 == ultimoItem.letra4)
                && (item.letra2 == ultimoItem.letra3)
                && (item.letra3 == ultimoItem.letra2)
                && (item.letra4 == ultimoItem.letra1)) {
            nBrindes++;
        }
        else {
            inserePilha(&pilha, ultimoItem);
            inserePilha(&pilha, item);
        }
    }

    liberaPilha(&pilha);

    printf("%d\n", nBrindes);

    return 0;
}

