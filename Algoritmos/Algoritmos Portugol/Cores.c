#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define blue system("color 1"); /// Azul 
#define green system("color 2"); /// Verde 
#define waterGreen system("color 3"); ///Verde Agua
#define red system("color 4"); // Vermelho 
#define purple system("color 5"); // Roxo
#define yellow system("color 6"); // Amarelo 
#define white system("color 7"); // Branco (Cor padrão da fote)
#define gray system("color 8"); // Cinza
#define lightBlue system("color 9"); // Azul claro
#define lightGreen system("color a"); // Verde Claro
#define lightRed system("color c"); // Vermelho claro
#define pink system("color d"); // Rosa
#define lightYellow system("color e"); // Amarelo claro
#define lightWhite system("color f"); // Branco claro
/// Funcao gotoxy
void gotoxy(int x, int y);
int main () {
	int coluna = 66;
	int linha  = green;
	system("cls");
	gotoxy (coluna, linha);
	printf (" Testando COR!\n");
	coluna = blue;
	gotoxy (coluna, linha+1);
	printf (" Testando COR!\n");
	return 0;
}

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

