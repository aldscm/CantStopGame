#include <stdio.h>
#include <stdlib.h>

#include "Interface.h"
#include "Estruturas.h"
#include "Lab.h"
#include "Funcoes.h"

#define DADO_MIN_NUMBER 1
#define DADO_MAX_NUMBER 6

// Gera numeros aleatórios
int NumAleatorio(int min, int max)
{
    int n = min + rand() % (max - min);

    return n;
}

// Lança os dados
void LancarDados(int *dados, int nElements)
{
    int i;

    for (i = 0; i < nElements; i++)
    {
        dados[i] = NumAleatorio(DADO_MIN_NUMBER, DADO_MAX_NUMBER);
    }
}

// Soma o valor dos dados
int SomaDados(int *dados, int nElements)
{
    int i = 0, sum = 0;

    for (i = 0; i < nElements; i++)
    {
        sum += dados[i];
    }

    return sum;
}

