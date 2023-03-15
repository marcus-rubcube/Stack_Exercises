#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>
#include <locale.h>
#include "tad.h"

int palindromo(char *palavra){
	int tam = strlen(palavra);
	TpPilha pilha;
	inicializar(pilha);
	
	// passando os caracteres da palavra para a pilha
	for (int i = 0; i < tam; i++){
		if(isalpha(palavra[i])){
			push(pilha, toupper(palavra[i]));
		}
	}
	
	//comparar se os caracteres são iguais
	for(int i = 0; i < tam; i++){
		if(isalpha(palavra[i])){
			if(pop(pilha) != toupper(palavra[i])){
				return 0;
			}
		}
	}
	
	return 1;
	
	
}

int main (){
	setlocale(LC_ALL, "");
	
	char palavra[50];
	
	printf("Informe a palavra a ser testada: ");
	gets(palavra);
	
	if(palindromo(palavra)){
		printf("\n%s - São Palíndromos!\n", palavra);
	} else {
		printf("%s - Não são Palíndrimos!\n", palavra);
	}
}
