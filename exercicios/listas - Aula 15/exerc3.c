/*
	Proposta de solução para o exercício 3 de lista encadeada.

	3- Implemente uma função que receba um vetor de valores inteiros com N elementos e construa uma lista encadeada armazenando os elementos do vetor (elemento a elemento). Assim, se for recebido por parâmetro o vetor v[4] = {1,21,4,6} a função deve retornar uma lista encadeada onde o primeiro elemento é ‘1’, o segundo o ‘21’, o terceiro o ‘4’ e assim por diante. A função deve ter a seguinte assinatura: ListaInt *constroiLista (int n, int *v);


*/

#include<stdio.h>
#include<stdlib.h>


struct lista{
  int valor;
  struct lista *proximo;
}; 
typedef struct lista ListaInt;

void imprimeLista(ListaInt *lista){
	ListaInt *aux;
	if (lista == NULL){
		printf("Lista vazia\n");
		return;
	}
	for (aux = lista; aux != NULL; aux = aux->proximo){
		printf("valor: %d, ", aux->valor);
	}
}

ListaInt *constroiLista (int n, int *v){
	ListaInt *primeiro, *ultimo, *aux; /*Vamos utilizar o ultimo para encadear os elementos na forma correta. Uma opção seria encadear tudo com o primeiro, mas andando na lista de tras para frente.*/
	int i;
	primeiro = malloc(sizeof(ListaInt));
	primeiro->valor = v[0];
	primeiro->proximo = NULL;

	ultimo = primeiro; 
	/*Como já adicionamos o primeiro, então podemos começar o i de 1, já que a posição 0 já foi tratada.*/
	for(i=1; i<n; i++){
		aux = malloc(sizeof(ListaInt)); 
		aux->valor = v[i];
		aux->proximo = NULL;
		/*Faz o encademamento do novo elemento no fim da lista*/
		ultimo->proximo = aux;
		ultimo = aux; /*torna o novo elemento (aux) o último*/
	}

	/* uma alternativa para fazer a mesma coisa seria
		for(i=1; i<n; i++){
			ultimo->proximo = malloc(sizeof(ListaInt)); 
			ultimo = ultimo->proximo;
			
			ultimo->valor = v[i];
			ultimo->proximo = NULL;
		}
		Faz a mesma coisa que o código anterior, mas sem usar o aux;
	*/

	return primeiro;
}

/*Função para limpar a memoria*/
void limpaTodaLista(ListaInt primeiro){
	ListaInt *aux;
	while (primeiro != NULL){
		aux = primeiro;
		primeiro = primeiro->proximo;
		free(aux);
	}
}

int main(){
	ListaInt *primeiro = NULL;
	int n,i, *vet;

	/*Lendo os valores*/
	printf("Digite o número de valores: ");
	scanf("%d", &n);

	vet = malloc(sizeof(int)*n); //aloca o vetor dinamicamente.

	printf("\nDigite todos os valores separados por ',' sem espaços. (Ex: 1,2,3)\n");

	for (i=0; i<n; i++){
		scanf("%d,", &vet[i]);
	}
	/*Cria a lista*/
	primeiro = constroiLista(n, vet);

	/*Imprimindo a lista*/
	imprimeLista(primeiro);

	/*Vamos limpara a memoria, remover todos nossos ponteiros*/
	limpaTodaLista(primeiro);
	free(vet);
	
	printf("\nTerminamos!\n");


	return 0;
}