/*Utilize o arquivo main para fazer testes com as funções das
bibliotecas. */

#include <iostream>
#include <time.h>
#include <fstream> // E / S de arquivos
#include <iomanip> // Para ler em caracter a caracter
#include <graphics.h>

void GetImage(void** pImg, char path[], int width, int height);


/*Faça seus testes com os arquivos header aqui (;*/
#include "../td_defines.h"
#include "../tdelay.h"
#include "../sprite.h"
#include "../campojogo.h"
#include "../grade.h"
#include "../soldado.h"


using namespace std;


int main(){
	
	// Inicialize a janela gráfica
	initwindow(TELA_W,TELA_H);
	
	void *img;
	readimagefile("../../Assets/Lider/Stalin/Stalin01.bmp",0,0,LIDER_TILEW,LIDER_TILEH); 
	int size = imagesize(0,0,LIDER_TILEW,LIDER_TILEH);
	img = malloc(size);
	getimage(0,0,LIDER_TILEW,LIDER_TILEH,img); 
	cleardevice();
	putimage(0,0,img,0);

	

	
	while(!kbhit());
	closegraph();
	return 0;	
}

/*Busca uma imagem com as informações passadas por parâmetro*/
void GetImage(void** pImg, char path[], int width, int height){
		
		// Lê e coloca na tela uma imagem
		readimagefile(path,0,0,width,height); 
		
		/// Calcula o tamanho da imagem com base na posição
		int size = imagesize(0,0,width,height);
		
		// Aloca memória para a variável que vai recebe-la
		*pImg = malloc(size);
		
		// Recebe a imagem
		getimage(0,0,width,height,*pImg); 
}	


