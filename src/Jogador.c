#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
#include "Lab.h"
#include "Funcoes.h"
#include "Estruturas.h"
#include "Jogador.h"

// Cria um novo jogador humano
void NovoJogador(Jogador *jogador)
{
    jogador->turno = NAO_E_MEU_TURNO;
    jogador->tipo = JOGADOR_TIPO_HUMANO;
       
   	jogador->percurso = (int*)malloc(sizeof(int));
    jogador->percursoAvancado = (int*)malloc(sizeof(int)); 
	
	// Inicializa os percursos a zero
    InicializarPercursos(jogador);

	fflush(stdin);
    printf("Nome Jogador: ");
    fflush(stdin);
    gets(jogador->nome);
}

// Cria um novo bot
void NovoBot(Jogador *bot)
{
    bot->turno = NAO_E_MEU_TURNO;
    bot->tipo = JOGADOR_TIPO_BOT;
    
    bot->percurso = (int*)malloc(sizeof(int));
    bot->percursoAvancado = (int*)malloc(sizeof(int)); 
       
	// Inicializa os percursos a zero
    InicializarPercursos(bot);
  
    strcpy(bot->nome, "Mr.Bot");
}

// Inicializa os percurso a zero
void InicializarPercursos(Jogador *jogador) 
{
    int i;
   
    for (i = 0; i< 11; i++) 
	{
		jogador->percurso = (int*) realloc(jogador->percurso, (i + 1)* sizeof(int));	
		jogador->percurso[i] = 0;
		
		jogador->percursoAvancado = (int*) realloc(jogador->percursoAvancado, (i + 1)* sizeof(int));
		jogador->percursoAvancado[i] = 0;
    }
}

// Copiar percurso avançado para percurso
void CopiarPercursoAvancadoParaPercurso(Jogador *jogador)
{
	int i;
   
    for (i = 0; i< 11; i++) 
	{
		// TODO: Não pode ser assim
		// Como resetamos o percursoAvançado a cada mudança de turno, no segundo turno o vetor de percursoAvançado começa do zero.
		// Se copiar direto, o vetor percurso vai perder os dados que tinha e vai sempre "começar do zero"
		// Temo que atualizar o vetor percurso com as novas posições e não copiar direto
		jogador->percurso[i] = jogador->percursoAvancado[i];
	}
}

// Faz reset ao percurso avançado
void ResetPercursoAvancado(Jogador *jogador) 
{
	int i;
   
    for (i = 0; i< 11; i++) 
	{
		jogador->percursoAvancado[i] = 0;
	}
}

// Seleciona a jogada para o Bot
char BotSelecionaJogada(Jogador *bot) 
{
	gotoxy(104, 14);
	printf(" %s está a pensar...          ", bot->nome);
	sleep(2);
	
	int jogadaSelecionada = NumAleatorio(1, 3);
	
	if (jogadaSelecionada == 1) 
	{
		gotoxy(104, 14);
		printf(" %s escolhe a opcao 1.", bot->nome);
		sleep(2);
		return '1';	
	}

	if (jogadaSelecionada == 2) 
	{
		gotoxy(104, 14);
		printf(" %s escolhe a opcao 2.\n", bot->nome);
		sleep(2);
		return '2';	
	}
	
	if (jogadaSelecionada == 3) 
	{
		gotoxy(104, 14);
		printf(" %s escolhe a opcao 3.\n", bot->nome);
		sleep(2);
		return '3';	
	}
}

// Decide o Bot continua a jogar ou finaliza o turno
char BotDecideSeContinuaAJogar(Jogador *bot) 
{
	int s, n;
	
	gotoxy(104, 14);
	printf(" %s está a pensar...          ", bot->nome);
	sleep(2);
	
	do 
	{
		s = NumAleatorio(1, 5);
		n = NumAleatorio(1, 5);
	} while(s == n);
	
	if (s > n) 
	{
		gotoxy(104, 14);
		printf(" %s decide continuar...", bot->nome);
		sleep(2);
		return 's';	
	} 
	else 
	{
		gotoxy(104, 14);
		printf(" %s decide parar por aqui...", bot->nome);
		sleep(2);
		return 'n';	
	} 
}

