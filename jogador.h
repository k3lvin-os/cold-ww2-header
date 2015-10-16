
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
		
	Soldado GUISold;
	
	char textDin[19] = "Dinheiro: ";
	char buffer[8];
	itoa(dinheiro,buffer,10);
	strcat(textDin,buffer);
	
	if(lado == LADO1){
		
		// Soldado dos EUA
		GUISold.Init("Urss");
		GUISold.GoTo(GUIEuaX,GUIEuaY);
		GUISold.Show();
		
		// GUI do Dinheiro
		setcolor(GREEN);
		settextstyle(BOLD_FONT, HORIZ_DIR, 1);
		outtextxy(MONEY_X,MONEY_Y,textDin );
	}
	
}

//=====================================================================
// Trabalha com a interação com a GUI
void Jogador::InputGUI(){
	
	int mouseX, mouseY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80){
		mouseX = mousex();
		mouseY = mousey();
		
		// DelayEnvio click no icone do soldado da URSS
		if(mouseX >= GUIEuaX && mouseX <= GUIEuaX + TILE_W &&
		mouseY >= GUIEuaY && mouseY <= GUIEuaY + TILE_H) {
			
			// DelayEnvio o delay
			if(envioSold.DelayEnvio() == true){
				
				// DelayEnvio a compra
				if (soldado0->Compra(&dinheiro) == true){
						
					// Se tudo estiver certo, insere um novo soldado
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
	envioSold.Init();
	esperaIni.Init();
	vida = VIDA;
	lado = NULL;
}

//=================================================================
// Chama o construtor geral e também passa dados específicos
void Jogador::Init(char *meuLado){
	
	Init();
	lado = meuLado;	
}
