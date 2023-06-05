//// lidando com arquivos
#include <stdio.h>
#include <stdlib.h>
#define salvar fclose(file);

int main(){
	FILE *file;
	char palavra[100];
	
	file = fopen("teste.txt", "w"); /// o w serve para escrever no arquivo
	fprintf(file, "Brasil, pentacampeao");
	salvar; /// fechar o arquivo com segurança
	/// agora ler o arquivo
	if(file == NULL){ /// garatir que nao abra arquivos que nao existem
		printf("\n Arquivo nao encontrado");
		return 0;
	}
	salvar; /// salvar o arquivo com seguranca
	return 0;
}
