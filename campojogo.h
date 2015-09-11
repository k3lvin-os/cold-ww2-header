// Este � o cen�rio principal do jogo
struct CampoJogo{
	
	// Posi��o dos tiles
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite *tipoTile;	

	// Fun��es
	void Mostrar(); 
	void Console();
	
	// Construtor (padr�o)
	CampoJogo();	
};


// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	int j, i,  meuTipo, x,y;
	
	int tecla = 0; // teste
	
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			// "Qual � o tipo do tile nos indices atuais"
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			
			// Coloca o tile na tela
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}

// Imprime a posi��o dos tiles no console
void CampoJogo::Console(){
		
	int i, j;
	
	for(i = 0; i < TILE_QTDY; i++){
		
		std::cout << "\nColuna " << i << std::endl; 
		for(j = 0; j < TILE_QTDX; j++){
			std::cout << posTile[j][i] << "|";
		}
	}
	
}

// Construtor padr�o 
CampoJogo::CampoJogo(){
	
	// Aloca espa�o para os membros do array de estrutura
	tipoTile = (Sprite *) malloc(sizeof(Sprite) * QTD_TIPO);
	
	// Carregue os sprites de campo
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].BasicTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].BasicTile(TILE_W,TILE_H, BLACK); // HUD inferior
	
	// Organiza��o de tiles do campo (isso � pr�-definido)
	int x, y;
	for(x = 0; x < TILE_QTDX; x++){
		
		for(y = 0; y < TILE_QTDY; y++){
			
			
			switch(y){
				case 0: // Linha da muralha e caminho dos soldados
					
					if(x!= 2 && x!=37 && x!= 18 && x!=25 ){
						// Muralha (maioria dos tiles dessa linha)
						posTile[x][y] = 0;
					} else{
						// Caminho
						posTile[x][y] = 1;
					}
					break;
				default:
					posTile[x][y] = 0; 
					
			}
		}
	}
}

