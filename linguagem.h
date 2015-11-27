
// Idiomas do jogo
enum Idioma{
	PORTUGUES,
	INGLES,
	qtdIdioma
};

struct Linguagem{
	
	// Indica a quantidade de textos que o jogo contém
	static int const QTD_TEXTO_JOGO = /* ? */ ;
	
	// Armazena os textos do jogo 
	char *texto[qtdIdioma][qtdTextoJogo];
	int escolhaIdioma;
	
	
	//Funções
	char* Texto();
	
	// "Construtor"
	void Init(Idioma escolha);
	bool CarregaIdioma(char *arquivoIdioma);
	
	
};


// Carrega a linguagem do jogo
void Linguagem::Init(Idioma escolha){
	
	if(escolha == PORTUGUES)
		CarregaIdioma("pt-br.txt");	
	
	else if(escolha == INGLES)
		CarregaIdioma("en.txt");		
}

// Carrega um idioma a partir de um arquivo de idioma
bool Linguagem::CarregaIdioma(char *arquivoIdioma){
	std::ifstream leitor;
	char c;
	bool recebeTxt, recebeNTxt;
	char buffer[50], temp[2], nTextoChar[4] ;
	int nTexto;
	
	leitor.open(arquivoIdioma);
	
	
	if(!leitor.is_open())
		return false;
	
	texto = UNDEFINED_TEXT;
	recebeTxt = false;
	recebeNTxt = false;
	nTexto = NULL;
	strcpy(temp,"");
	while(leitor.get(c)){
	
		
		if(c == '_' ){
			
			recebeNTxt = true;	
		}
		
		else if(recebeNTxt == true){
			
			if( c >= 48 && c <= 57){
				temp[0] = c;
				temp[1] = '\0';	
				strcat(nTextoChar,temp);		
			}
			
			else
				nTexto = atoi(nTextoChar);	
		} 
		
		else if(c == '\"'){
			
			if(recebeTxt == false){
				recebeTxt = true;
			} 
			
			else{
				
				
			}
			
			
		}

	}
	
	return true;
	
}



