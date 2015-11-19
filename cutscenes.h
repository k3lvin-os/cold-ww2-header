

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
	FINAL_EUA,FINAL_URSS,FINAL_NAZI,FINAL_GUERRAFRIA, SEM_FINAL
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
	void EscreveDevagar(int x0, int y0, char* msg, int delayPorLetra);
	
	
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
	
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	cleardevice();
	
	if(meuFinal != FINAL_GUERRAFRIA){
		setcolor(WHITE);
		settextstyle(BOLD_FONT,HORIZ_DIR,3);
		if(meuFinal == FINAL_NAZI)
			outtextxy(TELA_W / 2 - 64,TELA_H / 2,"FINAL DOS NAZISTAS");
		else if(meuFinal == FINAL_EUA)
			outtextxy(TELA_W / 2,TELA_H / 2- 32,"FINAL DOS EUA");
		else if(meuFinal == FINAL_URSS)
			outtextxy(TELA_W / 2, TELA_H / 2- 32, "FINAL DA URSS");
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
	}
	
	minhaPg.Visual();
	delay(2000);
	
	if(meuFinal == FINAL_NAZI)
		FinalNazi();
	else if(meuFinal == FINAL_URSS)
		FinalUrss();
	else if(meuFinal == FINAL_EUA)	
		FinalEua();
	else if(meuFinal == FINAL_GUERRAFRIA)
		FinalGuerraFria();
}


// Mostra o final dos nazistas
void Cutscenes::FinalNazi(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT   ,HORIZ_DIR,1);
	cleardevice();
	minhaPg.Visual();
	
	sprites[ESTATUA_HITLER].GoTo(TELA_W - 513,0);
	sprites[ESTATUA_HITLER].Show();
	delay(1500);
	
	EscreveDevagar(0,80,"Nem União Soviética,nem Estados Unidos \.\.\.",75);
	EscreveDevagar(0,160,"Eles não imaginavam que o poderio nazista",75);
	EscreveDevagar(0,190,"era tão forte\.",75);
	delay(100);
	
	EscreveDevagar(0,270,"Derrotando os dois inimigos, ",75);
	EscreveDevagar(0,300,"Hitler implantou um único regime",75);
	EscreveDevagar(0,330,"onde todas nações obedecem aos Nazistas,",75);
	EscreveDevagar(0,360,"isso com posições vantajosas para aqueles",75);
	EscreveDevagar(0,390,"que pertenceram ao Eixo (Itália e Japão).",75);
	delay(200);
	
	EscreveDevagar(0,480,"Com a supremacia da raça ariana,",75);
	EscreveDevagar(0,510,"os Nazistas encontraram a desejada paz e, ",75);
	EscreveDevagar(0,540,"agora, inimigo algum pode atrapalhar isso.",75);
	
	delay(2000);
	setbkcolor(BLACK);
	cleardevice();
}

// Escrve o texto devagar com base em um delay
void Cutscenes::EscreveDevagar(int x0, int y0, char* msg, int delayPorLetra){
	
	char buffer[101], temp[2], c;
	int i, x;
	
	if(strlen(msg) <= 100){
		
		strcpy(buffer,msg);
		i = 0;
		x = x0;
		c = buffer[0];
		
		while(c != '\0'){
			
			temp[0] = c;
			temp[1] = '\0';
			
			if(c != ' ')
				outtextxy(x,y0,temp);		
			delay(delayPorLetra);
			
			if(c == ' ')
				x += 15;
			else
				x += 19;
			
				
			i++;
			c = buffer[i];	
		} 
		
	}
	
	
}

void Cutscenes::FinalEua(){
	
}


void Cutscenes::FinalUrss(){
	
	
}


void Cutscenes::FinalGuerraFria(){
	
	
}


