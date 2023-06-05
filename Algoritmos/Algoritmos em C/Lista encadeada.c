#include <stdio.h>
#include <stdlib.h>
#define cls system("cls");

typedef struct Lista {
	int info;
	struct Lista* prox;
} lista;

/// prototipos
lista* criarLista(); /// funcao de criacao da lista
lista* inserirLista(lista* l, int i); // funcao inserir inicio
void imprimirLista(lista* l); /// funcao para imprimir lista
int vazia(lista* l); // vereficar se a lista esta vazia
lista* buscar(lista* l, int v); /// busca de elementos na lista
lista* remover(lista* l, int v); /// remocao de elementos
void liberar(lista* l); /// liberar lista
int igual(lista* l1, lista* l2); /// comparar listas
int menu(); /// menu

int main() { /// principal /////////////////////////////////
	int escolher, i, numero, fechar=0, flag;
	lista* tLista;
	while(fechar != 1) {
	cls;
	escolher = menu();
		switch (escolher) {
			case 1:
				tLista = criarLista();
				cls;
				printf("\n Inserir Lista");
				printf("\n Informe um valor para inserir na lista: ");
				scanf("%i", &numero);
				tLista = inserirLista(tLista, numero);
				cls;
				printf("\n Numero inserido com sucesso.\n");
				system("pause");
				break;
			case 2:
				cls;
				printf("\n Imprimir Lista");
				imprimirLista(tLista);
				printf("\n");
				system("pause");
				break;
		}
	}
	return 0;
} ///fimPricipal ///////////////////////

/// funcao de criacao da lista
lista* criarLista() {
	return NULL;
}

// funcao inserir inicio
lista* inserirLista(lista* l, int i) {
	lista* novo = (lista*)malloc(sizeof(lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/// funcao para imprimir lista
void imprimirLista(lista* l) {
	lista* p;

	for(p= l; p!= NULL; p = p->prox) {
		printf("\n-%i", p->info);
	}
}

// menu
int menu() {
	int escolher;
	do {
		printf("\n Informe um numero: ");
		
		printf("\n- (1) Inserir ");
		printf("\n- (2) Imprimir ");
		printf("R: ");
		scanf("%i", &escolher);

		if(escolher != 1 && escolher != 2 && escolher != 3 && escolher != 4 && escolher != 5 &&
		        escolher != 6 && escolher != 7) {
			printf("\n Caracter invalido");
		}
	} while(escolher != 1 && escolher != 2 && escolher != 3 && escolher != 4 && escolher != 5 &&
	        escolher != 6 && escolher != 7);
	return escolher;
}
