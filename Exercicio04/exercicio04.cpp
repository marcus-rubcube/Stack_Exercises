#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio2.h>
#include <locale.h>
#include "tad.h"

#define MAX_NUM_STACKS 15 // número máximo de Pilhas

void aleatorioPilha(TpPilha stacks[MAX_NUM_STACKS], int num_stacks, int num_operations){
	for (int i = 0; i < num_stacks; i++) {
        inicializar(stacks[i]);
    }

    // realizar operações aleatórias de inserção e retirada em Pilhas aleatórias
    for (int i = 0; i < num_operations; i++) {
        int operation = rand() % 2; // 0 para push, 1 para pop
        int stack_index = rand() % num_stacks; // escolher Pilha aleatória
        if (operation == 0) { // push
            int value = rand() % 100;
            if(!cheia(stacks[stack_index].topo)){
            	push(stacks[stack_index], value);
            	printf("Inserindo %d na Pilha %d\n", value, stack_index);
            }
        } else { // pop
            if (!vazia(stacks[stack_index].topo)) {
            	int value = pop(stacks[stack_index]);
                printf("Removendo %d da Pilha %d\n", value, stack_index);
            }
        }
    }

    getch();
}

int main() {
	setlocale(LC_ALL, "");
    srand(time(NULL)); // inicializar gerador de números aleatórios

    int num_stacks, num_operations;
    printf("Digite o número de Pilhas a serem utilizadas: ");
    scanf("%d", &num_stacks);
    printf("Digite o número de operações a serem realizadas: ");
    scanf("%d", &num_operations);

    // criar vetor de Pilhas vazio
    TpPilha stacks[MAX_NUM_STACKS];
    aleatorioPilha(stacks, num_stacks, num_operations);
    return 0;
}
