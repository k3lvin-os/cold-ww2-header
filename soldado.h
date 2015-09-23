// Rela��o entre tipo de sprite e valor
enum NomeSprit{ FRENTE1 = 0, FRENTE2, FRENTE3,
	COSTA1, COSTA2, COSTA3,
	ESQRD1,ESQRD2,ESQRD3,
	DIREITA1,DIREITA2,DIREITA3,
	numSprit
};

// Dire��o do soldado
enum Direcao{
	FRENTE, COSTA, ESQUERDA, DIREITA 
};


struct Soldado{
	//==========================================================================
	// Propriedades
		

	// Quantidades padr�es dos soldados
	static const int VIDA = 100;
	static const int SPEED = 8;
	static const int X = 0;
	static const int Y = 32;
	const char PEH = 'd';
	static const Direcao DIRECAO = COSTA;
	static const int IMGATUAL = 4; // corresponde ao "COSTA2"
	static const NomeSprit QTD_IMG = numSprit;
	static const bool IDLE = false;
		
	// Vida do soldado ('0' � igual a morte)
	int vida;
	
	// Velocidade do soldado
	int speed;
	
	// Sprite ou imagem atual do soldado  
	int imgAtual;
	
	// Coordenadas
	int x, y;
	
	// Tipo do soldado
	char *tipo;
	
	// Dire��o do soldado
	Direcao direcao;
	
	// Indica se o p� que o personagem utiizou por ultimo para se movimentar
	//(isso � usado para saber o pr�ximo sprite de movimenta��o)
	char peh;
	
	// Imagens (ou sprites) do soldado
	void *imagens[QTD_IMG];
	
	// Indica se o soldado est� parado ou n�o 
	bool idle;
	
	//=============================================================================
	
	// Fun��es
	void Carrega(char rPath[]);
	void GoTo(int novoX, int novoY);
	void MoveTo(int destX, int destY);
	void Move();
	void Show();
	void TrocaImg();
	void TrocaDir(Direcao trocaDir);
	
	// "Construtores"
	void Init();
	void Init(char* tipo);
};

//===========================================================================
void Soldado::Move(){
	
	// Se o personagem n�o estiver parado
	if (idle == false){
		
		// Verifica a dire��o e movimenta-se com base nisso
		
		
		if(direcao == ESQUERDA){
			x -= speed;
		} 
		
		if (direcao == DIREITA){
			x += speed; 
		}
		
		if( direcao == FRENTE){
			y += speed;
		}
		
		if(direcao == COSTA){
			y -= speed;
		}
	}
	
	
}


//===========================================================================
// "Construtor sem par�metros"
void Soldado::Init(){
	
	// qtd. de vida inicial
	vida = VIDA;
	speed = SPEED;
	x = X;
	y = Y;
	tipo = "default";
	direcao = COSTA;
	imgAtual = IMGATUAL;
	idle = IDLE;
}
//===========================================================================

// "Construtor" que recebe o tipo de soldado e atribui valores baseado nisso
void Soldado::Init(char* tipoSold ){
	
	// Caminho para encontrar os sprites dos soldados
	char *CHARA = "/Soldado/Chara/Chara";
	
	// Faz altera��es gerais
	Init();
	
	// Faz altera��es espec�ficas
	if(tipoSold == "Chara"){
		
		// Carrega as imagens do soldado
		Carrega(CHARA);
	}
	
	
}
 

//===========================================================================
// Muda a posi��o do soldado
void Soldado::GoTo(int novoX, int novoY){
	x = novoX;
	y = novoY;
}
//===========================================================================
// Mostra o soldado
	void Soldado::Show(){
		
		// Cria uma vari�vel para utilizar o gerenciador do sprite
		Sprite spritHnd;
		
		// Mostra o sprite atual
		spritHnd.Show(imagens[imgAtual],x,y);
	}

//===========================================================================
// Carrega todas imagens do soldado atrav�s do caminho relativo
// a partir da pasta assets
void Soldado::Carrega(char rPath[]){
	
	int i;
	
	// Cria uma vari�vel do tipo Sprite, a fim de usar uma fun��o
	Sprite imgHandl;

	// Caminho para acessar a pasta com os sprites
	char caminho[70]; 
	
	// Vari�vel tempor�ria que recebe o o indice do loop em char array
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){

		
		// O caminho exato - com o numero do sprite - ainda n�o foi calculado
		// Ent�o copie o caminho para a pasta assets
		strcpy(caminho,ASSETS);
		
		// Agora, adicione o caminho relativo (argumento que foi passado)
		strcat(caminho,rPath);
		
		// Verifica se o n�mero do sprite � menor que 10 (dois algarismos)
		if(i < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(caminho,"0");
		}
		
		// Converte o indice do contador para o formato "humano" (+ 1) - a partir do '0') 
		//para char array
		itoa(i + 1,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(caminho,temp);
		
		// Adicione a especifica��o de arquivo bitmap
		strcat(caminho,BITMAP);
		
		// Teste
		std::cout << caminho << "\n"; 
		
		// Recebe a imagem especificada pelo caminho
		imgHandl.GetImage(&imagens[i],caminho,TILE_W,TILE_H);
		
	}
}  



//========================================================================
// Troca o indice da anima��o do soldado na dire��o atual
void Soldado::TrocaImg(){
	
	int indiceH, iImg;
	
	// Faz a troca do indice da imagem atual para o indice humano
	indiceH = imgAtual + 1;
	
	// Calcula o indice de imagem
	iImg = indiceH % 3; 
	
	// Verifica o indice de imagem e atribui o valor conforme ele
	switch(iImg){
		case 1:
			imgAtual +=  1;
			break;
		case 2:
			
			// Verifica o p� que o soldado utilizou por �ltimo
			if(peh == 'd'){
				imgAtual -= 1;
				peh = 'e';
			} else{
				imgAtual += 1;
				peh = 'd';
			}
			break;
		case 3:
		imgAtual -= 1;
		break;		
	}
}
//===========================================================================
// Troca a dire��o do soldado
void Soldado::TrocaDir(Direcao trocaDir){
	
	// Verifica a dire��o passada
	switch(trocaDir){	
		
		// A imagem atual � igual a dire��o no movimento 2
		case FRENTE:
			imgAtual = FRENTE2;
			break;
		case COSTA:
			imgAtual = COSTA2;
			break;
		case ESQUERDA:
			imgAtual = ESQRD2;
			break;
		case DIREITA:
			imgAtual = DIREITA2;
			break;
	}
	
	// Por fim, recebe o valor da dire��o
	direcao = trocaDir;
	
}
