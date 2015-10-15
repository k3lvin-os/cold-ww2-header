
/*Trabalha com o delay para algumas funcionanlidades do jogo*/
struct TDelay{
	
	// Marcador de tempo
	time_t marcador;
	
	// Fun��o
	bool Valida();
	
	// "Construtor"
	void Init();
	

};

// Inicializa o marcador de tempo
void TDelay::Init(){
	time(&marcador);
}

// Valida o envio do soldado
bool TDelay::Valida(){
	
	bool envia;
	
	// Calcula o hor�rio atual
	time_t agora;
	time(&agora);
	
	// Se se o tempo de delay passou
	if(difftime(agora,marcador) >= S_DELAY){
			
			// Envia o soldado e reinicia o marcador
			envia = true; 
			time(&marcador);
	}
	// Caso contr�rio, n�o envia
	else
		envia = false;
		
	return envia;
}
