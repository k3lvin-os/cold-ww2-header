/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"
#include "campojogo.h"

using namespace std;


// Mostra o campo de jogo nos gráficos e no console
int main(){
	
	initwindow(TELA_W, TELA_H);
	CampoJogo meuCampo = CampoJogo(); // Constrói o campo de jogo
	meuCampo.Mostrar();
	meuCampo.Console();

	
	while(!kbhit());
	return 0;
}
