
// Metódos que trabalham com grades
struct Grade{
	static const int FIM_CAMPO_URSS_TX = 18;
	static const int FIM_CAMPO_URSS_TY = 19;
	
	void Colocar();
	//void NoCampo();
};

// Coloca uma grade
void Grade::Colocar(){
	int i, j, x, y;
		
		for(j = 0, y = 0; j < TILE_QTDX; j++){
			
			x = j * TILE_W; 
			
			line(x,y,x,TELA_H); 
		}
		
		for(i = 0, x = 0; i < TILE_QTDX; i++){
			
			y = i * TILE_H; 
			
			line(x,y,TELA_W, y); 
		}
}
/*
// Coloca grades no campo de jogo
void Grade::NoCampo()
{
	int x, y, xF, yF ,i;
	
	
	y = TILE_H * 1;
	xF = TILE_W * FIM_CAMPO_URSS_TX;
	yF = TILE_H * FIM_CAMPO_URSS_TY;
	setcolor(WHITE);
	
	for(i = 1; i < FIM_CAMPO_URSS_TX; i++ )
	{	
		x = TILE_W * i;
		line(x,y,xF,yF);	
	}
}
*/








