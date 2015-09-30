// Este é o cenário principal do jogo
struct CampoJogo{
	
	// Qtd. padrão de tiles de campo de jogo
	static const int QTD_TILE = 16;
	
	// Matriz do Campo de Jogo com o tipo de tile de cada posição
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite tipoTile[QTD_TILE];	

	// Funções
	void Mostrar(); 
	void Console();
	void Arquiva(char nomeArq[8]);
	void Zera(int tileZero);
	void TileLoad();
	bool PosLoad(char nomeArq[8]);

	//"Construtores" 
	void Init();
	void Init(char nomeArq[8]);

};

//=========================================================================


// Preenche o campo de jogo com um tile básico
void CampoJogo::Zera(int tileZero){
	
	int i, j;
	
	// Preenche todas posições da matriz com o valor passado	
	for( i =0; i < TILE_QTDY; i++){
		for(j = 0; j < TILE_QTDX; j++){
			posTile[j][i] = tileZero;
		}
	}
}

//=========================================================================

// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	
	int j, i,  meuTipo, x,y;
		
	// Laço para percorrer a matriz de tiles de campo de jogo
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			// "Qual é o tipo do tile no indice atual"
			meuTipo = posTile[j][i];
	
			// A posição do tile está em função do indice do tile
			x = j * TILE_W;
			y = i * TILE_H;
			
			// Coloca o tile na tela
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}

//=========================================================================


// Arquiva a matriz de coordenadas dos tiles (cria um arquivo com nome dado e o conteúdo citado)
void CampoJogo::Arquiva(char *nomeArq){
	
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
	
	std:: cout << "\nArquivo gravado com sucesso!\n";
}


//=========================================================================


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

//=========================================================================


//"Construtor" que recebe o nome do arquivo  
void CampoJogo::Init(char nomeArq[8]){
		
		// Carrega os tiles
		TileLoad();
		
		// Carrega a posição dos tiles
		PosLoad(nomeArq);
}

//=========================================================================


// "Construtor" que apenas carrega os tiles
void CampoJogo::Init(){
	
	// Tile preto para "zerar" o campo de jogo
	const int T_PRETO = 0;
	
	// Zera a matriz com o tile preto
	Zera(T_PRETO);
	
	// Carrega os tiles
	TileLoad();
}


//=========================================================================
	

// Carrega os tipos de tiles do campo de jogo	
void CampoJogo::TileLoad(){
	
	/*
			INFORMAÇÕES PARA ACRESENTAR TILES
		- Primeiramente, aumente o tamanho do array. O número do array
		deve ser igual a quantidade de tiles que você vai armazenar
		
		- Após isso, use BasicTile, caso você queira criar protótipos de tiles
		,e use Init para criar tiles com imagens bitmpas criados por você
		
		- Não se esqueça de ter uma pasta chamada Assets. ELa deve estar
		no mesmo local que o caminho dos tiles que usam Init, como mostra os 
		exemplos abaixo. E, obviamente,	ela deve conter
	    os bitmaps que você especifica no nosso "construtor" Init
	
	*/
	
	tipoTile[0].BasicTile(TILE_W,TILE_H, BLACK, "Preto"); 
	tipoTile[1].BasicTile(TILE_W,TILE_H, BROWN, "Marrom"); // Tiles de protótipo
	tipoTile[2].BasicTile(TILE_W,TILE_H, WHITE, "Branco"); 
	tipoTile[3].BasicTile(TILE_W,TILE_H, RED,"Vermelho");
	tipoTile[4].BasicTile(TILE_W,TILE_H, YELLOW, "Amarelo"); 
	
	// Carregue os sprites de campo
	tipoTile[5].Init("../../Assets/Campo/eua.bmp","Campo do EUA e Aliados",TILE_W,TILE_H);
	tipoTile[6].Init("../../Assets/Campo/urss.bmp","Campo da URSS", TILE_W, TILE_H);
	tipoTile[7].Init("../../Assets/Campo/muro.bmp","Muro de Tijolos Brancos",TILE_W,TILE_H);
	tipoTile[8].Init("../../Assets/Campo/rota.bmp","Rota dos Soldados",TILE_W,TILE_H);
	tipoTile[9].Init("../../Assets/Campo/sacos1.bmp","Trincheira - Baixo",TILE_W,TILE_H);
	tipoTile[10].Init("../../Assets/Campo/sacos2.bmp","Trincheira - Grama",TILE_W,TILE_H);
	tipoTile[11].Init("../../Assets/Campo/sacos3.bmp","Trincheira - Neve",TILE_W,TILE_H);
	tipoTile[12].Init("../../Assets/Campo/torre1.bmp","Torre EUA - Cima",TILE_W,TILE_H);
	tipoTile[13].Init("../../Assets/Campo/torre2.bmp","Torre EUA - Baixo",TILE_W,TILE_H);
	tipoTile[14].Init("../../Assets/Campo/torre3.bmp","Torre URSS - Cima",TILE_W,TILE_H);
	tipoTile[15].Init("../../Assets/Campo/torre4.bmp","Torre URSS - Baixo",TILE_W,TILE_H);
	
	

}

//=========================================================================


// Carrega a matriz do campo de jogo com os dados de um arquivo
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
	
	


		
	



