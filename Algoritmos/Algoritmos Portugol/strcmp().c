#include<stdio.h>
#include <string.h>
int comparaTexto(char *nome1, char *nome2);
main(){
	char nome[12];

	
	//gets(nome);
	if(comparaTexto(nome,"Carla")==0){//strcmp() compara dois textos e retorna 0 se forem iguais.
		puts("Valores iguais.");
	}else
		puts("Valores diferentes.");
}

int comparaTexto(char *nome1, char *nome2){
	int i;
	gets(nome1);
	for(i=0;nome1[i]!='\0';i++)
		if(nome1[i]!=nome2[i])
		 	return 1;	 	
	return 0;
}


