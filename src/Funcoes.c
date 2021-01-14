#include <stdio.h>
#include <stdlib.h>

#include "Funcoes.h"

// Gera um nï¿½mero aleatï¿½rios
int NumAleatorio(int min, int max)
{
    int n = min + rand() % (max - min);

    return n;
}

// Soma o valor dos dados
int SomaDados(int *dados, int numeroTotalDeDados)
{
    int i = 0, sum = 0;

    for (i = 0; i < numeroTotalDeDados; i++)
    {
        sum += dados[i];
    }

    return sum;
}

// Grava os dados do jogo num ficheiro
void GravarJogo(Jogador *jogador, Jogador *bot)
{
	FILE * ficheiro;
	
	// Abre o ficheiro em modo de escrita
	ficheiro = fopen("savedgame.txt", "w");
	
	if (ficheiro == NULL) 
	{
		printf("\n ERRO: Nao e possivel abrir o ficheiro <savedgame.txt>.\n\n");
		system("pause");
		exit(1);
	}
	
	// Adiciona os dados do jogador ao ficheiro
	AdicionarDadosAoFicheiro(ficheiro, jogador);
	
	// Adiciona os dados do bot ao ficheiro
	AdicionarDadosAoFicheiro(ficheiro, bot);
	
	// Fecha o ficheiro
	fclose(ficheiro);
}

// Adiciona os dados do jogador ao ficheiro
void AdicionarDadosAoFicheiro(FILE *ficheiro, Jogador *jogador) 
{
	int i;
	
	// Adiciona o nome do jogador
	fprintf(ficheiro, "%s\n", jogador->nome);
	// Adiciona o tipo do jogador
	fprintf(ficheiro, "%d\n", jogador->tipo);
	// Adiciona o turno do jogador
	fprintf(ficheiro, "%d\n", jogador->turno);
	
	// Adiciona o percurso do jogador	
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++ ) 
	{
		fprintf(ficheiro, "%d\n", jogador->percurso[i]);
	}
		
	// Adiciona o percursoAvancado do jogador
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++ ) 
	{
		fprintf(ficheiro, "%d\n", jogador->percursoAvancado[i]);
	}
}

// Carregar os dados do jogo do ficheiro
int CarregarJogo(Jogador *jogador, Jogador *bot) 
{
	FILE *ficheiro;
	
	// Inicializa os arrays dos percursos
	InicializarPercursos(jogador);
	InicializarPercursos(bot);
	
	// Abre o ficheiro em modo leitura
	ficheiro = fopen("savedgame.txt","r");

	if(ficheiro == NULL)
	{	    
		printf("\n ERRO: Nao e possivel abrir o ficheiro <savedgame.txt>.\n\n");
		system("pause");
		return 0;	
	}
	
	// Le os dados do jogador para a estrutura
	LerDadosDoFicheiro(ficheiro, jogador);
	
	// Le os dados do bot para a estrutura
	LerDadosDoFicheiro(ficheiro, bot);
	
	// Fecha o ficheiro
	fclose(ficheiro);
	
	// Ok
	return 1;
}

// Lê os dados do ficheiro para a estrutura
void LerDadosDoFicheiro(FILE *ficheiro, Jogador *jogador) 
{
	int i;
	
	// Adiciona o nome do jogador
	fscanf(ficheiro, "%[^\n]s\n", jogador->nome);
	// Adiciona o tipo do jogador
	fscanf(ficheiro, "%d\n", &jogador->tipo);
	// Adiciona o turno do jogador
	fscanf(ficheiro, "%d\n", &jogador->turno);
		
	// Le o percurso para a estrutura
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++ ) 
	{
		fscanf(ficheiro, "%d\n", &jogador->percurso[i]);
	}
	
	// Le o percurso avancado para a estrutura
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++) 
	{
		fscanf(ficheiro, "%d\n", &jogador->percursoAvancado[i]); 
	}
}


