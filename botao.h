
// Bot�o usado no menu de jogo
struct Botao{
	
	
	int x, y; // Coordendadas
	int tileQtdX,tileQtdY; // Tamanho em tiles
	
	// Fun��es
	bool CheckClick();
	void Show();
	void Init(int meuX, int meuY, int tileQtdX1, int tileQtdY1);
	
};


// Atribuir os devidos valores do bot�o
void Botao::Init(int meuX, int meuY, int tileQtdX1, int tileQtdY1){
	x = meuX;
	y = meuY;
	tileQtdX = tileQtdX1;
	tileQtdY = tileQtdY1;
}
	




// Verifica por clicks na regi�o do bot�o
bool Botao::CheckClick(){
	
	int mouseX,mouseY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80){
		
		mouseX = mousex();
		mouseY = mousey();	
		
		if(mouseX > x && mouseX < x + tileQtdX * TILE_W &&
		mouseY > y && mouseY < y + tileQtdY * TILE_H)
			return true;
		else
			return false;
	}
}


// Mostra o bot�o
void Botao::Show(){
	setcolor(LIGHTGREEN);
	setfillstyle(1,LIGHTGRAY);
	bar(x,y,x + tileQtdX * TILE_W, y + tileQtdY * TILE_H);
}
