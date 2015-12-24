
// Cursor utilizado no modo splitscreen
struct Cursor
{
	
	int tileX, tileY, meuX, meuY; // Coordenadas
	TipoCursor tipo;
	Jogador *meuJog;
	Cenario *campoJogo;
	bool helpMode;
	bool faltaDinTorre;
	bool faltaDinSold;
	bool posInvalid;
	Sprite *img;
	
	void CheckInput();
	bool AnyItemWasUsed();
	void Show();
	void Init(Cenario *campoJogo, Jogador *meuJog, Sprite *img);

};


// Verifica se algum item foi utilizado
bool Cursor::AnyItemWasUsed()
{
	
	
	if(meuJog->lado == LADOEUA)
	{
		if(GetKeyState(VK_RCONTROL) & 0x80 )
		{
			return true;
		}
	}
	
	else
	{
		if(GetKeyState(VK_LCONTROL) & 0x80)
		{
			return true;
		}
	}
	
	return false;
}

// Verifica a entrada de dados
void Cursor::CheckInput()
{
	
	if(meuJog->lado == LADOEUA)
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
		
		if(GetKeyState(VK_DOWN) & 0x80)
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
		
		if(GetKeyState(0x53) & 0x80) // 'S'
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
void Cursor::Init(Cenario *campoJogo, Jogador *meuJog, Sprite *img)
{
	
	if(meuJog->lado == LADOEUA)
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
	
	this->campoJogo = campoJogo;
	this->meuJog = meuJog;
	this->img = img;
	faltaDinSold = false;
	faltaDinTorre = false;
	posInvalid = false;
	tipo = C_SELETOR;
	helpMode = false;


	

}

// Mostra o cursor
void Cursor::Show()
{
	if(meuJog->lado == LADOEUA)
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
				
	img->GoTo(meuX, meuY);
	img->Show();
	
	if(tipo == C_TORRE)
	{
			
		img->GoTo(meuX, meuY + 32);
		img->Show();

			
		meuJog->tempTorre.x = meuX;
		meuJog->tempTorre.y = meuY;
		meuJog->tempTorre.MostraTorre();
		setcolor(BLUE);
		circle(meuX + 16,meuY + 32,TORRE_RAIO);


		
		if(faltaDinTorre == false && posInvalid == false)
		{
			setcolor(LIGHTBLUE);
			outtextxy(meuX - 25 , meuY + 90, linguagem.GetText(114));
			outtextxy(meuX - 10, meuY + 115, linguagem.GetText(115));
		}
		else
		{
			if(posInvalid == true)
			{
				setcolor(LIGHTRED);
				outtextxy(meuX - 15 , meuY + 90, linguagem.GetText(116));
				outtextxy(meuX - 10, meuY + 115, linguagem.GetText(117));
				posInvalid = false;
			}
			
			else
			{
				setcolor(LIGHTRED);
				outtextxy(meuX - 25 , meuY + 90,linguagem.GetText(118));
				outtextxy(meuX - 40, meuY + 115, linguagem.GetText(119));
				faltaDinTorre = false;
			}
		}

	}
	
	else if(tipo == C_SOLDADO)
	{
		meuJog->soldGUI.GoTo(meuX,meuY);
		meuJog->soldGUI.Show();	
		setcolor(LIGHTRED);
		
		if(faltaDinSold == false)
		{
			if(meuJog->envioSold.PassouDelay(ESPERA_DELAY) == true)
			{
				outtextxy(meuX - 50,meuY + 50,linguagem.GetText(56));
			} 
			
			else
			{
				outtextxy(meuX - 50,meuY + 50,linguagem.GetText(120));
			}
		}
		
		else		
		{
			setcolor(LIGHTRED);
			outtextxy(meuX - 50,meuY + 50,linguagem.GetText(121));	
			faltaDinSold = false;	
		}
		


	}

	
	
	if(helpMode == true)
	{			
		if(meuJog->lado == LADOEUA)
		{	
			setcolor(LIGHTGREEN);
			outtextxy(meuX - 40, meuY - 80,  linguagem.GetText(122));
			if(tipo != C_SELETOR)
				outtextxy(meuX - 40, meuY - 100, linguagem.GetText(123));
		}
		
		else
		{
			setcolor(WHITE);
			outtextxy(meuX - 40, meuY - 80,  linguagem.GetText(124));
			if(tipo != C_SELETOR)
				outtextxy(meuX - 40, meuY - 100, linguagem.GetText(125));	
		}									
	}



	

}




