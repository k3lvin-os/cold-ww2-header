// Este � o cen�rio principal do jogo
struct CampoJogo{
	
	// Posi��o dos tiles
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite *tipoTile;	

	// Fun��es
	void Mostrar(); 
	void Console();
	void Arquiva(char nomeArq[8]);
	
	// Construtor (padr�o)
	CampoJogo(char nomeArq[8]);	
};


// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	int j, i,  meuTipo, x,y;
	
	int tecla = 0; // teste
	
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			// "Qual � o tipo do tile nos indices atuais"
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			
			// Coloca o tile na tela
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}

// Arquiva a matriz de coordenadas dos tiles (cria um arquivo com nome dado e o conte�do citado)
void CampoJogo::Arquiva(char nomeArq[8]){
	
	// Contadores
	int i, j;
	
	char temp[4];
	
	
	// Mainpulador de arquivos	
	std::ofstream escreve;
	
	// Abre o arquivo
	escreve.open(nomeArq);
	
	// Escreve o conte�do da matriz de posi��es no arquivo
	for(i = 0; i < TILE_QTDY; i++){
		for(j = 0; j < TILE_QTDX; j++){

			// Escreve a posi��o e separa o conte�do
			escreve << posTile[i][j];
			escreve << "|"; 

		}
	}
	
	//Fecha o arquivo
	escreve.close();
	
	
}


// Imprime a posi��o dos tiles no console
void CampoJogo::Console(){
		
	int i, j;
	
	for(i = 0; i < TILE_QTDY; i++){
		
		std::cout << "\nColuna " << i << std::endl; 
		for(j = 0; j < TILE_QTDX; j++){
			std::cout << posTile[j][i] << "|";
		}
	}
	
}

// Construtor padr�o 
CampoJogo::CampoJogo(char nomeArq[8]){
		
	// Leitor de arquivos
	std::ifstream leitor;
	
	// Leitor de caracteres dos arquivos
	char c;
	
	// Avalia se todas as coordenadas da matriz foram preenchdias
	bool mtxCheia = false;
	
	// Contadores
	int i, j;
	
	// Vari�vel que recebe o valor da posi��o em formato char 
	char temp[4] = "   ";
	
	// Contador para a vari�vel temp
	int  tempPos = 0;
	
	// Aloca espa�o para os membros do array de estrutura
	tipoTile = (Sprite *) malloc(sizeof(Sprite) * QTD_TIPO);
	
	// Carregue os sprites de campo
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].BasicTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].BasicTile(TILE_W,TILE_H, BLACK); // HUD inferior
	
	// Abre o arquivo
	leitor.open(nomeArq);
	
	// Verifica se o arquivo N�O foi aberto
	if(!leitor.is_open()){
		std::cout << "N�o foi poss�vel abrir o arquivo " << nomeArq[8];
	}
	 else{
		
	
		i = 0;  // Contadores para alocar corretamente as posi��es
		j = 0;
		
		// L� os caracteres at� chegar no fim do arquivo
		while(leitor.get(c) && mtxCheia!= true ){
			
			// Verifique se o char � um valor n�merico na tabela ASC
			if (c >= 48 && c <= 57 ){
				
				// Recebe o caracter
				temp[tempPos] = c;
				
				// Vai para o pr�ximo indice do array de char
				tempPos++;
			} 
			
			// Caso for um separador
			else if(c == '|'){
				
				// Converte e Transfere o valor para a matriz de posi��es de tiles (matriz de inteiros)
				posTile[i][j] = atoi(temp);
			    
				// Zera o conte�do da vari�vel tempor�ria
				strcpy(temp, "   ");
			    
			    // Vai para a pr�xima coluna
			    j++;
		
				// Verifica��es de fim de dos indices
			    if(j == (TILE_QTDX - 1)){
			    	j = 0;
			    	i++;
				}
				
				if(i == (TILE_QTDY - 1)){
					mtxCheia = true; // Isso faz o programa sair do la�o de leitura
				}
				
				// Retorna para o primeiro indice do array tempor�rio
				tempPos = 0;
				
			}
			
		}
		
		// Fecha o arquivo
		leitor.close();
		
		}
	}
	
	


		
	



