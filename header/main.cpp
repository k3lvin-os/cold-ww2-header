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
	
	
	// Teste com a criação do soldado Chara
	Soldado meuSold;
	meuSold.Init("Chara");
	

	
	// Quando o usuário apertar algo, o programa fecha
	while(!kbhit());
	closegraph();
	return 0;
}

