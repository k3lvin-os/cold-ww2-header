




struct Jogador{
	
	/*=========================
			Constantes
	===========================*/
	static const int DINHEIRO = 100;
	static const int VIDA = 100;

	
	/*=========================
			Propriedades
	===========================*/
	
	// Cabeça da lista encadeada de inimigos
	Inimigo *inimigo0;
	
	// Cabeça da lista encadeada de soldados do jogador
	Soldado *soldado0;
	
	// Vida do jogador
	int vida;
	
	// Lado do jogador
	char* lado;
	
	// Marcador de tempo de envio de soldados
	T_Envio envioSold;
	
	// Dinheiro do jogador
	int dinheiro;	
	
	/*===========================
				Funções
	==============================*/
	
	void MostraGUI();
	void InputGUI();
	
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
		GUISold.Init("Eua");
		GUISold.GoTo(GUIEuaX,GUIEuaY);
		GUISold.Show();
		
		// Dinheiro do jogador
		outtextxy(MONEY_X,MONEY_Y,textDin );
	}
	
}

//=====================================================================
// Trabalha com a interação com a GUI
void Jogador::InputGUI(){
	
	int mouseX, mouseY;
	
	// Verifica o click do mouse
	if(GetKeyState(VK_LBUTTON) & 0x80){
		mouseX = mousex();
		mouseY = mousey();
		
		// Ícone do soldado dos EUA	
		if(mouseX >= GUIEuaX && mouseX <= GUIEuaX + TILE_W &&
		mouseY >= GUIEuaY && mouseY <= GUIEuaY + TILE_H) {
			
			// Valida o delay
			if(envioSold.Valida() == true){
				
				// Valida a compra
				if (soldado0->Compra(&dinheiro) == true){
						
					// Se tudo estiver certo, insere um novo soldado
					soldado0->Insere(soldado0,"Eua");
				}				
			}
		}
	}
}

//===============================================================
// "Construtor" geral 
void Jogador::Init(){
	
	inimigo0 = (Inimigo *) malloc(sizeof(Inimigo));
	inimigo0->prox = NULL;
	soldado0 = (Soldado *) malloc(sizeof(Soldado));
	soldado0->prox = NULL;
	dinheiro = DINHEIRO;
	envioSold.Init();
	vida = VIDA;
	lado = NULL;
}

//=================================================================
// "Construtor" específico
void Jogador::Init(char *meuLado){
	
	// Chama o constutor geral
	Init();
	
	// Passa os dados específicos
	lado = meuLado;
}
