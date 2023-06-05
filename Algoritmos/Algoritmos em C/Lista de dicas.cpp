/*dicas de como usar o programa em C++

1) quando utilizar mais de um codigo exemplo: int numero, numero2 
	scanf (numero)
	scanf (numero2)....
	antes do codigo deve ser inserido dentro dos parenteses o "%i, &...", mas cuidado se digitar o "i" antes da % o programa so ira executar uma linha e encerrar o programa.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2) para usar a fonte com acentos basta digitar na biblioteca //#include <stdlocale.h>
	depois de // int main () {
		colocar: setlocale(LC_ALL, "Portuguese"); // para rodar os acentos em erro no programa.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3) para executar um programa utilizando o  if e o else  voce vai precisar utilizar o //"%i", codigo... ou %d, codigo... para executar de forma correta.
	se caso usar da forma "O", numero, "eh o maior deles."? o programa nao ira rodar as condicionais // if e else.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4) para transformar o caracter em maiusculo basta usar a biblioteca //#include <ctype.h>
	// codigo = toupper (codigo);
	
5) Tipos de fun��es string.h
-----------------------------
1)

- strcpy: Essa string � usada para fazer uma c�pia de uma var�vel � outra:
Ex: strcpy (string_destino, string_origem);

Ex2: 
int main (void)
{
  char nome[15];
  
  strcpy(nome, "Fulano de Tal");
  //strcpy(string_destino, string_origem);
  //note que a string de destino � nome
  //a string de origem � "Fulano de Tal"
  
  printf("Nome = %s", nome);
  
  getch();
  return 0;
} TELA DE EXECU��O: Nome = Fulano de Tal
----------------------------------
2)

- strcat: Essa string realiza a concatena��o do conte�do de uma var�vel a outra

Ex:

int main (void)
{
  char str[10] = "Curso";
  strcat(str, " de C");
  //Concatena a string " de C" com o conte�do da string str
  
  printf("str = %s\n", str);
  //Ser� exibido curso de C
  
  getch();
  return 0;
} TELA DE EXECU��O: str = Curso de C
------------------------------------
3)

- strlen: Uma vari�vel do tipo inteiro = strlen (string);
- Determia o tamanho de uma string;

Ex:

int main (void)
{
  char str[5] = "Curso";
  int tamanho;
  
  tamanho = strlen(str);
  
  printf("O tamanho da string %s vale %d\n", str, tamanho);
  
  getch();
  return 0;
} TELA DE EXECU��O: O tamanho da string Curso vale 5
---------------------------------------------------
4)

- strcmp: Vari�vel do tipo inteiro = strcmp (string1, string2);
- Ele compara o conte�do de duas strings;
- Poss�veis valores de retorno;
- 0: conte�do das strings s�o iguais;
- < 0: conte�do da string1 � menor do que a string2;
- > 0: conte�do da string1 � maior do que a string2;


*/

