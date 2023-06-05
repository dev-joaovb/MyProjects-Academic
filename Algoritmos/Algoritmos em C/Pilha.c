#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas
typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char nome[50];
	Data data;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;
}No;

typedef struct{
	No *topo;
	int tamanho;
}Pilha;

//// Prototipos

void criarPilha(Pilha *p);
//
Pessoa lerPessoa();
//
void imprimirPessoa(Pessoa p);
//
void empilhar(Pilha *p);
//
No* desempilhar(Pilha *p);
//
void imprimirPilha(Pilha *p);

int main(){ /////////// principal
	No *remover;
	Pilha p;
	int opcao;
	
	criarPilha(&p);
	
	do{
		printf("\n 0 - Sair\n 1 - Empilhar\n 2 - Desempilhar\n 3 - Imprimir\n R: ");
		scanf ("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				empilhar(&p);
				break;
			
			case 2:
				remover = desempilhar(&p);
				if(remover){
					printf("\n Elemento removido com sucesso...\n");
					imprimirPessoa(remover->p);
					
					free(remover);
				}
				else
					printf("\n Sem No a remover...");
				break;
				
			case 3:
				imprimirPilha(&p);
				break;
			default:
				if(opcao != 0){
					printf("\n Opcao invalida\n");
				}
		}
	}while(opcao != 0);
	
	
	return 0;
} //////// FIM

///// Funcoes


Pessoa lerPessoa(){
	Pessoa p;
	
	printf("\n Digite o nome: ");
	gets(p.nome);
	printf("\n Digite a data de nascimento: ");
	scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);
	fflush(stdin);
	return p;
}
//
void imprimirPessoa(Pessoa p){
	printf("\n Nome: %s\n Data: %2d/%2d/%4d ", p.nome, p.data.dia, p.data.mes, p.data.ano);
}
//
void empilhar(Pilha *p){
	No *novo = malloc(sizeof(No));
	if(novo){
		novo->p = lerPessoa();
		novo->proximo = p->topo;
		p->topo = novo;
		p->tamanho++;
	}
	else
	printf("\n Erro ao alocar memoria...");
}
//
No* desempilhar(Pilha *p){
	if(p->topo){
		No *remover = p->topo;
		p->topo = remover->proximo;
		p->tamanho--;
		return remover;
	}
	else
		printf("\n Pilha vazia!\n");
	return NULL;
}
//
void imprimirPilha(Pilha *p){
	No *aux = p->topo; 
	printf("\n -------------- PILHA Tamanho: %d --------------\n", p->tamanho);
	while(aux){
		imprimirPessoa(aux->p);
		aux = aux->proximo;
	}
	printf("\n -------------- FIM PILHA --------------\n");
}
//
void criarPilha(Pilha *p){
	p->topo == NULL;
	p->tamanho = 0;
}
