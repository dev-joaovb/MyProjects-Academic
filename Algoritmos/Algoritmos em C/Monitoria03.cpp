#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Função1
int validaCidade() {
  int cidade;
	do{
		printf ("\n Informe a quantidade de cidades: ");
		scanf ("%i", &cidade);
	}while (cidade < 5 || cidade > 100);
	return cidade;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main () {
	setlocale (LC_ALL, "");
	int quantidadeCidade, cidade;
	int contador;
	
		quantidadeCidade = validaCidade();
				printf (" São %i cidades", quantidadeCidade);
	
			for (contador > 1; contador <= quantidadeCidade; contador++){
			printf ("\n Informe as Cidades! ");
			printf ("\n Cidade: ");
			scanf ("%i", &cidade);
	}
	
	
	
	
	return 0;
}
