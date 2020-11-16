#include <iostream>
using namespace std;

void criaHeap(int *vet, int i, int f){
	// salva a posicao inicial em aux
	int aux=vet[i];
	// calcula a posicao do primeiro filho 
	int j=i*2+1;
	while(j<=f){ // se o filho for menor que o final do vetor, segue o loop
		if(j<f){
			//verifica qual dos dois filhos eh maior
			// se o segundo filho for maior, o valor de j eh sobrescrito
			// caso contrario, o j continua o mesmo valor atribuido anteriormente
			if(vet[j]<vet[j+1]){
				j=j+1;
			}
		}
		if(aux<vet[j]){ 
			// se o pai eh menor que o filho, ele nao esta na posicao correta
			// substitui o pai pelo filho
			vet[i]=vet[j];
			// atribui o J como pai
			i=j;
			// calcula o proximo filho e volta no while
			j=2*i+1;
		} else {
		// se o pai nao for menor q o filho
			j=f+1;
		}
	}
	vet[i]=aux;
}

void heapSort(int *vet, int N) {
	int i, aux;
	for(i=(N-1)/2; i>=0; i--)
		criaHeap(vet, i, N-1);		
	for(i=N-1; i>=1; i--) {
		aux=vet[0];
		vet[0]=vet[i];
		vet[i]=aux;
		criaHeap(vet, 0, i-1);
	}
}

void imprime(int *vet, int N){
	for(int i = 0; i < N; i++)
		cout << vet[i] << " ";
	cout << endl;
}


int main(){
	int N = 6;
	int vet[N] = {14,21,6,9,1,5};
	cout<<"\nVetor original: ";
	imprime(vet, N);
	heapSort(vet,N);
	cout<<"\nVetor ordenado: ";
	imprime(vet, N);	
}

