#include "header.h"

// Codificação Huffman :
// . cada palavra será representada em uma folha de uma árvore binária
// . o código de cada palavra é obtida através do caminhamento da árvore
// . caminhou para a esquerda? adiciona 0
// . caminhou para a direita? adiciona 1

/*
Inicialmente cada palavra é um nó raiz de uma arvore binária. A cada iteração do código as duas árvores de menores contadores são combinadas
de forma que a com o menor contador dentre as duas fique à esquerda da raiz da nova árvore.

Essa nova árvore é então re-inserida na floresta, sendo sua frequência a soma dos contadores das árvores combinadas.

Para criar a floresta inicial tenho que percorrer a hash_table e para cada posição não vazia criar uma árvore com cada palavra.

Cada nó da árvore tem 3 campos :
	registro com - contador; folhas; palavra.
	apontador para árvore à esquerda.
	apontador para árvore à direita.
*/

void criar_floresta_inicial(Apontador Floresta, tipodicionario T,int Tam_Floresta){
	int i,contador = 0;
	for(i = 0; i < MAX_SIZE_OF_A_DICTIONARY; i++){
		if(strcmp(T[i].chave, VAZIO) != 0){
			Floresta[contador].Reg = T[i];
			Floresta[contador].Dir = NULL;
			Floresta[contador].Esq = NULL;
			contador++;
		}
		if(contador==Tam_Floresta){
			break;
		}
	}
}

void arvore_huffman(Apontador Floresta, int Tam_Floresta){
	int i,j,fim,Tam_Subvetor;
	int Total_De_Iteracoes = Tam_Floresta-1;
	No Nova_Arvore;
	
	for(i=0;i < Total_De_Iteracoes;i++){
		printf("---------------------------------------------\nITERACAO i = %d\n---------------------------------------------\n",i+1);
		//Ordenando a floresta
		mergesort_for_count(Floresta,0,Tam_Floresta-1-i);
		printf("Vetor Floresta apos Mergesort_for_count\n");
		for(j=0;j<Tam_Floresta;j++){
 			printf("Floresta[%d] ->\t counter = %d\t folhas = %d\t palavra = ' %s '\n",j,Floresta[j].Reg.counter,Floresta[j].Reg.folhas,Floresta[j].Reg.chave);
		}
		
		if(Floresta[0].Reg.counter==Floresta[1].Reg.counter){
			
			fim = achar_fim(Floresta);
			
			mergesort_for_leaves(Floresta,0,fim-1-i);
			printf("Vetor Floresta apos Mergesort_for_leaves\n");
			for(j=0;j<Tam_Floresta;j++){
 				printf("Floresta[%d] ->\t counter = %d\t folhas = %d\t palavra = ' %s '\n",j,Floresta[j].Reg.counter,Floresta[j].Reg.folhas,Floresta[j].Reg.chave);
			}
			
			if(Floresta[0].Reg.folhas==Floresta[1].Reg.folhas){
				bubblesort(Floresta,fim);
				printf("Vetor Floresta apos Bubblesort\n");
				for(j=0;j<Tam_Floresta;j++){
 					printf("Floresta[%d] ->\t counter = %d\t folhas = %d\t palavra = ' %s '\n",j,Floresta[j].Reg.counter,Floresta[j].Reg.folhas,Floresta[j].Reg.chave);
				}
			}
		}
		
		// Juntando as primeiras duas árvores e reorganizando a floresta
		juntar_arvores(Floresta,&Nova_Arvore);
		reorganizar_floresta(Floresta,Nova_Arvore,Tam_Floresta,i);
		/*
		printf("FLORESTA REORGANIZADA!!!\n");
			for(j=0;j<Tam_Floresta;j++){
 			printf("Floresta[%d] ->\t counter = %d\t folhas = %d\t palavra = ' %s '\n",j,Floresta[j].Reg.counter,Floresta[j].Reg.folhas,Floresta[j].Reg.chave);
		}
		*/
	}
	
	printf("----------------------------------\nFIM\n----------------------------------\n");
	
	// Ao final a árvore huffman que desejamos estará em Floresta[0]
}

