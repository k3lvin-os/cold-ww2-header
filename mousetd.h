/*Verifica entrada de dados baseada em mouse*/
struct MouseTd{
	
	// Verifica a entrada de dados baseada em mouse
	void Check(int mouseX, int mouseY);
	
};

// Verifica a entrada de dados baseada em mouse
void MouseTd::Check(int mouseX, int mouseY){
	
	// Click na região do soldado dos EUA
	if(mouseX >= GUISoldX && mouseX <= GUISoldX + TILE_W
		&& mouseY >= GUISoldY && mouseY <= GUISoldY + TILE_H ){
			
		if(envioSold.Valida() == true){
			/*CONTINUAR DAQUI --> Insira um soldado no jogador0*/
		}
	}
}
