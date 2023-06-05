#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define cls system("cls"); /// limpa tela
#define buffer fflush(stdin); /// limpar o buffer
#define pause system("pause"); /// pause


struct cadastro { // categoria/filme
	char nome[100];
};

/// lista de funcoes
void leValidaTexto(char *nome);
char sair();

int main() {
	struct cadastro categoria[50];
	struct cadastro filmes[100];
	int i=0;
	char resposta;

	do{
		printf("\n Informe a categoria: ");
		leValidaTexto(categoria[i].nome);
		printf("\n Categoria: %s", categoria[i].nome);
		i++;
	}while(resposta=sair() != 'S');

	return 0;
}

/// categoria/filmes
void leValidaTexto(char *nome) {

	do {
		buffer;
		gets(nome);
		strupr(nome); /// converte a string em maiusculo
		if(strcmp(nome, "")== 0) {
			cls;
			printf("\n Campo obrigatorio, tente novamente...\n");
		}
	} while(strcmp(nome, "")== 0);
}

/// sair do programa
char sair(){
	char resposta;
	buffer;
	printf("\n Concluir? (S/N): ");
	scanf("%c", &resposta);
	resposta = toupper(resposta);
	return resposta;
}
