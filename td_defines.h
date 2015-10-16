/*Constantes*/

/*Dimensões da tela de jogo*/
#define TELA_W 1280
#define TELA_H 704

/*Caminho para as imagens dos soldados*/
#define CHARA "/Soldado/Chara/Chara"
#define EUA  "/Soldado/Eua/Eua"
#define URSS  "/Soldado/Urss/Urss"

/*Ponto cego dos EUA 
(local onde as tropas da URSS não podem ser visualizadas)*/
#define EUACEGOX 512
#define EUACEGOY -64 // Corrigir esses valores

/*Ponto cego da URSS
(local onde as tropas do EUA não podem ser visualizadas)*/
#define URSSCEGOX 736
#define URSSCEGOY -64


/*Tile de caminho*/
#define CAMINHO 8

/*Tile de cor preta*/
#define T_PRETO 0

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
#define ONDA1 30 // 30 s
#define ONDA2 90 // 1 m 30 s
#define ONDA3 150 // 2 m 30 s
#define ONDA4 210 // 3 m 30 s
#define ONDAF 270 // 4 m 30 s

// Representa que não há onda há serem enviadas
#define SEM_ONDA '?'

// Define o inicio e o fim do jogo
#define BEGIN 0 // 0 s 
#define END 330 // 5 m 30 s 


// Posição do soldado dos EUA
#define GUIEuaX  1000
#define GUIEuaY  TELA_H - (TILE_H * 3)

// Posição do dinheiro do jogador
#define MONEY_X 1050
#define MONEY_Y 685


// Opções para lado do jogador
#define LADO1 "Aliados Capitalistas"
#define LADO2 "Aliados Comunistas"
#define LADO3 "Eixo"







