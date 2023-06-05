/// Batalha naval
#include <stdio.h>
#include <stdlib.h>

struct cadastro{
	char player1[100];
	char player2[100];
};

int main(){
	struct cadastro cad;
	int tabuleiro[10][10];
	int i, j;
	
	for(i=0; i<10; i++){
		printf("\n[%c]", 65+i);
		for(j=0; j<10; j++){
			printf("[%i]", j);
		}
	}	
	
	return 0;
}
