#include <stdlib.h>
#include <stdio.h>

typedef struct arv Arv;

struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

Arv* criar_vazia() {
	return NULL;
}

Arv* criar(char c, Arv* sae, Arv* sad) {
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

int vazia(Arv* a) {
	return a == NULL;
}

void imprimir(Arv* a) {
	if(!vazia(a)) {
		printf("%c ", a->info); // mostra a raiz
		imprimir(a->esq); //  mostra subárvore a esquerda
		imprimir(a->dir); // mostra subárvore a direita
	}
}

void imprimir_arvore(Arv* a) {
	printf("<");
	if(!vazia(a)) {
		printf("%c ", a->info); // mostra a raiz
		imprimir_arvore(a->esq); //  mostra subárvore a esquerda
		imprimir_arvore(a->dir); // mostra subárvore a direita
	}
	printf(">");
}

Arv* liberar(Arv* a) {
	if(!vazia(a)) {
		liberar(a->esq);
		liberar(a->dir);
		free(a);
	}
	return NULL;
}

int maior(int a, int b) {
	if(a > b) {
		return a;
	} else {
		return b;
	}
}

int altura(Arv* raiz){
	if((raiz == NULL) || (raiz->esq == NULL && raiz->dir == NULL))
		return 0;
	else
		return 1 + maior(altura(raiz->esq), altura(raiz->dir));
}

int main(int argc, char *argv[]) {
	Arv* a1 = criar('m', criar_vazia(), criar_vazia());
	Arv* a2 = criar('a', criar_vazia(), a1);
	Arv* a3 = criar('o', criar_vazia(), criar_vazia());
	Arv* a4 = criar('p', a3, a2);

	imprimir_arvore(a4);
	liberar(a4);
	return 0;
}
