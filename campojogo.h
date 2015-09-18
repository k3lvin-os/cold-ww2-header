// Este é o cenário principal do jogo
struct CampoJogo{
	
	// Posição dos tiles
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite *tipoTile;	

	// Funções
	void Mostrar(); 
	void Console();
	void Arquiva(char nomeArq[8]);
	void Zera(int tileZero);
	void TileLoad();
	bool PosLoad(char nomeArq[8]);
	
	
	//Construtores
	CampoJogo();
	CampoJogo(char nomeArq[8]);
	
	//Destrutor (padrão)
	~CampoJogo(){
	}	
};

void CampoJogo::Zera(int tileZero){
	
	// Preenche todas posições da matriz com o valor passado
	memset(posTile,tileZero,sizeof (posTile));
}


// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	int j, i,  meuTipo, x,y;
	
	int tecla = 0; // teste
	
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			// "Qual é o tipo do tile nos indices atuais"
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			
			// Coloca o tile na tela
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}

// Arquiva a matriz de coordenadas dos tiles (cria um arquivo com nome dado e o conteúdo citado)
void CampoJogo::Arquiva(char nomeArq[8]){
	
	// Contadores
	int i, j;	
	
	// Mainpulador de arquivos	
	std::ofstream escreve;
	
	// Abre o arquivo
	escreve.open(nomeArq);
	
	// Escreve o conteúdo da matriz de posições no arquivo
	for(i = 0; i < TILE_QTDY; i++){
		for(j = 0; j < TILE_QTDX; j++){

			// Escreve a posição e separa o conteúdo
			escreve << posTile[j][i];
			escreve << "|"; 

		}
	}

	//Fecha o arquivo
	escreve.close();
	
	
}


// Imprime a posição dos tiles no console
void CampoJogo::Console(){
		
	int i, j;
	
	for(i = 0; i < TILE_QTDY; i++){
		
		std::cout << "\nColuna " << i << std::endl; 
		for(j = 0; j < TILE_QTDX; j++){
			std::cout << posTile[j][i] << "|";
		}
		
	}
	
}

//Construtor  
CampoJogo::CampoJogo(char nomeArq[8]){

		// Carrega os tiles
		TileLoad();
		
		// Carrega a posição dos tiles
		PosLoad(nomeArq);
}

// Construtor que apenas carrega os tiles
CampoJogo::CampoJogo(){
	
	// Zera a matriz com o tile preto
	Zera(T_PRETO);
	
	// Carrega os tiles
	TileLoad();
}
	



// Carrega os tipos de tiles do campo de jogo	
void CampoJogo::TileLoad(){
	
	// Aloca espaço para os membros do array de estrutura
	tipoTile = (Sprite *) malloc(sizeof(Sprite) * QTD_TIPO);
	
	// Carregue os sprites de campo
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLUE); // Muralha
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN); // Caminho
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE); // Campo da URSS
	tipoTile[3].BasicTile(TILE_W,TILE_H, LIGHTGREEN); // Campo dos EUA e Aliados
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW); // Base
	tipoTile[5].BasicTile(TILE_W,TILE_H, BLACK); // HUD inferior
}

bool CampoJogo::PosLoad(char nomeArq[8]){
			
	// Leitor de arquivos
	std::ifstream leitor;
	
	// Leitor de caracteres dos arquivos
	char c;
	
	// Avalia se todas as coordenadas da matriz foram preenchidas
	bool mtxCheia = false;
	
	// Contadores
	int i, j;
	
	// Variável que recebe o valor da posição em formato char 
	char temp[4] = "   ";
	
	// Contador para a variável temp
	int  tempPos = 0;
	
	// Abre o arquivo
	leitor.open(nomeArq);
	
	// Verifica se o arquivo NÃO foi aberto
	if(!leitor.is_open()){
		std::cout << "Não foi possível abrir o arquivo " << nomeArq[8];
		return false;
	}
	 else{
		
	
		i = 0;  // Contadores para alocar corretamente as posições
		j = 0;
		
		// Lê os caracteres até chegar no fim do arquivo
		while(leitor.get(c) && mtxCheia!= true ){
			
			// Verifique se o char é um valor númerico na tabela ASC
			if (c >= 48 && c <= 57 ){
				
				// Recebe o caracter
				temp[tempPos] = c;
				
				// Vai para o próximo indice do array de char
				tempPos++;
			} 
			
			// Caso for um separador
			else if(c == '|'){
				
				// Converte e Transfere o valor para a matriz de posições de tiles (matriz de inteiros)
				posTile[j][i] = atoi(temp);
			    
				// Zera o conteúdo da variável temporária
				strcpy(temp, "   ");
				
				// Retorna para o primeiro indice do array temporário
				tempPos = 0;
			    
			    // Vai para a próxima coluna
			    j++;
		
				// Verificações de fim de dos indices
			    if(j == TILE_QTDX){
					
					j = 0;
			    	i++;
			    	
					if(i == TILE_QTDY)
						mtxCheia = true; // Isso faz o programa sair do laço de leitura
					
				}
				
			}
			
		}
		
		// Fecha o arquivo
		leitor.close();
		
		return true;
			
	}
}
	
	


		
	



