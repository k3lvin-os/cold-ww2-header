/*Utilize o arquivo main para fazer testes com as fun��es das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense
("../" � utilizado aqui porque os arquivos est�o na pasta 
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
	
	// Inicialize a janela gr�fica
	initwindow(TELA_W,TELA_H);
	
	
	// Teste com a cria��o do soldado Chara
	Soldado meuSold;
	meuSold.Init("Chara");
	

	
	// Quando o usu�rio apertar algo, o programa fecha
	while(!kbhit());
	closegraph();
	return 0;
}

