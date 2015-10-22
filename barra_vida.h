
/*Barra de vida / hp dos soldados e líderes*/
struct BarraVida{
	
	// Prototipo de barra de vida
	void Simples(int x, int y);
	
};

// Prototipo de barra de vida
void BarraVida::Simples(int x, int y){
	Soldado meuSold;
	meuSold.Init("Nazi");
	
	setcolor(WHITE);
	setfillstyle(1,RED);
	bar3d(x - 16  , y - 16 , x + 52, y - 6,1,1 );
	meuSold.GoTo(x, y);
	meuSold.TrocaDir(CIMA);
	meuSold.Show();
}
