/*Constantes*/

/*Dimensões da tela de jogo*/
#define TELA_W 1280
#define TELA_H 704

/*Posição do Roosevelt*/
#define ROOSEVELT_X TILE_W * 38
#define ROOSEVELT_Y TILE_H * 19

#define STALIN_X 0
#define STALIN_Y TILE_H * 19


/*Caminho para as imagens dos soldados*/
#define CHARA "/Soldado/Chara/Chara"
#define EUA  "/Soldado/Eua/Eua"
#define URSS  "/Soldado/Urss/Urss"
#define NAZI "/Soldado/Nazi/Nazi"

/*Caminho para as imagens das torres e dos canhões delas*/
#define TORRE_EUA "/Torre/Eua/Eua"
#define CANHAO_EUA "/Torre/Eua/EuaTiro"
#define TORRE_URSS "/Torre/Urss/Urss"
#define CANHAO_URSS "/Torre/Urss/UrssTiro"


/*Caminho para as imagens dos líderes*/
#define PATH_HITLER "/Lider/Hitler/Hitler"
#define PATH_ROOSEVELT "/Lider/Roosevelt/Roosevelt"
#define PATH_STALIN "/Lider/Stalin/Stalin"

/*Vida dos soldados e dos generais*/
#define VIDA 100

/*Ponto cego dos EUA 
(local onde as tropas da URSS não podem ser visualizadas)*/
#define ENTRADAURSSX TILE_W * 15
#define ENTRADAURSSY -64 // Corrigir esses valores

/*Ponto cego da URSS
(local onde as tropas do EUA não podem ser visualizadas)*/
#define ENTRADAEUAX 768
#define ENTRADAEUAY -64

// Indentifica o alvo na função DefesaTorre()
#define EIXO_ID "E"
#define OUTROJOG_ID "O"


/*Simboliza algo que está para ser definido*/
#define UNDEFINED -1

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

/*Portão padrão de acesso ao servidor*/
#define PORTA_PADRAO 20131

/*FPS do jogo*/
#define FPS 60

/*Teclado*/
#define ESC 27

/*Base numérica decimal (para uso no itoa() e outras funções que necessitam desta constante)*/
#define DECIMAL 10

/*Caminho para encontrar a pasta assets*/
#define ASSETS "../../Assets"

/*Extensão bitmap*/
#define BITMAP ".bmp"

/*Destino dos soldados da URSS (em tile)*/
#define DEST_URSS_TX 35
#define DEST_URSS_TY 2

/*Destino dos soldados do EUA (em tile)*/
#define DEST_EUA_TX 4
#define DEST_EUA_TY 2


/*Qtd. de soldados nas tropas*/
#define MAXTROPA 4

/*Delay de envio de soldados (10 s)*/
#define S_DELAY 1.5

/*Delay de fila de espera dos soldados*/
#define ESPERA_DELAY 2

/*Qtd. de ondas de nazistas que o jogo lança*/
#define QTD_ONDA 11

// Define o inicio e o fim do jogo
#define BEGIN 0 // 0 s 
#define END 90 // 1 m 30 s

/*Horário das ondas de soldados*/
#define ONDA1 5 
#define ONDA2 15 
#define ONDA3 30   
#define ONDA4 45
#define ONDA5 60 
#define ONDA6 75



// Representa que não há onda há serem enviadas
#define SEM_ONDA '?'

// Dano que o soldado infrige quando chega na base inimiga
#define DANO_CHEGOU 10



// Tempo de fúria dos lideres
#define TEMPOFURIA 2000 // 2 s

// Tempo de reload da torre
#define TORRE_RELOAD 2

// Preço de enviar um soldado
#define PRECO_SOLDADO 10

// Preço de colocar uma torre
#define PRECO_TORRE 50

// Bonus por matar soldado atacante
#define BONUS_SOLD 10



// Posição da GUI do soldado EUA
#define GUI_EUA_X  TILE_W * 33
#define GUI_EUA_Y  TILE_H * 20

// Posição da GUI do soldado URSS
#define GUI_URSS_X TILE_W * 6 
#define GUI_URSS_Y TILE_H * 20

// Posição do texto do soldado da URSS
#define URSS_TEXT_X TILE_W * 6
#define URSS_TEXT_Y TILE_H * 21

// Posição do texto do soldado dos EUA
#define EUA_TEXT_X TILE_W * 33
#define EUA_TEXT_Y TILE_W * 21

// Posição da palavra soldado na URSS 
#define SOLD_URSS_X TILE_W * 4
#define SOLD_URSS_Y TILE_H * 19

// Posição da palavra soldado nos EUA
#define SOLD_EUA_X TILE_W * 32
#define SOLD_EUA_Y TILE_H * 19

// Delay para torre trocar a posição quando 
//no modo Sem Alvo
#define TEMPO_TROCAPOS 1


// Posição do texto da torre
#define TORRE_TEXT_X TILE_W * 19 - 8
#define TORRE_TEXT_Y TILE_H * 18

// Posição da torre acima do texto de torre
#define TORRE1_X TILE_W * 19 + 16
#define TORRE1_Y TILE_H * 15

// Posição do dinheiro do jogador
#define MONEY_EUA_X 22 * TILE_W 
#define MONEY_EUA_Y 21 * TILE_H 
#define MONEY_URSS_X 14 * TILE_W - 10
#define MONEY_URSS_Y 21 * TILE_H 	

// Raio de alacance padrão para as torres
#define TORRE_RAIO 100


// Posição do botão "jogar"
#define BOTAO_JOGAR_X TILE_W * 19
#define BOTAO_JOGAR_Y TILE_H * 18

// Botão do cliente
#define BOTAO_CLIENTE_X TILE_W * 13
#define BOTAO_CLIENTE_Y TILE_H * 12


// Botão do servidor
#define BOTAO_SERV_X TILE_W * 24
#define BOTAO_SERV_Y TILE_H * 12

// Posição do botão "voltar"
#define BOTAO_VOLTAR_X TILE_W * 14
#define BOTAO_VOLTAR_Y TILE_H * 18

// Posição do logo de jogo
#define LOGO_X TILE_W * 11
#define LOGO_Y TILE_H * 5

#define LOGO2_X TILE_W * 14
#define LOGO2_Y TILE_H * 8 - 16 

// IP do localhost
#define LOCALHOST "127.0.0.1"



// Posição dos botões de menu de jogo
#define BOTAO1_X 9 * TILE_W
#define BOTAO1_Y 13 * TILE_H

#define BOTAO2_X 19 * TILE_W
#define BOTAO2_Y 13 * TILE_H

#define BOTAO3_X 29 * TILE_W
#define BOTAO3_Y 13 * TILE_H


// Opções para lado do jogador
#define LADO1 "Eua"
#define LADO2 "Urss"
#define LADO3 "Eixo"

// Dimensões das imagens dos lideres
#define LIDER_TILEW 64
#define LIDER_TILEH 96

// Dimensões das imagens das torres
#define TORRE_W 32
#define TORRE_H 64







