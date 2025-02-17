#include <stdio.h>
#include <stdlib.h>

#include "Tabuleiro.h"

// Desenha o tabuleiro
void DesenharTabuleiro(Jogador *jogador, Jogador *bot)
{
	int k;
	int percurso[ARRAY_PERCURSO_SIZE] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int topo[ARRAY_PERCURSO_SIZE] = {3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};

    // Desenha o tabuleiro
    for (k = 0; k < ARRAY_PERCURSO_SIZE; k++)
    {
        DesenharLinha(percurso[k], topo[k]);
    }

	// Desenha no tabuleiro as fichas para o percurso do jogador
	DesenharFichasDoPercurso(jogador);
	DesenharFichasDoPercurso(bot);
}

// Desenha a linha do tabuleiro
void DesenharLinha(int num, int limite) // num = nr escrito dentro do retangulo; lim = nr de retangulos a desenhar
{
    int k;

    for (k = 1; k <= limite; k++)
    {
        showRectAt(3 + 8 * (k - 1), 3 + 4 * (num - 2), 6, 3);
        gotoxy(6 + 8 * (k - 1), 5 + 4 * (num - 2)); // posi??o dentro do retangulo
        printf("%d", num);
    }
}

// Desenha as fichas para o percurso do jogador
void DesenharFichasDoPercurso(Jogador *jogador)
{
	int i;

	for(i=0; i < ARRAY_PERCURSO_SIZE; i++){

		if (jogador->percurso[i] != 0 )
		{
			setColor(12 - (jogador->tipo - 1), 12 - (jogador->tipo - 1));
			showRectAt(4 + 3 * (jogador->tipo - 1) + 8 * (jogador->percurso[i] - 1), 4 + 4 * i, 1, 0);
			resetColor();
		}
	}
}

// Desenha as fichas para o percurso avancado do jogador
void DesenharFichasDoPercursoAvancado(Jogador *jogador)
{
	int i;

	for (i = 0; i < ARRAY_PERCURSO_SIZE; i++)
	{
		if (jogador->percursoAvancado[i] != 0)
		{
			setColor(15, 15);

			if (jogador->tipo == JOGADOR_TIPO_HUMANO)
			{
				showRectAt(4 + 8 * (jogador->percurso[i] + jogador->percursoAvancado[i] - 1), 4 + 4 * i, 1 ,0);
			}
			else // BOT
			{
				showRectAt(7 + 8 * (jogador->percurso[i] + jogador->percursoAvancado[i] - 1), 4 + 4 * i, 1 ,0);
			}

			resetColor();
		}
	}
}

