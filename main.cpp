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
	int i, j,  meuTipo, x, y;
	
	int tecla = 0; // teste
	
	for(i = 0; i < TILE_QTDX; i++){ /*	for(i = 0; i < TILE_QTDY; i++)*/ // Código alternativo
	
		for(j = 0; j < TILE_QTDY; j++) { /*	for(j = 0; j < TILE_QTDX; j++)*/// Código alternativo
			
			// "Qual é o tipo do tile nos indices atuais"
			meuTipo = posTile[i][j];
			
			// Calcula a posição x e y
			x = i * TILE_W;
			y = j * TILE_H;
			
			/*x = j * TILE_W;// Código alternativo
			y = i * TILE_H;
			*/
			
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
	int i, j;
	for(i = 0; i < TILE_QTDX; i++){
		
		for(j = 0; j < TILE_QTDY; j++){
			
			
			switch(i){
				case 0: // Linha da muralha e caminho dos soldados
					
					if(j!= 2 && j!=19 ){
						// Muralha (maioria dos tiles dessa linha)
						posTile[i][j] = 0;
					} else{
						// Caminho
						posTile[i][j] = 1;
					}
					break;
				default:
					posTile[i][j] = 0;
					
			}
		}
	}
}


int main(){
	initwindow(TELA_W, TELA_H);
	CampoJogo meuCampo = CampoJogo();
	meuCampo.Colocar();
	
	int i, j;
	
	for(i = 0; i < TILE_QTDX; i++){
		for(j = 0; j < TILE_QTDY; j++){
			cout << meuCampo.posTile[i][j] << "|";
		}
		cout << endl;
	}
	
	/*setfillstyle(1,RED);
	bar(0,0,32,32);
	int size = imagesize(0,0,32,32);
	void *image = malloc(size);
	getimage(0,0,32,32,image);
	cleardevice();
	putimage(0,0,image,0);*/
	
	while(!kbhit());
	return 0;
}
