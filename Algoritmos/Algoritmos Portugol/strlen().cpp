#include<stdio.h>
int tamanhoTexto(char *nome);
main(){
	char nome[12];
	int tamanho;
	
	gets(nome);
	tamanho=tamanhoTexto(nome); //strlen() retorna o tamanho do texto.
	puts(nome);
	printf("Nome: %i\n", tamanho);
}
int tamanhoTexto(char *nome){
	int i;
	for(i=0;nome[i]!='\0';i++);
	
	return i;
}


