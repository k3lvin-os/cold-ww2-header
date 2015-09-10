/*Utilize o arquivo main para fazer testes com as fun��es das
bibliotecas. */

#include <iostream>
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"


using namespace std;


struct Tiles{
	Sprite *tipoTile = (Sprite *) malloc(sizeof(Sprite) * QTD_TIPO);
	
	// Construtor padr�o
	Tiles();
};




Tiles::Tiles(){
 /*new Sprite[15];*/
 
 	// Carrega os tiles
	tipoTile[0].SimpleTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].SimpleTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].SimpleTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].SimpleTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].SimpleTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].SimpleTile(TILE_W,TILE_H, BLACK); // HUD inferior
	
	// Limpa a tela
	cleardevice();

}

// Este � o cen�rio principal do jogo
struct CampoJogo{
	
	int tiles[TILE_QTDX][TILE_QTDY]; // Indicacao dos tiles
	Tiles *tilesJogo = new Tiles(); // Tipos de tiles
	
	
	void Colocar(); // Coloca o campo de jogo
	
	CampoJogo();	// Construtor padr�o
};


// Coloca os sprites na tela
void CampoJogo::Colocar(){
	int i, j, x, y, tipo;
	
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	tipo = 0;
	
	while(i < TILE_QTDX){
		while(j < TILE_QTDY){
			
			tipo = tiles[i][j];
			tilesJogo->tipoTile[tipo].Show();
			
			y += TILE_H; // Pr�xima posi��o para inser��o de tile
			j++; // Pr�ximo indice no array
		}
		x += TELA_W;// Pr�xima posi��o para inser��o de tile
		i++;// Pr�ximo indice no array
	}
	
}

// Construtor padr�o (o cen�rio j� � predefinido)
CampoJogo::CampoJogo(){
	int i, j;
	for(i = 0; i < TILE_QTDX; i++){
		for(j = 0; j < TILE_QTDY; j++){
			tiles[i][j] = 0;
		}
	}
}


int main(){
	initwindow(TELA_W, TELA_H);
	
	Tiles *meuTile = new Tiles();	
	meuTile->tipoTile[0].Move(MidX(), MidY());
	meuTile->tipoTile[0].SimpleTile(32,32,RED);
	cleardevice();
	meuTile->tipoTile[0].Show();
	
	while(!kbhit());
	return 0;
}
