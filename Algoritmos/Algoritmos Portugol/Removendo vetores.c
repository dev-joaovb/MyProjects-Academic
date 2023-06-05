#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct registro {
	char nome[100];
} dado;

int main () {
	dado x[4];
	dado removerNome;
	int numero[10], quantidade =0;
	int indice2, indice3;
	int indice, aux, id, flag;
	//char nome[10][100];
	for (indice = 0; indice < 4; indice++) {
		fflush(stdin);
		printf ("\n nome: ");
		id++;
		gets(x[indice].nome);
	}
	int remover, contador, novo, i, j;
	printf("\n Informe o nome que deseja remover: ");
	fflush(stdin);
	gets(removerNome.nome);

	for (contador=0; contador<4; contador++) {
		if (strcmp(x[contador].nome, removerNome.nome)==0) {
			printf("\n Codigo: %i \n Nome encontrado %s",id , x[contador].nome);
			flag = 0;
			//numero[contador] = 0;

		//	for(j=contador; j<4; j++) {
		//		x[contador] = x[contador+1];
		//	}
			//10-1;
		//	for(j=0; j<3; j++) {
		//		x[contador] = x[contador+1];
		//	}
		//	printf("\n\nexcluido com sucesso!\n\n");
		}
	}

//	for (j=0; j<3; j++) {
//		if(id!=0 && strlen(x[j].nome)>0) {
//			printf("%d" "     -" "\t%s\n\n", id,x[j].nome);
//		}
//	}



	for (contador = 0; contador<10; contador++) {
		if (flag == 0) {
			printf ("\n  removido. ");
			x[contador].nome == "";
			x[contador].nome == x[contador+1].nome;
			break;
		}
	}
	for (contador = 0; contador<10; contador++){
		if (flag == 0){
			printf("\n Nome: %s", x[contador].nome);
		}
	}
//	for(indice2 = 0; indice2 < 10; indice2++) {
//		for(indice3 = indice2; indice3 < 10 ; indice3++) {
//			if(numero[indice2]>numero[indice3]) {
//				aux = numero[indice2];
//				numero[indice2] = numero[indice3];
//				numero[indice3] = aux;
//			}
//		}
//	}
//	system("cls");
//	for (indice=0; indice<10; indice++) {
//		printf("\n numeros: %i", numero[indice]);
//	}
	return 0;
}
