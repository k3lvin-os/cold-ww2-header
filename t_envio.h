
/*Recebe e atualiza o tempo de envio de soldados*/
struct T_Envio{
	
	// Marcador de tempo
	time_t marcador;
	
	// Função
	bool Valida();
	
	// "Construtor"
	void Init();
	

};

// Inicializa o marcador de tempo
void T_Envio::Init(){
	time(&marcador);
}

// Valida o envio do soldado
bool T_Envio::Valida(){
	
	bool envia;
	
	// Calcula o horário atual
	time_t agora;
	time(&agora);
	
	// Se se o tempo de delay passou
	if(difftime(agora,marcador) >= S_DELAY){
			
			// Envia o soldado
			time(&marcador);
			envia = true; 
	}
	// Caso contrário, não envia
	else
		envia = false;
		
	return envia;
}




