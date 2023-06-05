package com.mycompany.desconto;

public class Desconto {

private String nome;
private float preco;
private double precototal;
private int quantidade;
private double desconto;


public Desconto() {}

public String getNome() {
	return nome;
}
public void setNome(String nome) {
	this.nome = nome;
}
public float getPreco() {
	return preco;
}
public void setPreco(float preco) {
	this.preco = preco;
}
public int getQuantidade() {
	return quantidade;
}
public void setQuantidade(int quantidade) {
	this.quantidade = quantidade;
}
public double getPrecototal() {
	if (quantidade <=10) {
		
		return this.precototal = preco * quantidade;	
	}	
	else if (quantidade <=20) {
		return (this.preco * quantidade );	
	
	}
	// preco * quantidade = valor total
	else if(quantidade <=50) {
		return (this.preco * quantidade); 	
	}
	return preco;
}
public void setPrecototal(float precototal) {
		this.precototal = preco * quantidade;
//b. de	11 a 20	unidades: 10% de desconto
//de 21	a 50 unidades: 20% de desconto
//acima	de 50 unidades: 25% de desconto
		}
public void status() {
	System.out.println("Nome do produto: " + this.getNome());
	System.out.println("Preço: R$ " + this.getPreco());
	System.out.println(this.getQuantidade() + " quantidades");
	System.out.println("Valor total " + this.getPrecototal() + "R$");
	System.out.println("Valor com desconto " + "È o valor total menos * 0.2 mas desta maneira nao vai");
	System.out.println("Desconto é de: R$" + this.getPrecototal() * 0.1);
}
}
