package com.mycompany.cardiorate;

public class CardioRate 
{
	//Variaveis
	private String nome;
	private String sobrenome;
	private int idade;
	//Data de nascimento
	private int nascDia;
	private int nascMes;
	private int nascAno;
	//Dia de hj
	private int hjDia;
	private int hjMes;
	private int hjAno;
	//Variaveis de data:
	private String hoje;
	private String splitH;
	private String nascimento;
	private String splitN;
	//Variaveis de calculo cardiaco
	private double mxRate = 220;
	private double minAlvo;
	private double mxAlvo;
	
	//CONTRUTOR:	
	public CardioRate (
			String nome,
			String sobrenome,
			int idade,
			
			int nascDia,
			int nascMes,
			int nascAno,
			
			int hjDia,
			int hjMes,
			int hjAno,
			
			String hoje,
			String splitH,
			String nascimento,
			String splitN,
			
			double mxRate,
			double minAlvo,
			double mxAlvo

			)
	{
		//---SETTERS:-----------
		this.nome = nome;		
		this.sobrenome = sobrenome;
		this.idade = idade;
		
		this.nascDia = nascDia;
		this.nascMes = nascMes;
		this.nascAno = nascAno;
		
		this.hjDia = hjDia;
		this.hjMes = hjMes;
		this.hjAno = hjAno;
		
		this.hoje = hoje;
		this.nascimento = nascimento;
		
		this.mxRate = mxRate;
		this.minAlvo = minAlvo;
		this.mxAlvo = mxAlvo;
		
	}//Fim do Construtor
	/*A Função principal do construtor é inicializar as variaveis dentro da classe que for utiliza-lo */	
	
	public void setNasc (String nascimento){
		String splitN[] = nascimento.split("/");	//separa a data em tres variaveis novas, a cada barra "/" sendo elas: d[0] - dia / d[1] - mes / d[2] - ano
		this.nascDia = Integer.parseInt(splitN[0]);
		this.nascMes = Integer.parseInt(splitN[1]);
		this.nascAno = Integer.parseInt(splitN[2]);
	}
	public void setHoje (String hoje){
		String splitH[] = hoje.split("/");	
		this.hjDia = Integer.parseInt(splitH[0]);
		this.hjMes = Integer.parseInt(splitH[1]);
		this.hjAno = Integer.parseInt(splitH[2]);
	}
	public void setIdade(int idade){
		if (hjMes < nascMes){
			idade = this.hjAno - this.nascAno - 1;
		} else if (this.hjMes == this.nascMes && this.hjDia < this.nascDia){
			this.idade = this.hjAno - this.nascAno - 1;
		}else {
			this.idade = this.hjAno - this.nascAno;	
		} 
			
	}
	//------------GETTERS-------------------
	//invoca os valores da variavel nome
	public String getNome (){
		return nome;
	}
	//invoca os valores da variavel sobrenome
	public String getSobrenome (){
		return sobrenome;
	}
	//invoca os valores da variavel idade
	public int getIdade (){
		return idade;
	}
	//invoca os valores da variavel nascDia
	public int getNascDia (){
		return nascDia;
	}
	//invoca os valores da variavel nascMes
	public int getNascMes(){
		return nascMes;
	}
	//invoca os valores da variavel nascAno
	public int getNascAno(){
		return nascAno;
	}
	//invoca os valores da variavel hjDia
	public int getHjDia(){
		return hjDia;
	}
	//invoca os valores da variavel hjMes
	public int getHjMes(){
		return hjMes;	
	}
	//invoca os valores da variavel hjAno
	public int getHjAno(){
		return hjAno;
	}
	
//----------DEMAIS MÉTODOS---------------
	//Calcula a frequencia cardiaca máxima
	public double getMaxRate(){
		this.mxRate = 220 - this.idade;		
		return mxRate;
	}
	//Calcula a frequencia cardiaca alvo minima:
	public double getMinRateAlvo (){
		this.minAlvo = this.mxRate *0.50;
		return minAlvo;
	}
	//Calcula a frequencia cardiaca alvo máxima:
	public double getMaxRateAlvo (){
		this.mxAlvo = this.mxRate * 0.85;
		return mxAlvo;
	}
}
