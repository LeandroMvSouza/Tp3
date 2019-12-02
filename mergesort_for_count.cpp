#include "header.h"

void merge_for_count(Apontador Floresta,int left,int meio,int right){
	int i,j,k;
	
	int n1 = meio - left + 1; // Numero de elementos do início ao meio do vetor
	int n2 = right - meio;   // Numero de elementos do meio ao fim do vetor
	
	// Criando vetores auxiliares
	No L[n1], R[n2];
	
	// Copiar os dados da Floresta para os vetores auxiliares
	for(i=0;i<n1;i++){
		L[i] = Floresta[left + i];
	}
	for(j=0;j<n2;j++){
		R[j] = Floresta[meio + 1 + j];
	}	
	
	i=0; j=0; k=left;
	
	while(i<n1 && j<n2){
		if(L[i].Reg.counter <= R[j].Reg.counter){
			Floresta[k] = L[i];
			i++;
		}
		else{
			Floresta[k] = R[j];
			j++;
		}
		k++;
	}
		
	// Caso sobrarem elementos no vetor auxiliar à esquerda L, copie-os para o cronograma
	while(i<n1){
		Floresta[k] = L[i];
		i++;
		k++;
	}
	// Caso sobrarem elementos no vetor auxiliar à direita R, copie-os para o cronograma
	while(j<n2){
		Floresta[k] = R[j];
		j++;
		k++;
	}
}

void mergesort_for_count(Apontador Floresta,int left, int right){
	if(left<right){
		int meio = left+(right-left)/2;
		mergesort_for_count(Floresta,left,meio);
		mergesort_for_count(Floresta,meio+1,right);
		merge_for_count(Floresta,left,meio,right);
	}
}
