
/*Barra de vida / hp dos soldados e líderes*/
struct BarraVida{
	
	static const int MAX_VIDA = 50;
	// Prototipo de barra de vida
	void Simples(int x, int y, unsigned int vida);
	int CalcDano(unsigned int vida);
	
};

// Prototipo de barra de vida
void BarraVida::Simples(int x, int y, unsigned int vida){
	int left,top, right, bottom, dano;
	
	left = x - 10;
	top = y - 16;
	right = x + 40;
	bottom = y - 6;
	dano = CalcDano(vida);
	int VERDE = COLOR(68,181,31);
	
	
	Soldado meuSold;
	meuSold.Init("Nazi");
	
	// Barra de vida completa
	setcolor(YELLOW);
	setfillstyle(1,RED);
	bar(  left,  top, right, bottom);
	
	// Barra de vida atual
	setfillstyle(1,VERDE);
	bar(left,  top, right - dano , bottom);
	
	meuSold.GoTo(x, y);
	meuSold.TrocaDir(CIMA);
	meuSold.Show();
}


int BarraVida::CalcDano(unsigned int vida){
	int porCent, porCentDano, dano;
	
	porCent = (vida * 100.0) / VIDA;
	porCentDano = -(porCent - 100);
	dano =  (MAX_VIDA / 100.0) * porCentDano;
	
	return dano;	
}
