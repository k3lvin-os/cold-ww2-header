
struct Soldado{
	
	// Propriedades
	
	// Relação entre tipo de sprite e valor
	enum NomeSprit{ FRENTE1 = 0, FRENTE2, FRENTE3,
 	BAIXO1, BAIXO2, BAIXO3,
	  ESQRD1,ESQRD2,ESQRD3,
	   DIREITA1,DIREITA2,DIREITA3,
	    numSprit
	};
	
	// Indices necessários para armazenar as imagens dos solados
	static const int QTD_IMG = numSprit;
	
	// Imagens (ou sprites) do soldado
	void *imagens[QTD_IMG];
	
	// Funções
	void Carrega(char rPath[]);
};



// Carrega todas imagens do soldado através do caminho relativo
// a partir da pasta assets
void Soldado::Carrega(char rPath[]){
	
	int i;
	
	// Cria uma variável do tipo Sprite, a fim de usar uma função
	Sprite imgHandl;

	// Caminho para acessar a pasta com os sprites
	char caminho[70]; 
	
	// Variável temporária que recebe o o indice do loop em char array
	char temp[3]; 
				
	for(i = 0; i < QTD_IMG; i++){

		
		// O caminho exato - com o numero do sprite - ainda não foi calculado
		// Então copie o caminho para a pasta assets
		strcpy(caminho,ASSETS);
		
		// Agora, adicione o caminho relativo (argumento que foi passado)
		strcat(caminho,rPath);
		
		// Verifica se o número do sprite é menor que 10 (dois algarismos)
		if(i < 10){
			
			// Se sim, acresenta-se um '0'
			strcat(caminho,"0");
		}
		
		// Converte o indice do contador para o formato "humano" (+ 1) - a partir do '0') 
		//para char array
		itoa(i + 1,temp,DECIMAL);
		
		// Acresenta esse valor
		strcat(caminho,temp);
		
		// Adicione a especificação de arquivo bitmap
		strcat(caminho,BITMAP);
		
		// Teste
		std::cout << caminho << "\n"; 
		
		// Recebe a imagem especificada pelo caminho
		imgHandl.GetImage(&imagens[i],caminho,TILE_W,TILE_H);
		
	}
}  
