#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include <ctype.h>
#include "TAD.h"

char menu(void){
	system("cls");
	printf("\n**Testando a Pilha**\n");
	printf("\n[A] Inicializar");
	printf("\n[B] Empilhar -PUSH");
	printf("\n[C] Exibir o elemento do topo");
	printf("\n[D] Desempilhar -POP");
	printf("\n[E] Exibir Pilha");
	printf("\n[ESC] Sair\n");
	printf("\nOpção: ");
	return toupper(getch());
}

int main (void){
	TpPilha p;
	char op;
	do {
		op = menu();
		switch(op){
			case 'A': 
				inicializar(p);
				printf("\nPilha inicializada!\n");
				getch();
				break;
			
			case 'B':
				if(cheia(p.topo)){
					printf("\nPilha esta cheia!\n");
				} else {
					printf("Elemento: ");
					push(p, getche());
					printf("\nElemento inserido com sucesso\n");

				}
				getch();
				break;
			
			case 'C':
				if(vazia(p.topo)){
					printf("\nPilha esta vazia!\n");
				} else {
					printf("Elemento: %c", elementoTopo(p));
					getch();
				}
				break;
			
			case 'D':
				if(vazia(p.topo)){
					printf("\nPilha esta vazia!\n");
				} else {
					pop(p);
					printf("\nElemento removido com sucesso!\n");
				}
				getch();
				break;
			
			case 'E':
				if(vazia(p.topo)){
					printf("\nPilha esta vazia!\n");
				} else {
					exibir(p);
				}
				getch();
				break;
		}
	}while(op != 27);
}
