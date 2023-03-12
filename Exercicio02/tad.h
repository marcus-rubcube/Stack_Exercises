#define MAX_PILHA 20

struct TpPilha {
	int topo;
	int pilha[MAX_PILHA];
};

//INICIALIZAR
void inicializar(TpPilha &pilha){
	pilha.topo = -1;
}

//EMPILHAR
void push(TpPilha &pilha, int elemento){
	pilha.pilha[++pilha.topo] = elemento;
}

//DESEMPILHAR
int pop(TpPilha &pilha){
	return pilha.pilha[pilha.topo--];
}

//EXIBIR ELEMENTO DO TOPO
int topo(TpPilha pilha){
	return pilha.pilha[pilha.topo];
}

//VAZIA
int vazia(int topo){
	return topo == -1;
}

//CHEIA
int cheia(int topo){
	return topo == MAX_PILHA-1;
}

//MOSTRAR PILHA
void exibePilha(TpPilha pilha){
	while(!vazia(pilha.topo)){
		printf("\n%d\n", pop(pilha));
	}
} 
