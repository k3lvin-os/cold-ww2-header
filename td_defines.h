/*Constantes*/

/*Dimensões da tela de jogo*/
#define TELA_W 1280
#define TELA_H 704

/*Dimensões da tela do editor de sprites*/
#define EDIT_W 1280
#define EDIT_H 736

/*Dimensões dos tiles*/
#define TILE_W 32
#define TILE_H 32

/*Qtd. de tiles (Dimensão da tela / Dimensão dos tiles)*/
#define TILE_QTDX 40
#define TILE_QTDY 22

/*FPS do jogo*/
#define FPS 30

/*Teclado*/
#define ESC 27

/*Base numérica decimal (para uso no itoa() e outras funções que necessitam desta constante)*/
#define DECIMAL 10

/*Caminho para encontrar a pasta assets*/
#define ASSETS "../../Assets"

/*Extensão bitmap*/
#define BITMAP ".bmp"

/*Destino dos soldados da URSS*/
#define DEST1_X 35
#define DEST1_Y 2

/*Qtd. de soldados nas tropas*/
#define MAXTROPA 4

/*Delay de envio de soldados (10 s)*/
#define S_DELAY 1.5

/*Horário das ondas de soldados*/
#define ONDA1 30
#define ONDA2 90
#define ONDA3 150
#define ONDA4 210
#define ONDAF 300
#define END 360


// Posição do soldado dos EUA
#define GUIEuaX  1000
#define GUIEuaY  TELA_H - (TILE_H * 3)

// Posição do dinheiro do jogador
#define MONEY_X 1050
#define MONEY_Y 685


// Opções para lado do jogador
#define LADO1 "Aliados Capitalistas"
#define LADO2 "Aliados Comunistas"



