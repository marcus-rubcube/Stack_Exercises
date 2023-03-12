#define MAX_PILHA 10

struct TpPilha {
	int topo;
	char pilha[MAX_PILHA];
};

void inicializar (TpPilha &pilha){
	pilha.topo = -1;
}
void push(TpPilha &pilha, char elemento){
	pilha.pilha[++pilha.topo] = elemento;
}
char pop(TpPilha &pilha){
	return pilha.pilha[pilha.topo--];
}
char elementoTopo(TpPilha pilha){
	return pilha.pilha[pilha.topo];
}
char vazia(int topo){
	return topo == -1;
}
char cheia(int topo){
	return topo == MAX_PILHA-1;
}
void exibir(TpPilha pilha){
	while(!vazia(pilha.topo)){
		printf("%c\n", pop(pilha));
	}
}

