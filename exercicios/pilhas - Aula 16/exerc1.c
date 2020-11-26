/*
 * Proposta de solucao para o exercicio 1 sobre pilhas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STR_PAR 100

typedef char Item;

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
    *item = pilha->topo->item; // ATENCAO: Depende da definicao do tipo do item

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
    char seqParent[TAM_MAX_STR_PAR + 1];
    Pilha pilha;
    int parentNaoEmpar;
    int i;
    Item item;
    Item itemEsperado;

    printf("Digite a sequencia de parenteses a ser avaliada: ");

    fgets(seqParent, sizeof(seqParent), stdin);
    seqParent[strcspn(seqParent, "\n")] = '\0';

    printf("Sequencia de parenteses a ser avaliada:\n%s\n", seqParent);

    inicializaPilha(&pilha);

    parentNaoEmpar = 0; // Abaixo esta variavel recebera valor 1 se a
                        // sequencia de parenteses contem pelo menos um par de
                        // parenteses que nao esta corretamente emparelhado

    for (i = 0; i < strlen(seqParent); i++) {
        item = seqParent[i];

        if ((item == '(') || (item == '[') || (item == '{'))  {
            inserePilha(&pilha, item);
        }
        else {
            if (item == ')') {
                itemEsperado = '(';
            }
            else if (item == ']') {
                itemEsperado = '[';
            }
            else if (item == '}') {
                itemEsperado = '{';
            }
            else {
                printf("Erro no processamento da sequencia de parenteses: "
                        "caractere invalido!\n");
                liberaPilha(&pilha);
                return 1;
            }

            if (pilhaVazia(&pilha) != 0) { // Se a pilha esta vazia
                parentNaoEmpar = 1;
                break;
            }

            removePilha(&pilha, &item);
            if (item != itemEsperado) {
                parentNaoEmpar = 1;
                break;
            }
        }
    }

    if ((parentNaoEmpar != 0) ||
            (pilhaVazia(&pilha) == 0) /* a pilha nao esta vazia */) {
        printf("Incorreto\n");
    }
    else {
        printf("Correto\n");
    }

    liberaPilha(&pilha);

    return 0;
}

