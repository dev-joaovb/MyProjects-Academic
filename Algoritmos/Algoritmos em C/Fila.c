#include<stdio.h>
#include<stdlib.h>

/// Estruturas
typedef struct no{
	int valor;
	struct no *proximo;
}No;

//// Prototipos
void inserirFila(No **fila, int numero);
No* removerFila(No **fila);
void imprimir(No *fila);

int main(){ ////////////////
	No *r,*fila = NULL;
	
	int opcao, valor;
		
	do{
		printf("\n0 - Sair");
		printf("\n1 - Inserir");
		printf("\n2 - Remover");
		printf("\n3 Imprimir");
		printf("\n Informe uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\n Informe um valor: ");
				scanf("%d", &valor);
				inserirFila(&fila, valor);
				break;
			case 2:
				r = removerFila(&fila);
				if(r){
					printf("\n Removido: %d\n", r->valor);
					free(r);
				}
				break;
			case 3:
				imprimir(fila);
				break;
			default:
				if(opcao !=0){
					printf("\n Opcao Invalida......");
				}	
		}
		
	}while(opcao != 0);
	
	
	
	
	return 0;
} ////// FIM

///// FUncoes
void inserirFila(No **fila, int numero){
	No *aux, *novo = malloc(sizeof(No));
	if(novo){
		novo->valor = numero;
		novo->proximo = NULL;
		if(*fila == NULL)
			*fila = novo;
		else{
			aux = *fila;
			while(aux->proximo)
				aux = aux->proximo;
				aux->proximo = novo;
		}
	}
	else
		printf("\n Erro ao alocar memoria...");
}
//

No* removerFila(No **fila){
	No *remover = NULL;
	
	if(*fila){
		remover = *fila;
		*fila = remover->proximo;
	}
	else
		printf("\n Fila vazia...");
		return remover;
}
//

void imprimir(No *fila){
	printf("\n ------------ FILA ------------\n");
	while(fila){
		printf("%d -", fila->valor);
		fila = fila->proximo;
	}
	printf("\n ------------ FIM Fila -----------\n");
}
