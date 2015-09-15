/*Utilize o arquivo main para fazer testes com as fun��es das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <string>
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
	
	// Mainpulador de arquivo
	ifstream arquivo;
	
	// Linha de tiles
	string linha;
	
	// Abre o arquivo
	arquivo.open("teste.txt");
	
	// L� at� encontrar o caracter de
	// fim de arquivo
	while(!arquivo.eof()){
		
		// L� o conte�do de uma linha
		getline(arquivo,linha);
		
		//Exibindo o conte�do da linha
		cout << linha << endl;
	}
	
	// Fecha o arquivo
	arquivo.close();
	
	cout << endl << endl;
	
	system("pause");
	

	
	while(!kbhit());
	return 0;
}

