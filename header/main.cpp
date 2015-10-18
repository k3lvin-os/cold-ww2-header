/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <time.h>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

void* GetImage(char path[], int width, int height);


/*Faça seus testes com os arquivos header aqui (;*/
#include "../td_defines.h"



using namespace std;


int main(){
	
	// Inicialize a janela gráfica
	initwindow(TELA_W,TELA_H);
	/*
	void *img;
	readimagefile("../../Assets/Lider/Stalin/Stalin01.bmp",0,0,LIDER_TILEW,LIDER_TILEH); 
	int size = imagesize(0,0,LIDER_TILEW,LIDER_TILEH);
	img = malloc(size);
	getimage(0,0,LIDER_TILEW,LIDER_TILEH,img); 
	cleardevice();
	putimage(0,0,img,0);
*/
	void **img;
	GetImage("../../Assets/Lider/Stalin/Stalin01.bmp",64,96);
	

	
	while(!kbhit());
	closegraph();
	return 0;	
}

/*Busca e retorna uma imagem com as informações passadas por parâmetro*/
void* GetImage(char path[], int width, int height){
		
		void *pImg;
		readimagefile(path,0,0,width,height); 
		int size = imagesize(0,0,width,height);
		pImg = malloc(size);
		getimage(0,0,width,height,pImg); 
		return pImg;
}	


