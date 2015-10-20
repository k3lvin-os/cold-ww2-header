
/*Trabalha com o delay para algumas funcionanlidades do jogo*/
struct TDelay{
	
	// Marcador de tempo
	time_t marcador;
	
	// Função
	bool PassouDelay(int delay);
	char SoldOnda();
	int GameTime();
	bool VerificaFuria();
	
	// Atualiza o timer
	void Atualiza();
	

};

// Atualiza o marcador de tempo
void TDelay::Atualiza(){
	time(&marcador);
}






// Valida o delay 
bool TDelay::PassouDelay(int delay){
	
	bool passou;
	time_t agora;
	time(&agora);
	int diferenca = (int ) difftime(agora,marcador);
	
	if(diferenca >= delay)	
		return true; 
	else
		return false; 
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
		case ONDA5:
			onda = '5';
			break;
		case ONDA6:
			onda = '6';
			break;
		case ONDA7:
			onda = '7';
			break;
		case ONDA8:
			onda = '8';
			break;
		case ONDA9:
			onda = '9';
			break;
		case ONDA10:
			onda = '10';
			break;
		case ONDA11:
			onda = '11';
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

