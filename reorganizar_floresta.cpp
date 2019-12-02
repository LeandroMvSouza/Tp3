#include "header.h"

void reorganizar_floresta(Apontador Floresta,No Nova_Arvore,int Tam_Floresta,int Iterator){
	int i;
	int Tam_Subvetor = Tam_Floresta - 2 - Iterator;
	for(i=0;i<Tam_Subvetor;i++){
		Floresta[i]=Floresta[i+2];
	}
	Floresta[Tam_Floresta - 2 - Iterator] = Nova_Arvore;
}

