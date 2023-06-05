#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct pilha{
	int n;
	float vetor[N];
}tPilha; 

tPilha* criarPilha(){
	tPilha* p = (tPilha*)malloc(sizeof(tPilha));
	p->n = 0;
	return p;
}

void push(tPilha* p, float v){
	if(p->n == N){
		printf("\n Capacidade maxima!!");
		exit(1);
	}
	p->vetor[p->n] = v;
	p->n++;
}

int vazia(tPilha* p){
	return (p->n == 0);
}

float pop(tPilha* p){
	float v;
	
	if(vazia(p)){
		printf("\n Pilha vazia");
		exit(1);
	}
	v = p->vetor[p->n - 1];
	p->n--;
}


void liberar(tPilha* p){
	free(p);
}

float topo(tPilha* p){
	if(vazia(p)){
		printf("\n Pilha vazia");
		exit(1);
	}
	return p->vetor[p->n - 1];
}


int main(){
	tPilha* p;
	
	p = criarPilha();
	push(p, 10);
	push(p, 34);
	push(p, 77);
	printf("\n Topo: %f", topo(p));
	pop(p);
	printf("\n Topo: %f", topo(p));
	pop(p);
	printf("\n Topo: %f", topo(p));
	pop(p);
	printf("\n Topo: %f", topo(p));
}

