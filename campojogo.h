// Este é o cenário do gameplay do jogo
struct CampoJogo{
	
	// Qtd. padrão de tiles de campo de jogo
	static const int QTD_TILE = 30;
	
	// Matriz do Campo de Jogo com o tipo de tile de cada posição
	int posTile[TILE_QTDX][TILE_QTDY]; 
	
	// Tipos de tiles (sprites de tiles)
	Sprite tipoTile[QTD_TILE];	

	// Funções
	void Mostrar();
	void Mostrar(int tX0,int tY0,int tXF,int tYF);
	void Console();
	void Arquiva(char nomeArq[8]);
	void Zera(int tileZero);
	void TileLoad();
	bool PosLoad(char nomeArq[8]);
	bool PosExist(int tileX, int tileY);
	bool Caminho(int tileX, int tileY);
	void LimpaD();
	void LimpaMem();

	//"Construtores" 
	void Init();
	void Init(char nomeArq[8]);

};
//=========================================================================

// Limpa a memória que foi alocada dinamicamente 
// aos membros da struct CampoJogo
void CampoJogo::LimpaMem(){
	
	free(tipoTile);
}



//=========================================================================

// Limpa a zona de carregamento de imagens
void CampoJogo::LimpaD(){

	Mostrar(0,0,4,4); // Intervalo de tiles de desenho
}
//=========================================================================

// Verifica se o tile corresponde a um tile de caminho ou não
bool CampoJogo::Caminho(int tileX, int tileY){

	bool caminho;
	
	if(posTile[tileX][tileY] >= 18 && posTile[tileX][tileY] <= 29 )
		caminho  = true; 
	else 
		caminho = false;
	
	return caminho;
}

//=========================================================================


// Preenche o campo de jogo com um tile básico
void CampoJogo::Zera(int tileZero){
	
	int i, j;
	
	for( i =0; i < TILE_QTDY; i++){
		for(j = 0; j < TILE_QTDX; j++)
			posTile[j][i] = tileZero;
		
	}
}

//=========================================================================

// Coloca os sprites na tela
void CampoJogo::Mostrar(){
	
	int j, i,  meuTipo, x,y;
		
	for(i = 0; i < TILE_QTDY; i++){ 
	
		for(j = 0; j < TILE_QTDX; j++) { 
			
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}
//=========================================================================

// Coloca os sprites de campo apenas aonde determinado
void CampoJogo::Mostrar(int tX0,int tY0,int tXF,int tYF){
	
	int j, i,  meuTipo, x,y;
		
	for(i = tY0; i < tYF; i++){ 
	
		for(j = tX0; j < tXF; j++) { 
			
			meuTipo = posTile[j][i];
	
			x = j * TILE_W;
			y = i * TILE_H;
			
			putimage(x,y,tipoTile[meuTipo].image,0);
		}
	
	}
}



//=========================================================================


// Arquiva a matriz de coordenadas dos tiles
// (cria um arquivo com nome dado e o conteúdo citado)
void CampoJogo::Arquiva(char *nomeArq){
	
	int i, j;	
	
	std::ofstream escreve;
	
	escreve.open(nomeArq);
	
	for(i = 0; i < TILE_QTDY; i++){
		for(j = 0; j < TILE_QTDX; j++){

			escreve << posTile[j][i];
			escreve << "|"; 

		}
	}

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
		
		TileLoad();
		PosLoad(nomeArq);
}

//=========================================================================


// "Construtor" que apenas carrega os tiles
void CampoJogo::Init(){
	
	Zera(T_PRETO);
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
	
	// Sprites de campo
	tipoTile[5].Init("../../Assets/Campo/eua.bmp","Campo do EUA e Aliados",TILE_W,TILE_H);
	tipoTile[6].Init("../../Assets/Campo/urss.bmp","Campo da URSS", TILE_W, TILE_H);
	tipoTile[7].Init("../../Assets/Campo/muro.bmp","Muro de Tijolos Brancos",TILE_W,TILE_H);
	tipoTile[8].Init("../../Assets/Campo/rota0.bmp","Rota dos Soldados",TILE_W,TILE_H);
	tipoTile[9].Init("../../Assets/Campo/sacos1.bmp","Trincheira - Baixo",TILE_W,TILE_H);
	tipoTile[10].Init("../../Assets/Campo/sacos2.bmp","Trincheira - Grama",TILE_W,TILE_H);
	tipoTile[11].Init("../../Assets/Campo/sacos3.bmp","Trincheira - Neve",TILE_W,TILE_H);
	tipoTile[12].Init("../../Assets/Campo/cerca1.bmp","Cerca - Grama",TILE_W,TILE_H);
	tipoTile[13].Init("../../Assets/Campo/cerca2.bmp","Cerca 1 - Grama",TILE_W,TILE_H);
	tipoTile[14].Init("../../Assets/Campo/cerca3.bmp","Cerca 2 - Grama",TILE_W,TILE_H);
	tipoTile[15].Init("../../Assets/Campo/cerca4.bmp","Cerca - Neve",TILE_W,TILE_H);
	tipoTile[16].Init("../../Assets/Campo/cerca5.bmp","Cerca 1 - Neve",TILE_W,TILE_H);
	tipoTile[17].Init("../../Assets/Campo/cerca6.bmp","Cerca 2 - Neve",TILE_W,TILE_H);
	tipoTile[18].Init("../../Assets/Campo/rota1a.bmp","Rota - Horiz Grama",TILE_W,TILE_H);
	tipoTile[19].Init("../../Assets/Campo/rota2a.bmp","Rota - Verti Grama",TILE_W,TILE_H);
	tipoTile[20].Init("../../Assets/Campo/rota3a.bmp","Rota - Sup Esq Grama",TILE_W,TILE_H);
	tipoTile[21].Init("../../Assets/Campo/rota4a.bmp","Rota - Sup Dir Grama",TILE_W,TILE_H);
	tipoTile[22].Init("../../Assets/Campo/rota5a.bmp","Rota - Inf Esq Grama",TILE_W,TILE_H);
	tipoTile[23].Init("../../Assets/Campo/rota6a.bmp","Rota - Inf Dir Grama",TILE_W,TILE_H);
	tipoTile[24].Init("../../Assets/Campo/rota1b.bmp","Rota - Horiz Neve",TILE_W,TILE_H);
	tipoTile[25].Init("../../Assets/Campo/rota2b.bmp","Rota - Verti Neve",TILE_W,TILE_H);
	tipoTile[26].Init("../../Assets/Campo/rota3b.bmp","Rota - Sup Esq Neve",TILE_W,TILE_H);
	tipoTile[27].Init("../../Assets/Campo/rota4b.bmp","Rota - Sup Dir Neve",TILE_W,TILE_H);
	tipoTile[28].Init("../../Assets/Campo/rota5b.bmp","Rota - Inf Esq Neve",TILE_W,TILE_H);
	tipoTile[29].Init("../../Assets/Campo/rota6b.bmp","Rota - Inf Dir Neve",TILE_W,TILE_H);
	
	

}

//=========================================================================


// Carrega a matriz do campo de jogo com os dados de um arquivo
bool CampoJogo::PosLoad(char nomeArq[8]){
			
	std::ifstream leitor;
	char c;
	bool mtxCheia = false;
	int i, j;
	char temp[4] = "   ";
	int  tempPos = 0;
	
	leitor.open(nomeArq);
	
	if(!leitor.is_open()){
		std::cout << "Não foi possível abrir o arquivo " << nomeArq[8];
		return false;
	}
	else{
		
	
		i = 0;  
		j = 0;
		
		while(leitor.get(c) && mtxCheia!= true ){
			
			// Verifique se o char é um valor númerico na tabela ASC
			if (c >= 48 && c <= 57 ){
				
				temp[tempPos] = c;
				
				tempPos++;
			} 
			
			else if(c == '|'){
				
				posTile[j][i] = atoi(temp);
			 	strcpy(temp, "   ");
				tempPos = 0;
				j++;
		
			    if(j == TILE_QTDX){
					
					j = 0;
			    	i++;
			    	
					if(i == TILE_QTDY)
						mtxCheia = true; 
					
				}
				
			}
			
		}
		
		leitor.close();
		return true;
			
	}
}
//=========================================================================

// Verifica se a coordenada de tile é válida
bool CampoJogo::PosExist(int tileX, int tileY){
	
	bool existe;
	
	if( ( (tileX >= 0) && (tileX <= (TILE_QTDX - 1) ) )
	 && ( (tileY >= 0) && (tileY <= (TILE_QTDY - 1) ) ) )
	 	existe = true; 
	 else
	 	existe = false; 
	 	 
	 return existe; 
}	
	


		
	



