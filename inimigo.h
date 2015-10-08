/*
	Lista encadeada com as tropas inimigas que vão sair no campo do 
	jogador
*/

struct Inimigo{
	
	// Propriedades
	Soldado *inimigo;
	Inimigo *prox;
	
	// Funções
	Inimigo* Insere(Inimigo *inimigo0, char * tipo);
	void Envia(Inimigo *inimigo0); // NÃO DESENVOLVIDA AINDA
	void Remove(Inimigo *anterior);
	Inimigo* Anterior(Inimigo *inimigo0);
	void LimpaNo(Inimigo *inimigo0);
	
	
};
//==================================================
// Insere um inimigo na lista encadeada
Inimigo* Inimigo::Insere(Inimigo *inimigo0, char * tipo){
	Inimigo *novo;
	novo = (Inimigo *) malloc(sizeof(Inimigo));
	novo->prox = inimigo0->prox;
	inimigo0->prox = novo;
	
	return novo;
}

//======================================================
// Limpa lista encadeada
void Inimigo::LimpaNo(Inimigo *inimigo0){
	Inimigo *p, *aux;
	p = inimigo0;
	while (p != NULL){
		aux = p;
		p->prox;
		free(aux->inimigo);
		free(aux);
	}
	inimigo0 = NULL;
}
//====================================================
//Remove o inimigo da lista encadeada com base em seu antecessor
void Inimigo::Remove(Inimigo *anterior){
	Inimigo *remove;
	remove = anterior->prox;
	anterior->prox = remove->prox;
	free(remove);
}

//=======================================================
// Calcula o inimigo que atencede a posição atual
Inimigo* Inimigo::Anterior(Inimigo *inimigo0){
	Inimigo *p;
	Inimigo *atual;
	
	atual = this;
	p = inimigo0;
	
	while( p != NULL && p->prox != atual)
		p = p->prox;
		
	return p;
}
		

