#include <stdio.h>
#include <stdlib.h>
#define salvar fclose(file);
int main(){
	FILE * file;
	char dados[100];
	file = fopen("teste.txt", "a"); /// vai anexar os dados no arquivo ja existente
	
	if(file == NULL){/// validacao de arquivo
		printf("\n Arquivo nao encontrado");
		return 0;
	}
	gets(dados);
	fprintf(file, "\n");
	fputs(dados, file);  ///adicionar vetores de caracteres(strings)
	//fputc(variavel, file) para adicionar somente caracteres
	salvar;
}
