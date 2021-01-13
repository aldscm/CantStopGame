#include <stdio.h>
#include <stdlib.h>

#include "Funcoes.h"

// Gera um número aleatórios
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
	fprintf(ficheiro, "Nome: %s\n", jogador->nome);
	// Adiciona o tipo do jogador
	fprintf(ficheiro, "Tipo: %d\n", jogador->tipo);
	// Adiciona o turno do jogador
	fprintf(ficheiro, "Turno: %d\n", jogador->turno);
	
	// Adiciona o percurso do jogador
	fprintf(ficheiro, "Percurso:");
	
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++ ) 
	{
		fprintf(ficheiro, " %d", jogador->percurso[i]);
	}
	
	
	// Muda o cursor para a próxima linha do ficheiro
	fprintf(ficheiro, "\n");
	
	// Adiciona o percursoAvancado do jogador
	fprintf(ficheiro, "Percurso Avancado:");
	
	for(i = 0; i < ARRAY_PERCURSO_SIZE; i++ ) 
	{
		fprintf(ficheiro, " %d", jogador->percursoAvancado[i]);
	}
	
	// Acrescenta uma linha em branco para espaçar os jogadores.
	fprintf(ficheiro, "\n\n");
}


