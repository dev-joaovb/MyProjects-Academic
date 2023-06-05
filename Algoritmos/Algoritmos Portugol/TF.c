// Trabalho Final João Victor Bueno Carneiro uc19106154
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define cls system("cls") /// cls
#define buffer fflush(stdin); /// limpar o buffer
#define pause system("pause") /// pause
#define handle   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /// Lidando com a saida
#define console  CONSOLE_SCREEN_BUFFER_INFO consoleInfo; ///Obter informacoes do buffer na tela
#define word     WORD saved_attributes; /// Atributos salvos
#define obter    GetConsoleScreenBufferInfo(hConsole, &consoleInfo); /// Obter as informacoes da tela (fonte)
#define save     saved_attributes = consoleInfo.wAttributes; /// Atributos do console
#define green    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //verde
#define red    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);     //vermelho
#define blue    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);   //azul
#define original  SetConsoleTextAttribute(hConsole, saved_attributes); /// Voltar a cor padrao da tela

/// Sumario de funcoes
void leValidaFilme(char * nome);
int leValidaQuantidadeCadeiras();
float leValidaValor ();
int leValidaIdade();
float mostraIngresso(int idade, char resposta, char categoria, float valorIngresso);
int leValidaCadeiras (int cadeiras[], int quantidade);
void calculaIngresso(float calcula);
/////////Principal////////
int main () {
	char nome[100], resposta, categoria, continuar;
	int poltronas, idade, indice, quantidade, cadeiras[499], indice2, indice3, aux;
	float ingresso, confirmaIngresso;
	float somaValor;
	int somaQuantidade, somaOcupados, remover, flag, flag2 = 0, contador, diminuiValor = 0;
	handle;
	console;
	word;
	obter;  /// funcao definida para obter informacoes da tela (fonte)
	save; /// funcao definida para salvar as informacoes obtidas anteriormente
	green;
	printf ("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf ("       ##########   ######   ######         ######   #############   ##########                 ##########     ################     ######         ######\n");
	printf ("     ############   ######   #######        ######   #############   ###########               ###########    ##################     ######       ###### \n");
	printf ("   ######           ######   ########       ######   ######          ############             ############   ####################     ######     ######  \n");
	printf ("   ######           ######   #########      ######   ######          #############           #############   ######        ######      ######   ######   \n");
	printf ("   ######           ######   ##########     ######   ######          ###### #######         ####### ######   ######        ######       ###### ######    \n");
	printf ("   ######           ######   ###########    ######   ######          ######  #######       #######  ######   ######        ######        ###########     \n");
	printf ("   ######           ######   ###### #####   ######   ###########     ######   #######     #######   ######   ####################         #########      \n");
	printf ("   ######           ######   ######  #####  ######   ###########     ######    #######   #######    ######   ####################         #########      \n");
	printf ("   ######           ######   ######   ##### ######   ###########     ######     ####### #######     ######   ####################        ###########     \n");
	printf ("   ######           ######   ######    ###########   ######          ######      #############      ######   ######        ######       ###### ######    \n");
	printf ("   ######           ######   ######     ##########   ######          ######       ###########       ######   ######        ######      ######   ######   \n");
	printf ("   ######           ######   ######      #########   ######          ######        #########        ######   ######        ######     ######     ######  \n");
	printf ("     ############   ######   ######       ########   #############   ######         #######         ######   ######        ######    ######       ###### \n");
	printf ("       ##########   ######   ######        #######   #############   ######          #####          ######   ######        ######   ######         ######\n");
	printf ("\n\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	original;
	pause;
	int i;
	cls;
//	printf("\n\n\n\n                                                  Loading"); // Exibir a Palavra Loading na tela em branco
//	for(i=0; i < 10; i++) { // abrir um laço de repetição com for
//		sleep(1); // pausa de 1 segundo
//		printf("."); // escrever 1 "." na tela
//		fflush(stdout); // atualizar a tela
//	}
	cls;
	leValidaFilme(nome);
	cls;
	printf ("\n Nome do filme: %s", nome);
	poltronas = leValidaQuantidadeCadeiras();
	ingresso = leValidaValor();
	buffer;
	cls;
	somaValor = 0;
	printf ("\n\n\n\n\n\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	printf ("\t\t\t\t\t       Filme: %s                                  \n", nome);
	printf ("\t\t\t\t\t       Quantidade de cadeiras na sala: %i poltronas       \n", poltronas);
	printf ("\t\t\t\t\t       Valor do Ingresso a ser pago: R$%f    \n", ingresso);
	printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
	pause;
	cls;
	somaQuantidade = 0;
	indice = 0;
	confirmaIngresso = ingresso;
	char opcao;
	do {
		printf("\n\n\n\n\n\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\t\t\t\t\t       Filme: %s                                  \n", nome);
		printf("\t\t\t\t\t       Quantidade de cadeiras na sala: %i poltronas       \n", poltronas);
		printf("\t\t\t\t\t       Valor do Ingresso: R$%f               \n", confirmaIngresso);
		printf("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		blue;
		printf("\t\t\t\t\t      ###      ###   ######   ###   ##   ##  ##\n");
		printf("\t\t\t\t\t      ####    ####   ##       ####  ##   ##  ##\n");
		printf("\t\t\t\t\t      ## ##  ## ##   ####     ## ## ##   ##  ##\n");
		printf("\t\t\t\t\t      ##  ####  ##   ##       ##  ####   ##  ##\n");
		printf("\t\t\t\t\t      ##   ##   ##   ######   ##   ###    #### \n");
		original;
		printf("\t\t\t\t\t \xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
		printf("\t\t\t\t\t       Informe uma das opcoes a baixo:                   \n");
		red;
		printf("\t\t\t\t\t       R - Fazer a reserva                               \n");
		blue;
		printf("\t\t\t\t\t       C - Vendas Confirmadas                            \n");
		green;
		printf("\t\t\t\t\t       D - Cadeiras Disponiveis                          \n");
		original;
		printf("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("\n\n R: ");
		do {
			scanf ("%c", &opcao);
			opcao = toupper(opcao);
			buffer;
			ingresso = confirmaIngresso;
			switch (opcao) {////// Escolha
				case 'R':
					cls;
					printf ("\t\t\t\t\t        Faca sua reserva!!\n");
					somaQuantidade = somaQuantidade + 1;
					printf ("\t\t\t\t\t        Numero da reserva: %i\n", somaQuantidade);
					idade = leValidaIdade();
					buffer;
					ingresso = mostraIngresso(idade, resposta, categoria, ingresso);
					diminuiValor = ingresso;
					printf ("\t\t\t\t\t       Filme: %s                                  \n", nome);
					printf ("\t\t\t\t\t       Quantidade de cadeiras na sala: %i          \n", poltronas);
					printf ("\t\t\t\t\t       Valor do Ingresso a ser pago: R$%f    \n", ingresso);
					printf ("\t\t\t\t\t       Idade do pagante: %i anos                    \n", idade);
					printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
					do {
						if (flag2 == 0) { /// O flag2 sera sempre 0 enquanto nenhum usuario cancelar a sua reserva
							somaValor = somaValor + ingresso;
							cadeiras [indice]= leValidaCadeiras(cadeiras, indice);
							indice = indice + 1;
							quantidade = indice;
						}
						if (flag2 == 1) { /// O flag2 sera 1 somente quando houver cancelamento de reserva, o vetor = 0 sera substituido por uma nova reserva
							for (contador=0; contador<poltronas; contador++) {
								if (cadeiras[contador] == 0) {
									cadeiras[contador] = leValidaCadeiras(cadeiras, indice);
									flag2=0;
									break;
								}
							}
						}
					} while (indice < poltronas && pause);
					buffer;
					cls;
					break;

				case 'C':
					for(indice2=0; indice2<quantidade; indice2++) { /// Organizar na ordem as cadeiras
						for (indice3 = indice2; indice3<quantidade; indice3++) {
							if(cadeiras[indice2]>cadeiras[indice3]) {
								aux = cadeiras[indice2];
								cadeiras[indice2] = cadeiras[indice3];
								cadeiras[indice3] = aux;
							}
						}
					}
					cls;
					printf ("\t\t\t\t\t  CADEIRAS RESERVADAS!\n ");
					indice = 0;
					for (indice; indice < quantidade; indice++) {
						printf ("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t      Cadeira: %i    \n", cadeiras[indice]);
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
					}
					calculaIngresso(somaValor); /// Informando o valor somado das vendas (excluindo as canceladas)
					pause;
					cls;
					flag = 0;
					printf ("\nPressione 'N' para cancelar a reserva ou outra tecla para continuar. \nR: ");
					scanf("%c", &resposta);
					resposta = toupper(resposta);
					buffer;
					if (resposta == 'N') {
						flag2= 0;
						diminuiValor = 0;
						printf ("\nInforme a cadeira que deseja cancelar a reserva:\n ");
						scanf ("%i", &remover);
						cls;
						indice = 0;
						for (indice; indice<quantidade; indice++) {
							if (remover == cadeiras[indice]) {
								printf ("\nCadeira: %i cancelada.  \n", cadeiras[indice]);
								flag = 1;
								flag2 = 1;
							}
						}

						if (flag==0) {
							printf ("\nCadeira nao encontrada.   \n");
						}
						if (flag==1) {
							for (contador=0; contador<poltronas; contador++) {
								if (cadeiras[contador] == remover) {
									cadeiras[contador] = 0;
									somaQuantidade = somaQuantidade - 1;
									somaValor = somaValor - diminuiValor;
								}
							}
						}
					}
					pause;
					buffer;
					cls;
					break;
				case 'D':
					cls;
					somaOcupados = poltronas - quantidade;
					printf ("\nNumero de cadeiras disponiveis: %i", somaOcupados);
					indice = 0;
					printf ("\nCadeiras indisponiveis!\n");
					for (indice; indice< somaOcupados; indice++) {
						printf ("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t      Cadeira: %i    \n",           indice+1);
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
					}
					printf ("\t\t\t\t\t    CADEIRAS RESERVADAS!!\n");
					for (indice = 0; indice< quantidade; indice++) {
						red;
						printf ("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						green;
						printf ("\t\t\t\t\t      Cadeira: %i    \n", cadeiras[indice]);
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						printf ("\t\t\t\t\t                     \n");
						red;
						printf ("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
						original;
					}
					pause;
					cls;
					break;
			}
			if (opcao != 'D' && opcao != 'R' && opcao != 'C') {
				puts (" Caracter invalido. Tente novamente...");
			}
		} while (opcao != 'D' && opcao != 'R' && opcao != 'C');
	} while (indice < poltronas );/// até esgotar a sala

	return 0;

}///fimPrincipal/////

/// Nome do filme
void leValidaFilme(char * nome) {
	do {
		printf ("\n Informe o nome do filme: ");
		gets (nome);
		if(strcmp(nome, "")==0) {
			puts (" O nome do filme e obrigatorio. Tente Novamente...");
		}
	} while (strcmp(nome, "")==0);
}
//Quantidade de poltronas//////
int leValidaQuantidadeCadeiras() {
	int quantidade;
	do {
		printf ("\n Informe a quantidade de poltronas disponivel na sala: ");
		scanf ("%i", &quantidade);
		if (quantidade < 100 || quantidade > 499) {
			printf ("\n A capacidade da sala e de 100 e 499 poltronas. Tente novamente...");
		}
	} while (quantidade < 100 || quantidade > 499);
	return quantidade;
}
/// Validando o valor
float leValidaValor () {
	float valor;
	do {
		printf ("\n Informe o valor do ingresso: ");
		scanf ("%f", &valor);
		if (valor < 0) {
			printf ("\n O valor do Ingresso não pode ser negativo.");
		}
	} while (valor < 0);
	return valor;
}
/// Validando a idade
int leValidaIdade() {
	int idade;
	do {
		printf ("\n Informe a idade: ");
		scanf ("%i", &idade);
		if (idade < 0) {
			printf ("\n A idade não pode ser negativa. Tente Novamente...");
		}
	} while (idade < 0);

	return idade;
}

//Valor do ingresso/////
float mostraIngresso(int idade, char resposta, char categoria, float valorIngresso) {
	float meia;
	if (idade <= 12) { /// Somente para usuarios com 12 anos para baixo
		printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
		printf ("\t\t\t\t\t       Garantia de meia entrada para criancas!\n");
		meia = valorIngresso/2;
		return meia;
	} else {
	} if (idade >= 13) { /// A partir dos 13 anos o usuario sera informado se possui os beneficios necessarios para a meia entrada
		do {
			printf("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
			printf("\t\t\t\t\t\xBA                                                           \xBA\n");
			printf("\t\t\t\t\t\xBA     CATEGORIA DE BENEFICIO DE MEIA ENTRADA SOMENTE PARA:  \xBA\n");
			printf("\t\t\t\t\t\xBA                                                           \xBA\n");
			printf("\t\t\t\t\t\xBA     ESTUDANTES:                                           \xBA\n");
			printf("\t\t\t\t\t\xBA     PORTADORAS DE NECESSIDADES ESPECIAIS:                 \xBA\n");
			printf("\t\t\t\t\t\xBA     IDOSOS:                                               \xBA\n");
			printf("\t\t\t\t\t\xBA     DOADOR DE SANGUE:                                     \xBA\n");
			printf("\t\t\t\t\t\xBA                                                           \xBA\n");
			printf("\t\t\t\t\t\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n");
			printf("\t\t\t\t\t\xBA     VOCE TEM DIREITO A ALGUM DESSES BENEFICIOS?           \xBA\n");
			printf("\t\t\t\t\t\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n");
			printf("\t\t\t\t\t\xBA     (S) - SIM                                             \xBA\n");
			printf("\t\t\t\t\t\xBA     (N) - NAO                                             \xBA\n");
			printf("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
			scanf ("%c", &resposta);
			resposta = toupper(resposta);
			cls;
			if (resposta == 'S') {
				printf("\t\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
				printf("\t\t\t\t\t\xBA                                                           \xBA\n");
				printf("\t\t\t\t\t\xBA         MENU DE OPCOES                                    \xBA\n");
				printf("\t\t\t\t\t\xBA                                                           \xBA\n");
				printf("\t\t\t\t\t\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n");
				printf("\t\t\t\t\t\xBA                                                           \xBA\n");
				printf("\t\t\t\t\t\xBA    (E)- ESTUDANTES:                                       \xBA\n");
				printf("\t\t\t\t\t\xBA    (P)- PORTADORAS DE NECESSIDADES ESPECIAIS:             \xBA\n");
				printf("\t\t\t\t\t\xBA    (I)- IDOSOS:                                           \xBA\n");
				printf("\t\t\t\t\t\xBA    (D)- DOADOR DE SANGUE:                                 \xBA\n");
				printf("\t\t\t\t\t\xBA                                                           \xBA\n");
				printf("\t\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

				scanf ("%s", &categoria);
				categoria = toupper(categoria);
				buffer;
				switch (categoria) {
					case 'E':
						cls;
						printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
						printf ("\t\t\t\t\t       Resumo.\n");
						printf ("\t\t\t\t\t       Categoria do comprador: Estudante.\n");
						break;
					case 'P':
						cls;
						printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
						printf ("\t\t\t\t\t       Resumo.\n");
						printf ("\t\t\t\t\t Categoria do comprador: Portador de Necessidades Especiais.\n");
						break;
					case 'I':
						cls;
						printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
						printf ("\t\t\t\t\t       Resumo.\n");
						printf ("\t\t\t\t\t       Categoria do comprador: Idoso.\n");
						break;
					case 'D':
						cls;
						printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
						printf ("\t\t\t\t\t       Resumo.\n");
						printf ("\t\t\t\t\t       Categoria do comprador: Doador de Sangue.\n");
				}
				meia = valorIngresso/2; // meia entrada
				return meia;
			}
			if (resposta != 'S' && resposta != 'N') {
				puts (" \nCaracter invalido. Tente novamente");
			} else {
			} if (resposta == 'N') {
				printf ("\t\t\t\t\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
			}
		} while (resposta != 'S' && resposta != 'N');
	}
	return valorIngresso;
}
/// Validando a quantidade de cadeiras
int leValidaCadeiras (int cadeiras[], int quantidade) {
	int flag, indice;
	int cadeira;
	indice = 0;
	do {
		flag = 0;
		puts (" \nInforme o numero da cadeira: ");
		scanf("%i",&cadeira);
		buffer;
		for (indice; indice < quantidade; indice++) {
			if(cadeira == cadeiras[indice]) {
				flag = 1;
				break;
			}
		}
		if (cadeira <= 0) {
			puts (" O numero da cadeira nao pode ser menor que 1. Tente Novamente...");
		}
		if (flag == 1) {
			puts (" \nEssa cadeira ja foi escolhida. Escolha outra por favor!");
		}
	} while (flag == 1 || cadeira <= 0);
	return cadeira;
}
/// Valor final dos ingressos somados
void calculaIngresso(float calcula) {
	printf ("\n Valor total das vendas: R$%f\n", calcula);
}
