
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
	int diferenca;
	//std::cout << "|tempoEspera =" << marcador << std::endl;
	time_t agora;
	time(&agora);
	diferenca = difftime(agora,marcador);
	/*std::cout << "Agora = " << agora << "\n";
	std::cout << "Diferenca = " << diferenca << "\n";
	*/
	
	if(diferenca >= delay){
		//std::cout << "TRUE\n";
		return true; 
	}	
	else{
		//std::cout << "FALSE\n";
		return false; 
	}
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
		case ONDA_IA1:
			onda = '6';
			break;
		case ONDA_IA2:
			onda = '7';
			break;
		case ONDA_IA3:
			onda = '8';
			break;
		case END:
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

