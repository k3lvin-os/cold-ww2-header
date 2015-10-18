
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
	
	
	// Métodos
	void Show();
	void TrocaImg();
	void Carrega(char *rPath);
	void Init();
	void Init(char *nomeLider);
	
	
};
// "Construtor" geral do lider
void Lider::Init(){
	x = 0;
	y = 0;
	nome = "default";
	imgAtual = NORMAL;
	delayImg.Init();
}

// "Construtor" específico do líder
void Lider::Init(char *nomeLider){
	
	nome = nomeLider;
	
		
	if(nomeLider == "Roosevelt"){
		x = 0;
		y = TILE_H * 18;
		Carrega(PATH_ROOSEVELT);	
	}
	
	else if(nomeLider == "Stalin"){
		x = TILE_W * 38;
		y = TILE_H * 18;
		Carrega(PATH_STALLIN);
	}
	
	else{
		x = TELA_W / 2;
		y = 0;
		Carrega(PATH_HITLER);
	}
	

	
}

// Carrega as imagens do líder
void Lider::Carrega(char *rPath){
		
	int i, indiceH;	
	Sprite imgHandl; 
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
		
		GetImage(&imagens[i],pathImg,LIDER_TILEW,LIDER_TILEH);
		
		std::cout << pathImg << std::endl;		
	}
}

// Mostra o lider
void Lider::Show(){
	putimage(x,y,imagens[imgAtual],0);
}
	

