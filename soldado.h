// Relação entre tipo de sprite e valor
enum NomeSprit{ CIMA1 = 0, CIMA2, CIMA3,
	BAIXO1, BAIXO2, BAIXO3,
	ESQRD1,ESQRD2,ESQRD3,
	DIREITA1,DIREITA2,DIREITA3,
	numSprit
};

// Direção do soldado
enum Direcao{
	CIMA, BAIXO, ESQUERDA, DIREITA 
};

// Sequência da animção
enum SeqAnim{
	DO1ATE3, DO3ATE1
};


struct Soldado{
	//==========================================================================
		
	// Constantes do "construtor" geral do soldado
	static const int SPEED = 8;
	static const int IMGATUAL = 4; // corresponde ao "BAIXO2"
	static const NomeSprit QTD_IMG = numSprit;
	static const int UNDEFINE = -1;
	
	// Variáveis	
	int vida;	
	int speed;	
	int imgAtual;
	int x, y;	
	char *tipo;
	Direcao direcao; // Para onde ele estar a se movimentar
	SeqAnim seqAnim; // sequência da animação(1,2 ou 3)
	void *imagens[QTD_IMG];	// Imagens/ Sprites do soldado
	void *mascaras[QTD_IMG];
	bool movNUntil; // Flag para indicar 
					//movimentação baseada na função MovUntil
	int untilPos[2]; // Armazena um destino para o soldado
	bool posCego; // Indica se soldado passou pelo ponto cego
	char *dest;
	bool chegou; // Indica se o soldado chegou ao destino
	bool visivel; // Indica se o soldado chegou ao ponto visivel
	bool liberado; // Indica se o soldado foi liberado da fila de inimigomigos
 	Soldado *prox;	// Próxima célula da lista encadeada

	//=============================================================================
	
	// Funções
	void Carrega(char rPath[]);
	void GoTo(int novoX, int novoY);
	bool Pathfind(CampoJogo meuCampo,int tileXF, int tileYF);
	void Move();
	void Until(int untilX, int untilY);
	bool MovUntil();
	void Show();
	void TrocaImg();
	void TrocaDir(Direcao trocaDir);
	void IA(CampoJogo meuCampo, TDelay *tempoEspera);
	void UltTile(int *ultTile);
	
	/*Funções relativas a lista encadeada empregada no tipo Soldado*/
	Soldado* Insere(Soldado *soldado0, char* tipo);
	Soldado* Insere(Soldado *soldado0, char* tipo, char *dest);
	void Remove(Soldado *anterior);
	void LimpaNo(Soldado *soldado0);
	Soldado* Anterior(Soldado *soldado0);

	// "Construtores"
	void Init(char* tipo);
	void Init();
	void Init(char* tipo, char *meuDest);
};


//==================================================================
// "Construtor" utilizado para soldados do Eixo
void Soldado::Init(char* tipo, char *meuDest){
	Init(tipo);
	dest = meuDest;
}

//=====================================================================
// Calcula o soldado anterior a partir posição atual 
Soldado* Soldado::Anterior(Soldado *soldado0){
	Soldado *p;
	Soldado *atual;
	
	atual = this;
	p = soldado0;
	
	while( p != NULL && p->prox != atual)
		p = p->prox;
		
	return p;
}
//===========================================================================
// Remove o soldado da lista encadeada com base em seu antecessor
void Soldado::Remove(Soldado *anterior){
	Soldado *remove;
	remove = anterior->prox;
	anterior->prox = remove->prox;
	free(remove);
	remove = NULL;
}



//===========================================================================
// Limpa nó da lista encadeada
void Soldado::LimpaNo(Soldado *soldado0){
	Soldado *p, *aux;
	p = soldado0;
	while(p != NULL){
		aux = p;
		p = p->prox;
		free(aux->imagens); 
		free(aux->mascaras);
		free(aux);
	}
	soldado0 = NULL;	
}

// Insere um novo soldado (essa versão utiliza um construtor ESSENCIAL
// na inserção de soldados nazistas)
Soldado* Soldado::Insere(Soldado *soldado0,char *tipo, char *dest){
	Soldado *novo;
	novo = (Soldado *) malloc(sizeof(Soldado));
	novo->Init(tipo,dest); 
	novo->prox = soldado0->prox;
	soldado0->prox = novo;
	
	// Retorna a nova tropa
	return novo;
}


// Insere um novo soldado na lista encadeada
Soldado* Soldado::Insere(Soldado *soldado0, char *tipo){
	Soldado *novo;
	novo = (Soldado *) malloc(sizeof(Soldado));
	novo->Init(tipo); // Inicializa o soldado
	novo->prox = soldado0->prox;
	soldado0->prox = novo;
	
	// Retorna a nova tropa
	return novo;
}


//===========================================================================
// Movimenta o soldado com base na direção dele
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
		
		if( direcao == CIMA){
			y += speed;
		}
		
		if(direcao == BAIXO){
			y -= speed;
		}	
}


//===========================================================================
// "Construtor" sem parâmetros
void Soldado::Init(){
	
	// qtd. de vida inimigocial
	vida = VIDA;
	speed = SPEED;
	x = 0;
	y = 0;
	tipo = "default";
	direcao = BAIXO;
	imgAtual = 4;
	seqAnim = DO1ATE3;
	untilPos[0] = UNDEFINE;
	untilPos[1] = UNDEFINE;
	posCego = false;
	chegou = false;
	liberado = false;
	visivel = false;
	movNUntil = false;
	prox = NULL;
}
//===========================================================================

// "Construtor" que recebe o tipo de soldado 
//e atribui valores baseado nisso
void Soldado::Init(char* tipoSold ){
	

	
	Init();
	tipo = tipoSold;
	if(tipoSold == "Nazi"){
		
		Carrega(NAZI);			
		posCego = true; 		
	}
	
	else if(tipoSold == "Urss"){
		
		x = TILE_W * 2;
		y = TILE_H * 1;
		Carrega(URSS);
		dest = LADO1;
	}
	
	else if(tipoSold == "Eua"){
		x = TILE_W * 37;
		y = TILE_H * 1;
		Carrega(EUA);
		dest = LADO2;
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

	// Mostra a máscara primeiro
	putimage(x,y,mascaras[imgAtual],AND_PUT);
	
	// Mostra a imagem
	putimage(x,y,imagens[imgAtual],OR_PUT);
}

//===========================================================================
// Carrega todas imagens do soldado através do caminho relativo
// a partir da pasta assets
void Soldado::Carrega(char rPath[]){
	
	
	int i, indiceH;	
	Sprite imgHandl; 
	char pathImg[60]; 	
	char pathMask[60];
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){

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
		
		GetImage(&imagens[i],pathImg,TILE_W,TILE_H);
		
		GetImage(&mascaras[i],pathMask,TILE_W,TILE_H);
		
	}
}  

//========================================================================
// Troca o indice da animação do soldado na direção atual
void Soldado::TrocaImg(){
	
	bool trocaImg;
	int iAnim;
	
	/*===========================================*/
	// Deixa a animação mais lenta
	if(direcao == DIREITA || direcao == ESQUERDA){
		
		if(x % 16 == 0)
			trocaImg = true;
		else
			trocaImg = false;
	}
	else 
		trocaImg = true;
	/*=================================*/
		

	if(trocaImg == true){
		
		iAnim = (imgAtual % 3) + 1;
		switch(iAnim){
			case 1:
				imgAtual +=  1;
				break;
			case 2:
				
				// Verifica o tipo de sequencia e altera com base nisso
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

}
//===========================================================================
// Troca a direção do soldado
void Soldado::TrocaDir(Direcao trocaDir){
		
		// Recebe o valor da direção
		direcao = trocaDir;
	
		// Verifica a direção 
		switch(direcao){	
			
			// A imagem atual é igual a direção no movimento 2
			case CIMA:
				imgAtual = CIMA2;
				break;
			case BAIXO:
				imgAtual = BAIXO2;
				break;
			case ESQUERDA:
				imgAtual = ESQRD2;
				break;
			case DIREITA:
				imgAtual = DIREITA2;
				break;
	}	
}

//=====================================================
// Calcula o último tile que o soldado esteve
void Soldado::UltTile(int *ultTile){
	
	// Assume, incialmente o valor das coordenadas atuais
	ultTile[0] = x / TILE_W;
	ultTile[1] = y / TILE_H;
	
	// Verifica o último movimento feito 
	switch(direcao){
		
		//Calcula último movimento feito 
		case ESQUERDA:
			ultTile[0] += 1; // Inverso da esquerda (direita)
			break;
		case DIREITA:
			ultTile[0] -= 1; // Inverso da direita (esquerda)
			break;
		case BAIXO:
			ultTile[1] += 1; // Inverso de para baixo (cima)
			break;
		case CIMA:
			ultTile[1] -= 1; // Inverso de para cima (baixo)
			break;
	}
	
	
}

//===========================================================================

// Vai até o tile de destino com a pathfind
bool Soldado::Pathfind(CampoJogo meuCampo,int tileXF, int tileYF){
	
	// Calcula o tile do soldado
	int tileX,  tileY;
	
	// Flag que indica que o soldado encontrou uma posição 
	// para onde ir
	bool myPath = false;
		
	// Inicialmente, supõe-se que o soldado não chegou ao destino
	bool moveDest = false;
	
	// Recebe as coordendas do ultimo tile do soldado
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
			Após verificar o tile de destino...
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
							
							// Registra uma coordenada de movimentação
							Until(x - TILE_W,y);
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
							
							// Registra uma coordenada de movimentação
							Until(x + TILE_W,y);
						}
					}
				}
				
				// Cima
				if(myPath == false && meuCampo.PosExist(tileX,tileY + 1) ){
					if(meuCampo.Caminho(tileX, tileY + 1)){
						if(ultTile[0] != tileX  || ultTile[1] != tileY + 1 ){
							
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							// Registra uma coordenada de movimentação
							Until(x ,y + TILE_H);
						}
					}
				}
				
				// Baixo			
				if(myPath == false && meuCampo.PosExist(tileX,tileY - 1)){
					if(meuCampo.Caminho(tileX , tileY - 1)){
						if(ultTile[0] != tileX  || ultTile[1] != tileY - 1 ){
							
							// Indica que o soldado encontrou 
							// um caminho válido
							myPath = true;
							
							// Registra uma coordenada de movimentação
							Until(x,y - TILE_H);
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

/*Registra uma coordenada de movimentação*/
void Soldado::Until(int untilX, int untilY){
	
	//=======================================================
	/*ATENÇÃO: é necessário que a coordenada seja múltiplo da velocidade*/	
	//=======================================================
	
	// Recebe as coordenadas de destino
	untilPos[0] = untilX;
	untilPos[1] = untilY;
	
	// Altera o estilo de movimentação
	movNUntil = true;
}

//========================================================

/*Movimenta-se até a coordenada registrada no soldado*/
bool Soldado::MovUntil(){
	
	// Indica que se o soldado chegou ou não no destino
	bool reach;
	
	// Se o estilo de movimento foi ativado
	if(movNUntil == true){
		
		// Verifica o tipo de diferença no eixo y 
		//e troca direção com base nisso
		if(y < untilPos[1] && direcao != CIMA)
			TrocaDir(CIMA);	
		else if(y > untilPos[1] && direcao != BAIXO)
			TrocaDir(BAIXO);
		
		// Se a coordenada do soldado não for igual a coord. de
		// destino
		if( y != untilPos[1])
			Move();	// O soldado move-se um pouco

		// Caso o soldado esteja na posiçao Y do destino
		else{
			
			// Verifica o tipo de diferença no eixo x e troca direção com base nisso
			if(x < untilPos[0] && direcao != DIREITA){
				TrocaDir(DIREITA);
			} else if(x > untilPos[0] && direcao != ESQUERDA ){
				TrocaDir(ESQUERDA);
			}
			
			// Se a coordenada do soldado não for igual  a coordenada de
			// destino
			if(x != untilPos[0]){
				
				// O soldado se move um pouco
				Move();
			}
		
		}	
	}
	
	// Se o soldado estiver na posição de destino
	if(x == untilPos[0] && y == untilPos[1]){
		
		// Confirma isso através da variável de retorno
		reach = true;
		
		// Altera o estilo de movimentação
		movNUntil = false;
		
		// Reseta os valores de movimentação
		untilPos[0] = UNDEFINE;
		untilPos[1] = UNDEFINE;
	} else{
		
		// Nega a chegada através desta variável
		reach = false;
	}
	
	// Retorna se o soldado chegou no destino ou não
	return reach;
}


//===========================================================
// Comportamento geral do soldado
void Soldado::IA(CampoJogo meuCampo, TDelay *tempoEspera){
	
	Soldado *anterior;
	
	int pCegoX, pCegoY, destTX, destTY;
	
	if(dest == LADO2){
		pCegoX = ENTRADAURSSX;
		pCegoY = ENTRADAURSSY;
		destTX = DEST_EUA_TX;
		destTY = DEST_EUA_TY;
	} 
	else if (dest == LADO1){
		pCegoX = ENTRADAEUAX;
		pCegoY = ENTRADAEUAY;
		destTX = DEST_URSS_TX;
		destTY = DEST_URSS_TY;
	}
	

	
	
	// Ponto cego da tela
	if(posCego == false){
		
		if(movNUntil == false){		 // destino foi definimigodo?
		
			Until(pCegoX,pCegoY);  // define destino
		}
	
		posCego = MovUntil(); // move-se até destino
		
	}
	
	// Tempo de espera
	if(posCego == true && liberado == false){
		
		liberado = tempoEspera->PassouDelay(ESPERA_DELAY);
		
		if(liberado == true)
			tempoEspera->Atualiza();
		
	}
	
	// Região visivel
	if(liberado == true && visivel == false){
		
		if(movNUntil == false){				
			Until(x, 64);
		} 	
				
		visivel = MovUntil();
	} 
		
	// Uso da pathfind	
	if(visivel == true && chegou == false){
			
				
		if(movNUntil == false){	
			chegou = Pathfind(meuCampo,destTX,destTY);
		} 		
		MovUntil();
	}
	

			
		
}

//=====================================================================

