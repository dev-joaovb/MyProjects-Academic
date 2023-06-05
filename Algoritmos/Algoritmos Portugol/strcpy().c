#include<stdio.h>
void copiaTexto(char *nome1, char *nome2);
main(){
	char nome[12];

	copiaTexto(nome,"Igor");//strcpy() copia um texto
	puts(nome);
}

void copiaTexto(char *nome1, char *nome2){
	int i;
	for(i=0;nome2[i]!='\0';i++)
		nome1[i]=nome2[i];
	nome1[i]='\0';	
}




