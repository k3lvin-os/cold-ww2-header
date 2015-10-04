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

// Sequência da animção
enum SeqAnim{
	DO1ATE3, DO3ATE1
};


struct Soldado{
	//==========================================================================
	// Propriedades
		

	// Quantidades padrões dos soldados
	static const int VIDA = 100;
	static const int SPEED = 8;
	static const int X = 64;
	static const int Y = 32;
	static const SeqAnim SEQANIM = DO1ATE3;
	static const Direcao DIRECAO = COSTA;
	static const int IMGATUAL = 4; // corresponde ao "COSTA2"
	static const NomeSprit QTD_IMG = numSprit;
	static const bool IDLE = false;
		
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
	
	// Direção do soldado
	Direcao direcao;
	
	// Indica a sequência da animação
	SeqAnim seqAnim;
	
	// Imagens (ou sprites) do soldado
	void *imagens[QTD_IMG];
	
	// Indica se o soldado está parado ou não 
	bool idle;
	
	//=============================================================================
	
	// Funções
	void Carrega(char rPath[]);
	void GoTo(int novoX, int novoY);
	bool MoveDest(CampoJogo meuCampo,int tileXF, int tileYF);
	void Move();
	bool MovUntil(int untilX, int untilY);
	void Show();
	void TrocaImg();
	void TrocaDir(Direcao trocaDir);
	void UltTile(int *ultTile);
	
	// "Construtores"
	void Init();
	void Init(char* tipo);
};

//===========================================================================
void Soldado::Move(){
		
		// Troca a imagem de movimento do personagem
		TrocaImg();
		
		// Verifica a direção e movimenta-se com base nisso
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


//===========================================================================
// "Construtor sem parâmetros"
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
	seqAnim = SEQANIM;
}
//===========================================================================

// "Construtor" que recebe o tipo de soldado e atribui valores baseado nisso
void Soldado::Init(char* tipoSold ){
	
	// Caminho para encontrar os sprites dos soldados
	char *CHARA = "/Soldado/Chara/Chara";
	
	// Faz alterações gerais
	Init();
	
	// Faz alterações específicas
	if(tipoSold == "Chara"){
		
		// Carrega as imagens do soldado
		Carrega(CHARA);
	}
	
	
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
	
	// Contador do laço
	int i;
	
	// Indice mais humano (indice array + 1)
	int indiceH;
	
	// Cria uma variável do tipo Sprite, a fim de usar uma função dela
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
		
		// Converte o indice do contador para o formato "humano"
		// que é o número do sprite
		indiceH = i + 1;
		
		// Verifica se o número do sprite é menor que 10 (dois algarismos)
		if(indiceH < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(caminho,"0");
		}
		
		// Recebe a conversão do número do sprite para o tipo string
		itoa(indiceH,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(caminho,temp);
		
		// Adicione a especificação de arquivo bitmap
		strcat(caminho,BITMAP);
		
		// Recebe a imagem especificada pelo caminho
		imgHandl.GetImage(&imagens[i],caminho,TILE_W,TILE_H);
		
	}
}  



//========================================================================
// Troca o indice da animação do soldado na direção atual
void Soldado::TrocaImg(){
	
	// Indice da animação
	int iAnim;
			
	// Função para achar o indice da animação
	iAnim = (imgAtual % 3) + 1;
	
	// Verifica o indice de imagem e atribui o valor conforme ele
	switch(iAnim){
		case 1:
			imgAtual +=  1;
			break;
		case 2:
			
			// Verifica o pé que o soldado utilizou por último
			if(seqAnim == DO1ATE3){
				imgAtual += 1;
				seqAnim = DO3ATE1;
			} else{
				imgAtual -= 1;
				seqAnim = DO1ATE3;
			}
			
			break;
		case 3:
			imgAtual -= 1;
			break;		
	}

}
//===========================================================================
// Troca a direção do soldado
void Soldado::TrocaDir(Direcao trocaDir){
		
		// Recebe o valor da direção
		direcao = trocaDir;
	
		// Verifica a direção 
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

// Calcula o último tile que o soldado esteve
void Soldado::UltTile(int *ultTile){
	

	// Assume, incialmente o valor das coordenadas atuais
	ultTile[0] = x / TILE_W;
	ultTile[1] = y / TILE_H;
	
	// Verifica o último movimento feito 
	switch(direcao){
		
		//Calcula a última coordenada com base nisso
		case ESQUERDA:
			ultTile[0] += 1; // Inverso da esquerda (direita)
			break;
		case DIREITA:
			ultTile[0] -= 1; // Inverso da direita (esquerda)
			break;
		case COSTA:
			ultTile[1] += 1; // Inverso da costa (frente)
			break;
		case FRENTE:
			ultTile[1] -= 1; // Inverso da frente (costa)
			break;
	}
	
	
}

//===========================================================================
bool Soldado::MoveDest(CampoJogo meuCampo,int tileXF, int tileYF){
	
	
	// Calcula o tile do soldado
	int tileX,  tileY;
	
	// Flag que indica que o soldado encontrou uma posição 
	// para onde ir
	bool myPath = false;
		
	// Inicialmente, supõe-se que o soldado não chegou ao destino
	bool moveDest = false;
	
	// Recebe as coordendas do ultimo tile do soldado
	//int *ultTile = (int *) malloc(sizeof(int) * 2);
	int ultTile[2];
	
	UltTile(ultTile);
	
	// Calcula o tile atual com base na posição x e y do soldado
	tileX = x / TILE_W;
	tileY = y / TILE_H;	
	

		
	// Se o tile existir
	if(meuCampo.PosExist(tileXF, tileYF)){
	
		// Se o tile de destino for um tile de caminho
		if(meuCampo.Caminho(tileXF, tileYF)){
			

			
			/* ========================
			1 - Verifique se o tile existe no campo de jogo;
			2 - Verifique se o tile é um tile de caminho;
			3 - Verfique se o tile não é o último tile percorrido
			4 - Vá até a nova posição se tudo estiver certo
			============================*/
			
			// Se o soldado não estiver no destino
			if(tileX != tileXF || tileY != tileYF){
				
				// Verifica se o tile da esquerda é válido
				if(meuCampo.PosExist(tileX - 1,tileY)){
					
					// Verifica se é um tile de caminho
					if(meuCampo.Caminho(tileX - 1, tileY)){
						
						// Verifica se ele não é igual ao ultimo tile
						if(ultTile[0] != tileX - 1  || ultTile[1] != tileY ){
							
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							// Move o soldado
							MovUntil(x - TILE_W,y);
						}
					}
				}
				
				// Direita
				if(myPath == false && meuCampo.PosExist(tileX + 1,tileY)){ 
					if(meuCampo.Caminho(tileX + 1, tileY)){
						if(ultTile[0] != tileX + 1  || ultTile[1] != tileY ){
							
														
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							// Move o soldado
							MovUntil(x + TILE_W,y);
						}
					}
				}
				
				// Frente
				if(myPath == false && meuCampo.PosExist(tileX,tileY + 1) ){
					if(meuCampo.Caminho(tileX, tileY + 1)){
						if(ultTile[0] != tileX  || ultTile[1] != tileY + 1 ){
							
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							MovUntil(x ,y + TILE_H);
						}
					}
				}
				
				// Costa			
				if(myPath == false && meuCampo.PosExist(tileX,tileY - 1)){
					if(meuCampo.Caminho(tileX , tileY - 1)){
						if(ultTile[0] != tileX  || ultTile[1] != tileY - 1 ){
							
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							MovUntil(x,y - TILE_H);
						}
					}
				}
				
		}
			// Se o soldado estiver no destino
			else{
				moveDest = true; // Confirma a chegada ao destino
			}							
		}
	}

	
	// Retorna se o soldado chegou ao destino ou não
	return moveDest;

}


//===========================================================================

// Movimenta-se até chegar em uma coordenada X e Y 
// e retorna se o soldado chegou ou não
bool Soldado::MovUntil(int untilX, int untilY){
	
	/*ATENÇÃO: é necessário que a coordenada seja múltiplo da velocidade*/
	
	// Inicialmente, o soldado não chegou ao destino
	bool movUntil = false;
	
	// Verifica o tipo de diferença no eixo y e troca direção com base nisso
	if(y < untilY && direcao != FRENTE){
		TrocaDir(FRENTE);
	} 
	
	else if(y > untilY && direcao != COSTA){
		TrocaDir(COSTA);
	}
	
	// Se a coordenada do soldado não for igual  a coordenada de
	// destino
	if( y != untilY){
		
		// O soldado se move um pouco
		Move();
	} 
	
	// Caso o soldado esteja na posiçao Y desejada
	else{
		// Verifica o tipo de diferença no eixo x e troca direção com base nisso
		if(x < untilX && direcao != DIREITA){
			TrocaDir(DIREITA);
		} else if(x > untilX && direcao != ESQUERDA ){
			TrocaDir(ESQUERDA);
		}
		
		// Se a coordenada do soldado não for igual  a coordenada de
		// destino
		if(x != untilX){
			
			// O soldado se move um pouco
			Move();
		}
		// Caso o soldado também esteja na posição x desejada
		else{
			
			// O soldado chegou ao destino
			movUntil = true;
		}
	}
	
	// Retorna se o soldado chegou ou não ao destino
	return movUntil;
}
