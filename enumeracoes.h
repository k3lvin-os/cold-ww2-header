
// Indica o gameplay
enum TipoGameplay{
	SINGLEPLAYER,MULTIPLAYER
};


// Indica o tipo de mensagem de dados
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
	SAIR
};


enum LeituraIPEPorta{
	SEM_LEITURA = 0,
	LEITURA_IP,
	LEITURA_PORTA
};
