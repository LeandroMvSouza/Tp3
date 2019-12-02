#include "header.h"

unsigned int hash_function(palavra item,int N){
	int i,sum = 0;
	int tamanho_da_string = strlen(item);
	
	for(i = 0;i < tamanho_da_string; i++){
		sum += ( item[i] - MIN );
	}
	if(sum%N<0){
		return (sum%N*-1);
	}
	else{
		return (sum%N);
	}	
}
