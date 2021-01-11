#include <stdio.h>
#include <stdlib.h>

#include "Constants.h"
#include "Interface.h"
#include "Estruturas.h"
#include "Lab.h"
#include "Funcoes.h"

// Gera numeros aleatórios
int NumAleatorio(int min, int max)
{
    int n = min + rand() % (max - min);

    return n;
}

// Lança os dados
void LancarDados(int *dados, int numeroTotalDeDados)
{
    int i;

    for (i = 0; i < numeroTotalDeDados; i++)
    {
        dados[i] = NumAleatorio(DADO_MIN_NUMBER, DADO_MAX_NUMBER);
    }
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

// Define as possivies jogadas do jogador.
void DefinirJogadas(int *dados, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]) 
{
	// dados A, B, C e D. 
	// Associação A + B e C + D na posição 0
	matrizJogadas[0][0] = dados[0] + dados[1];
	matrizJogadas[0][1] = dados[2] + dados[3];
	
	// Associação A + C e B + D na posição 0	
	matrizJogadas[1][0] = dados[0] + dados[2];
	matrizJogadas[1][1] = dados[1] + dados[3];
	
	// Associação A + D e B + C na posição 0	
	matrizJogadas[2][0] = dados[0] + dados[3];
	matrizJogadas[2][1] = dados[1] + dados[2];
}

