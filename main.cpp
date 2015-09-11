/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"


using namespace std;

// Armazena os tipos de tiles do jogo
struct Tiles{
	
	Sprite *tipoTile; 
	
	// Construtor padrão
	Tiles();
};


Tiles::Tiles(){
	
	// ALoca espaço para os tiles
 	tipoTile = new Sprite();
 	
 	// Carrega os tiles
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].BasicTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].BasicTile(TILE_W,TILE_H, BLACK); // HUD inferior
	
	// Limpa a tela
	cleardevice();
	
}

// Este é o cenário principal do jogo
struct CampoJogo{
	
	int posTile[TILE_QTDX][TILE_QTDY]; // Indicacao dos tiles
	//Tiles *tilesJogo;// Tipos de tiles
	Sprite *tipoTile;

	
	
	void Colocar(); // Coloca o campo de jogo
	
	CampoJogo();	// Construtor padrão
};


// Coloca os sprites na tela
void CampoJogo::Colocar(){
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
			
			
			switch(y){
				case 0: // Linha da muralha e caminho dos soldados
					
					if(x!= 2 && x!=37 ){
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


int main(){
	initwindow(TELA_W, TELA_H);
	CampoJogo meuCampo = CampoJogo();
	meuCampo.Colocar();
	
	// Imprime código dos tiles de campo
	int i, j;
	
	for(i = 0; i < TILE_QTDY; i++){
		
		cout << "Coluna " << i << endl; 
		for(j = 0; j < TILE_QTDX; j++){
			cout << meuCampo.posTile[j][i] << "|";
		}
	}
	
	
	while(!kbhit());
	return 0;
}
