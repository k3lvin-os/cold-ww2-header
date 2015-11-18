

// Relação entre os números da enum/array de imagens e nomes para as imagens
enum ImgCutscenes{
	ESTATUA_TIOSAM = 0, 
	ESTATUA_LENIN,
	ESTATUA_HITLER,
	STALIN_QUADRO,
	ROOSEV_QUADRO,
	HITLER_QUADRO,
	ROOSEV_GAME,
	STALIN_GAME,
	HILTER_GAME,
	BOMBA_NUCLEAR,
	LIDERES_IALTA,
	STALIN_BRAVO,
	ROOSEV_BRAVO,
	qtdImgCutscenes
};


// Relação entre números da enum e nomes para os finais do jogo
enum Final{
	FINAL_EUA,FINAL_URSS,FINAL_NAZI,FINAL_GUERRAFRIA
};



// Trabalha com as animações não interativas da introdução e dos finais do jogo
struct Cutscenes{
	
	// Propriedades
	
	// Imagens utilizadas nas cutscenes
	Sprite sprites[qtdImgCutscenes];
	
	// Métodos
	void Carrega();
	void MostraFinal(Final meuFinal);
	void FinalEua();
	void FinalUrss();
	void FinalNazi();
	void FinalGuerraFria();
	void Introducao(char *meuLado);
	void EscreveDevagar(char* msg, int delay);
	
	
};


// Carrega as imagens utilizadas nas cutscenes
void Cutscenes::Carrega(){
	
	int i, indiceH, width, height;
	char pathImg[40], temp[3];
	for( i = 0; i < qtdImgCutscenes; i++){
		
		indiceH = i + 1;
	
		strcpy(pathImg,ASSETS);
		strcat(pathImg,CUTSCENES);	
			
		if(indiceH < 10)
			strcat(pathImg,"0");
			
		itoa(indiceH,temp,10);
		strcat(pathImg,temp);
		strcat(pathImg,BITMAP);
		
		
		
		if(indiceH >= 1 && indiceH <= 3){
			width = 513;
			height = 720;
		}
		
		else if(indiceH >= 4 && indiceH <= 6){
			width = 316;
			height = 436;			
		} 
		
		else if(indiceH >= 7 && indiceH <= 9){
			width = 64;
			height = 96;
		}
		
		else if(indiceH == 10  ){
			width = 580;
			height = 418;		
		}
		
		else if(indiceH == 11){
			width = 543;
			height = 242;			
			
		}
		
		else if(indiceH == 12 || indiceH == 13){
			width = 316;
			height = 436;			
		}
		
		
		sprites[i].Init();
		sprites[i].GetImage(pathImg,width,height);
	}
}


// Recebe um final como parâmetro e mostra o final solicitado
void Cutscenes::MostraFinal(Final meuFinal){
	
	if(meuFinal == FINAL_NAZI)
		FinalNazi();
	
}


// Mostra o final dos nazistas
void Cutscenes::FinalNazi(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT   ,HORIZ_DIR,3);
	cleardevice();
	minhaPg.Visual();
	
	sprites[ESTATUA_HITLER].GoTo(TELA_W - 513,0);
	sprites[ESTATUA_HITLER].Show();
	outtextxy(0,0,"Nem União Soviética, nem Estados Unidos \.\.\.");
	while(!kbhit()){
		
	}
	
}

