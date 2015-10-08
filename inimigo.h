/*
	Lista encadeada com as tropas inimigas que vão sair no campo do 
	jogador
*/

struct Inimigo{
	
	Soldado *inimigo;
	Inimigo *prox;
	
	/*Funções que serão necessárias
	
	Soldado* Insere(Soldado *soldado0, char* tipo);
	void Remove(Soldado *anterior);
	void Enviar(Soldado *soldado0, CampoJogo meuCampo);
	void LimpaNo(Soldado *soldado0);
	void Chegou(Soldado *anterior);
	Soldado* Anterior(Soldado *soldado0);

	*/
	
	
	Inimigo* Insere(Inimigo *inimigo0, char * tipo);
	
	
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
/*Soldado* Soldado::Insere(Soldado *soldado0, char * tipo){
	Soldado *novo;
	novo = (Soldado *) malloc(sizeof(Soldado));
	novo->Init(tipo); // Inicializa o soldado
	novo->prox = prox;
	prox = novo;
	
	// Retorna a nova tropa
	return novo;
}
*/

