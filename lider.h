
enum ImgLider{
	NORMAL = 0, BRAVO, MORTO, QTD_IMG
};


// Avatares/ Líderes do Jogo (Stallin, Roosevalt e Hitler )
struct Lider{
	
	// Propriedades
	int x, y;				// Coordenadas da imagem
	char *nome;				// Nome do lider
	int imgAtual;			// Imagem atual do lider
	TDelay delayImg;		// Delay do lider ao tomar dano
	void *imagens[QTD_IMG];	// Imagens/ Sprites do soldado
	bool furia;				// Indica se está com sprite de fúria
	int *vida;				// Vida do jogador que controla o lider
	TDelay tempoFuria;      // Tempo que o líder fica em estado de fúria
	
	
	// Métodos
	void Show();
	void TrocaImg(ImgLider minhaImg);
	void Carrega(char *rPath);
	void Init();
	void Init(char *nomeLider, int *vidaJogador);
	void Furia();
	void VerificaImg();
	void VerificaFuria();

	
	
};
// "Construtor" geral do lider
void Lider::Init(){
	x = 0;
	y = 0;
	nome = "default";
	imgAtual = 0;
	delayImg.Atualiza();
	furia = false;
	tempoFuria.marcador = NULL;
}

// Verifica qual imagem do lider deve ser mostrada
void Lider::VerificaImg(){
	if(*vida <= 0)
		imgAtual = MORTO; 	
	else if(furia == true)
		imgAtual = BRAVO;
	else
		imgAtual =  NORMAL;
	
}


//==========================================================================


//==========================================================================
// "Construtor" específico do líder
void Lider::Init(char *nomeLider, int *vidaJogador){
	
	Init();
	nome = nomeLider;
	vida = vidaJogador;
		
	if(nome == "Roosevelt"){
		x = ROOSEVELT_X;
		y = ROOSEVELT_Y;
		Carrega(PATH_ROOSEVELT);	
	}
	
	else if(nome == "Stalin"){
		x = STALIN_X;
		y = STALIN_Y;
		Carrega(PATH_STALIN);
	}
	
	else{
		x = 608;
		y = 64;
		Carrega(PATH_HITLER);
		imgAtual = BRAVO;
	}
	

	
}

//==========================================================================
// Carrega as imagens do líder
void Lider::Carrega(char *rPath){
	
	int size;	
	int i, indiceH;	
	char pathImg[60]; 	
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){
		
		strcpy(pathImg,ASSETS);
		strcat(pathImg,rPath);
		
		indiceH = i + 1;
		if(indiceH < 10)
			strcat(pathImg,"0");
		
		itoa(indiceH,temp,DECIMAL);
		strcat(pathImg,temp);

		strcat(pathImg,BITMAP);
		strcat(pathImg,"\0");
		
		imagens[i] = GetImage(pathImg,LIDER_TILEW,LIDER_TILEH);
	}
}

//==========================================================================
// Mostra o lider
void Lider::Show(){
	putimage(x,y,imagens[imgAtual],0);
}

//==========================================================================
// Afirma que o lider está em furioso - o que leva a troca de imagem por um
// período
void Lider::Furia(){
	furia = true;
	tempoFuria.Atualiza();
}


void Lider::VerificaFuria(){
	
	bool passou;
	if(furia == true){
		passou = tempoFuria.PassouDelay(TEMPOFURIA);
		if(passou == true)
			furia = false;
	}
}

