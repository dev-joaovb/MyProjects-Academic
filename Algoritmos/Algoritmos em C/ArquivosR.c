#include <stdio.h>
#include <stdlib.h>
#define salvar fclose(file);

int main(){
	FILE * file;
	char dados[100];
	
	file = fopen("pausa.bin", "r"); // o r serve para ler o arquivo
	/// quando se ler um arquivo, deve ser feito uma validacao de arquivo
	/// ou seja, se ele existe ou nao, para nao criar lixo de memoria
	if(file == NULL){
		printf("\n Arquivo nao encontrado");
		return 0;
	}
	//fputs(dados, file);
	while(fgets(dados, 100, file) != NULL){ // para ler as quebras de linha
		printf("\n %s", dados);
	}
	
	printf("\n\n\n %s", dados);
	salvar;
	
	
	return 0;
}
