#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio2.h>
#include <locale.h>
#include "tad.h"

int main() {
    int n, i;
    TpPilha pilha;
    inicializar(pilha);
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);                       
    
    int vetor[n];
    
    printf("Digite os valores do vetor: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        push(pilha, vetor[i]);
    }
    
    printf("Vetor invertido: ");
    for (i = 0; i < n; i++) {
        vetor[i] = pop(pilha);
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}

