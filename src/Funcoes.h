#ifndef FUNCOES_H // protectes from multiple including...
#define FUNCOES_H // ... needs an #endif at bottom

#include "Constants.h"
#include "Jogador.h"

// Gera um numero aleatório
int NumAleatorio(int min, int max);

// Soma o valor dos dados
int SomarDados(int *dados, int numeroTotalDeDados);

// Grava os dados do jogo num ficheiro
void GravarJogo(Jogador *jogador, Jogador *bot);

// Adiciona os dados do jogador ao ficheiro
void AdicionarDadosAoFicheiro(FILE *file, Jogador *jogador);

// Carregar os dados do jogo do ficheiro
int CarregarJogo(Jogador *jogador, Jogador *bot);

// Lê os dados do ficheiro para a estrutura
void LerDadosDoFicheiro(FILE *ficheiro, Jogador *jogador);

#endif
