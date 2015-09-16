/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"
#include "campojogo.h"
#include "grade.h"

using namespace std;


int main(){
	
	initwindow(TELA_W,TELA_H);
	
	// Cria o campo, mostra na tela e no console 
	CampoJogo *meuCampo = new CampoJogo();	
	meuCampo->Mostrar();
	meuCampo->Console();
	
	// Cria e mostra uma grade
	Grade *minhaGrd;
	minhaGrd->Colocar();
	
	// Arquiva as coordenadas em um txt
	meuCampo->Arquiva("Tile.txt");
	
	while(!kbhit());
	closegraph();
	return 0;
}

