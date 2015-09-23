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

#define MAXCHARA 1

using namespace std;


int main(){
	
	// Indica o loop do jogo
	bool gameLoop = true;
	
	// Paginação
	int pg = 1;
	
	// Cria um array de soldados
	Soldado chara[MAXCHARA];
	
	// Inicialize a janela gráfica
	initwindow(TELA_W,TELA_H);

	// Soldado que o jogador vai controlar	
	chara[0].Init("Chara");
	chara[0].x = getmaxx() / 2;
	chara[0].y = getmaxy() / 2;
	
	// Loop do jogo
	while(gameLoop == true){
		
		// Limpa a tela
		cleardevice();
		
		// Troca a página
		if(pg == 1){
			pg = 2;
		} else{
			pg = 1;
		}
		
		// Deixa a página em modo desenho
		setactivepage(pg);
		
		// Se o usuário apertar uma das teclas de movimento...
		if( (GetKeyState(VK_LEFT) && 0x80) ||
		  (GetKeyState(VK_RIGHT) && 0x80)  ||
		  (GetKeyState(VK_UP) && 0x80)     ||
		   (GetKeyState(VK_DOWN) && 0x80)
			){
				// Indica o movimento
				chara[0].idle = false;
							
				// O soldado vai fazer um movimento e, por isso, 
				//troca a imagem
				chara[0].TrocaImg();
		
				// Movimenta o sprite
				chara[0].Move();	
			}
		
		
		// Verifica o pressionamento
		if(GetKeyState(VK_LEFT) && 0x80){
				
			// Troca o sprite da direção
			chara[0].TrocaDir(ESQUERDA);
		}
			
		else if(GetKeyState(VK_RIGHT) && 0x80){
				
			// Troca o sprite da direção
			chara[0].TrocaDir(DIREITA);
				
			// Indica o movimento
			chara[0].idle = false;
		}
			
		else if(GetKeyState(VK_UP) && 0x80){
				
			// Troca o sprite da direção
			chara[0].TrocaDir(FRENTE);
				
			// Indica o movimento
			chara[0].idle = false;
		}
			
		else if(GetKeyState(VK_DOWN) && 0x80){
				
			// Troca o sprite da direção
			chara[0].TrocaDir(COSTA);
				
			// Indica o movimento
			chara[0].idle = false;
		}
		
		else{
			
			// Indica que o soldado está parado
			chara[0].idle = true;
		}
			
		// Mostra o sprite
		chara[0].Show();
		
		// Deixa a página em modo de visualização
		setvisualpage(pg);	
			
		// Delay
		delay(FPS);		
			
	}

		closegraph();
		return 0;	
}

	



