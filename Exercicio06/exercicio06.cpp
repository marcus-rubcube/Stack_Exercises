#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include "tad.h"

#define MAX 1000

void inverterArquivo(char nomeArqEntrada[50], char nomeArqSaida[50]){
	FILE *arqEntrada, *arqSaida;
	char linha[MAX];
	
	arqEntrada = fopen(nomeArqEntrada, "r");
    if (arqEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }
    
    arqSaida = fopen(nomeArqSaida, "w");
    if (arqSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        exit(1);
    }
    
    TpPilha pilha;
    inicializar(pilha);
    
    while (fgets(linha, MAX, arqEntrada) != NULL) {
        for (int i = 0; linha[i] != '\0'; i++) {
            push(pilha, linha[i]);
        }
        while (!vazia(pilha.topo)) {
            fputc(pop(pilha), arqSaida);
        }
    }
    
    fclose(arqEntrada);
    fclose(arqSaida);
    printf("Arquivo Invertido com Sucesso!");
    getch();
    
}

int main() {
	    
    inverterArquivo("entrada.txt", "saida.txt");
    return 0;
    
}

