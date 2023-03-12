#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include "tad.h"

void removeElemento(TpPilha &pilha, int &achou){
	int elem, i = 0, eleRem;
	inicializar(pilha);
	
	printf("\nInforme os elementos da pilha: \n");
	do{
		printf("Elemento %d: ", i+1);
		scanf("%d", &elem);
		push(pilha, elem);
		i++;
	
	}while(elem != 0);
	
	pop(pilha); //remover o ultimo 0
	
	system("cls");
	printf("***PILHA***\n\n");
	exibePilha(pilha);
	getch();
	
	if(vazia(pilha.topo)){
		printf("A pilha está vazia!\n");
		return;
	}

	system("cls");
	printf("Informe o elemento que deseja remover: ");
	scanf("%d", &eleRem);
	
	TpPilha aux;
	inicializar(aux);
	
	int elemAux;
	
	while(!vazia(pilha.topo) && !achou){
		elemAux = pop(pilha);	
		if(elemAux == eleRem){
			achou = 1;
		}else {
			push(aux, elemAux);
		}
	}
	
	if(achou){
		while(!vazia(aux.topo)){
			elemAux = pop(aux);
			push(pilha, elemAux);
		}
		printf("Elemento removido da Pilha com sucesso!\n");
	} else {
		printf("Elemento nao foi encontrado!");
	}
	
	getch();
	
}

int main (void){
	TpPilha pilha;
	int achou = 0;
	removeElemento(pilha, achou);
	system("cls");
	
	if(achou){
		printf("****P I L H A   F I N A L****\n");
		exibePilha(pilha);
		getch();	
	}
	
}
