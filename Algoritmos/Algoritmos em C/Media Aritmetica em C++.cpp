/*
 * Escreva um programa que leia 3 notas, calcule a m?dia aritm?tica,
 * e imprima o resultado na tela com precis?o de 1 casa decimal.
 *
 * Dica: o tipo "real" no C ? "float" e o formatador, "%f".
 */

#include <stdlib.h>
#include <stdio.h>

float calculaMediaAritmetica(float nota1, float nota2, float nota3) {
    float resultado;
    resultado = (nota1 + nota2 + nota3) / 3.0;
    return resultado;
}

int main() {
	// Declara??es
	float nota1, nota2, nota3;
	float resultado;
	
	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	
	printf("Digite a terceira nota: ");
	scanf("%f", &nota3);
	
	resultado = calculaMediaAritmetica(nota1, nota2, nota3);
	
	// Equivalente ao "limpaTela()" do Calango.
	system("cls");
	
	printf("O resultado da media aritmetica eh: %.1f", resultado);
	
	return 0;
}




