#include "header.h"

void Troca(Apontador Arvore_A,Apontador Arvore_B){
	No Copia_A = (*Arvore_A);
	No Copia_B = (*Arvore_B);
	(*Arvore_A) = Copia_B;
	(*Arvore_B) = Copia_A;
}

void bubblesort(Apontador Floresta, int Tam_Floresta){
	int i, j, trocou;
	
	for(i=0;i < Tam_Floresta - 1 ;i++){
		trocou = 0;
		for(j = 1; j < Tam_Floresta - i ; j++){
			if (strcmp(Floresta[j].Reg.chave, Floresta[j-1].Reg.chave) < 0){
				Troca(&Floresta[j-1], &Floresta[j]);
				trocou = 1;
			}
		}
		if (!trocou){
			break;
		}
	}
}
