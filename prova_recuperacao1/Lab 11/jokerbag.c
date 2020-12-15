/*
 * Tarefa de laboratorio 11 - Avaliacao de Recuperacao 1 - Parte 2 - JokerBag!
 *
 * GEX605 AB 2020/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Item; /*vamos criar dessa forma, ai cada jogar vai empilhar uma entrada*/
/*definições da pilha*/
typedef struct elemPilha {
    Item item;
    struct elemPilha *proximo;
} ElemPilha;
typedef struct {
    ElemPilha *topo;
} Pilha;

/*definições da fila*/
typedef struct elemFila {
    Item item;
    struct elemFila *proximo;
} ElemFila;
typedef struct {
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;


/*MÉTODOS DA IMPLEMENTAÇÃO DE PILHA*/
void inserePilha(Pilha *pilha, Item item) {
    ElemPilha *aux;

    /* Cria um novo elemento da lista encadeada que representa a pilha e
     armazena neste novo elemento o item a ser inserido na pilha*/
    aux = malloc(sizeof(ElemPilha));

	/* Como nosso item é um vetor, precisamos atribuir elemeno por elemento*/
	aux->item = item;

    /* Insere o novo elemento no inicio da lista encadeada que representa a
     pilha*/
    aux->proximo = pilha->topo;
    pilha->topo = aux;

}

void removePilha(Pilha *pilha, Item *item) {
    ElemPilha *aux;

    /* Verificar se a pilha esta vazia!*/
	if (pilha == NULL)
		return;


    /* Armazena o primeiro elemento da lista encadeada que representa a pilha
     e remove este primeiro elemento da lista*/
    aux = pilha->topo;
	*item = aux->item;
    pilha->topo = pilha->topo->proximo;

    /* Libera a memoria alocada para o elemento removido*/
    free(aux);
}

void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

/*Verifica se a pilha esta vazia, retorna 1 caso afimativo, senão 0*/
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void liberaPilha(Pilha *pilha) {
    ElemPilha *aux;

    while (pilha->topo != NULL) {
        /* Armazena o primeiro elemento da lista encadeada que representa a
         pilha e remove este primeiro elemento da lista*/
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        /* Libera a memoria alocada para o elemento removido*/
        free(aux);
    }
}

/*MÉTODOS DE IMPLEMENTAÇÃO DA FILA*/
void insereFila(Fila *fila, Item item) {
    ElemFila *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(ElemFila));
    aux->item = item;
    aux->proximo = NULL;

    // Insere o novo elemento no fim da lista encadeada que representa a
    // fila
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

    // Verificar se a fila esta vazia!

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

void inicializaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int filaVazia(Fila *fila) {
    return (fila->primeiro == NULL);
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



int main(){
	
	Pilha *pilha = malloc(sizeof(Pilha)); /*cria a pilha*/
	Fila *fila = malloc(sizeof(Fila));/*cria fila*/
	int n, nLinhas, elemento, removido, isPilha, isFila;
	char operacao;
	
	/*incializa a pilha*/
	inicializaPilha(pilha);

	/*inicializa a fila*/
	inicializaFila(fila);
	
	
	scanf("%d%*c", &n);
	while (n!=0){
		nLinhas = n;
		isPilha=-1;
		isFila=-1;
		while(nLinhas-- > 0){
			/*Lê a operação do usuário e o elemento*/
			scanf("%c %d%*c", &operacao, &elemento); /* %*c é só uma forma de nos livramos do porblema do '\n'*/
			
			if (operacao == 'I'){
				inserePilha(pilha, elemento); //insere o elemento na pilha
				insereFila(fila, elemento);	//insere o elemento na fila

			} else {
				/*primeiro tentamos remover da pilha*/
				if (pilhaVazia(pilha)){
					isPilha=0;
				}
				removePilha(pilha, &removido);
				if (elemento == removido){
					if (isPilha == -1) isPilha=1;
				}else{
					isPilha = 0;
				}
				/*até aqui tratamo a pilha*/

				/*tratamento para ver ser é fila*/
				if (filaVazia(fila)){
					isFila=0;
				}

				removeFila(fila, &removido);
				if (elemento == removido){
					if (isFila == -1) isFila=1;
				}else{
					isFila = 0;
				}

			}

		}
		if(isPilha && isFila){ /* Se for os dois quer dizer que ambos estão */
			printf("nem Turing sabe!\n");
		} else if(isPilha){
			printf("pilha!\n");
		}else if (isFila){
			printf("fila!\n");	
		}else{
			printf("jokerBag!\n");
		}
		liberaPilha(pilha); /*LImpa a pilha para recomeçar depois*/
        liberaFila(fila);/*LImpa a fila para recomeçar depois*/
		scanf("%d%*c", &n);
	}
}
