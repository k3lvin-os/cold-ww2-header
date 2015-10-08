struct Jogador{
	
	/*=========================
			Constantes
	===========================*/
	static const int DINHEIRO = 100;
	static const int VIDA = 100;
	
	/*=========================
			Propriedades
	===========================*/
	
	// Cabeça da lista encadeada de inimigos
	Inimigo *inimigo0;
	
	// Vida do jogador
	int vida;
	
	// Lado do jogador
	char* lado;
	
	// Dinheiro do jogador
	int dinheiro;
	
	/*===========================
				Funções
	==============================*/
	
	
	// "Construtores"
	void Init();
	void Init(char* meuLado);
	
};

// "Construtor" geral
void Jogador::Init(){
	
	inimigo0 = (Inimigo *) malloc(sizeof(Inimigo));
	inimigo0->prox = NULL;
	dinheiro = DINHEIRO;
	vida = VIDA;
	lado = NULL;
}

// "Construtor" específico
void Jogador::Init(char* meuLado){
	
	// Chama o constutor geral
	Init();
	
	// Passa os dados específicos
	lado = meuLado;
}
