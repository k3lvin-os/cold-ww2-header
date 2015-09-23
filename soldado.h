
struct Soldado{
	//==========================================================================
	// Propriedades
	
	// Vida do soldado ('0' � igual a morte)
	int vida;
	
	// Sprite ou imagem atual do soldado  
	int imgAtual;
	
	// Coordenadas
	int x, y;
	
	// Nome do soldado
	char *nome;
	
	// Indica se o p� que o personagem utiizou por ultimo para se movimentar
	char peh;
	
	// Rela��o entre tipo de sprite e valor
	enum NomeSprit{ FRENTE1 = 0, FRENTE2, FRENTE3,
 	BAIXO1, BAIXO2, BAIXO3,
	  ESQRD1,ESQRD2,ESQRD3,
	   DIREITA1,DIREITA2,DIREITA3,
	    numSprit
	};
	
	// Indices necess�rios para armazenar as imagens dos solados
	static const int QTD_IMG = numSprit;
	
	// Imagens (ou sprites) do soldado
	void *imagens[QTD_IMG];
	
	//=============================================================================
	
	// Fun��es
	void Carrega(char rPath[]);
	void GoTo(int novoX, int novoY);
	void MoveTo(int destX, int destY);
	void TrocaImg();
};


//===========================================================================
// Carrega todas imagens do soldado atrav�s do caminho relativo
// a partir da pasta assets
void Soldado::Carrega(char rPath[]){
	
	int i;
	
	// Cria uma vari�vel do tipo Sprite, a fim de usar uma fun��o
	Sprite imgHandl;

	// Caminho para acessar a pasta com os sprites
	char caminho[70]; 
	
	// Vari�vel tempor�ria que recebe o o indice do loop em char array
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){

		
		// O caminho exato - com o numero do sprite - ainda n�o foi calculado
		// Ent�o copie o caminho para a pasta assets
		strcpy(caminho,ASSETS);
		
		// Agora, adicione o caminho relativo (argumento que foi passado)
		strcat(caminho,rPath);
		
		// Verifica se o n�mero do sprite � menor que 10 (dois algarismos)
		if(i < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(caminho,"0");
		}
		
		// Converte o indice do contador para o formato "humano" (+ 1) - a partir do '0') 
		//para char array
		itoa(i + 1,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(caminho,temp);
		
		// Adicione a especifica��o de arquivo bitmap
		strcat(caminho,BITMAP);
		
		// Teste
		std::cout << caminho << "\n"; 
		
		// Recebe a imagem especificada pelo caminho
		imgHandl.GetImage(&imagens[i],caminho,TILE_W,TILE_H);
		
	}
}  

//========================================================================
void Soldado::TrocaImg(){
	
	int indiceH, iImg;
	
	// Faz a troca do indice da imagem atual para o indice humano
	indiceH = imgAtual + 1;
	
	// Calcula o indice de imagem
	iImg = indiceH % 3; 
	
	// Verifica o indice de imagem e atribui o valor conforme ele
	switch(iImg){
		case 1:
			imgAtual += + 1;
			break;
		case 2:
			
			// Verifica o p� que o soldado utilizou por �ltimo
			if(peh == 'd'){
				imgAtual -= 1;
				peh = 'e';
			} else{
				imgAtual += 1;
				peh = 'd';
			}
			break;
		case 3:
		imgAtual -= 1;
		break;		
	}
}
