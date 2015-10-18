
enum ImgLider{
	NORMAL = 0, BRAVO, MORTO, qtdImg
};


// Avatares/ Líderes do Jogo (Stallin, Roosevalt e Hitler )
struct Lider{
	
	int x, y;
	char *nome;
	int imgAtual;
	TDelay delayImg;
	
	// Propriedades
	void *image;
	
	
	// Métodos
	void Show();
	void TrocaImg();
	void Carrega();
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
	
	if(nomeLider == "Hitler"){
		x = TELA_W / 2;
		y = 0;
	}	
	
	else if(nomeLider == "Stallin"){
		x = TILE_W * 38;
		y = TILE_H * 18;
	}
	
	else if(nomeLider == "Roosevelt"){
		x = 0;
		y = TILE_H * 18;	
	}
	
}
