#ifndef JOGADOR_H // protectes from multiple including...
#define JOGADOR_H // ... needs an #endif at bottom

#include "Lab.h"
#include "Constants.h"
#include "Funcoes.h"

typedef struct jogador
{
    char nome[MAX_PLAYER_NAME_INPUT]; // Tipo de jogador.
    int tipo;
    int *percurso; // Array que guarda a o percurso do jogador
    int *percursoAvancado; // Array que guarda o percurso avançado a cada jogada 
	int turno; // 1: É o meu turno | 0: Não é o meu turno.
} Jogador;

// Cria um novo jogador humano
void NovoJogador(Jogador *jogador);

// Cria um novo bot
void NovoBot(Jogador *bot);

// Inicializa os percurso a zero
void InicializarPercursos(Jogador *jogador);

// Copiar percurso avançado para percurso
void CopiarPercursoAvancadoParaPercurso(Jogador *jogador);

// Faz reset ao percurso avançado
void ResetPercursoAvancado(Jogador *jogador);

// Seleciona a jogada para o Bot
char BotSelecionaJogada(Jogador *bot);

// Decide se o Bot continua a jogar ou finaliza o turno
char BotDecideSeContinuaAJogar(Jogador *bot);

#endif
