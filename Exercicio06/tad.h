#define MAX_PILHA 30

struct TpPilha {
	int topo;
	char pilha[MAX_PILHA];
};

//INICIALIZAR
void inicializar(TpPilha &pilha){
	pilha.topo = -1;
}

//EMPILHAR
void push(TpPilha &pilha, char elemento){
	pilha.pilha[++pilha.topo] = elemento;
}

//DESEMPILHAR
char pop(TpPilha &pilha){
	return pilha.pilha[pilha.topo--];
}

//EXIBIR ELEMENTO DO TOPO
char topo(TpPilha pilha){
	return pilha.pilha[pilha.topo];
}

//VAZIA
char vazia(int topo){
	return topo == -1;
}

//CHEIA
char cheia(int topo){
	return topo == MAX_PILHA-1;
}

//MOSTRAR PILHA
void exibePilha(TpPilha pilha){
	while(!vazia(pilha.topo)){
		printf("\n%d\n", pop(pilha));
	}
} 

