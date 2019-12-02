#include "header.h"

void Insere(palavra item,int N, tipodicionario T,int *Num_Palavras_Diferentes){
	int i = 0;
	unsigned int hash_code;

	if (Pesquisa(item, N, T) < N) {
		T[Pesquisa(item, N, T)].counter++;
	}
	
	else {
		hash_code = hash_function(item, N); /* transforma a chave */
		while ((strcmp(T[(hash_code + i) % N].chave, VAZIO) != 0) &&
 			   (i < N)) {
 			i++;
		}
		if (i < N) {
 			strcpy (T[(hash_code + i) % N].chave, item);
 			T[Pesquisa(item, N, T)].counter++;
 			(*Num_Palavras_Diferentes) += 1;
 			/* Copiar os demais campos de x, se existirem */
		}
		else {
			return;
		}
	}
}
