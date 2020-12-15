/*
 * Tarefa de laboratorio 10 - Avaliacao de Recuperacao 1 - Parte 1 - Expressao
 * Logica
 *
 * GEX605 AB 2020/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

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
    int nValores;
    int nOperadores;
    int i;
    char caract;
    Item item1;
    Item item2;
    char resultado;

    inicializaPilha(&pilha);

    // Le numero de caracteres da expressao logica escrita usando a
    // representacao alternativa
    scanf("%d", &N);

    nValores = 0;
    nOperadores = 0;
    for (i = 0; i < N; i++) {
        scanf(" %c", &caract);

        if (caract == 'v') {
            nValores++;

            item1 = 1;

            inserePilha(&pilha, item1);
        } else if (caract == 'f') {
            nValores++;

            item1 = 0;

            inserePilha(&pilha, item1);
        }
        else if (caract == 'E') {
            nOperadores++;

            removePilha(&pilha, &item1);
            removePilha(&pilha, &item2);

            inserePilha(&pilha, item1 & item2);
        }
        else if (caract == 'O') {
            nOperadores++;

            removePilha(&pilha, &item1);
            removePilha(&pilha, &item2);

            inserePilha(&pilha, item1 | item2);
        }
        else if (caract == 'X') {
            nOperadores++;

            removePilha(&pilha, &item1);
            removePilha(&pilha, &item2);

            inserePilha(&pilha, item1 ^ item2);
        }
        else if (caract == 'N') {
            nOperadores++;

            removePilha(&pilha, &item1);

            inserePilha(&pilha, !item1);
        }
    }

    // Obtem o resultado da expressao logica escrita usando a representacao
    // alternativa
    removePilha(&pilha, &item1);
    if (item1 == 1) {
        resultado = 'v';
    }
    else { // item1 == 0
        resultado = 'f';
    }

    liberaPilha(&pilha);

    printf("Valores: %d\n", nValores);
    printf("Operadores: %d\n", nOperadores);
    printf("Resultado: %c\n", resultado);

    return 0;
}

