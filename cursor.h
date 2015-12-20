
// Cursor utilizado no modo splitscreen
struct Cursor
{
	static const int MAX_IDLE = 20;
	static const int MAX_NO_TIMER = 10;
	
	
	int tileX, tileY, meuX, meuY; // Coordenadas
	char *lado;
	TipoCursor tipo;
	Soldado *guiSold;
	Torre *guiTower;
	Cenario *campoJogo;
	bool helpMode;

	Sprite imgCursor, *botaoJog;
	
	void CheckInput();
	bool AnyItemWasUsed();
	void Show();
	void Init(char * lado, Sprite imgCursor, Sprite *botaoJog, Soldado *s, Torre *t );
};


// Verifica se algum item foi utilizado
bool Cursor::AnyItemWasUsed()
{
	if(lado == LADOEUA)
	{
		if(GetKeyState(VK_RCONTROL) & 0X80)
		{
			return true;
		}
	}
	
	else
	{
		if(GetKeyState(VK_LCONTROL) & 0X80)
		{
			return true;
		}
	}
	
	return false;
}

// Verifica a entrada de dados
void Cursor::CheckInput()
{
	
	if(lado == LADOEUA)
	{
		
		if(GetKeyState(VK_NUMPAD0) & 0x80) // '0'
		{
			if(tipo == C_SELETOR)
			{
				tipo = C_TORRE;
			}
			
			else if(tipo == C_TORRE)
			{
				tipo = C_SOLDADO;
			}
			
			else
			{
				tipo = C_SELETOR;
			}
		}	
		
		if(GetKeyState(VK_LEFT) & 0x80)
		{
			tileX--;
		}
		
		if(GetKeyState(VK_RIGHT) & 0x80)
		{
			tileX++;
		}
		
		if(GetKeyState(VK_DOWN) & 0X80)
		{
			tileY++;
		}
		
		if(GetKeyState(VK_UP) & 0x80)
		{
			tileY--;
		}
		
		if(tileX > 38)
			tileX = 38;
		else if(tileX < 22)
			tileX = 22;
			
	} 
	
	else
	{
		if(GetKeyState(VK_SPACE) & 0x80)
		{
			if(tipo == C_SELETOR)
			{
				tipo = C_TORRE;
			}
			
			else if(tipo == C_TORRE)
			{
				tipo = C_SOLDADO;
			}
			
			else
			{
				tipo = C_SELETOR;
			}	
		}
		
		if(GetKeyState(0x41) & 0x80) // 'A'
		{
			tileX--;
		}
		
		if(GetKeyState(0x44) & 0x80) // 'D'
		{
			tileX++;
		}
		
		if(GetKeyState(0x53) & 0X80) // 'S'
		{
			tileY++;
		}
		
		if(GetKeyState(0x57) & 0x80) // 'W'
		{
			tileY--;
		}
		
		if(tileX > 17)
			tileX  = 17;
		else if(tileX < 1)
			tileX = 1;	
	}
	
	if(tileY < 1)
		tileY = 1;
	else if(tileY > 18)
		tileY = 18;
		
	if(tileY > 17 && tipo == C_TORRE)
		tileY = 17;
		
	meuX = tileX * TILE_W; 
	meuY = tileY * TILE_H;
}

// "Construtor"
void Cursor::Init(char * lado, Sprite imgCursor, Sprite *botaoJog, Soldado *s, Torre *t )
{
	
	if(lado == LADOEUA)
	{		
		tileX = 30;
		tileY = 10;
	} 
	
	else
	{
		tileX = 9;
		tileY = 10;	
	}
	
	meuX = TILE_W * tileX;
	meuY = TILE_H * tileY;
	
	this->lado = lado;
	this->imgCursor = imgCursor;
	this->botaoJog = botaoJog;
	tipo = C_SELETOR;
	helpMode = false;
	guiSold = s;
	guiTower = t;

	

}

// Mostra o cursor
void Cursor::Show()
{
	if(lado == LADOEUA)
	{
		setcolor(LIGHTGREEN);
		outtextxy(meuX,meuY,"P2");
		
		if(tipo == C_SELETOR)
		{
			outtextxy(meuX + 64,meuY + 16,">");			
			outtextxy(meuX - 64,meuY + 16,"<");			
			outtextxy(meuX + 8,meuY + 80,"v");			
			outtextxy(meuX + 8 ,meuY - 48,"^");
		}

	}
	
	else
	{
		setcolor(WHITE);
		outtextxy(meuX,meuY,"P1");
		
		if(tipo == C_SELETOR)
		{
			outtextxy(meuX + 64,meuY + 16,"D");
			outtextxy(meuX - 64,meuY + 16,"A");
			outtextxy(meuX + 8,meuY + 80,"S");
			outtextxy(meuX + 4 ,meuY - 48,"W");	
		}
		
		

	}
				
	imgCursor.GoTo(meuX, meuY);
	imgCursor.Show();
	
	if(tipo == C_SELETOR)
	{
			
		
		
	}
	
	else if(tipo == C_TORRE)
	{
			
		imgCursor.GoTo(meuX, meuY + 32);
		imgCursor.Show();
			
		guiTower->x = meuX;
		guiTower->y = meuY;
		guiTower->MostraTorre();
		
		setcolor(LIGHTBLUE);
		outtextxy(meuX - 25 , meuY + 90, "Colocar");
		outtextxy(meuX - 10, meuY + 115, "Torre");
	}
	
	else if(tipo == C_SOLDADO)
	{
		guiSold->GoTo(meuX,meuY);
		guiSold->Show();
		
		setcolor(LIGHTRED);
		outtextxy(meuX - 50,meuY + 50,"Enviar soldado");

	}

	
	
	if(helpMode == true)
	{			
		if(lado == LADOEUA)
		{	
			setcolor(LIGHTGREEN);
			outtextxy(meuX - 40, meuY - 80,  "'0' = Troca Item");
			outtextxy(meuX - 40, meuY - 100, "'LCTRL' = Usa Item");
		}
		
		else
		{
			setcolor(WHITE);
			outtextxy(meuX - 40, meuY - 80,  "'Espaço' = Troca Item");
			outtextxy(meuX - 40, meuY - 100, "'RCTRL' = Usa Item");		
		}									
	}



	

}




