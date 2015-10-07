
/*==================================================
					ARQUIVADO
====================================================*/

/*Lista encadeada de tropas*/
struct Tropa{
	
	/*==================
	Propriedades
	====================*/
	
	// Array com os soldados
	Soldado tropa[MAXTROPA];
	
	// Cronometro para verifica��o de tempo da tropa
	time_t marcador;
	
	// Pr�xima c�lula da lista encadeada
	Tropa *prox;
	
	/*====================
	Fun��es
	======================*/
	void Init(char *tipo);
	void Enviar(Tropa *cabeca, CampoJogo meuCampo);
	Tropa* Insere(char *tipo);
	void Remove(Tropa *anterior);
	
};


// "Construtor" que recebe o tipo de soldado como par�metro 
void Tropa::Init(char *tipo){

	int i;
	for(i = 0; i < MAXTROPA; i++){
		tropa[i].Init(tipo);
	}
}

// Direciona as tropas at� o alvo (deve ser utilizado na cabe�a da lista)
void Tropa::Enviar(Tropa *cabeca, CampoJogo meuCampo){
	Tropa *t;
	int i;
	time_t agora;
	
	// La�o das tropas
	for(t = cabeca->prox; t != NULL; t = t->prox){
		
		// La�o dos soldados das tropas
		for(i = 0; i < MAXTROPA; i++){
			
			// Se soldado N�O saiu do ponto visivel
			if(t->tropa[i].saiu == false){
				
				// Calcula a hora atual
				time(&agora);
				
				//Se o  delay j� passou
				if(difftime(agora,marcador) >= S_DELAY){
					
					// Indica a sa�da do soldado
					t->tropa[i].saiu = true;
					
					
				}
						
			}
			
			// Se o soldado saiu do ponto visivel
			if(t->tropa[i].saiu = true){
				
				// Mostra o soldado
				t->tropa[i].Show();
				
				// Permite o comportamento da IA
				t->tropa[i].IA(meuCampo);
				
			}
			
		}
		
		
		
	}	
	
	
}

// Cria uma nova tropa ap�s a tropa atual na lista encadeada
Tropa* Tropa::Insere(char * tipo){
	Tropa *nova;
	nova = (Tropa *) malloc(sizeof(Tropa));
	nova->Init(tipo); // Prepara os soldados
	time(& (nova->marcador)); // Inicia o contador
	nova->prox = prox;
	prox = nova;
	
	// Retorna a nova tropa
	return nova;
}

// Remove uma tropa (� necess�rioa passar a tropa anterior como par�metro)
void Tropa::Remove(Tropa *anterior){
	Tropa *perda;
	perda = anterior->prox;
	anterior->prox = perda->prox;
	free(perda);
}







