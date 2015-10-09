
// Interface gráfica com o usuário
struct GUI{
	
	// Constantes
	static const int GUISoldX = 1000;
	static const int GUISoldY = TELA_H - (TILE_H * 3);
	
	// Função
	void Mostra(char *tipo);
};

// Recebe e mostra um tipo de GUI
void GUI::Mostra(char *tipo){
	
	Soldado GUISold;
	
	if(*tipo == "default"){
		
		// Soldado dos EUA
		GUISold.Init("Eua");
		GUISold.GoTo(GUISoldX,GUISoldY);
		GUISold.Show();
	}
}
