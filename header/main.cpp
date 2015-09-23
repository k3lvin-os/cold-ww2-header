/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense
("../" é utilizado aqui porque os arquivos estão na pasta 
anterior a pasta dos testes header)
*/
#include "../td_functions.h"
#include "../td_defines.h"
#include "../sprite.h"
#include "../campojogo.h"
#include "../grade.h"
#include "../soldado.h"

using namespace std;


int main(){
	
	// Inicialize a janela gráfica
	initwindow(TELA_W,TELA_H);
	
	Soldado meuSold;
	meuSold.Carrega("/Soldado/Chara/Chara");
	int i;
	
	for(i = 0; i < meuSold.QTD_IMG; i++){
		// Espere até que se pressione o espaço
		while(!GetKeyState(VK_SPACE)&&0x80){}
		
		// Coloque a imagem referente ao indice do soldado
		putimage(0,0,meuSold.imagens[i],0);
		
		delay(FPS);
	}	
	
	// Quando o usuário apertar algo, o programa fecha
	while(!kbhit());
	closegraph();
	return 0;
}

