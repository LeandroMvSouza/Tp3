#include "header.h"

void juntar_arvores(Apontador Floresta,Apontador Nova_Arvore){
	Nova_Arvore->Dir = &Floresta[1];
	Nova_Arvore->Esq = &Floresta[0];
	
	Nova_Arvore->Reg.counter = Floresta[1].Reg.counter + Floresta[0].Reg.counter;
	Nova_Arvore->Reg.folhas = Floresta[1].Reg.folhas + Floresta[0].Reg.folhas;
	
	if(strcmp(Floresta[0].Reg.chave,Floresta[1].Reg.chave) < 0){
		strcpy(Nova_Arvore->Reg.chave,Floresta[0].Reg.chave);
	}
	else{
		strcpy(Nova_Arvore->Reg.chave,Floresta[1].Reg.chave);
	}
	printf("Nova_Arvore->Reg.chave = %s\tNova_Arvore->Esq->Reg.chave = %s\tNova_Arvore->Esq->Dir.chave = %s\n",Nova_Arvore->Reg.chave,
																											  Nova_Arvore->Esq->Reg.chave,
																											  Nova_Arvore->Dir->Reg.chave);
}
