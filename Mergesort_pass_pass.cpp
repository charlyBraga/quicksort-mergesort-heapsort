#include <iostream>
#define TAM 7
#define INTEIRO unsigned long int 

using namespace std;

void imprime(string texto, INTEIRO * V, INTEIRO  inicio, INTEIRO fim){
	cout << texto;
	for(INTEIRO i = inicio; i <= fim; i++)
		cout << V[i] << " ";
	cout << endl;
}

void merge(INTEIRO *V, INTEIRO inicio, INTEIRO fim){
	INTEIRO med = (inicio + fim) / 2;
    INTEIRO tam1 = med - inicio + 1;
    INTEIRO tam2 = fim - med;
    INTEIRO * Esq = new INTEIRO [tam1];
	INTEIRO * Dir = new INTEIRO [tam2];
    for(INTEIRO i = 0; i < tam1; i++)
        Esq[i] = V[inicio + i];
    for(INTEIRO j = 0; j < tam2; j++)
        Dir[j] = V[med + 1 + j]; 
    INTEIRO i = 0; 
    INTEIRO j = 0; 
    INTEIRO k = inicio;     
    while (i < tam1 && j < tam2){
        if (Esq[i] <= Dir[j]){
            V[k] = Esq[i];
            i++;
        } else{
            V[k] = Dir[j];
            j++;
        }
        k++;
    }
    while (i < tam1){
        V[k] = Esq[i];
        i++;
        k++;
    }
    while (j < tam2){
        V[k] = Dir[j];
        j++;
        k++;
    }
   
    delete []Esq;
	delete []Dir;
}
 
void mergesort(INTEIRO *V, INTEIRO inicio, INTEIRO fim){
	imprime("Divide - Mergesort(): ", V, inicio, fim);
	if (inicio < fim){		
		INTEIRO med = (inicio + fim) / 2;
		mergesort(V, inicio, med);	
		mergesort(V, med + 1, fim);
		merge(V, inicio, fim);
		imprime("Junta e Ordena - Merge(): ", V, inicio, fim);	
	}
}


int main() {
	INTEIRO *V =  new INTEIRO [TAM];	
	cout << "\n++++++ ALGORITMO MERGESORT (Ordenacao por Fusao) ++++++ \n\n";
	cout<<"\n++ Vetor original DESORDENADO ++\n\n";		
	V[0]=38;
	V[1]=27;
	V[2]=43;
	V[3]=3;
	V[4]=9;
	V[5]=82;
	V[6]=10; 
	imprime("Elementos do vetor: ", V, 0, TAM-1);
	
	cout << "\n-----------------------------\n++ Passo a passo do processo de ordenacao ++\n\n";
	mergesort(V, 0, TAM-1);
	cout<<"\n---------------------------------\n++ Vetor ORDENADO ++\n\n";	
	imprime("Elementos do vetor: ", V, 0, TAM-1);	
	delete [] V;
	return 0;
}














