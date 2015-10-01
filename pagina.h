// Estrutura que facilita o uso de p�gina ativa e p�gina visual
struct Pagina{
	
	// N�mero da p�gina
	int pg;
	
	// Fun��es
	int GetPagina();
	void Ativa();
	void Visual();
	void Troca();
	
	// "Construtor"
	void Init();
};

// Inicializa a p�gina
void Pagina::Init(){
	pg = 1;
}

// Recebe a p�gina atual
int Pagina::GetPagina(){
	return pg;
}

// Deixa a p�gina em modo visual (com visualiza��o na tela)
void Pagina::Visual(){
	setvisualpage(pg);
}

// Troca a p�gina atual
void Pagina::Troca(){
	
	if(pg == 1){
		pg = 2;
	} else{
		pg = 1;
	}
}

// Deixa a p�gina em modo ativo (sem a visualiza��o na tela)
void Pagina::Ativa(){
	setactivepage(pg);
}

