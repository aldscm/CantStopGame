#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
#include "Estruturas.h"
#include "Jogador.h"

// TODO: Isto é para apagar, é apenas para teste
void CriarPercursosDeTest(Jogador *jogador) 
{
    int i;
    int auxPercurso[11] = {1,0,2,8,2,1,0,0,1,0,2};
    int auxPercursoAvancado[11] = {0,0,1,0,0,2,0,0,2,0,0};
    
    int auxPercursoBot[11] = {1,1,0,5,2,1,0,0,1,0,2};
    int auxPercursoAvancadoBot[11] = {0,0,1,0,0,2,0,0,2,0,0};
    
    for (i = 0; i< 11; i++) 
	{
    	if (jogador->tipo == JOGADOR_TIPO_HUMANO) 
		{
			jogador->percurso = (int*) realloc(jogador->percurso, (i + 1)* sizeof(int));	
			jogador->percurso[i] = auxPercurso[i];
			
			jogador->percursoAvancado = (int*) realloc(jogador->percursoAvancado, (i + 1)* sizeof(int));
			jogador->percursoAvancado[i] = auxPercursoAvancado[i];
    	} 
    	else 
		{
			jogador->percurso = (int*) realloc(jogador->percurso, (i + 1)* sizeof(int));	
			jogador->percurso[i] = auxPercursoBot[i];
			
			jogador->percursoAvancado = (int*) realloc(jogador->percursoAvancado, (i + 1)* sizeof(int));
			jogador->percursoAvancado[i] = auxPercursoAvancadoBot[i];
    	}
    }
}

// Cria um novo jogador humano
void NovoJogador(Jogador *jogador)
{
    jogador->turno = NAO_E_MEU_TURNO;
    jogador->tipo = JOGADOR_TIPO_HUMANO;
       
   	jogador->percurso = (int*)malloc(sizeof(int));
    jogador->percursoAvancado = (int*)malloc(sizeof(int)); 
	   
    CriarPercursosDeTest(jogador);

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
       
    CriarPercursosDeTest(bot);
  
    strcpy(bot->nome, "Mr.Bot");
}
