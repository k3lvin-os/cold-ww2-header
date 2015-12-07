struct OndaEixo{
	
	// Verifica se as ondas foram enviadas
	bool onda[11];
	
	// Manipula os dados da IA (Eixo)
	Jogador *eixoIA;
	
	// Velocidade do jogo
	int *gameSpeed;
	
	// Indica o destino dos soldados da IA
	char *dest;
	
	// Com base no destino, define-se as coordenadas de inicio dos soldados
	int soldX,  soldY;
	
	//"Construtores"
	void Init();
	void Init(Jogador *oEixoIA, int *velocidadeJogo,char *meuDest);
	
	// Funções
	void Verifica(char onda,Cenario meuCampo);
	void InsereEixo(int x, int y, int qtd, int nFlag);


};

// "Construtor" sem parâmetros - incializa as flags
void OndaEixo::Init(){
	int i;
	
	gameSpeed = NULL;
	dest = NULL;
	for(i = 0; i < QTD_ONDA;i++)
		onda[i] = false;
}

//  "Construtor" com parâmetros
void OndaEixo::Init(Jogador *oEixoIA, int *velocidadeJogo,char *meuDest){
	
	Init();
	gameSpeed = velocidadeJogo;
	eixoIA = oEixoIA;
	dest = meuDest;
	
	if(dest == LADOURSS){
		soldX = ENTRADAURSSX;
		soldY = ENTRADAURSSY;
	} 
	else if(dest == LADOEUA){
		soldX = ENTRADAEUAX;
		soldY = ENTRADAEUAY;
	}
}


// Procedimento de inserir soldado do eixo
void OndaEixo::InsereEixo(int x, int y, int qtd, int nFlag){

	int i;
	Soldado *pSold;
	Soldado *soldado0;
	soldado0 = eixoIA->soldado0;
	
	if(onda[nFlag] == false){
		
		for(i = 0; i < qtd; i++){
			
			pSold = soldado0->Insere(soldado0,&eixoIA->soldGUI,*gameSpeed,dest);
			pSold->GoTo(x,y);
		}
		
		onda[nFlag] = true;
	}

}


// Rotina de envio de onda de soldados do Eixo
void OndaEixo::Verifica(char onda,  Cenario meuCampo){
	
	int qtdIni, nFlag;
	Soldado *soldado0;

	soldado0 = eixoIA->soldado0;

	if(onda != SEM_ONDA){
		
		switch(onda){
	
			case '1':
				nFlag = 0;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '2':
				nFlag = 1;
				qtdIni= 3;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '3':
				nFlag = 2;
				qtdIni= 5;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;							
			case '4':
				nFlag = 3;
				qtdIni= 7;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '5':
				nFlag = 4;
				qtdIni= 7;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;		
			case '6':
				nFlag = 5;
				qtdIni= 8;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;	
		
		}		
	}	
}
