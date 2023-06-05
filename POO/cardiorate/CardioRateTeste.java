package com.mycompany.cardiorate;

import java.util.Scanner;
public class CardioRateTeste {
	public static void main (String args []){
		String nome;
		String sobrenome;
		String nascimento;
		String hoje;
		int nascDia;
		int nascMes;
		int nascAno;
		int hjDia;
		int hjMes;
		int hjAno;
		int idade = 0;
		
		//------------------------------------------------------------
		//Geração de um Scanner chamado "dados"
		Scanner dados = new Scanner(System.in);
		//Geração de um CardioRate chamado "pessoa"
		CardioRate pessoa = new CardioRate ("","",0,0,0,0,0,0,0,"","","","",0.0,0.0,0.0);
		
		System.out.printf("Qual o seu nome? ");
			nome = dados.next();
		System.out.printf("Qual seu sobrenome? ");
			sobrenome = dados.next();
		System.out.printf("Informe sua data de nascimento: ");
			nascimento = dados.next();
		System.out.printf("informe a data de hoje: ");
			hoje = dados.next();
		
		pessoa.setNasc(nascimento);
		pessoa.setHoje(hoje);
		pessoa.setIdade(idade);
			
		System.out.printf("sua idade é %s\n\nSua frequencia cardiaca máxima é: %.1f\n\n"
		+ "Sua frequencia alvo minima é %.1f\n\n"
		+ "E sua frequencia alvo máxima é %.1f\n\n", 
		pessoa.getIdade(),
		pessoa.getMaxRate(),
		pessoa.getMinRateAlvo(),
		pessoa.getMaxRateAlvo());
		
		//---TESTE DE SPLIT----
	System.out.printf("Você Nasceu em: %s/%s/%s\n\nHoje é: %s/%s/%s", pessoa.getNascDia(),pessoa.getNascMes(),pessoa.getNascAno(), pessoa.getHjDia(),pessoa.getHjMes(),pessoa.getHjAno());
		
	}//fim do método main
}
