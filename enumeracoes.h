
// Indica o gameplay
enum TipoGameplay{
	SINGLEPLAYER,MULTIPLAYER_ONLINE, MULTIPLAYER_SPLIT, TUTORIAL_SPLIT
};


// Indica o tipo de mensagem 
enum TipoPacote{
	SEM_TIPO = 0,
	LIDER_SERV,
	GAMESPEED,
	CLIENT_OK,
	SERVER_OK,
	NEW_SOLD,
	TORRE,
	DANO
};

enum TipoCursor
{
	C_SELETOR,
	C_TORRE,
	C_SOLDADO
};


// Indica o menu de jogo
enum EscolhaEmMenu{
	SEM_ESCOLHA = 0, 
	MENU,
	UM_JOGADOR, 
	DOIS_JOGADORES,
	CREDITOS, 
	MENU_UM_JOG,	
	MENU_DOIS_JOG,
	MENU_CLIENTE,
	MENU_SERVIDOR,
	MENU_SPLITSCREEN,
	SPLITSCREEN,
	SAIR
};

// Indica o tipo de leitura de ip e porta
enum LeituraIPEPorta{
	SEM_LEITURA = 0,
	LEITURA_IP,
	LEITURA_PORTA
};
