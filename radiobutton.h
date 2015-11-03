struct RadioButton{

	int x,y;
	bool checked;
	RadioButton *prox;
	char *label;
	
	// Funções
	RadioButton* Insere(Radio *radio0, char* label1, bool checked1, int meuX, int meuY);
	void LimpaNo(Radio *radio0);
	void CheckRadio(Radio *radio0);
	void MostraLista(Radio *torre0);
	
	// "Construtor"
	void Init(char *label, bool checked, int meuX, int meuY);
};


// Insere um novo botão de rádio na lista encadeada radio0
RadioButton* RadioButton::Insere(Radio *radio0, char* label1, bool checked1){
	
	RadioButton *novo;
	novo = (RadioButton *) malloc(sizeof(RadioButton));
	novo->Init(label1,checked1,meuX,meuY); 
	novo->prox  = torre0->prox;
	torre0->prox = novo;
	return novo;	
}

//============================================================
// Atribui os dados de um novo botão
void RadioButton::Init(char *label1, bool checked1, int meuX, int meuY){
	x = meuX;
	y = meuY;
	checked = checked1;
	label = label1;
	prox = NULL;
}

