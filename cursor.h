
// Cursor utilizado no modo splitscreen
struct Cursor
{
	int cursorX, cursorY; // Coordenadas
	char *lado;
	void* img;
	
	void CheckInput();
	void Show();
};

// Verifica a entrada de dados
void Cursor::CheckInput()
{
	
		
		if(GetKeyState(VK_LEFT) & 0x80)
		{
			cursorX--;
		}
		
		if(GetKeyState(VK_RIGHT) & 0x80)
		{
			cursorX++;
		}
		
		if(GetKeyState(VK_DOWN) & 0X80)
		{
			cursorY++;
		}
		
		if(GetKeyState(VK_UP) & 0x80)
		{
			cursorY--;
		}
		
		
		if(cursorY < 1)
			cursorY = 1;
		else if(cursorY > 18)
			cursorY = 18;
}
