/* C implementation QuickSort */
#include <stdio.h> 
#include <iostream>

using namespace std;

// Função para trocar dois elementos
void swap(int* a, int* b) // Ex.: a = 3 e b = 1
{ 
	int t = *a;  // t = 3
	*a = *b;     // a = 1
	*b = t;      // b = 3
}                // Resultado: a = 1 e b =3


/* Esta função leva o último elemento como pivô, lugares
o elemento pivô em sua posição correta na classificação
array e coloca todos menores (menores que pivô)
à esquerda do pivô e todos os elementos maiores à direita
de pivô */

int partition (int array1[], int first, int last) 
{ 
	int pivot = array1[last]; // O pivo recebe o ultimo valor do vetor. 
	int i = (first - 1); // O indice i recebe o elemento menor

	for (int j = first; j <= last- 1; j++) 
	{ 		
		if (array1[j] <= pivot) // Se o elemento atual for menor ou igual ao pivo
		{ 
			i++;                 // Incrementa o índice do elemento menor
			swap(&array1[i], &array1[j]); // Troca o elemento maior a esquerda com o elemento menor direita
		} 
		// Caso o elemento atual seja maior que o pivo, não tem ação.
	} 
	swap(&array1[i + 1], &array1[last]); // Troca o maior elemento da esquerda com o menor elemento da direita
										  
	return (i + 1); // Retorna incrimentando uma possição do elemento.
} 

/* A função principal que implementa QuickSort
arr [] -> Array a ser classificado,
first -> Índice inicial,
last -> Índice final */

void quickSort(int array1[], int first, int last) 
{ 
	if (first < last) // Se o primeiro elemento for menor que o último
	{ 
	
		int pi = partition(array1, first, last); // pi é o indice de particionamento,

		quickSort(array1, first, pi - 1); // Classifica os elementos separadamente antes da partição
		quickSort(array1, pi + 1, last);  // e depois da partição
	} 
} 

/* Função para imprimir o vetor */
void printArray(int array1[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++)  // Percorre todo o vetor
        cout << " " <<array1[i]; // Imprime os valores do vetor
    cout << endl;
} 

// Função principal
int main() 
{ 
	int array1[] = {10, 7, 8, 9, 1, 5};  // Inserindo valores no vetor para ordenação
	int n = sizeof(array1)/sizeof(array1[0]); // N é o tamanho do vetor
	quickSort(array1, 0, n-1); // Faz a chamada do Quicksort para a ordenação
	printf("Sorted array1: ");  // Imprime a string no terminal
	printArray(array1, n); // Imprime no terminal o vetor ordenado
    cout << endl;
	return 0; 
} 
