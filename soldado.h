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
	static const int VIDA = 100;
	static const int SPEED = 4;
	static const int IMGATUAL = 4; // corresponde ao "BAIXO2"
	static const NomeSprit QTD_IMG = numSprit;
	static const int UNDEFINE = -1;
	static const int PRECO = 10;
	
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
	bool dest; // Indica se o soldado chegou ao destino
	bool visivel; // Indica se o soldado chegou ao ponto visivel
	bool liberado; // Indica se o soldado foi liberado da fila de inimigos
 	Soldado *prox;	// Próxima célula da lista encadeada
	int preco;

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
	void IA(CampoJogo meuCampo);
	void UltTile(int *ultTile);
	void Morre(Soldado *anterior);
	Soldado* Insere(Soldado *soldado0, char* tipo);
	Soldado* Aloca(Soldado *soldado0);
	void Remove(Soldado *anterior);
	void Enviar(Soldado *soldado0 ,CampoJogo meuCampo);
	void LimpaNo(Soldado *soldado0);
	void Chegou(Soldado *anterior);
	Soldado* Anterior(Soldado *soldado0);
	bool Compra(int *dinheiro);


	// "Construtores"
	void Init(char* tipo);
	void Init();
};

//==================================================================

// Valida a compra de um soldado
bool Soldado::Compra(int *dinheiro){
	
	/*Se o dinheiro for suficiente*/
	if(*dinheiro >= PRECO){
		
		// Paga o soldado e valida a compra
		*dinheiro -= PRECO;
		return true;
	}else{
		
		// Não compra nada u.u
		return false;
	}	
	
}

//====================================================================

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
// Comportamento encadeada pela morte do soldado
void Soldado::Morre(Soldado *anterior){
	// Insira o comportamento de morte aqui (algum som, troca de sprite,...)
	//[...]
	
	// Reomove o soldado da lista encadeada
	Remove(anterior);
}

//===========================================================================

// Comportamento do soldado ao chegar na base inimiga
void Soldado::Chegou(Soldado *anterior){
	
	// Insira o comportamento de infrigir dano aqui
	//[...]
	
	// Remove o soldado da lista encadeada
	Remove(anterior);
}


//===========================================================================
// Remove o soldado da lista encadeada com base em seu antecessor
void Soldado::Remove(Soldado *anterior){
	Soldado *remove;
	remove = anterior->prox;
	anterior->prox = remove->prox;
	free(remove);
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


//===========================================================================

// Envia todos soldados ativos
void Soldado::Enviar(Soldado *soldado0 , CampoJogo meuCampo){

	Soldado *novoIni;
	Soldado *pSold, *anterior;
	
	// Percorre a lista encadeada de soldados
	for(pSold = soldado0->prox; pSold != NULL; pSold = pSold->prox){
		
		// Se a vida do soldado é maior que 0 e o soldado não chegou ao destino
		if(pSold->vida > 0 && pSold->dest != true){
			
			// Mostra soldado
			pSold->Show();
			
			// Usa IA 
			pSold->IA(meuCampo);
			
		} 
		
		// Caso contrário
		else{
			
			// Calcula o soldado anterior na lista encadeada
			anterior = Anterior(soldado0);
			
			// Se o soldado chegou ao destino
			if(pSold->dest == true){
			
				// Soldado infrige dano e morre
				pSold->Chegou(anterior);	
			}
			
			// Caso o soldado tenha o hp menor ou igual a 0
			else{
			
				// Soldado morre 
				pSold->Morre(anterior);	
			}
			
		}
	}

}



//===========================================================================
// Apenas aloca uma posição na lista encadeada
Soldado* Soldado::Aloca(Soldado *soldado0){
	Soldado *novo;
	novo = (Soldado *) malloc(sizeof(Soldado));
	
	return novo;
}
//===============================================================


// Insere um novo soldado na lista encadeada
Soldado* Soldado::Insere(Soldado *soldado0, char * tipo){
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
	
	// qtd. de vida inicial
	vida = VIDA;
	preco = PRECO;
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
	dest = false;
	liberado = false;
	visivel = false;
	movNUntil = false;
	prox = NULL;
}
//===========================================================================

// "Construtor" que recebe o tipo de soldado 
//e atribui valores baseado nisso
void Soldado::Init(char* tipoSold ){
	
	// Caminhos para encontrar os sprites dos soldados
	char *CHARA = "/Soldado/Chara/Chara";
	char *EUA = "/Soldado/Eua/Eua";
	char *URSS = "/Soldado/Urss/Urss";
	
	// Faz alterações gerais
	Init();
	
	// Faz alterações específicas
	if(tipoSold == "Chara"){
		
		// Carrega as imagens do soldado
		Carrega(CHARA);
	}
	else if(tipoSold == "Urss"){
		
		x = 64;
		y = 64;
		Carrega(URSS);
	}
	
	else if(tipoSold == "Eua"){
		Carrega(EUA);
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
	
	
	int i; // contador
	int indiceH;	// Indice mais humano (indice array + 1)
	Sprite imgHandl; // Para manipular imagens
	char pathImg[60]; 	// Caminho para acessar a imagem
	char pathMask[60]; // Caminho para acessar a mascara da imagem
	char temp[3]; // indice do loop em char array
	

				
	for(i = 0; i < QTD_IMG; i++){
		
		// O caminho exato - com o numero do sprite - ainda não foi calculado
		// Então copie o caminho para a pasta assets
		strcpy(pathImg,ASSETS);
		
		// Agora, adicione o caminho relativo (argumento que foi passado)
		strcat(pathImg,rPath);
		
		// Converte o indice do contador para o formato "humano"
		// que é o número do sprite
		indiceH = i + 1;
		
		// Verifica se o número do sprite é menor que 10 (dois algarismos)
		if(indiceH < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(pathImg,"0");
		}
		
		// Recebe a conversão do número do sprite para o tipo string
		itoa(indiceH,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(pathImg,temp);
		
		// Recebe o caminho da imagem até agora na máscara
		strcpy(pathMask,pathImg);
		
		//Acresenta o 'M' que representa uma máscara
		strcat(pathMask,"M");
		
		// Adicione a especificação de arquivo bitmap
		strcat(pathImg,BITMAP);
		strcat(pathMask,BITMAP);
		
		// Recebe a imagem especificada pelo caminho da imagem
		imgHandl.GetImage(&imagens[i],pathImg,TILE_W,TILE_H);
		
		// Recebe a imagem especificada pelo caminho da máscara
		imgHandl.GetImage(&mascaras[i],pathMask,TILE_W,TILE_H);
		
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
void Soldado::IA(CampoJogo meuCampo){
	
	Soldado *anterior;
	
	int P_CEGOX = x; 
	int P_CEGOY = -64;
	
	
	// Ponto cego da tela
	if(posCego == false){
		
		if(movNUntil == false){		 // destino foi definido?
		
			Until(P_CEGOX,P_CEGOY);  // define destino
		}
	
		posCego = MovUntil(); // move-se até destino
		
		if(posCego == true){
			speed = 2* speed;
		}	
	}
	
	// Região visivel
	if(liberado == true && visivel == false){
		
		if(movNUntil == false){				
			
			Until(x, 64);
		} 	
				
		visivel = MovUntil();
	} 
		
	// Uso da pathfind	
	if(visivel == true && dest == false){
			
				
		if(movNUntil == false){	
			dest = Pathfind(meuCampo,DEST1_X,DEST1_Y);
		} 		
		MovUntil();
	}
	

			
		
}

//=====================================================================

