/*
	Proposta de solução para o exercício 1 de lista encadeada.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

struct funcionario{
  int id;
  char nome[41];
  double salario;
  Data nascimento;
  struct funcionario *proximo;
}; 
typedef struct funcionario Funcionario;

void imprimeLista(Funcionario *lista){
	Funcionario *aux;
	for (aux = lista; aux != NULL; aux = aux->proximo){
		printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n", aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
	}
}


int main(){
	Funcionario *primeiro, *segundo;

	/*Criando o primeiro funcionário*/
	primeiro = malloc (sizeof(Funcionario));
	snprintf(primeiro->nome, sizeof(primeiro->nome),"%s", "Joselindo Sirvinha");
    primeiro->id=1;
	primeiro->nascimento.dia= 11;
    primeiro->nascimento.mes= 8;
    primeiro->nascimento.ano=1900;
    primeiro->salario = 945.67;
    primeiro->proximo = NULL;
	/*Fim criação primeiro*/

	/*Criando o segundo funcionário*/
	segundo = malloc (sizeof(Funcionario));
	snprintf(segundo->nome, sizeof(segundo->nome),"%s", "Joselindo Sirvinha");
    segundo->id=2;
	segundo->nascimento.dia= 11;
    segundo->nascimento.mes= 8;
    segundo->nascimento.ano=1900;
    segundo->salario = 945.67;
    segundo->proximo = NULL;
	//encadeamento
	primeiro->proximo = segundo;
	/*Fim criação segundo*/

	imprimeLista(primeiro);

	/*antes de encerrar apagamos os endereços de memoria que estavamos utilizando
		como apenas temos 2 elementos e sabemos quem são eles podemos apagá-los diretamente.
	*/
	free(primeiro);
	free(segundo); 


	return 0;
}