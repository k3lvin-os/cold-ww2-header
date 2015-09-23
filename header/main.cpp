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
	meuSold.imgAtual = 4;
	meuSold.peh = 'e';
	cout << "meuSold.imgAtual = " << meuSold.imgAtual << "\n";
	meuSold.TrocaImg();
	cout << "Troquei o pé!!!\n";
	cout << "meuSold.imgAtual = " << meuSold.imgAtual << "\n";
	

	
	// Quando o usuário apertar algo, o programa fecha
	while(!kbhit());
	closegraph();
	return 0;
}

