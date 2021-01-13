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


