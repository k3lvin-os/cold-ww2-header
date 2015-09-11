// Este é o cenário principal do jogo
struct CampoJogo{
	
	// Posição dos tiles
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite *tipoTile;	

	// Funções
	void Mostrar(); 
	void Console();
	
	// Construtor (padrão)
	CampoJogo();	
};


// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	int j, i,  meuTipo, x,y;
	
	int tecla = 0; // teste
	
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			// "Qual é o tipo do tile nos indices atuais"
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			
			// Coloca o tile na tela
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}

// Imprime a posição dos tiles no console
void CampoJogo::Console(){
		
	int i, j;
	
	for(i = 0; i < TILE_QTDY; i++){
		
		std::cout << "\nColuna " << i << std::endl; 
		for(j = 0; j < TILE_QTDX; j++){
			std::cout << posTile[j][i] << "|";
		}
	}
	
}

// Construtor padrão 
CampoJogo::CampoJogo(){
	
	// Aloca espaço para os membros do array de estrutura
	tipoTile = (Sprite *) malloc(sizeof(Sprite) * QTD_TIPO);
	
	// Carregue os sprites de campo
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].BasicTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].BasicTile(TILE_W,TILE_H, BLACK); // HUD inferior
	
	// Organização de tiles do campo (isso é pré-definido)
	int x, y;
	
	
	for(x = 0; x < TILE_QTDX; x++){
		for(y = 0; y < TILE_QTDY; y++){
			
			if (y == 0){ // Linha da muralha e caminho dos soldados
					
				if(x!= 2 && x!=37 && x!= 18 && x!=25 )				
					posTile[x][y] = 0; // Muralha
				else
					posTile[x][y] = 1; // Caminho		
			}
			else			
				posTile[x][y] = 0; 
		}
	}
		
			
	// Terreno da URSS
	for( x = 1; x < 20; x++){
		for(y = 1; y < 19; y++ ){
		
			posTile[x][y] = 2;
		}
	}
	
	// HUD do usuário
	for(x = 0; x < TILE_QTDX; x++ ){
		for(y = 19; y < TILE_QTDY; y++){
			posTile[x][y]= 5;
		}
	}
	
	// Terreno dos Aliados capitalistas
	for(x = 24; x < 39; x++){
		for(y = 1; y <19; y++){
			posTile[x][y] = 3;
		}
	}
	
	// Caminho das tropas
	posTile[2][0] = 1;
	posTile[2][1] = 1;
	posTile[2][2] = 1;
	for(x = 3, y = 2; x <10; x++ ){
		posTile[x][y] = 1;
	}
	for(x = 10, y = 2; y < 9; y++  ){
		posTile[x][y] = 1;
	}
	
	// Final do laço
	for(x = 15, y = 7; x < 18; x++){
		posTile[x][y] = 1;
	}
	
	for(x = 18, y = 7; y >= 0; y--){
		posTile[x][y] = 1;
	}

}
		
	



