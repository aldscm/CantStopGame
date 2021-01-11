#ifndef FUNCOES_H // protectes from multiple including...
#define FUNCOES_H // ... needs an #endif at bottom

// Gera numeros aleatório
int NumAleatorio(int min, int max);

// Lança os dados
void LancarDados(int *dados, int numeroTotalDeDados);

// Soma o valor dos dados
int ResultadoDados(int *dados, int numeroTotalDeDados);

// Define as possivies jogadas do jogador.
void DefinirJogadas(int *dados, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

#endif
