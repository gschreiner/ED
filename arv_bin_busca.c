#include <stdio.h>
#include <stdlib.h>

typedef int Chave;

typedef struct noArvBinBusca {
    Chave chave;
    struct noArvBinBusca *esq;
    struct noArvBinBusca *dir;
} NoArvBinBusca;

NoArvBinBusca *insereArvBinBusca(NoArvBinBusca *raiz, Chave chave) {
    NoArvBinBusca *novoNo;

    if (raiz == NULL) {
        novoNo = malloc(sizeof(NoArvBinBusca));
        novoNo->chave = chave;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        return novoNo;
    }

    if (chave <= raiz->chave) {
        raiz->esq = insereArvBinBusca(raiz->esq, chave);
    }
    else { // chave > raiz->chave
        raiz->dir = insereArvBinBusca(raiz->dir, chave);
    }
    return raiz;
}

int main() {
    // Vamos representar uma arvore binaria de busca atraves de um ponteiro para
    // a sua raiz
    NoArvBinBusca *raiz;

    // Inicializa a arvore binaria de busca (arvore vazia)
    raiz = NULL;

    raiz = insereArvBinBusca(raiz, 9);

    printf("raiz->chave: %d\n", raiz->chave);

    // ATENCAO: Falta liberar a memoria alocada para a arvore binaria de busca!

    return 0;
}
