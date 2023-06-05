#include<stdio.h>
#include <string.h>
void concatena(char *nome1, char *nome2);
main(){
	char nome[25], sobrenome[25];
	
	puts("Digite o seu nome:");
	gets(nome);
	puts("Digite o seu sobrenome:");
	gets(sobrenome);
	concatena(nome," ");//strcat() concatena dois textos.
	concatena(nome, sobrenome);
	puts(nome);
}
void concatena(char *nome1, char *nome2){
	int i, j;
	i=strlen(nome1);
	for(j=0; nome2[j]!='\0'; j++, i++)
		nome1[i]=nome2[j];
	nome1[i]='\0';
}






