
struct Soldado{
	//==========================================================================
	// Propriedades
	
	// Quantidades padrões dos soldados
	static const int VIDA = 100;
	static const int SPEED = 8;
	static const int X = 0;
	static const int Y = 32;
	const char PEH = 'd';
		
	// Vida do soldado ('0' é igual a morte)
	int vida;
	
	// Velocidade do soldado
	int speed;
	
	// Sprite ou imagem atual do soldado  
	int imgAtual;
	
	// Coordenadas
	int x, y;
	
	// Tipo do soldado
	char *tipo;
	
	// Indica se o pé que o personagem utiizou por ultimo para se movimentar
	char peh;
	
	// Relação entre tipo de sprite e valor
	enum NomeSprit{ FRENTE1 = 0, FRENTE2, FRENTE3,
 	COSTA1, COSTA2, COSTA3,
	  ESQRD1,ESQRD2,ESQRD3,
	   DIREITA1,DIREITA2,DIREITA3,
	    numSprit
	};
	
	// Direção do soldado
	enum Direcao{
		FRENTE, COSTA, ESQUERDA, DIREITA 
	};
	
	// Indices necessários para armazenar as imagens dos solados
	static const int QTD_IMG = numSprit;
	
	// Imagens (ou sprites) do soldado
	void *imagens[QTD_IMG];
	
	//=============================================================================
	
	// Funções
	void Carrega(char rPath[]);
	void GoTo(int novoX, int novoY);
	void MoveTo(int destX, int destY);
	void Show();
	void TrocaImg();
	void TrocaDir(int direcao);
	
	// "Construtores"
	void Init();
	void Init(char* tipo);
};


//===========================================================================
// "Construtor sem parâmetros"
void Soldado::Init(){
	
	// qtd. de vida inicial
	vida = VIDA;
	speed = SPEED;
	x = X;
	y = Y;
	tipo = "default";
}
//===========================================================================

// "Construtor" que recebe o tipo de soldado e atribui valores baseado nisso
void Soldado::Init(char* tipoSold ){
	
	// Caminho para encontrar os sprites dos soldados
	char *CHARA = "/Soldado/Chara/Chara";
	
	if(tipoSold == "Chara"){
		
		// Carrega as imagens do soldado
		Carrega(CHARA);
	}
	
	// Outros ifs de outros soldados
	
	// Alterações gerais
	x = X;
	y = Y;
	tipo = tipoSold;
	vida = VIDA;
	speed = SPEED;
	peh = PEH;
}
 

//===========================================================================
// Muda a posição do soldado
void Soldado::GoTo(int novoX, int novoY){
	x = novoX;
	y = novoY;
}
//===========================================================================
// Mostra o soldado
	void Soldado::Show(){
		
		// Cria uma variável para utilizar o gerenciador do sprite
		Sprite spritHnd;
		
		// Mostra o sprite atual
		spritHnd.Show(imagens[imgAtual],x,y);
	}

//===========================================================================
// Carrega todas imagens do soldado através do caminho relativo
// a partir da pasta assets
void Soldado::Carrega(char rPath[]){
	
	int i;
	
	// Cria uma variável do tipo Sprite, a fim de usar uma função
	Sprite imgHandl;

	// Caminho para acessar a pasta com os sprites
	char caminho[70]; 
	
	// Variável temporária que recebe o o indice do loop em char array
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){

		
		// O caminho exato - com o numero do sprite - ainda não foi calculado
		// Então copie o caminho para a pasta assets
		strcpy(caminho,ASSETS);
		
		// Agora, adicione o caminho relativo (argumento que foi passado)
		strcat(caminho,rPath);
		
		// Verifica se o número do sprite é menor que 10 (dois algarismos)
		if(i < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(caminho,"0");
		}
		
		// Converte o indice do contador para o formato "humano" (+ 1) - a partir do '0') 
		//para char array
		itoa(i + 1,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(caminho,temp);
		
		// Adicione a especificação de arquivo bitmap
		strcat(caminho,BITMAP);
		
		// Teste
		std::cout << caminho << "\n"; 
		
		// Recebe a imagem especificada pelo caminho
		imgHandl.GetImage(&imagens[i],caminho,TILE_W,TILE_H);
		
	}
}  



//========================================================================
// Troca o indice da animação do soldado na direção atual
void Soldado::TrocaImg(){
	
	int indiceH, iImg;
	
	// Faz a troca do indice da imagem atual para o indice humano
	indiceH = imgAtual + 1;
	
	// Calcula o indice de imagem
	iImg = indiceH % 3; 
	
	// Verifica o indice de imagem e atribui o valor conforme ele
	switch(iImg){
		case 1:
			imgAtual += + 1;
			break;
		case 2:
			
			// Verifica o pé que o soldado utilizou por último
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
// Troca a direção do soldado
void Soldado::TrocaDir(int direcao){
	
	// Verifica a direção passada
	switch(direcao){	
		
		// A imagem atual é igual a direção no movimento 2
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
}
