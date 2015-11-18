

// Rela��o entre os n�meros da enum/array de imagens e nomes para as imagens
enum ImgCutscenes{
	TIO_SAM = 0, 
	LENIN,
	HITLER,
	STALIN_QUADRO,
	ROOSEV_QUADRO,
	HITLER_QUADRO,
	ROOSEV_GAME,
	STALIN_GAME,
	HILTER_GAME,
	BOMBA_NUCLEAR,
	LIDERES_IALTA,
	STALIN_BRAVO,
	ROOSEV_BRAVO
};


// Rela��o entre n�meros da enum e nomes para os finais do jogo
enum Final{
	FINAL_EUA,FINAL_URSS,FINAL_NAZI,FINAL_GUERRAFRIA
};



// Trabalha com as anima��es n�o interativas da introdu��o e dos finais do jogo
struct Cutscenes{
	
	void Carrega();
	void MostraFinal(Final meuFinal);
	void FinalEua();
	void FinalUrss();
	void FinalNazi();
	void FinalGuerraFria();
	void Introducao(char *meuLado);
	
	
};


void Cutscenes::MostraFinal(Final meuFinal){
	
	if(meuFinal == FINAL_NAZI)
		FinalNazi();
	
}


void Cutscenes::FinalNazi(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	setbkcolor(WHITE);
	cleardevice();
	minhaPg.Visual();
	while(!kbhit()){
		
	}
	
}
