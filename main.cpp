/*Utilize o arquivo main para fazer testes com as fun��es das
bibliotecas. */

#include <iostream>
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"
#include "campojogo.h"
#include "grade.h"

using namespace std;


// Mostra o campo de jogo nos gr�ficos e no console
int main(){
	
	initwindow(TELA_W, TELA_H);
	CampoJogo meuCampo = CampoJogo(); // Constr�i o campo de jogo
	meuCampo.Mostrar();
	meuCampo.Console();
	Grade *minhaGrd;
	minhaGrd->Coloca();

	
	while(!kbhit());
	return 0;
}
