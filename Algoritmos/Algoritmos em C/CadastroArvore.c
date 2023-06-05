#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
            Aula 277: Árvore Binária de Busca de Pessoas

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

typedef struct{
    char nome[50];
    char cpf[12];
}Pessoa;

typedef struct no{
    Pessoa pessoa;
    struct no *direita, *esquerda;
}NoArv;

Pessoa ler_pessoa(){
    Pessoa p;
    printf("\tDigite o nome da pessoa: ");
    fgets(p.nome, 49, stdin);
    printf("\tDigite o cpf: ");
    scanf("%c", &p.cpf);
    fflush(stdin);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\tNome: %s\tCpf: %c\n", p.nome, p.cpf[12]);
}

NoArv* inserir_versao_1(NoArv *raiz, Pessoa p){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->pessoa = p;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(p.cpf < raiz->pessoa.cpf)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, p);
        else
            raiz->direita = inserir_versao_1(raiz->direita, p);
        return raiz;
    }
}


int main(){

    NoArv *busca, *raiz = NULL;
    int opcao; 
	char valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);
        scanf("%c");

        switch(opcao){
        case 1:
            //printf("\n\tDigite um valor: ");
            //scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, ler_pessoa());
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
