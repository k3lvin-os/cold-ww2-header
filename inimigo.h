/*
	Lista encadeada com as tropas inimigas que v�o sair no campo do 
	jogador
*/

struct Inimigo{
	
	Soldado *inimigo;
	Inimigo *prox;
	
	/*Fun��es que ser�o necess�rias
	
	Soldado* Insere(Soldado *soldado0, char* tipo);
	void Remove(Soldado *anterior);
	void Enviar(Soldado *soldado0, CampoJogo meuCampo);
	void LimpaNo(Soldado *soldado0);
	void Chegou(Soldado *anterior);
	Soldado* Anterior(Soldado *soldado0);

	*/
	
	
	Inimigo* Insere(Inimigo *inimigo0, char * tipo);
	void Envia(Inimigo *soldado0);
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
/*// Limpa n� da lista encadeada
void Soldado::LimpaNo(Soldado *soldado0){
	Soldado *p, *aux;
	p = soldado0;
	while(p != NULL){
		aux = p;
		p = p->prox;
		free(aux->imagens);
		free(aux);
	}
	soldado0 = NULL;	
}*/
