

// Rela��o entre os n�meros da enum/array de imagens e nomes para as imagens
enum ImgCutscenes{
	ESTATUA_TIOSAM = 0, 
	ESTATUA_LENIN,
	ESTATUA_HITLER,
	STALIN_QUADRO,
	ROOSEV_QUADRO,
	STALIN_BRAVO,
	ROOSEV_BRAVO,
	HITLER_QUADRO,
	ROOSEV_GAME,
	STALIN_GAME,
	HILTER_GAME,
	BOMBA_NUCLEAR1,
	BOMBA_NUCLEAR2,
	LIDERES_IALTA,
	qtdImgCutscenes
};


// Rela��o entre n�meros da enum e nomes para os finais do jogo
enum Final{
	FINAL_EUA,FINAL_URSS,FINAL_NAZI,FINAL_GUERRAFRIA, SEM_FINAL
};



// Trabalha com as anima��es n�o interativas da introdu��o e dos finais do jogo
struct Cutscenes{
	
	// Propriedades
	
	// Imagens utilizadas nas cutscenes
	Sprite sprites[qtdImgCutscenes];
	
	// M�todos
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
		
		else if(indiceH >= 4 && indiceH <= 8){
			width = 316;
			height = 436;			
		} 
		
		else if(indiceH >= 9 && indiceH <= 11){
			width = 64;
			height = 96;
		}
				
		else if(indiceH == 12){
			width = 717;
			height = 476;			
		}
		
		else if(indiceH == 13){
			width = 450;
			height = 600;			
		}
		
		else if(indiceH == 14){
			width = 1258;
			height = 830;
		}		
		
		sprites[i].Init();
		sprites[i].GetImage(pathImg,width,height);
	}
}


// Recebe um final como par�metro e mostra o final solicitado
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
			outtextxy(TELA_W / 2 - 80,TELA_H / 2,"FINAL DOS NAZISTAS");
		else if(meuFinal == FINAL_EUA)
			outtextxy(TELA_W / 2 - 80,TELA_H / 2,"FINAL DOS EUA");
		else if(meuFinal == FINAL_URSS)
			outtextxy(TELA_W / 2 - 80,TELA_H / 2, "FINAL DA URSS");
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




// Escreve o texto devagar com base em um delay
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

// Mostra o final dos nazistas
void Cutscenes::FinalNazi(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	cleardevice();
	minhaPg.Visual();
	
	sprites[ESTATUA_HITLER].GoTo(TELA_W - 513,0);
	sprites[ESTATUA_HITLER].Show();
	delay(1500);
	
	EscreveDevagar(0,80,"Nem Uni�o Sovi�tica,nem Estados Unidos \.\.\.",75);
	EscreveDevagar(0,160,"Eles n�o imaginavam que o poderio nazista",75);
	EscreveDevagar(0,190,"era t�o forte\.",75);
	delay(100);
	
	EscreveDevagar(0,270,"Derrotando os dois inimigos, ",75);
	EscreveDevagar(0,300,"Hitler implantou um �nico regime",75);
	EscreveDevagar(0,330,"onde todas na��es obedecem aos Nazistas,",75);
	EscreveDevagar(0,360,"isso com posi��es vantajosas para aqueles",75);
	EscreveDevagar(0,390,"que pertenceram ao Eixo (It�lia e Jap�o).",75);
	delay(200);
	
	EscreveDevagar(0,480,"Com a supremacia da ra�a ariana,",75);
	EscreveDevagar(0,510,"os Nazistas encontraram a desejada paz e, ",75);
	EscreveDevagar(0,540,"agora, inimigo algum pode atrapalhar isso.",75);
	
	delay(2000);
	setbkcolor(BLACK);
	cleardevice();
}


// Final dos Eua
void Cutscenes::FinalEua(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	cleardevice();
	minhaPg.Visual();

	sprites[ESTATUA_TIOSAM].GoTo(TELA_W - 513, 0);
	sprites[ESTATUA_TIOSAM].Show();
	delay(1500);
	
	EscreveDevagar(0,80,"Os Estados Unidos derrotaram os Nazistas",75);
	EscreveDevagar(0,110,"em uma �ltima batalha.",75);
	delay(100);

	
	EscreveDevagar(0,200,"A Uni�o Sovi�tica n�o resistiu ao ",75);
	EscreveDevagar(0,230,"embate e acabou se rendendo aos ",75);
	EscreveDevagar(0,260,"americanos devido a superioridade",75);
	EscreveDevagar(0,290,"desses no campo de batalha.",75); 
	delay(200);

	EscreveDevagar(0,380,"Dessa forma, os americanos tiveram ",75);
	EscreveDevagar(0,410,"plena liberdade para implantar o",75);
	EscreveDevagar(0,440,"capitalismo em todas na��es do oriente.",75);
	
	delay(200);
	EscreveDevagar(0,530,"Alcan�aram a desejada paz e,",75);
	EscreveDevagar(0,560,"agora, inimigo algum pode atrapalhar isso.",75);
	
	delay(2000);
	setbkcolor(BLACK);
	cleardevice();
}


void Cutscenes::FinalUrss(){
	Pagina minhaPg;
	minhaPg.Init();
	minhaPg.Troca();
	minhaPg.Ativa();
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	cleardevice();
	minhaPg.Visual();

	sprites[ESTATUA_LENIN].GoTo(TELA_W - 513, 0);
	sprites[ESTATUA_LENIN].Show();
	delay(1500);
		
	EscreveDevagar(0,80,"A Uni�o Sovi�tica derrotou os Nazistas",75);
	EscreveDevagar(0,110,"em uma �ltima batalha.",75);
	delay(100);
	
	EscreveDevagar(0,200,"Os Estados Unidos n�o resistiram ao ",75);
	EscreveDevagar(0,230,"embate e acabaram se rendendo aos ",75);
	EscreveDevagar(0,260,"sovi�ticos devido a superioridade",75);
	EscreveDevagar(0,290,"desses no campo de batalha.",75); 
	delay(200);

	EscreveDevagar(0,380,"Dessa forma, os sovi�ticos tiveram ",75);
	EscreveDevagar(0,410,"plena liberdade para implantar o ",75);
	EscreveDevagar(0,440,"comunismo em todas na��es do ocidente.",75);
	
	delay(200);
	EscreveDevagar(0,530,"Alcan�aram a desejada paz e,",75);
	EscreveDevagar(0,560,"agora, inimigo algum pode atrapalhar isso.",75);


	
	
	delay(2000);
	setbkcolor(BLACK);
	cleardevice();	
}


// Final aonde os dois jogadores sobrevivem ao ataque dos nazistas
void Cutscenes::FinalGuerraFria(){
	sprites[BOMBA_NUCLEAR1].GoTo(TELA_W /2, 0);
	sprites[BOMBA_NUCLEAR1].Show();
	delay(2000);
}




