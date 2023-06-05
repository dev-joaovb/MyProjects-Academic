#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n);
int main(){
	int maximo;
	printf ("\n Informe a quantidade de numeros: ");
	scanf ("%i", &maximo);
    int arr[maximo];
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    for(i=0; i<maximo; i++){
    printf("\n Informe o valor: ");
    scanf("%i", &arr[i]);
	}
    
	insertionSort(arr, n);
    
	for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    printf("\n");
	}
    return 0;
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

