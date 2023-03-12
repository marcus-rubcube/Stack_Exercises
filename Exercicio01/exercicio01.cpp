#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include "tad.h"

int main (void){
	TpPilha pilha1;
	int elemento, i = 0;
	
	inicializar(pilha1);
	printf("\n**** PILHA 1 ****\n");
	printf("--0 para Parar a leitura--\n\n");
	printf("Elemento %d: ", i+1);
	scanf("%d", &elemento);
	
	while(elemento != 0){
		i++;
		push(pilha1, elemento);
		printf("Elemento %d: ", i+1);
		scanf("%d", &elemento);
	}
	
	TpPilha pilha2;
	i = 0;
	
	inicializar(pilha2);
	system("cls");
	printf("\n**** PILHA 2 ****\n");
	printf("--0 para Parar a leitura--\n\n");
	printf("Elemento %d: ", i+1);
	scanf("%d", &elemento);
	
	while(elemento != 0){
		i++;
		push(pilha2, elemento);
		printf("Elemento %d: ", i+1);
		scanf("%d", &elemento);
	}
	
	TpPilha aux;
	inicializar(aux);
	int elemAux;
	while(!vazia(pilha2.topo)){
		elemAux = pop(pilha2);
		push(aux, elemAux);
	}
	
	while(!vazia(aux.topo)){
		elemAux = pop(aux);	
		push(pilha1, elemAux);
	}
	
	system("cls");
	printf("\n***PILHA 1 - FINAL***\n");
	exibePilha(pilha1);
	return 0;
}
