#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
	int valor;
	struct no *prox;
}No;


void inserir_na_fila (No **fila, int num) {
	No *aux, *novo = malloc (sizeof(No));
	if (novo)
	{
		novo->valor = num;
		novo->prox = NULL;
		if (*fila == NULL)
			*fila = novo;
		else
		{
			aux = *fila;
			while (aux->prox)
				aux = aux->prox;
			aux->prox = novo;
		}
	}
	else
		printf("\nErro ao alocar memoria.");
}


No* remover_da_fila(No **fila) {
	No *remover = NULL;

	if (*fila)
	{
		remover = *fila;
		*fila = remover->prox;
	}
	else
		printf("\tFila vazia\n");
	return remover;
}

void imprimir (No *fila){
	printf("\t--------- FILA--------\n\t");
	while (fila){
		printf("%d ", fila->valor);
		fila = fila->prox;
	}
	printf("\t---------FIM FILA--------\n");
}





int main() {
	No *r, *fila = NULL;
	int opcao, valor;

	do
	{
		printf("\t0 - Sair\nt1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			printf("Digite o RA do aluno: ");
			scanf("%d", &valor);
			inserir_na_fila(&fila, valor);
			break;
		case 2:
			r = remover_da_fila(&fila);
			if (r)
			{
				printf("Removido: %d\n", r->valor);
				free(r);
			}
			break;
		case 3:
			imprimir(fila);
			break;
		default:
			if (opcao != 0)
				printf("\nOpcao Invalida!\n");
		}
	} while (opcao != 0);

	return 0;
}

