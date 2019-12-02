#include "header.h"

unsigned int Pesquisa(palavra item,int N, tipodicionario T) {
	int i = 0;
	unsigned int hash_code;
	hash_code = hash_function(item, N); // transforma a chave

	while ( (strcmp(T[(hash_code + i) % N].chave, VAZIO) != 0) &&
	 		(strcmp(T[(hash_code + i) % N].chave, item) != 0) && 
			(i < N)) {
 		i++;
 	}
 	if (strcmp(T[(hash_code + i) % N].chave, item) == 0) {
 		return ((hash_code + i) % N);
 	}
 	else{
 		return N; // Pesquisa sem sucesso
 	}
}

