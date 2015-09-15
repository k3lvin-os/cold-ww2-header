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


// Mostra o campo de jogo nos gráficos e no console
int main(){
	
	
	
	// Mainpulador de arquivo para saída
	ofstream arquivo;
	
	// Abre o arquivo
	arquivo.open("teste.txt");
	
	arquivo << "Veja, caro mortal! Eu escrevi em um arquivo .txt";
	arquivo << "\nAlgo que poucos podem fazer";
	
	// Fecha o arquivo
	arquivo.close();
	
	cout << "Acabei de escrever no arquivo \"teste.txt\". Leia-o";
	
	cout << endl << endl;
	
	system("pause");
	

	return 0;
}

