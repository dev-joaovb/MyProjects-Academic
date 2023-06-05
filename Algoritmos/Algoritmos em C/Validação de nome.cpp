#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define gets gets(nome)

int main () {
	setlocale (LC_ALL, "");
	char nome[20];

	do {
		printf("\nInforme o nome:" );
		gets;
		if (strcmp (nome, "")==0) {
			printf ("\n O nome é obrigatório. Tente novamente...");
		}
	} while (strcmp (nome, "")==0);
	printf("Olá %s", nome);
}
