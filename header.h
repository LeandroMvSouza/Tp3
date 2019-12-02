#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

#define MAX_SIZE_OF_A_DICTIONARY 16384
#define MAX_SIZE_OF_A_WORD 64
#define MIN 97 // MIN -> 'a' representado como inteiro na tabela ascii

#define VAZIO "!!!!!!!!!!"

//------------ Estrutura - Tabela Hash -----------------
typedef char palavra[MAX_SIZE_OF_A_WORD];
	
typedef struct tipoitem{
	palavra chave;
	int counter;
	int folhas;
}tipoitem;

typedef tipoitem tipodicionario[MAX_SIZE_OF_A_DICTIONARY];

//------------ Estrutura - Árvore Binária -----------------
typedef struct No * Apontador; 

typedef struct No {
	tipoitem Reg;
	Apontador Esq, Dir;
}No; 

//------------ Métodos - Tabela Hash ----------------------
unsigned int hash_function(palavra item,int N);

unsigned int Pesquisa(palavra item,int N, tipodicionario T);

void Insere(palavra item,int N, tipodicionario T,int *Num_Palavras_Diferentes);    

//------------ Métodos - Árvore Binária --------------------
void criar_floresta_inicial(Apontador Floresta, tipodicionario T,int Num_Palavras_Diferentes);

void juntar_arvores(Apontador Floresta,Apontador Arvore);
void reorganizar_floresta(Apontador Floresta,No Nova_Arvore,int Tam_Floresta,int Iterator);
void arvore_huffman(Apontador Floresta, int Tam_Floresta);

void central (Apontador r);

//------------ Métodos Auxiliares --------------------------

void merge_for_count(Apontador Floresta,int left,int meio,int right);
void merge_for_leaves(Apontador Floresta,int left,int meio,int right);
void mergesort_for_count(Apontador Floresta,int left, int right);
void mergesort_for_leaves(Apontador Floresta,int left, int right);

int achar_fim(Apontador Floresta);
void bubblesort(Apontador Floresta, int Tam_Floresta);
void Troca(Apontador Arvore_A,Apontador Arvore_B);
#endif
