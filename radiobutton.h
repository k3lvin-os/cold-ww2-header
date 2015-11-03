// Botão do tipo radio (semelhante ao usado na Web)

struct Radio{
	
	static const int RAIO = 10;
	int x,y;
	bool checked;
	Radio *prox;
	char *label;
	
	// Funções
	Radio *Insere(Radio *radio0, char* label1, bool checked1, int meuX, int meuY);
	void LimpaNo(Radio *radio0);
	void CheckRadio(Radio *radio0);
	void VerificaClick(Radio *radio0);
	void MostraLista(Radio *radio0);
	Radio *RadioChecked(Radio *radio0);
	
	// "Construtor"
	void Init(char *label, bool checked, int meuX, int meuY);
};


// Limpa o nó da lista encadeada
void Radio::LimpaNo(Radio *radio0){
	Radio *pRadio, *aux;
	pRadio = radio0;
	while(pRadio != NULL){
		aux = pRadio;
		pRadio = pRadio->prox;
		free(aux);
	}
	radio0 = NULL;
}


// Retorna o Radio que foi selecionado
Radio* Radio::RadioChecked(Radio *radio0){

	Radio *pRadio;
	pRadio = radio0->prox;
	while(1){
		
		if (pRadio->checked == true || pRadio == NULL)
			return pRadio;
					
		pRadio = pRadio->prox;	
	}
}



// Liga o radio selecionado e desliga todos outros
void Radio::CheckRadio(Radio *radio0){
	
	Radio *pRadio;
	for(pRadio = radio0->prox; pRadio != NULL; pRadio = pRadio->prox ){
		pRadio->checked = false;	
	}
	this->checked = true;
}


// Mostra a lista de botões Radio
void Radio::MostraLista(Radio *radio0){
	Radio *pRadio;
	
	setcolor(LIGHTGREEN);
	setfillstyle(1,LIGHTGREEN);

	for(pRadio = radio0->prox; pRadio != NULL; pRadio = pRadio->prox){
		
		outtextxy(pRadio->x + 15, pRadio->y + 5, pRadio->label);
		if(pRadio->checked == false)
			circle(pRadio->x,pRadio->y,RAIO);
		else
			fillellipse(pRadio->x,pRadio->y,RAIO,RAIO);
	}
}


// Verifica possíveis clicks em todo botões Radio
void Radio::VerificaClick(Radio *radio0){
	
	Radio *pRadio;
	int mouseX,mouseY;
	double tempX, tempY, distRaio;
	bool checkRadio = false;

	if(GetKeyState(VK_LBUTTON) & 0x80){
		
		mouseX = mousex();
		mouseY = mousey();
		for(pRadio = radio0->prox; pRadio != NULL; pRadio = pRadio->prox){
			
			tempX = pow(pRadio->x - mouseX,2.0);
			tempY = pow(pRadio->y - mouseY,2.0);
			distRaio = sqrt(tempX + tempY);
			
			if(distRaio <= RAIO){
				pRadio->CheckRadio(radio0);		
			}
		}
	}
}


// Insere um novo botão de rádio na lista encadeada radio0
Radio* Radio::Insere(Radio *radio0, char* label1, bool checked1, int meuX, int meuY){

	Radio *novo;
	novo = (Radio *) malloc(sizeof(Radio));
	novo->Init(label1,checked1,meuX,meuY); 
	novo->prox  = radio0->prox;
	radio0->prox = novo;
	return novo;	
}

//============================================================
// Atribui os dados de um novo botão
void Radio::Init(char *label1, bool checked1, int meuX, int meuY){
	x = meuX;
	y = meuY;
	checked = checked1;
	label = label1;
	prox = NULL;
}

