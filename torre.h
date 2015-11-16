// Relação entre sprites da torre e dos indices do array
enum PosicaoTorre{
	TORRE_ESQ = 0,TORRE_MEIO,TORRE_DIR, TORRE_GUI, QTD_IMG_TORRE
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
	void *imagensTorre[QTD_IMG_TORRE];
	void *mascaraGUI;
	
	// Imagens dos canhões da torre
	void *imagensCanhao[QTD_IMG_CANHAO];
	void *mascarasCanhao[QTD_IMG_CANHAO];
	
	SeqAnim seqAnim;	// Define o tipo de sequência de sprites
	Torre *prox; // Próxima posição na lista encadeada	
	int preco;	// Preço da torre
	char *tipo;
	TDelay tempoTrocaPos;
	
	// Soldado(s) que a torre não vai atacar
	char *aliados[QTD_ALIADOS];
	
	// Funções
	void ImagensCanhao(char *rPath); // Equivalem ao "Carregar"
	void ImagensTorre(char *rPath);  // de outras structs
	Soldado* BuscaAlvo(Soldado *inimigo0);
	int Atira(Soldado *alvo);
	void MostraTorre();
	void MostraCanhao(Direcao direcao);
	bool CampoVisao(Soldado inimigo);
	void AnimacaoPatrulha();
	void AnimacaoMira(Soldado *alvo);
	bool SemTorrePerto(Torre *torre0,int x,int y);
	
	
	/*Funções relativas a lista encadeada empregada no tipo Torre*/
	Torre* Insere(Torre *torre0, char* tipo, int meuX, int meuY);
	void Remove(Torre *anterior);
	void LimpaNo(Torre *torre0);
	void AnulaEsteAlvo(Torre *torre0, Soldado *esteAlvo);
	
	// "Construtores"
	void Init();
	void Init(char *tipoTorre, int meuX, int meuY);
	void Init(char *tipoTorre, int meuX, int meuY, bool isGUI);
	
	
		
};


//==============================================================
// Carrega as imagens da torre
void Torre::ImagensTorre(char *rPath){
	
	int size, inicio, fim;	
	int i, indiceH;	
	char pathImg[60];
	char pathMask[60]; 	
	char temp[3]; 

	for(i = 0; i < QTD_IMG_TORRE; i++){
		
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
	strcpy(pathMask,ASSETS);
	strcat(pathMask,rPath);
	strcat(pathMask,"04M");
	strcat(pathMask,BITMAP);
	mascaraGUI = GetImage(pathMask,TORRE_W,TORRE_H);
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
	tempoTrocaPos.Atualiza();
}


// "Construtor" que recebe e constroi um tipo de torre em específico
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

// Construtor que verifica se a torre é uma GUI ou não
void Torre::Init(char *tipoTorre, int meuX, int meuY, bool isGUI){
	Init(tipoTorre,meuX,meuY);
	
	if(isGUI == true)
		posicao = TORRE_GUI;
}


// Mostra a torre
void Torre::MostraTorre(){
	
	if(posicao == TORRE_ESQ){
		MostraCanhao(ESQUERDA);
	} else if(posicao == TORRE_DIR)
		MostraCanhao(DIREITA);
	else{
		MostraCanhao(ESQUERDA);
		MostraCanhao(DIREITA);
	}
	
	if(posicao == TORRE_GUI){
		putimage(x,y,mascaraGUI,AND_PUT);
		putimage(x,y,imagensTorre[posicao],OR_PUT);
	} else
		putimage(x,y,imagensTorre[posicao],0);
		

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

// Limpa a memória alocada dinamicamente
void Torre::LimpaNo(Torre *torre0){
	Torre *p, *aux;
	p = torre0;
	while(p != NULL){
		aux = p;
		p = p->prox;
		free(aux->mascarasCanhao); 
		free(aux->mascaraGUI);
		free(aux->imagensTorre);
		free(aux->imagensCanhao);
		free(aux);
	}
	torre0 = NULL;	
}


// Comporatamento da Torre quando ela está sem alvo
void Torre::AnimacaoPatrulha(){
	if(tempoTrocaPos.PassouDelay(TEMPO_TROCAPOS) == true){
		tempoTrocaPos.Atualiza();
		
		if(posicao == TORRE_ESQ || posicao == TORRE_DIR)
			posicao = TORRE_MEIO;
			
		else{
			if(seqAnim == DO1ATE3){
				posicao = TORRE_DIR;
				seqAnim = DO3ATE1; 	
			} else{
				posicao = TORRE_ESQ;
				seqAnim = DO1ATE3;
			}
		}	
	}
}


//==================================================
// Verifica se não há torres do jogador nos tiles de cima e de baixo
bool Torre::SemTorrePerto(Torre *torre0, int x,int y){
	
	bool semTorrePerto;
	Torre *pTorre;
	
	semTorrePerto = true;
	
	pTorre = torre0->prox;
	for(; pTorre != NULL && semTorrePerto == true; pTorre = pTorre->prox){
		
		if( (x == pTorre->x && y == pTorre->y) || 
		(x == pTorre->x && y == pTorre->y + TILE_H) )
			 semTorrePerto = false;
	}
	
	return semTorrePerto;
}


//===============================================================
// Procura um alvo para torre atirar
Soldado* Torre::BuscaAlvo(Soldado *inimigo0){
	
	Soldado *pSold, *alvo;
	
	alvo = NULL;	
	pSold = inimigo0->prox;
	
	for(;pSold != NULL && alvo == NULL;pSold = pSold->prox){
		
		if(CampoVisao(*pSold) == true)
			alvo = pSold;
	}
	
	return alvo;
}

// Verifica se o soldado está no campo de visão da torre
bool Torre::CampoVisao(Soldado inimigo){
	
	int torreX, torreY;
	bool campoVisao;
	double tempX, tempY, distRaio;
	
	torreX = x + TORRE_W / 2;
	torreY = y + TORRE_H / 2;
	
	tempX = pow( (inimigo.x - torreX),2.0);
	tempY = pow( (inimigo.y - torreY),2.0);
	distRaio = sqrt( tempX + tempY);
	
	if(distRaio < TORRE_RAIO)
		campoVisao = true;
	else
		campoVisao = false;
	
	return campoVisao;
}

// Atira no alvo
int Torre::Atira(Soldado *alvo){
	int dano;
	dano = 15 + rand() % 30;
	alvo->vida -= dano;
	
	return dano;
}

// Troca de posição conforme a posição do alvo
void Torre::AnimacaoMira(Soldado *alvo){

	if(x >= alvo->x)
		posicao = TORRE_ESQ;
	else
		posicao = TORRE_DIR;
}

