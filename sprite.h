
	struct Sprite{  
	
		// Variáveis
		int x, y;
		char nome[];
		void *image;
		
		// Funções
		void Show();
		void Move(int changeX, int changeY);
		void GetImage(char path[], int width, int height);
		void GoTo(int newX, int newY);
		void BasicTile(int width, int height, int color, char *nome);
	
		// Constructors	
		Sprite(char nomeSprit[] , int beginX,int beginY );
		Sprite(char path[], char nomeSprit[], int width, int height,int beginX, int beginY);
		Sprite(char path[], char nomeSprit[], int width, int height);
		Sprite();

		
		// Destructor
		~Sprite(){}
			
	};
	
	// Cria um quadrado preenchido por uma cor especificada --> protótipo de Tile
	void Sprite::BasicTile(int width, int height, int color, char *nome){
		
		int size;
		
		// Configura a cor e pinta o tile
		setfillstyle(1,color);
		bar(0,0 ,width, height );
		
		// Armazena o tile
		size = imagesize(0,0,width,height);
		image = malloc(size);
		getimage(0,0,width,height,image);
		nome = nome;
		
	}
	
	
	// Go to a new position
	void Sprite::GoTo(int newX, int newY){
		x = newX;
		y = newY; 
	}
	
	// Show sprite
	 void Sprite::Show(){
		putimage(x,y,image,0);
	}
	
	// Move sprite
	void Sprite::Move(int changeX, int changeY){
		x += changeX;
		y += changeY;
	}
	
	
	// Fill the image variable with the sprite
	void Sprite::GetImage(char path[], int width, int height){
		
		readimagefile(path,0,0,width,height); 
		int size = imagesize(0,0,width,height);
		image = malloc(size);
		getimage(0,0,width,height,image); 
	}
	
	// Constructor based in a sprite without image, but with coordinates
	Sprite::Sprite(char nomeSprit[], int beginX,int beginY){
		x = beginX;
		y = beginY;
		strcpy(nome,nomeSprit);
	}
	
	// Constructor based in a sprite with image and coordinates
	Sprite::Sprite(char path[], char nomeSprit[] , int width, int height,int beginX, int beginY){
		GetImage(path,width,height);
		x = beginX;
		y = beginY;
		strcpy(nome,nomeSprit);
	}
	
	// Constructor based in a sprite with image, but without a specific coordinate
	Sprite::Sprite(char path[], char nomeSprit[] , int width, int height){
		GetImage(path,width,height);
		strcpy(nome,nomeSprit);
		x = 0;
		y = 0;
	}
	
	// Constructor without parameters
	Sprite::Sprite(){
		x = 0;
		y = 0;
		strcpy(nome,"?");
	}
	
