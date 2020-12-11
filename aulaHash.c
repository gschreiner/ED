#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
  int id;
  char nome[41];
  struct item *proximo;
}; 
typedef struct item Item;

typedef struct {
	Item *primeiro;
} ItemHash;



int hashFunction( int k){
	return k%11;
}


int main(){
	//int *tabelaHash = calloc(11, sizeof(int)); //mesma 
	//calloc = alocar o vetor com malloc e zerar todas as posições
	
	ItemHash tabelaHash[11];
	Item *aux;

	int lido,i, posicaoHash;//, tabelaHash = malloc (sizeof(int)*11);
	for (i =0; i< 11; i++)
		tabelaHash[i].primeiro = NULL;
	

	do {
		aux = malloc(sizeof(Item));
		scanf("%d%*c", &aux->id);

		fgets(aux->nome, sizeof(aux->nome), stdin);
		aux->nome[strcspn(aux->nome, "\n")] = '\0';

		aux->proximo = NULL;
		
		posicaoHash = hashFunction(aux->id);

		if (tabelaHash[posicaoHash].primeiro == NULL)
			tabelaHash[posicaoHash].primeiro = aux;
		else{
			aux->proximo = tabelaHash[posicaoHash].primeiro;
			tabelaHash[posicaoHash].primeiro = aux;
		}

		printf("Incluir mais um: (0 > sai)");
		scanf("%d%*c", &lido);
	} while (lido > 0);


	for (i =0; i< 11; i++){
		if (tabelaHash[i].primeiro == NULL){
			printf("%d -> Vazio\n", i);
		} else{
			aux = tabelaHash[i].primeiro;
			printf("---%d----\n", i);
			while (aux != NULL){
				printf("\tid: %d, n: %s\n", aux->id, aux->nome);
				aux = aux->proximo;
			}
		}
	}


	return 0;
}