
/*Trabalha com o delay para algumas funcionanlidades do jogo*/
struct TDelay{
	
	// Marcador de tempo
	time_t marcador;
	
	// Função
	bool DelayEnvio();
	char SoldOnda();
	int GameTime();
	bool DelayFuria();
	
	// "Construtor"
	void Init();
	

};

// Inicializa o marcador de tempo
void TDelay::Init(){
	time(&marcador);
}

// Valida o delay de envio de personagem
bool TDelay::DelayEnvio(){
	
	
	// Calcula o horário atual
	bool envia;
	time_t agora;
	time(&agora);
	
	// Se o tempo de delay passou
	if(difftime(agora,marcador) >= ESPERA_DELAY){
			
			// Envia o soldado e reinicia o marcador
			envia = true; 
			time(&marcador);
	}
	// Caso contrário, não envia
	else
		envia = false;
		
	return envia;
}


//=======================================================================
// Verifica e retorna se é hora de mandar uma onda de soldados (Eixo IA)
char TDelay::SoldOnda(){
	
	int gTimeInt;
	char onda;


	gTimeInt = GameTime();
	
	switch(gTimeInt){
		case BEGIN:
			onda = '0';
			break;
		case ONDA1:
			onda = '1';
			break;
		case ONDA2:
			onda = '2';
			break;
		case ONDA3:
			onda = '3';
			break;
		case ONDA4:
			onda = '4';
			break;
		case ONDAF:
			onda = 'F';
			break;
		default:
			onda = SEM_ONDA;
	}
	return onda;
}


/*Calcula quanto tempo se passou desde que o marcador começou a marcar o tempo */
int TDelay::GameTime(){
	time_t agora;
	int gTimeInt;
	double gameTime;
	
	time(&agora);
	gameTime = difftime(agora,marcador);
	gTimeInt = (int) gameTime;
	
	return gTimeInt;
}

