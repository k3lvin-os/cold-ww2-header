struct OndaEixo{
	
	// Verifica se as ondas foram enviadas
	bool onda[11];
	
	// Manipula os dados da IA (Eixo)
	Jogador *eixoIA;
	
	// Indica o destino dos soldados da IA
	char *dest;
	
	//"Construtores"
	void Init();
	void Init(Jogador *oEixoIA);
	
	// Funções
	void Verifica(char onda, char* chegou,CampoJogo meuCampo);
	void InsereEixo(int x, int y, int qtd, int nFlag);


};

// "Construtor" sem parâmetros - incializa as flags
void OndaEixo::Init(){
	int i;
	
	dest = NULL;
	for(i = 0; i < QTD_ONDA;i++)
		onda[i] = false;
}

//  "Construtor" com parâmetros
void OndaEixo::Init(Jogador *oEixoIA){
	Init();
	eixoIA = oEixoIA;
}


// Procedimento de inserir soldado do eixo
void OndaEixo::InsereEixo(int x, int y, int qtd, int nFlag){

	int i;
	Soldado *pSold;
	Soldado *soldado0;
	soldado0 = eixoIA->soldado0;
	
	if(onda[nFlag] == false){
		
		for(i = 0; i < qtd; i++){
			
			pSold = soldado0->Insere(soldado0,"Nazi",dest);
			pSold->GoTo(x,y);
		}
		
		onda[nFlag] = true;
	}

}


// Rotina de envio de onda de soldados do Eixo
void OndaEixo::Verifica(char onda, char* meuDest,  CampoJogo meuCampo){
	
	int soldX,  soldY, qtdIni, nFlag;
	Soldado *soldado0;

	soldado0 = eixoIA->soldado0;

	if(onda != SEM_ONDA){
		
		if(meuDest == LADO2){
			soldX = ENTRADAURSSX;
			soldY = ENTRADAURSSY;
		} 
		else if(meuDest == LADO1){
			soldX = ENTRADAEUAX;
			soldY = ENTRADAEUAY;
		}
		
		dest = meuDest;
		
		switch(onda){
	
			case '1':
				nFlag = 0;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '2':
				nFlag = 1;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '3':
				nFlag = 2;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;							
			case '4':
				nFlag = 3;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '5':
				nFlag = 4;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;		
			case '6':
				nFlag = 5;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;	
			case '7':
				nFlag = 6;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;					
			case '8':
				nFlag = 7;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;	
			case '9':
				nFlag = 8;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;
			case '10':
				nFlag = 9;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;	
			case '11':
				nFlag = 10;
				qtdIni= 1;
				InsereEixo(soldX,soldY,qtdIni, nFlag);	
				break;			
		}		
	}	
}
