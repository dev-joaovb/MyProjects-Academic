/// alocacao dinamica
#include <stdio.h>
int main(){
	int *v;
	
	v = (int*)malloc(10* sizeof(int));
	if(v == NULL){
		printf ("\n Error 404.");
		exit(1);
	}
	
	v[100] = 33;
	
	printf("\nN: %i", v[100]);
	free(v);
	
	return 0;	
}
