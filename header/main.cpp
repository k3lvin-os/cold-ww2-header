/*Utilize o arquivo main para fazer testes com as fun��es das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Fa�a seus testes com os arquivos header aqui (;*/
#include "../td_functions.h"
#include "../td_defines.h"
#include "../sprite.h"
#include "../campojogo.h"
#include "../grade.h"
#include "../soldado.h"

using namespace std;


int main(){
	
	// Inicialize a janela gr�fica
	initwindow(TELA_W,TELA_H);
	
	while(!kbhit());
	closegraph();
	return 0;	
}

	


