struct Grade{
	void Colocar();
};

void Grade::Colocar(){
	int i, j, x, y;
		
		// Grade das colunas
		for(j = 0, y = 0; j < TILE_QTDX; j++){
			
			x = j * TILE_W; // Calcula posição da grade na tela
			
			line(x,y,x,TELA_H); // Desenha as linhas verticais
		}
		
		// Grade das linhas
		for(i = 0, x = 0; i < TILE_QTDX; i++){
			
			y = i * TILE_H; // Calcula a posição da grade da tela
			
			line(x,y,TELA_W, y); // Desenha as linhas diagonais 
		}
}

	



