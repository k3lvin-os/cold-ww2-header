// Relação entre sprites da torre e dos indices do array
enum PosicaoTorre{
	TORRE_ESQ = 0,TORRE_MEIO,TORRE_DIR, QTD_TORRE_POS
};

// Relação entre os sprites do canhão da torre e dos indices do array
enum CanhaoTorrre{
	CANHAO1_ESQ = 0 , CANHAO2_ESQ, CANHAO3_ESQ, 
	CANHAO4_ESQ,CANHAO5_ESQ,CANHAO1_DIR, CANHAO2_DIR, 
	CANHAO3_DIR, CANHAO4_DIR,CANHAO5_DIR,QTD_IMG_CANHAO
};
	
// Torre que o jogador pode colocar para defender-se de tropas 
//inimigas
struct Torre{
	
	// Constantes
	
	// Qtd. de posições do array de soldados aliados
	static const int QTD_ALIADOS = 1;
	
	// Propriedades
	int x, y;
	TDelay reload;
	int tipoAnimCanhao;
	PosicaoTorre posicao;
	
	// Imagens das posições da torre
	void *imagensTorre[QTD_TORRE_POS];
	void *mascarasTorre[QTD_TORRE_POS];
	
	// Imagens dos canhões da torre
	void *imagensCanhao[QTD_IMG_CANHAO];
	void *mascarasCanhao[QTD_IMG_CANHAO];
	
	Soldado *alvo;	// Alvo da torre
	SeqAnim seqAnim;	// Define o tipo de sequência de sprites
	Torre *prox; // Próxima posição na lista encadeada	
	int preco;	// Preço da torre
	char *tipo;
	
	// Soldado(s) que a torre não vai atacar
	char *aliados[QTD_ALIADOS];
	
	// Funções
	void ImagensCanhao(char *rPath); // Equivalem ao "Carregar"
	void ImagensTorre(char *rPath);  // de outras structs

	void BuscaAlvo();
	void Atira();
	void MostraTorre();
	void MostraCanhao(Direcao direcao);
	
	
	// "Construtores"
	void Init();
	void Init(char *tipoTorre);
	
		
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
// Carrega as imagens do canhão da torre
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
				



// "Construtor" sem parâmetros
void Torre::Init(){
	x = 0;
	y = 0;
	posicao = TORRE_MEIO;
	prox = NULL;
	reload.Atualiza();
	seqAnim = DO1ATE3;
	tipoAnimCanhao = 0;
}


// "Construtor" que recebe e constroi um tipo de torre em específico
void Torre::Init(char *tipoTorre){
	
	Init();
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
