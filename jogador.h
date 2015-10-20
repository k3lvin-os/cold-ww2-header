
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

	// Cabe�a da lista encadeada de soldados do jogador
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
				Fun��es
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
// Mostra a interface com o usu�rio do jogador
void Jogador::MostraGUI(){
		
	Soldado GUISold;
	
	char textDin[19] = "Dinheiro: ";
	char buffer[8];
	itoa(dinheiro,buffer,10);
	strcat(textDin,buffer);
	
	if(lado == LADO2){
		
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
// Trabalha com a intera��o com a GUI
void Jogador::InputGUI(){
	
	int mouseX, mouseY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80){
		mouseX = mousex();
		mouseY = mousey();
		
		if(mouseX >= GUIEuaX && mouseX <= GUIEuaX + TILE_W &&
		mouseY >= GUIEuaY && mouseY <= GUIEuaY + TILE_H) {
			
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
// Chama o construtor geral e tamb�m passa dados espec�ficos
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
