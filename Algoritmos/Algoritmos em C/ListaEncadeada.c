#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;	
}No;

/// Prototipos
void inserirInicio(No **lista, int numero);
void inserirFim(No **lista, int numero);
void inserirMeio(No **lista, int numero, int anterior);
void imprimir(No *no);
///

int main(){ ////// INICIO
	
	No *lista = NULL;
	int opcao, valor, anterior;
	
	do{
		printf("\n 0 - Sair");
		printf("\n 1 - InserirInicio");
		printf("\n 2 - InserirFim");
		printf("\n 3 - InserirMeio");
		printf("\n 4 - Imprimir");
		printf("\n R: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\n Informe um valor: ");
				scanf("%d", &valor);
				inserirInicio(&lista, valor);
				break;
			case 2:
				printf("\n Informe um valor: ");
				scanf("%d", &valor);
				inserirFim(&lista, valor);
				break;
			case 3:
				printf("\n Informe um valor: ");
				scanf("%d", &valor);
				printf("\n Agora o valor de referencia: ");
				scanf("%d", &anterior);
				inserirMeio(&lista, valor, anterior);
				break;
			case 4:
				imprimir(lista);
				break;
			default:
				if(opcao != 0){
					printf("\n Opcao invalidada.");
				}
		}
	}while(opcao != 0);
	
	return 0;
}////// FIM

void inserirInicio(No **lista, int numero){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor =  numero;
		novo->proximo = *lista;
		*lista = novo;
	}
	else
		printf("\n Erro ao alocar memoria...");
}
///

void inserirFim(No **lista, int numero){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = numero;
		novo->proximo = NULL;
		
		//é o proximo??
		if(*lista == NULL)
			*lista = novo;
		else{
			aux = *lista;
			while(aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo; 	
		}		
	}
	else
		printf("\n Erro ao alocar memoria...");
}
////

void inserirMeio(No **lista, int numero, int anterior){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = numero;
		/// é o primeiro?
		if(*lista == NULL){
			novo->proximo = NULL;
			*lista = novo;
		}
		else
			aux = *lista;
			while(aux->valor != anterior && aux->proximo)
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
			
		
	}
	else{
		printf("\n Erro ao alocar memoria....");
	}
}
///

void imprimir(No *no){
	printf("\n ----- LISTA -----\n");
	while(no){
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n\n");
}
