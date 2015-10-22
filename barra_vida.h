
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
	bar3d(TILE_W * 19 + 16 , TILE_H * 10 + 16 , (TILE_W * 18) + 116, (TILE_H * 10) + 26,5,1 );
	meuSold.GoTo(TILE_W * 20, TILE_H * 11);
	meuSold.TrocaDir(CIMA);
	meuSold.Show();
}
