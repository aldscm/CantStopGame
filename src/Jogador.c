#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
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

