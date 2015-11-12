
// Representa o jogador do game em um dos dois avatares
// (Churchill ou Stallin)
struct Jogador{
	
	/*=========================
			Constantes
	===========================*/
	static const int DINHEIRO = 120;

	
	/*=========================
			Propriedades
	===========================*/

	// Cabeça da lista encadeada de soldados do jogador
	Soldado *soldado0;
	
	// Caebça da lista encadeada de torres do jogador
	Torre *torre0;
	
	// Vida do jogador
	int vida;
	
	//  Velocidade do jogo
	int *gameSpeed;
	
	// Lado do jogador
	char* lado;
	
	// Marcador de tempo de envio de soldados
	TDelay envioSold;
	
	// Marcador de tempo para espera de inimigo
	TDelay esperaIni;
	
	// Dinheiro do jogador
	int dinheiro;
	
	// Avatar do jogador (Roosevalt, Stallin ou Hitler)
	Lider lider;	
	
	// Flag para indicar que ele está colocando uma torre
	bool flagTorre;
	
	// Torre que o jogador visualiza na GUI 
	Torre torreGUI;
	
	// Torre que o jogador arrasta (GUI)
	Torre tempTorre;
	
	// Indica a qutantidade de soldados que o jogador está em enviando
	int qtdSoldEspera;
	
	// Indica as coordendas da torre que o jogador comprou recentemente
	int novaTorreXeY[2];
	

	// Soldado temporário do jogador (também faz parte da GUI)
	Soldado soldGUI;
	
	// Coordenadas para GUI
	int guiSoldX, guiSoldY, guiDinX, guiDinY,
	guiNameSoldX,guiNameSoldY,guiSoldTextX,guiSoldTextY,
	guiCircleX,guiCircleY;
	
	/*===========================
				Funções
	==============================*/
	
	void MostraGUI();
	void InputGUI();
	void NovoIni();
	void EnviaIni();
	void ArrastaTorre(CampoJogo meuCampo);
	bool Compra(int preco);

		
	// "Construtores"
	void Init();
	void Init(char* meuLado, int *velocidadeJogo);
	
};

//==================================================================
// Mostra a interface com o usuário do jogador
void Jogador::MostraGUI(){
		
	char textDin[19] = "Dinheiro: ";
	char buffer[8];
	
	settextjustify(LEFT_TEXT,TOP_TEXT);

	// Dinheiro
	itoa(dinheiro,buffer,10);
	strcat(textDin,buffer);
	setcolor(GREEN);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(guiDinX,guiDinY,textDin );

	// GUI da Torre
	torreGUI.MostraTorre();
	
	// GUI do Soldado
	soldGUI.Show();	
	
	// "Colocar Torre" (GUI)
	setcolor(LIGHTBLUE);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(TORRE_TEXT_X,TORRE_TEXT_Y,"Colocar");
	outtextxy(TORRE_TEXT_X + 12,TORRE_TEXT_Y + 32,"Torre");

	
	// "Enviar Soldado" (GUI)
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	outtextxy(guiNameSoldX,guiNameSoldY,lado);
	
	// Texto do Soldado
	setcolor(LIGHTRED);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(guiSoldTextX,guiSoldTextY,"Enviar Soldado");
	
	// Círculo em volta do soldado
	setcolor(BLACK);	
	circle(guiCircleX ,guiCircleY,16);	
}

//=====================================================================
// Trabalha com a interação com a GUI
void Jogador::InputGUI(){
	
	int mouseX, mouseY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80){
					
		mouseX = mousex();
		mouseY = mousey();
		
		if(mouseX >= guiSoldX && mouseX <= guiSoldX + TILE_W &&
		mouseY >= guiSoldY && mouseY <= guiSoldY + TILE_H) {
			
			if(envioSold.PassouDelay(ESPERA_DELAY) == true){
				
				envioSold.Atualiza();	
			
				if (Compra(PRECO_SOLDADO) == true){
 					soldado0->Insere(soldado0,lado,*gameSpeed);	
					qtdSoldEspera = 1;			
				}	
			}
		}
		
		// Verifica input de colocação de torre
		if(mouseX >= TORRE1_X && mouseX <= TORRE1_X + TORRE_W &&
		mouseY >= TORRE1_Y && mouseY <= TORRE1_Y + TORRE_H){
			flagTorre = true;
		}	
	}
	
}

//===============================================================
// "Construtor" geral 
void Jogador::Init(){
	
	soldado0 = (Soldado *) malloc(sizeof(Soldado));
	torre0 = (Torre *) malloc(sizeof(Torre));
	soldado0->prox = NULL;
	torre0->prox = NULL;
	dinheiro = DINHEIRO;
	envioSold.Atualiza();
	esperaIni.Atualiza();
	vida = VIDA;
	lado = NULL;
	gameSpeed = NULL;
	qtdSoldEspera = 0;
	flagTorre = false;
	novaTorreXeY[0] = UNDEFINED;
	novaTorreXeY[1] = UNDEFINED;
}

//=================================================================
// Chama o construtor geral e também passa dados específicos
void Jogador::Init(char *meuLado, int *velocidadeJogo){
	
	Init();
	lado = meuLado;	
	gameSpeed = velocidadeJogo;
		
	if(meuLado == LADO1 || meuLado == LADO2){
		
		if(meuLado == LADO1){
	
			guiNameSoldX = EUA_TEXT_X;
			guiNameSoldY = EUA_TEXT_Y;
			guiSoldTextX = SOLD_EUA_X;
			guiSoldTextY = SOLD_EUA_Y;
			guiDinX = MONEY_EUA_X;
			guiDinY = MONEY_EUA_Y;
			guiSoldX = GUI_EUA_X ;
			guiSoldY = GUI_EUA_Y ;
			guiCircleX = guiSoldX + 16;
			guiCircleY = guiSoldY + 16;
			lider.Init("Roosevelt",&vida);
			tempTorre.Init(lado,0,0,true);
		}
			
		else if(meuLado == LADO2){
			guiNameSoldX = URSS_TEXT_X;
			guiNameSoldY = URSS_TEXT_Y;
			guiSoldTextX = SOLD_URSS_X;
			guiSoldTextY = SOLD_URSS_Y;
			guiDinX = MONEY_URSS_X;
			guiDinY = MONEY_URSS_Y;
			lider.Init("Stalin",&vida);
			guiSoldX = GUI_URSS_X ;
			guiSoldY = GUI_URSS_Y;
			guiCircleX = guiSoldX + 16;
			guiCircleY = guiSoldY + 16;	
		}		
		
		soldGUI.Init(meuLado,0);
		soldGUI.GoTo(guiSoldX,guiSoldY);
		soldGUI.TrocaDir(CIMA);
		torreGUI.Init(meuLado,TORRE1_X,TORRE1_Y,true);
		tempTorre.Init(lado,0,0,true);	
	}
	else
		lider.Init("Hitler",&vida);
	
}

//======================================================================
// Procedimento de arrastar a torre após o click
void Jogador::ArrastaTorre(CampoJogo meuCampo){
	
	int tMouseX,tMouseY, meuX, meuY;
		
	if(flagTorre == true){

		tMouseX = mousex() / TILE_W;
		tMouseY = mousey() / TILE_H;
		
		if(tMouseX < 1 )
			tMouseX = 1;
		else if(tMouseX > 38)
			tMouseX = 38;
		
		if(tMouseY < 1)
			tMouseY = 1;
		else if(tMouseY > 17)
			tMouseY = 17;
		
		meuX = tMouseX * TILE_W; 
		meuY = tMouseY * TILE_H;
	
		tempTorre.x = meuX;
		tempTorre.y = meuY;
		
		tempTorre.MostraTorre();
		
		setcolor(BLUE);
		circle(meuX + 16,meuY + 32,TORRE_RAIO);
		
		if(ismouseclick(WM_LBUTTONUP )){
			
			clearmouseclick(WM_LBUTTONUP);
			
				if(meuCampo.PosExist(tMouseX,tMouseY) == true && 
				meuCampo.PosExist(tMouseX,tMouseY - 1) == true){
				
					if(meuCampo.CheckPosTorre(tMouseX,tMouseY,lado) == true){
						
						if(torre0->SemTorrePerto(torre0,meuX,meuY) == true){
							if(Compra(PRECO_TORRE) == true){
								torre0->Insere(torre0,lado,meuX,meuY);
								novaTorreXeY[0] = meuX;
								novaTorreXeY[1] = meuY;
							}

						}
					}
				}
			flagTorre = false;		
		}
	}
}



/*Compra e paga algum recurso. 
Retorna true ou false dependendo do dinheiro para compra*/
bool Jogador::Compra(int preco){

	if(dinheiro >= preco){
		dinheiro -= preco;
		return true;
	} else
		return false;
}
