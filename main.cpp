/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

/*Bibliotecas do projeto TowerDefense*/
#include "td_functions.h"
#include "td_defines.h"
#include "sprite.h"
#include "campojogo.h"
#include "grade.h"

using namespace std;


int main(){
	
	// Linha e coluna (contadores)
	int i, j;
	
	// Confirma a leitura do arquivo
	bool leu = true;
	
	// Nome do arquivo
	char arqnome[12];
	

	
	cout << "Digite um nome para o arquivo de coordenadas (.txt)\n";
	cout << "Seu arquivo deve conter, no máximo, 8 caracteres\n";
	cin >> arqnome;
	
	// Possibilita que o arquivo se torne txt
	strcat(arqnome,".txt");

	
	// Cria e manipula o arquivo com a posição dos tiles
	ofstream arqTile;
	
	// Abre o arquivo
	arqTile.open(arqnome);
		
	arqTile << "OLÁ !!!!";
	
	arqTile.close();
		
	
/*	
	for(i = 0; i < TILE_QTDY; i++){
		
		for(j = 0; j < TILE_QTDX; j++){
			
			arqTiles << "0"; 
		}
	
		cout << endl;
	}	

	return 0;*/
}

