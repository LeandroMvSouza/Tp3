#include "header.h"

// Rick deseja diminuir o tamanho de suas mensagens.
// Criar um algoritmo capaz de comprimir suas mensagens de texto, e assim, diminuir a quantidade de dados enviados.

// Programa deve ser capaz de analisar mensagens de texto e produzir uma codificação eficiente do texto, 
// reduzindo o número de bits necessários para codificar a mensagem.

// Utilizar códigos curtos para palavras que são muito utilizadas na mensagem, e códigos mais longos para palavras pouco utilizadas.

// Num primeiro momento, seu programa deverá analisar a mensagem para descobrir quais
// palavras são mais frequentes naquele texto. Em seguida, seu programa deverá criar a nova codificação
// das palavras através de uma estrutura de árvore que irá priorizar as palavras mais frequentes com códigos mais curtos.

int main() {
	
	int i,N, Tam_Floresta = 0;
	char aux;
	palavra word;
	//-------------------------------------------------------------------------------------
	// inteiro N (1 < N < 2^31) indicando o número de palavras contida na mensagem de texto.
	printf("Diga o tamanho da mensagem:\n");
	scanf("%d\n",&N);
	
	tipodicionario T;
	// Construtor do dicionario T
	for (i = 0; i < N; i++){
		strcpy(T[i].chave, VAZIO);
		T[i].counter = 0;
		T[i].folhas = 1;
	}
		
	for (i = 0; i < N; i++){
    	scanf("%s",word);
    	// insira/atualize o contador de `word` na estrutura de busca aqui
    	Insere(word,N,T,&Tam_Floresta);
 	}
 	
 	No Floresta[Tam_Floresta];
 	criar_floresta_inicial(Floresta,T,Tam_Floresta);
 	
 	printf("A floresta tem tamanho = %d\n",Tam_Floresta);
 	
 	arvore_huffman(Floresta,Tam_Floresta);
 	
 	printf("Vetor Floresta APOS apos criar arvore huffman :\n");
 	for(i=0;i<Tam_Floresta;i++){
 		printf("Floresta[%d] ->\t counter = %d\t palavra = ' %s '\n",i,Floresta[i].Reg.counter,Floresta[i].Reg.chave);
	}
	
	printf("\n-------------------------------------\n");
	printf("Folha mais a esquerda = %s\n",Floresta[0].Esq->Esq->Esq->Esq->Reg.chave);
	printf("Folha mais a direita = %s\n",Floresta[0].Dir->Dir->Dir->Dir->Reg.chave);
	printf("Node no caminho Dir Esq = %s\n",Floresta[0].Dir->Esq->Reg.chave);
	printf("Node no caminho Esq Dir = %s\n",Floresta[0].Esq->Dir->Reg.chave);
	//central(Floresta);
	
 	printf("\nEntre qual palavra deseja medir o numero de ocorrencias\n");
	scanf(" %c %s",&aux,word);
	while(aux=='q'||aux=='c'){
		if(aux=='q'){
			printf("%d\n", T[Pesquisa(word,N,T)].counter);
			scanf(" %c %s",&aux,word);	
		}
		else{
			
		}
	}
	return 0;
}
