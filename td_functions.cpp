#include <iostream>
#include <graphics.h>
using namespace std;

// Limpa o buffer e recebe a tecla pressionada pelo jogador
void GetKey(int *key){
		
		// Limpa o buffer para usar getch
		fflush(stdin);
		
		// Receba o input do jogador
		*key = getch();
}

// Detect and initialize graphics mode
void GraphicsInit(){
	int driver, mode;
	detectgraph(&driver, &mode);
	initgraph(&driver,&mode,"");
}

// Prints on console the width and height of screen
void WidthHeight(){
	cout << "Largura da tela " << getmaxx() + 1 << "px\nAltura da tela " << getmaxy() + 1 << "px.";

}
