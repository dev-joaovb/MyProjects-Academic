// Sintese
//   objetivo "?rvore Bin?ria de Busca"
//   autor "Edson F. da Fonseca & Turma de ED de ES de 2020/2"
//   data "02/10/2020"
#include <stdio.h>
#include <stdlib.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenacao
	char descricao[30];
};

struct tNo {
	struct tNo *esq;
	struct tProduto dado;
	struct tNo *dir;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void incluir(struct tNo**, struct tNo*);
//void listar(struct tDescritor);
struct tNo *consultar(struct tNo*, int);
//void excluir(struct tDescritor*, struct tNo*);
//void destruir(struct tDescritor*);

//*** Bloco Principal **********************************************************
int main(void) {
	struct tNo *p, *arvore=NULL;
	int opcao, codigo;
	
	do {
        opcao = menu();
        switch (opcao) {
               case 1: 
                    printf("\n\n*** Inclusao ***\n\n");
                    p = (struct tNo *)malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    fflush(stdin);
                    gets(p->dado.descricao);
                    incluir(&arvore, p); // Incluir o no com produto criado na lista
	                break;
               case 2: 
                    printf("\n\n*** Consulta ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(arvore, codigo);
                    if (p != NULL)
	               		printf("Descricao......: %s\n", p->dado.descricao);
	               	else
	               		printf("Codigo nao encontrado!\n");
	                break;
               case 3: 
                    printf("\n\n*** Listagem ***\n\n");
                    //listar(lista); // Listar (mostrar na tela) todos os produtos
	                break;
               case 4: 
                    printf("\n\n*** Alteracao ***\n\n");
                    printf("Digite o codigo...: ");
                    scanf("%d", &codigo);
                    //p = consultar(lista, codigo);
                    if (p != NULL) {
	               		printf("Descricao.........: %s\n", p->dado.descricao);
	                    printf("Digite a descricao: ");
	                    fflush(stdin);
	                    gets(p->dado.descricao);
					}
	               	else
	               		printf("Codigo nao encontrado!\n");	                
					break;
               case 5: 
                    printf("\n\n*** Exclusao ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    //p = consultar(lista, codigo);
                    if (p != NULL) {
	               		printf("Descricao......: %s\n", p->dado.descricao);
//	               		excluir(&lista, p);
					}
	               	else
	               		printf("Codigo nao encontrado!\n");
	                break;
        }
    } while (opcao != 0);
    //destruir(&lista);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Consulta\n");
    printf("3. \"Listagem\"\n");
    printf("4. Alteracao\n");
	printf("5. Exclusao\n");
	printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inclusao *****************************************************************
void incluir(struct tNo **raiz, struct tNo *novo) {
	if (*raiz == NULL) {
		*raiz = novo;
		novo->esq = novo->dir = NULL;
	}
		if (novo->dado.codigo < (*raiz)->dado.codigo)
			incluir(&((*raiz)->esq), novo);
		else
			incluir(&((*raiz)->dir), novo);
}

//*** Consultar ****************************************************************
struct tNo *consultar(struct tNo *raiz, int cod) {
	if (raiz == NULL)
		return NULL;
	if (raiz->dado.codigo == cod)
		return raiz;
	if (cod < raiz->dado.codigo)
		return consultar(raiz->esq, cod);
	return consultar(raiz->dir, cod);
}

/*

//*** Listagem *****************************************************************
void listar(struct tDescritor lst) {
	struct tNo *p = lst.ini;

	printf("Temos %d produtos\n\n", lst.qtd);
	printf("QTD DESCRICAO\n");
	printf("--- ---------------------------------------\n");
	while (p != NULL) {
		printf("%3d %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}

//*** Exclusao *****************************************************************
void excluir(struct tDescritor *lst, struct tNo *vitima) {
	if (vitima->ant == NULL) // primeiro = ninguem antes
		(*lst).ini = vitima->prox;
	if (vitima->prox == NULL) // ultimo = ninguem depois
		(*lst).fim = vitima->ant;
	if (vitima->ant != NULL) // tem alguem antes
		vitima->ant->prox = vitima->prox;
	if (vitima->prox != NULL) // tem alguem depois
		vitima->prox->ant = vitima->ant;
	free(vitima);
	(*lst).qtd--;
}

//*** Destruir *****************************************************************
void destruir(struct tDescritor *lst) {
	struct tNo *p=(*lst).ini, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(lst);
}

*/

//*** FIM **********************************************************************

