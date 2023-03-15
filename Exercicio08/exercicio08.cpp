#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100 // tamanho m�ximo do vetor que simula a pilha

int topo[3] = {-1, -1, -1}; // vari�veis que armazenam o topo de cada pilha
int pilha[3][MAX_SIZE]; // vetor que simula as tr�s pilhas

// Fun��o que insere um disco na pilha correspondente
void push(int disco, int p) {
    if (topo[p] == MAX_SIZE - 1) {
        printf("Erro: a pilha %d est� cheia\n", p);
        return;
    }
    topo[p]++;
    pilha[p][topo[p]] = disco;
}

// Fun��o que remove e retorna o topo da pilha correspondente
int pop(int p) {
    if (topo[p] == -1) {
        printf("Erro: a pilha %d est� vazia\n", p);
        return -1;
    }
    int disco = pilha[p][topo[p]];
    topo[p]--;
    return disco;
}

// Fun��o que move um disco da haste origem para a haste destino
void moveDisco(int origem, int destino) {
    int disco = pop(origem);
    if(disco == -1){
    	return;
    }
    push(disco, destino);
    printf("Mova o disco %d da haste %d para a haste %d\n", disco, origem, destino);
}

int main() {
    int n = 3; // n�mero de discos
    int origem = 0, destino = 2, auxiliar = 1; // hastes de origem, destino e auxiliar
    int movimentos = (int)(pow(2, n) - 1);
    // Inicializar a pilha de origem com os n discos
    for (int i = n; i > 0; i--) {
        push(i, origem);
    }
    // Executar os movimentos necess�rios
    for (int i = 1; i <= movimentos; i++) {
        if (i % 3 == 1) {
            moveDisco(origem, destino);
        } else if (i % 3 == 2) {
            moveDisco(origem, auxiliar);
        } else {
            moveDisco(auxiliar, destino);
        }
    }
    return 0;
}
