
// Representa o jogador do game em um dos dois avatares
// (Churchill ou Stallin)
struct Jogador{
	
	/*=========================
			Constantes
	===========================*/
	static const int DINHEIRO = 100;
	static const int VIDA = 100;

	
	/*=========================
			Propriedades
	===========================*/

	// Cabeça da lista encadeada de soldados do jogador
	Soldado *soldado0;
	
	// Vida do jogador
	int vida;
	
	// Lado do jogador
	char* lado;
	
	// Marcador de tempo de envio de soldados
	TDelay envioSold;
	
	// Marcador de tempo para espera de inimigos
	TDelay esperaIni;
	
	// Dinheiro do jogador
	int dinheiro;
	
	// Avatar do jogador (Roosevalt, Stallin ou Hitler)
	Lider meuLider;	
	
	/*===========================
				Funções
	==============================*/
	
	void MostraGUI();
	void InputGUI();
	void NovoIni();
	void EnviaIni();
	
		
	// "Construtores"
	void Init();
	void Init(char* meuLado);
	
};

//==================================================================
// Mostra a interface com o usuário do jogador
void Jogador::MostraGUI(){
	
	
	settextjustify(LEFT_TEXT,TOP_TEXT);
		
	Soldado GUISold;
	
	char textDin[19] = "Dinheiro: ";
	char buffer[8];
	itoa(dinheiro,buffer,10);
	strcat(textDin,buffer);
		
	

	

	
	// GUI da URSS
	if(lado == LADO2){
		
		GUISold.Init("Urss");
		GUISold.GoTo(GUI_URSS_X,GUI_URSS_Y);
		GUISold.TrocaDir(CIMA);
		GUISold.Show();
		
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
		outtextxy(URSS_TEXT_X,URSS_TEXT_Y,"URSS");
		
		setcolor(BLACK);	
		circle(GUI_URSS_X + 16,GUI_URSS_Y + 16,16);	
			
		setcolor(RED);
		settextstyle(BOLD_FONT,HORIZ_DIR,2);
		outtextxy(TILE_W * 4,TILE_H * 19,"Soldado");

		
		setcolor(GREEN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 1);
		outtextxy(MONEY_URSS_X,MONEY_URSS_Y,textDin );
		
		setcolor(LIGHTBLUE);
		settextstyle(BOLD_FONT,HORIZ_DIR,2);
		outtextxy(TORRE_TEXT_X,TORRE_TEXT_Y,"Torre");
		
	}
	
}

//=====================================================================
// Trabalha com a interação com a GUI
void Jogador::InputGUI(){
	
	int mouseX, mouseY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80){
		mouseX = mousex();
		mouseY = mousey();
		
		if(mouseX >= GUI_URSS_X && mouseX <= GUI_URSS_X + TILE_W &&
		mouseY >= GUI_URSS_Y && mouseY <= GUI_URSS_Y + TILE_H) {
			
			if(envioSold.PassouDelay(ESPERA_DELAY) == true){
				
				envioSold.Atualiza();	
			
				if (soldado0->Compra(&dinheiro) == true){
						
 					soldado0->Insere(soldado0,"Urss");
				}				
			}
		}
	}
}

//===============================================================
// "Construtor" geral 
void Jogador::Init(){
	
	soldado0 = (Soldado *) malloc(sizeof(Soldado));
	soldado0->prox = NULL;
	dinheiro = DINHEIRO;
	envioSold.Atualiza();
	esperaIni.Atualiza();
	vida = VIDA;
	lado = NULL;
}

//=================================================================
// Chama o construtor geral e também passa dados específicos
void Jogador::Init(char *meuLado){
	
	Init();
	lado = meuLado;	
	if(meuLado == LADO1)
		meuLider.Init("Roosevelt");
		
	else if(meuLado == LADO2)
		meuLider.Init("Stalin");

	else
		meuLider.Init("Hitler");
	
}
