//// lidando com arquivos
#include <stdio.h>
#include <stdlib.h>
#define salvar fclose(file);

int main(){
	FILE *file;
	int i, numero[10];
	
	file = fopen("numero.txt", "w"); /// o w serve para escrever no arquivo
	if(file == NULL){ /// garatir que nao abra arquivos que nao existem
		printf("\n Arquivo nao encontrado");
		return 0;
	}
	for(i=0; i<10; i++){
		printf("\nN: ");
		scanf("%i", &numero[i]);
		fprintf(file, "%i\n", numero[i]);
	}
	salvar; /// salvar o arquivo com seguranca
	return 0;
}
