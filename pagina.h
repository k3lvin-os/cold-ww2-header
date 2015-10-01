// Estrutura que facilita o uso de página ativa e página visual
struct Pagina{
	
	// Número da página
	int pg;
	
	// Funções
	int GetPagina();
	void Ativa();
	void Visual();
	void Troca();
	
	// "Construtor"
	void Init();
};

// Inicializa a página
void Pagina::Init(){
	pg = 1;
}

// Recebe a página atual
int Pagina::GetPagina(){
	return pg;
}

// Deixa a página em modo visual (com visualização na tela)
void Pagina::Visual(){
	setvisualpage(pg);
}

// Troca a página atual
void Pagina::Troca(){
	
	if(pg == 1){
		pg = 2;
	} else{
		pg = 1;
	}
}

// Deixa a página em modo ativo (sem a visualização na tela)
void Pagina::Ativa(){
	setactivepage(pg);
}

