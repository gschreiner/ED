#include <stdio.h>
#include <stdlib.h>

typedef char Item[4]; /*vamos criar dessa forma, ai cada jogar vai empilhar uma entrada*/

typedef struct elemPilha {
    Item item;
    struct elemPilha *proximo;
} ElemPilha;

typedef struct {
    ElemPilha *topo;
} Pilha;

void inserePilha(Pilha *pilha, Item item) {
    ElemPilha *aux;

    /* Cria um novo elemento da lista encadeada que representa a pilha e
     armazena neste novo elemento o item a ser inserido na pilha*/
    aux = malloc(sizeof(ElemPilha));
    
	/* Como nosso item é um vetor, precisamos atribuir elemeno por elemento*/
	aux->item[0] = item[0];
	aux->item[1] = item[1];
	aux->item[2] = item[2];
	aux->item[3] = item[3];

    /* Insere o novo elemento no inicio da lista encadeada que representa a
     pilha*/
    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void removePilha(Pilha *pilha) {
    ElemPilha *aux;

    /* Verificar se a pilha esta vazia!*/
	if (pilha == NULL)
		return;


    /* Armazena o primeiro elemento da lista encadeada que representa a pilha
     e remove este primeiro elemento da lista*/
    aux = pilha->topo;
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

int comparaAoContrario(Item topo, Item novo){
	/*Faz a comparação elemento a elemento para ver se o topo é o contrário do novo. Compara o primeiro de topo com o ultimo do novo, e vai sucessivamente até comparar o ultimo do topo com o primeiro do novo*/
	return (topo[0] == novo[3] && topo[1] == novo[2] && topo[2] == novo[1] && topo[3] == novo[0] );
}


int main(){
	Pilha *pilha = malloc(sizeof(Pilha)); /*cria a pilha*/
	Item face = {'F','A','C','E'}; /*item que representa a FACE, adicionado pelos organizadores quando a pilha esta vazia*/
	Item leitura;
	/*incializa a pilha*/
	inicializaPilha(pilha);



	int n, premio = 0;
	
	scanf("%d\n", &n);
	while(n-- > 0){
		if (pilhaVazia(pilha)){ /* se a pilha estiver vazia, empilha a F A C E.*/
			inserePilha(pilha, face); /*empilha (adiona a pilha) o valor F A C E*/
		}
		scanf("%c %c %c %c%*c", &leitura[0], &leitura[1],&leitura[2],&leitura[3]); /* %*c é só uma forma de nos livramos do porblema do '\n'*/

		if (comparaAoContrario(pilha->topo->item, leitura)){
			removePilha(pilha);
			premio++;
		}else{
			inserePilha(pilha, leitura);
		}
	}
	printf("%d\n", premio);
	liberaPilha(pilha);
}
