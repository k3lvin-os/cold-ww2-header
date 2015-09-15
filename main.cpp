/*Utilize o arquivo main para fazer testes com as funções das
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


// Mostra o campo de jogo nos gráficos e no console
int main(){
	
	// Mainpulador de arquivo
	ifstream arquivo;
	
	// Linha de tiles
	string linha;
	
	// Abre o arquivo
	arquivo.open("teste.txt");
	
	// Lê até encontrar o caracter de
	// fim de arquivo
	while(!arquivo.eof()){
		
		// Lê o conteúdo de uma linha
		getline(arquivo,linha);
		
		//Exibindo o conteúdo da linha
		cout << linha << endl;
	}
	
	// Fecha o arquivo
	arquivo.close();
	
	cout << endl << endl;
	
	system("pause");
	

	
	while(!kbhit());
	return 0;
}

