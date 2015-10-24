
/*Barra de vida / hp dos soldados e líderes*/
struct BarraVida{
	
	static const int MAX_SOLD_VIDA = 50;
	static const int MAX_LIDER_VIDA = 64; 
	// Prototipo de barra de vida
	void Show(int x, int y, unsigned int vida, char *tipo);
	int CalcDano(unsigned int vida, int maxVida);
	
};

// Mostra barra de vida do soldado
void BarraVida::Show(int x, int y, unsigned int vida, char *tipo){
	int left,top, right, bottom, dano, maxVida;
	
	if (tipo == "soldado"){
		left = x - 10;
	    top = y - 16;
     	right = x + 40;
     	bottom = y - 6;
     	maxVida = MAX_SOLD_VIDA;
	} else if(tipo == "lider"){
		left = x;
	    top = y - 15;
     	right = x + 64;
     	bottom = y - 2;	
     	maxVida = MAX_LIDER_VIDA;
	}

	dano = CalcDano(vida,maxVida);
	int VERDE = COLOR(68,181,31);

	setcolor(WHITE);
	// Barra de vida completa
	setfillstyle(1,RED);
	bar3d(  left,  top, right, bottom,3,1);
	
	// Barra de vida atual
	setfillstyle(1,VERDE);
	bar3d(  left,  top, right - dano, bottom,3,1);
	


}


// Calcula o dano com base na qtd. de vida
int BarraVida::CalcDano(unsigned int vida, int maxVida){
	int porCent, porCentDano, dano;
	
	porCent = (vida * 100.0) / VIDA;
	porCentDano = -(porCent - 100);
	dano =  (maxVida / 100.0) * porCentDano;
	
	return dano;	
}
