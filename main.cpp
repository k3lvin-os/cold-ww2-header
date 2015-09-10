/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"


using namespace std;


int main(){
	initwindow(TELA_W, TELA_H);
	while(!kbhit());
	return 0;
}
