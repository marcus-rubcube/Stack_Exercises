#include <stdio.h>
#include <string.h>

#define MAX_PALAVRAS 100

void push(char pilha[MAX_PALAVRAS][50], int *topo, char palavra[]) {
    if (*topo == MAX_PALAVRAS - 1) {
        printf("Erro: a pilha de palavras está cheia\n");
        return;
    }
    (*topo)++;
    strcpy(pilha[*topo], palavra);
}

char* pop(char pilha[MAX_PALAVRAS][50], int *topo) {
    if (*topo == -1) {
        printf("Erro: a pilha de palavras está vazia\n");
        return NULL;
    }
    char* palavra = pilha[*topo];
    (*topo)--;
    return palavra;
}

void PalavrasOrdemReversa(char Frase[100]) {
    char pilha[MAX_PALAVRAS][50];
    int topo = -1;
    int n = 0;
    char palavra[50];
    // ler palavras da frase e inseri-las na pilha
    for (int i = 0; Frase[i] != '\0'; i++) {
        if (Frase[i] == ' ') {
            palavra[n] = '\0';
            push(pilha, &topo, palavra);
            n = 0;
        } else {
            palavra[n] = Frase[i];
            n++;
        }
    }
    // inserir última palavra na pilha
    palavra[n] = '\0';
    push(pilha, &topo, palavra);
    // imprimir palavras na ordem reversa
    printf("Palavras na ordem reversa:\n");
    while (topo >= 0) {
        printf("%s ", pop(pilha, &topo));
    }
    printf("\n");
}

int main() {
    char Frase[100];
    printf("Digite uma frase: ");
    fgets(Frase, 100, stdin);
    int tam = strlen(Frase);
	Frase[tam - 1] = '\0';
    PalavrasOrdemReversa(Frase);
    return 0;
}

