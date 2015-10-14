struct Relogio{
	
	time_t marcador;
	
	bool Verifica();
	void Init();
};


// Inicializa o relógio do jogo
void Relogio::Init(){
	time(&marcador);
}


//========================================================================
// Verifica tempo de jogo e age com base nele

bool Relogio::Verifica(){
	
	bool fimJogo = false;
	
	time_t agora;
	
	int gTimeInt;
	double gameTime;
	char relogio[10] ;

	// Verifica que horas são
	time(&agora);
	
	// Verifica o tempo de jogo
	gameTime = difftime(agora,marcador);
	
	// Teste - Converte o tempo de jogo para int
	gTimeInt = (int) gameTime;
	
	
	// Cor usual do texto
	setcolor(YELLOW);
	
	
	if(gTimeInt == BEGIN ){
		outtextxy(590,10,"COMEÇAR");
		delay(2000);
	}
	
	if(gTimeInt == ONDA1){
		outtextxy(480,30,"Faltam 4 m para o ataque final do EIXO");
		delay(2000);
		
	}
	
	else if(gTimeInt == ONDA2){
		outtextxy(480,30,"Faltam 3 m para o ataque final do EIXO");
		delay(2000);
	}
	
	else if(gTimeInt == ONDA3){
		outtextxy(480,30,"Faltam 2 m para o ataque final do EIXO");
		delay(2000);
	}
	
	else if(gTimeInt == ONDA4){
		outtextxy(480,30,"Falta 1 m para o ataque final do EIXO");
		delay(2000);
	}
	
	else if(gTimeInt == ONDAF){
		
		// Cor particular deste texto
		setcolor(RED);
		
		outtextxy(480,30,"É hora do ataque final do EIXO...");
		delay(2000);
	}
	
	else if(gTimeInt == END){
		outtextxy(590,10,"Fim de Jogo.");
		delay(2000);
		
		fimJogo = true;
	}	
	
	// Retorna a confirmação se o jogo acabou ou não
	return fimJogo;
}
