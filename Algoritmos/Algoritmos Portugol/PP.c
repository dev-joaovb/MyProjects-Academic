//// joao Victor Bueno Carneiro uc19106154 PP Professor Wesley
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define cls system("cls")
#define pause system("pause")
#define buffer fflush(stdin);
int leValidaVoto();
char leValidaSexo();
void leValidaNome(char nome[]);
int leValidaIdade();
int leValidaQuantidade();
int main() { ///// principal
	char nome[500][20], sexo[500], resposta;
	int idade[500], quantidadePessoas, indice, voto, indice2, quantidadeMulheres=0;
	int curry=0, durant=0, harden=0, lebron=0, maiorIdadeVotoLebron=0, pessoa[500];
	
		quantidadePessoas = leValidaQuantidade();
		buffer;
		cls;
		printf ("\n %i pessoas estao participando.", quantidadePessoas);
	do{
		printf ("\n %i%c voto! ", indice+1, 111);
		leValidaNome(nome[indice]);
		buffer;
		idade[indice] = leValidaIdade();
		buffer;
		sexo[indice] = leValidaSexo();
		buffer;
		voto = leValidaVoto();
		buffer;
		switch (voto){
		case 1:
			printf ("\n Voto para Stephen Curry.\n");
			curry = curry +1;
			break;
		case 2:
			printf ("\n Voto para Kevin Durant.\n");
			durant = durant +1;
			break;
		case 3:
			printf ("\n Voto para LeBron James.\n");
			lebron = lebron +1;
			break;
		case 4:
			printf ("\n Voto para James Harden.\n");
			harden = harden +1;
			break;
		}
		if(idade[indice]<18 && voto==3){
			maiorIdadeVotoLebron = maiorIdadeVotoLebron + 1; 
			 pessoa[indice] = indice;
		}
		if(sexo[indice] == 'F'){
			quantidadeMulheres = quantidadeMulheres + 1;
		}
		indice = indice + 1;
		cls;
	//	printf ("\n Caso queira encerrar o programa digite 'z'!!");
	//	scanf ("%c", &resposta && resposta != 'Z');
		//resposta = toupper(resposta);
	}while(indice<quantidadePessoas);/// em testes retornar para quantidadePessoas como variavel
	cls;
	//// Exibindo a quantidade de votos que cada jogador recebeu
	printf ("\n Resumo da votacao!\n");
	printf ("\n Stephen Curry recebeu %i voto(s).", curry);
	printf ("\n Kevin Durant recebeu %i voto(s).", durant);
	printf ("\n LeBron James recebeu %i voto(s).", lebron);
	printf ("\n James Harden recebeu %i voto(s).", harden);
	
	/// Exibir o jogador mais votado
	if (curry>durant && curry>lebron && curry>harden){
		printf ("\n\n Stephen Curry foi o mais votado com %i votos.", curry);
	}
		if (durant>curry && durant>lebron && durant>harden){
			printf ("\n\n Kevin Durant foi o mais votado com %i votos.", durant);
		}
	if (lebron>curry && lebron>durant && lebron>harden){
			printf ("\n\n LeBron James foi o mais votado com %i votos.", lebron);
	}
		if (harden>curry && harden>durant && harden>lebron){
			printf ("\n\n James Harden foi o mais votado com %i votos.", harden);
		}
		
		////Possibilidade de empate
	if (curry==durant){
		printf ("\n\n Curry e Durant empataram com %i votos", curry);
	}
	if (curry==lebron){
		printf ("\n\n Curry e Lebron empataram com %i votos", curry);
	}
	if (curry==harden){
		printf ("\n\n Curry e Durant empataram com %i votos", curry);
	}
	if (lebron==durant){
		printf ("\n\n Lebron e Durant empataram com %i votos", lebron);
	}
	if (lebron==harden){
		printf ("\n\n Lebron e Harden empataram com %i votos", harden);
	}
	if (durant==harden){
		printf ("\n\n Harden e Durant empataram com %i votos", durant);
	}
	
	//// Exibir nome, idade e sexo de todas as pessoas que participaram da pesquisa, separando por sexo, maior de idade e menor de idade
	for (indice=0;indice<=quantidadePessoas;indice++){
		if(idade[indice]<18 && sexo[indice]=='M'){
			printf("\n\n Homens Menores de idade!!");
			printf("\n\n Nome: %s, idade: %i, sexo: %c", nome[indice], idade[indice], sexo[indice]);
		}
		if(idade[indice]>18 && sexo[indice]=='M'){
			printf("\n\n Homens Maiores de idade!!");
			printf("\n\n Nome: %s, idade: %i, sexo: %c", nome[indice], idade[indice], sexo[indice]);
		}
		if(idade[indice]<18 && sexo[indice]=='F'){
			printf("\n\n Mulheres Menores de idade!!");
			printf("\n\n Nome: %s, idade: %i, sexo: %c", nome[indice], idade[indice], sexo[indice]);
		}
		if(idade[indice]>18 && sexo[indice]=='F'){
			printf("\n Mulheres Maiores de idade!!");
			printf("\n Nome: %s, idade: %i, sexo: %c", nome[indice], idade[indice], sexo[indice]);
		}	
	}
	
	
	////pessoas maiores de idade que votaram no LeBron
	printf ("\n\n Pessoas maiores de idade que votaram no LeBron\n");
	for (indice2=0;indice2<maiorIdadeVotoLebron;indice2++){
		if (indice2==pessoa[indice2]){
			printf ("\n Nome: %s, idade: %i", nome[indice2], idade[indice2]);
		}
	}
	/// Todas as mulheres que participaram
	printf ("\n\n Quantidade de mulheres que participaram da pesquisa: %i", quantidadeMulheres);
	
	
	
	return 0;
} ///// FimPrincipal
/// nome
void leValidaNome(char nome[]){
	do{
		printf ("\n Informe o nome: ");
		gets(nome);
		buffer;
		if (strcmp(nome, "")==0){
			printf ("\n O nome e obrigatorio. Tente novamente...");
		}
	}while(strcmp(nome, "")==0);
}
///Idade
int leValidaIdade(){
	int idade;
	do{
		printf ("\n Informe a idade: ");
		scanf ("%i", &idade);
		if (idade<16){
			printf ("\n Idade deve ser maior que 15 anos. Tente novamente...");
		}
	}while(idade<16);
	return idade;
}
/// sexo
char leValidaSexo(){
	char sexo;
	do{
		printf ("\n Informe o sexo: (M/F)");
		printf ("R: ");
		scanf ("%c", &sexo);
		sexo = toupper(sexo);
		buffer;
		if (sexo!= 'M' && sexo!= 'F'){
			printf ("\n Caracter Invalido. Tente Novamente...");
		}
	}while (sexo!= 'M' && sexo!= 'F');
	return sexo;
}
/// quantidade
int leValidaQuantidade(){
	int quantidade;
	do{
		printf ("\n Informe a quantidade de pessoas que irao participar da votacao: ");
		scanf ("%i", &quantidade);
		if (quantidade<100 || quantidade >500){
			printf ("\n A quantidade nao pode ser menor que 100 ou superior a 500. Tente novamente...");
		}
	}while(quantidade<100 || quantidade >500);
	return quantidade;
}
//// voto
int leValidaVoto(){
	int voto;
	do{
		printf ("\n Informe o voto da tabela abaixo!");
		printf ("\n\n Tabela de votos.");
		printf ("\n (1) - Stephen Curry ");
		printf ("\n (2) - Kevin Durant ");
		printf ("\n (3) - LeBron James ");
		printf ("\n (4) - James Harden ");
		printf ("\n\n Informe o voto: ");
		printf ("R: ");
		scanf ("%i", &voto);
		if (voto!= 1 && voto!= 2 && voto!= 3 && voto!= 4){
			printf ("\n Numero errado. Tente Novamente....");
		}
	}while(voto!= 1 && voto!= 2 && voto!= 3 && voto!= 4);
	return voto;
}

