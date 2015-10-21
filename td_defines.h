/*Constantes*/

/*Dimensões da tela de jogo*/
#define TELA_W 1280
#define TELA_H 704

/*Caminho para as imagens dos soldados*/
#define CHARA "/Soldado/Chara/Chara"
#define EUA  "/Soldado/Eua/Eua"
#define URSS  "/Soldado/Urss/Urss"
#define NAZI "/Soldado/Nazi/Nazi"

#define PATH_HITLER "/Lider/Hitler/Hitler"
#define PATH_ROOSEVELT "/Lider/Roosevelt/Roosevelt"
#define PATH_STALLIN "/Lider/Stalin/Stalin"

/*Ponto cego dos EUA 
(local onde as tropas da URSS não podem ser visualizadas)*/
#define EUACEGOX 512
#define EUACEGOY -64 // Corrigir esses valores

/*Ponto cego da URSS
(local onde as tropas do EUA não podem ser visualizadas)*/
#define URSSCEGOX 768
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

/*Delay de fila de espera dos soldados*/
#define ESPERA_DELAY 2

/*Qtd. de ondas de nazistas que o jogo lança*/
#define QTD_ONDA 11

/*Horário das ondas de soldados*/
#define ONDA1 15 
#define ONDA2 30 // 3 m para o ataque final
#define ONDA3 45   
#define ONDA4 75
#define ONDA5 90 // 2 m para o ataque final
#define ONDA6 105
#define ONDA7 135
#define ONDA8 150 // 1 m para o ataque final
#define ONDA9 165
#define ONDA10 210 // 1ª onda ataque final
#define ONDA11 240 // 2ª onda ataque final

#define FINALCOUNTDOWN 180 // Relogio regressivo


// Representa que não há onda há serem enviadas
#define SEM_ONDA '?'

// Define o inicio e o fim do jogo
#define BEGIN 0 // 0 s 
#define END 270 // 5 m 30 s 

// Tempo de fúria dos lideres
#define TEMPOFURIA 2000 // 2 s


// Posição da GUI do soldado EUA
#define GUI_EUA_X  1000
#define GUI_EUA_Y  TELA_H - (TILE_H * 3)

// Posição da GUI do soldado URSS
#define GUI_URSS_X TILE_W * 6 
#define GUI_URSS_Y TILE_H * 20

// Posição do texto do soldado da URSS
#define URSS_TEXT_X TILE_W * 6
#define URSS_TEXT_Y TILE_H * 21

// Posição do texto da torre
#define TORRE_TEXT_X TILE_W * 19
#define TORRE_TEXT_Y TILE_H * 18

// Posição do dinheiro do jogador
#define MONEY_USA_X 1050 
#define MONEY_USA_Y 685 
#define MONEY_URSS_X 14 * TILE_W - 10
#define MONEY_URSS_Y 21 * TILE_H 	


// Opções para lado do jogador
#define LADO1 "Aliados Capitalistas"
#define LADO2 "Aliados Comunistas"
#define LADO3 "Eixo"

// Tamanho das imagens dos lideres
#define LIDER_TILEW 64
#define LIDER_TILEH 96







