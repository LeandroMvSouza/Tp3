#include "header.h"

int achar_fim(Apontador Floresta){
	int i;
	int fim = 1;
	while( (Floresta[i].Reg.counter==Floresta[i+1].Reg.counter) &&
		   (Floresta[i].Reg.folhas==Floresta[i+1].Reg.folhas) ) {
		fim++;
		i++;
	}
	return fim;
}
