#include <stdio.h>
#include <string.h>
#define buffer fflush(stdin); /// limpar tela

typedef struct x{
	struct x *dataAnterior;
	int data;
	struct x *dataPosterior;
}Data;

int main(){
	Data data1;
	Data data2;
	Data data3;
	
	printf("\n Informe a primeira data: ");
	scanf("%i", &data1.data);
	buffer;
	printf("\n Informe a segunda data: ");
	scanf("%i", &data2.data);
	buffer;
	printf("\n Informe a terceira data: ");
	scanf("%i", &data3.data);
	buffer;
	
	system("cls");
	
	printf("\n Data 1: %i", data1.data);
	printf("\n Data 2: %i", data2.data);
	printf("\n Data 3: %i", data3.data);
		
	 	data2.data = data1.dataAnterior->data;
		data3.data = data1.dataPosterior->data;
		printf("\n Data 1 Anterior: %i", data1.dataAnterior->data);
		printf("\n Data 1 Normal: %i", data1.data);
		printf("\n Data 1 Posterior: %i", data1.dataPosterior->data);
		
	 	data1.data = data2.dataAnterior->data;
		data3.data = data2.dataPosterior->data;
		printf("\n Data 2 Anterior: %i", data2.dataAnterior->data);
		printf("\n Data 2 Normal: %i", data2.data);
		printf("\n Data 2 Posterior: %i", data2.dataPosterior->data);
		
	 	data2.data = data3.dataAnterior->data;
		data1.data = data3.dataPosterior->data;
		printf("\n Data 3 Anterior: %i", data3.dataAnterior->data);
		printf("\n Data 3 Normal: %i", data3.data);
		printf("\n Data 3 Posterior: %i", data3.dataPosterior->data);
		
}


