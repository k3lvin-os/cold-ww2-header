/*
	Este arquivo contém o PROTÓTIPO das funções e as estruturas que serão utilizadas no
	projeto Tower Defense da N2. Não deixe de conferi-las.
*/



#include <graphics.h>
#include <iostream>

/*=========================       FUNCTIONS         ====================================================*/


// Detecta e inicializa o modo gráfico 
void GraphicsInit(); 

// Limpa o buffer e recebe a tecla pressionada pelo jogador
void GetKey(int *key);

// Prints on console the width and height of screen
void WidthHeight();

/*=========================       STRUCTS         ====================================================*/

struct Sprite{

	// Proprieties
	int x, y;
	void *image;
	
	// Functions
	void Show();
	void Move(int changeX, int changeY);
	void GetImage(char name[], int width, int height);	

	// Constructors	
	Sprite(int beginX,int beginY);
	Sprite(char name[], int width, int height,int beginX, int beginY);
	Sprite(char name[], int width, int height);
	Sprite();
		
};

// Show sprite
 void Sprite::Show(){
	putimage(x,y,image,0);
}

// Move sprite
void Sprite::Move(int changeX, int changeY){
	x += changeX;
	y += changeY;
}


// Fill the image variable with the sprite
void Sprite::GetImage(char name[], int width, int height){
	
	readimagefile(name,0,0,width,height); 
	int size = imagesize(0,0,width,height);
	image = malloc(size);
	getimage(0,0,width,height,image); 
}

// Constructor based in a sprite without image, but with coordinates
Sprite::Sprite(int beginX,int beginY){
	x = beginX;
	y = beginY;
}

// Constructor based in a sprite with image and coordinates
Sprite::Sprite(char name[], int width, int height,int beginX, int beginY){
	GetImage(name,width,height);
	x = beginX;
	y = beginY;
}

// Constructor based in a sprite with image, but without a specific coordinate
Sprite::Sprite(char name[], int width, int height){
	GetImage(name,width,height);
}

// Constructor without parameters
Sprite::Sprite(){
	x = 0;
	y = 0;
}








