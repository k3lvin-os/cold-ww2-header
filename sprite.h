
	struct Sprite{  
	
		// Vari�veis
		int x, y;
		char *nome;
		void *image;
		
		// Fun��es
		void Show();
		void Move(int changeX, int changeY);
		void GetImage(char path[], int width, int height);
		void GetImage(void** pImg, char path[], int width, int height);
		void GoTo(int newX, int newY);
		void BasicTile(int width, int height, int color, char *nome);
		void Init(char path[], char nomeSprit[], int width, int height);
		
		// Destrutor
		//~Sprite(){}
			
	};
	
	// Cria um quadrado preenchido por uma cor especificada --> prot�tipo de Tile
	void Sprite::BasicTile(int width, int height, int color, char *nomeSprit){
		
		int size;
		
		// V� para uma posi��o padr�o de inicio
		GoTo(0,0);
		
		// Configura a cor e pinta o tile
		setfillstyle(1,color);
		bar(0,0 ,width, height );
		
		// Armazena o tile
		size = imagesize(0,0,width,height);
		image = malloc(size);
		getimage(0,0,width,height,image);
		nome = nomeSprit;		
	}
	
	
	// Muda a posi��o atual do sprite
	void Sprite::GoTo(int newX, int newY){
		
		// Altera os valores diretamente
		x = newX;
		y = newY; 
	}
	
	// Mostra o sprite
	 void Sprite::Show(){
	 	
	 	// Coloca a imagem na tela
		putimage(x,y,image,0);
	}
	
	// Movimenta o sprite
	void Sprite::Move(int changeX, int changeY){
		
		// Altera o valor de x e y com base em variaveis
		// de altera��o
		x += changeX;
		y += changeY;
	}
	
	// Atribui uma imagem ao sprite
	void Sprite::GetImage(char *path, int width, int height){
		
		
		
		// L� e coloca na tela uma imagem
		readimagefile(path,0,0,width,height); 
		
		/// Calcula o tamanho da imagem com base na posi��o
		int size = imagesize(0,0,width,height);
		
		// Aloca mem�ria para a vari�vel que vai recebe-la
		image = malloc(size);
		
		// Recebe a imagem
		getimage(0,0,width,height,image); 
	}
	
	// Manipula um ponteiro void a fim de receber uma imagem  
	void Sprite::GetImage(void** pImg, char path[], int width, int height){
		
		int size;
		
		// L� e coloca na tela uma imagem
		readimagefile(path,0,0,width,height); 
		
		/// Calcula o tamanho da imagem com base na posi��o
		size = imagesize(0,0,width,height);
		
		// Aloca mem�ria com base no tamanho da imagem
		*pImg = malloc(size);
		
		// Recebe a imagem
		getimage(0,0,width,height,*pImg); 

	}
	
		
	// "Construtor"
	void Sprite::Init(char *path, char *nomeSprit, int width, int height){
		
		// Configura a imagem do sprite
		GetImage(path,width,height);
		
		// Atribui o nome especificado
		nome = nomeSprit;
		
		// Come�a por uma posi��o padr�o
		x = 0;
		y = 0;
	}
	
