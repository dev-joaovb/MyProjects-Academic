/// João Victor Bueno
/// uc19106154
/// Estrutura de dados arvore

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer fflush(stdin);
/*
Informacoes

Sexo;
Data de nascimento;
Naturalidade;
Nome do pai;
Nome da mãe;
Dados de endereço:

Logradouro;
Número;
Complemento;
Bairro;
Cidade;
CEP;
Estado;
País;
Dados de contato:

E-mail;
Telefone;
*/

typedef struct{
    char nome[50];
    int cpf;
    char sexo;
    char data[10];
    char pais[20];
    char pai[50], mae[50];
    int numero;
    char complemento[100];
    char bairro[50];
    char cidade[15];
    int cep;
    char estado[2];
    char email[50];
    int telefone;
}Pessoa;

typedef struct no{
    Pessoa pessoa;
    struct no *direita, *esquerda;
}NoArv;

Pessoa ler_pessoa(){
    Pessoa p;
    printf("\tDigite o nome da pessoa: ");
    fgets(p.nome, 49, stdin);
    buffer;
    printf("\tDigite o cpf: ");
    scanf("%d", &p.cpf);
    buffer;
	printf("\tInforme o Sexo(m/f): ");
    scanf("%c", &p.sexo);
    buffer;
	printf("\tInforme a data(dd/mm/aaaa): ");
    scanf("%s", &p.data);
    buffer;
	printf("\tInforme o Pais: ");
    fgets(p.pais, 19, stdin);
    buffer;
    printf("\tInforme o nome do pai: ");
    fgets(p.pai, 49, stdin);
    buffer;
    printf("\tInforme o nome da mae: ");
    fgets(p.mae, 49, stdin);
    buffer;
    printf("\tInforme o numero(Casa): ");
    scanf("%d", &p.numero);
    buffer;
    printf("\tInforme o Complemento: ");
    fgets(p.complemento, 99, stdin);
    buffer;
    printf("\tInforme o Bairro: ");
    fgets(p.bairro, 49, stdin);
    buffer;
    printf("\tInforme a cidade: ");
    fgets(p.cidade, 14, stdin);
    buffer;
    printf("\tInforme o Estado(DF): ");
    scanf("%s", &p.estado);
    buffer;
	printf("\tInforme o CEP: ");
    scanf("%d", &p.cep);
    buffer;
    printf("\tInforme o Email: ");
    fgets(p.email, 49, stdin);
    buffer;
    printf("\tInforme o Telefone: ");
    scanf("%d", &p.telefone);
    buffer;
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s", p.nome);
	printf("\nCpf: %d", p.cpf);
	printf("\nSexo: %c", p.sexo);
	printf("\nData: %s", p.data);
	printf("\nPais: %s", p.pais);
	printf("\nPai: %s", p.pai);
	printf("\nMae: %s", p.mae);
	printf("\nNumero(casa): %d", p.numero);
	printf("\nComplemento: %s", p.complemento);
	printf("\nBairro: %s", p.bairro);
    printf("\nCidade: %s", p.cidade);
	printf("\nEstado: %s", p.estado);
	printf("\nCEP: %d", p.cep);
	printf("\nEmail: %s", p.email);
	printf("\nTelefone: %d\n", p.telefone);
}

void inserir(NoArv **raiz, Pessoa p){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->pessoa = p;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(p.cpf < (*raiz)->pessoa.cpf)
            inserir(&((*raiz)->esquerda), p);
        else
            inserir(&((*raiz)->direita), p);
    }
}

NoArv* buscar(NoArv *raiz, int cpf){
    while(raiz){
        if(cpf < raiz->pessoa.cpf)
            raiz = raiz->esquerda;
        else if(cpf > raiz->pessoa.cpf)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->pessoa.cpf == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    Pessoa p;
                    NoArv *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    p = raiz->pessoa;
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = p;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->pessoa.cpf)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}


void imprimir(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir(raiz->esquerda);
        imprimir_pessoa(raiz->pessoa);
        imprimir(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Remover\n\t5 - Quantidade No\n");
        scanf("%d", &opcao);
        scanf("%c");

        switch(opcao){
        case 1:
            inserir(&raiz, ler_pessoa());
            break;
        case 2:
            printf("\nImpressao: ");
            imprimir(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o cpf a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);
            if(busca){
                printf("\n\tValor encontrado:\n");
                imprimir_pessoa(busca->pessoa);
            }
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\t");
            imprimir(raiz);
            printf("\n\tDigite o cpf a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
