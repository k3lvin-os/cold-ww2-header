// Rela��o entre sprites da torre e dos indices do array
enum PosicaoTorre{
	TORRE_ESQ = 0,TORRE_MEIO,TORRE_DIR, QTD_TORRE_POS
};

// Rela��o entre os sprites do canh�o da torre e dos indices do array
enum CanhaoTorrre{
	CANHAO1_ESQ = 0 , CANHAO2_ESQ, CANHAO3_ESQ, 
	CANHAO4_ESQ,CANHAO5_ESQ,CANHAO1_DIR, CANHAO2_DIR, 
	CANHAO3_DIR, CANHAO4_DIR,CANHAO5_DIR,QTD_IMG_CANHAO
};
	
// Torre que o jogador pode colocar para defender-se de tropas 
//inimigas
struct Torre{
	
	// Constantes
	
	// Qtd. de posi��es do array de soldados aliados
	static const int QTD_ALIADOS = 1;
	static const int PRECO = 70;
	
	// Propriedades
	int x, y;
	TDelay reload;
	int tipoAnimCanhao;
	PosicaoTorre posicao;
	
	
	// Imagens das posi��es da torre
	void *imagensTorre[QTD_TORRE_POS];
	void *mascarasTorre[QTD_TORRE_POS];
	
	// Imagens dos canh�es da torre
	void *imagensCanhao[QTD_IMG_CANHAO];
	void *mascarasCanhao[QTD_IMG_CANHAO];
	
	Soldado *alvo;	// Alvo da torre
	SeqAnim seqAnim;	// Define o tipo de sequ�ncia de sprites
	Torre *prox; // Pr�xima posi��o na lista encadeada	
	int preco;	// Pre�o da torre
	char *tipo;
	
	// Soldado(s) que a torre n�o vai atacar
	char *aliados[QTD_ALIADOS];
	
	// Fun��es
	void ImagensCanhao(char *rPath); // Equivalem ao "Carregar"
	void ImagensTorre(char *rPath);  // de outras structs
	void BuscaAlvo();
	void Atira();
	void MostraTorre();
	void MostraCanhao(Direcao direcao);
	
	/*Fun��es relativas a lista encadeada empregada no tipo Torre*/
	Torre* Insere(Torre *torre0, char* tipo, int meuX, int meuY);
	void Remove(Torre *anterior);
	void LimpaNo(Torre *torre0);
	Torre* Anterior(Soldado *soldado0);	
	
	// "Construtores"
	void Init();
	void Init(char *tipoTorre, int meuX, int meuY);
	
		
};

//==============================================================
// Carrega as imagens da torre
void Torre::ImagensTorre(char *rPath){
	
	int size, inicio, fim;	
	int i, indiceH;	
	char pathImg[60]; 	
	char temp[3]; 

	for(i = 0; i < QTD_IMG_CANHAO; i++){
		
		strcpy(pathImg,ASSETS);
		strcat(pathImg,rPath);
		
		indiceH = i + 1;
		if(indiceH < 10)
			strcat(pathImg,"0");
		
		itoa(indiceH,temp,DECIMAL);
		strcat(pathImg,temp);

		strcat(pathImg,BITMAP);
		
		imagensTorre[i] = GetImage(pathImg,TORRE_W,TORRE_H);
	}		
}

//================================================================
// Carrega as imagens do canh�o da torre
void Torre::ImagensCanhao(char *rPath){
	
	int size, inicio, fim;	
	int i, indiceH;	
	char pathImg[60]; 
	char pathMask[60];	
	char temp[3]; 

	for(i = CANHAO1_ESQ; i < QTD_IMG_CANHAO; i++){
		
		strcpy(pathImg,ASSETS);
		strcat(pathImg,rPath);
		
		indiceH = i + 1;
		if(indiceH < 10)
			strcat(pathImg,"0");
		
		itoa(indiceH,temp,DECIMAL);
		strcat(pathImg,temp);
		
		strcpy(pathMask,pathImg);
		strcat(pathMask,"M");
		
		strcat(pathImg,BITMAP);
		strcat(pathMask,BITMAP);
		
		GetImage(&imagensCanhao[i], pathImg,TORRE_W,TORRE_H);
		GetImage(&mascarasCanhao[i],pathMask,TORRE_W,TORRE_H);
	}		
}
				



// "Construtor" sem par�metros
void Torre::Init(){
	x = 0;
	y = 0;
	posicao = TORRE_MEIO;
	prox = NULL;
	reload.Atualiza();
	seqAnim = DO1ATE3;
	tipoAnimCanhao = 0;
	preco = PRECO;
}


// "Construtor" que recebe e constroi um tipo de torre em espec�fico
void Torre::Init(char *tipoTorre, int meuX, int meuY){
	
	Init();
	x = meuX;
	y = meuY;
	tipo = tipoTorre;
	if(tipo == "Eua" ){
		ImagensTorre(TORRE_EUA);	
		ImagensCanhao(CANHAO_EUA);
		aliados[0] = "Eua";
	} 
	
	else if(tipo == "Urss"){
		ImagensTorre(TORRE_URSS);
		ImagensCanhao(CANHAO_URSS);
		aliados[0] = "Urss";
	}
}

// Mostra a torre
void Torre::MostraTorre(){
	putimage(x,y,imagensTorre[posicao],0);
	
	if(posicao == TORRE_ESQ){
		MostraCanhao(ESQUERDA);
	} else if(posicao == TORRE_DIR)
		MostraCanhao(DIREITA);
	else{
		MostraCanhao(ESQUERDA);
		MostraCanhao(DIREITA);
	}

	

}

//================================================================
// Mostra o canhao especificado pela direcao 
//(apenas esquerda e direita)
void Torre::MostraCanhao(Direcao direcao){
	int animAtual;
	if(direcao == ESQUERDA){
		animAtual = tipoAnimCanhao + CANHAO1_ESQ;
		putimage(x - TILE_W,y,mascarasCanhao[animAtual],AND_PUT);
		putimage(x - TILE_W,y,imagensCanhao[animAtual],OR_PUT);
	}
	else if(direcao == DIREITA){
		animAtual = tipoAnimCanhao + CANHAO1_DIR;
		putimage(x + TILE_W,y,mascarasCanhao[animAtual],AND_PUT);
		putimage(x + TILE_W,y,imagensCanhao[animAtual],OR_PUT);	
	}
}


// Insere uma torre na lista encadeada
Torre* Torre::Insere(Torre *torre0, char* tipo, int meuX, int meuY){
	Torre *novo;
	novo = (Torre *) malloc(sizeof(Torre));
	novo->Init(tipo, meuX, meuY); // Inicializa o soldado
	novo->prox = torre0->prox;
	torre0->prox = novo;
	
	// Retorna a nova tropa
	return novo;
}

// Limpa a mem�ria alocada dinamicamente
void Torre::LimpaNo(Torre *torre0){
	Torre *p, *aux;
	p = torre0;
	while(p != NULL){
		aux = p;
		p = p->prox;
		free(aux->mascarasCanhao); 
		free(aux->mascarasTorre);
		free(aux->imagensTorre);
		free(aux->imagensCanhao);
		free(aux);
	}
	torre0 = NULL;	
}
