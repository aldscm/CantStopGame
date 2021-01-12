#ifndef JOGO_H // protectes from multiple including...
#define JOGO_H // ... needs an #endif at bottom

// Iniciar um novo jogo
void NovoJogo(int *option, Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

// Define quem � o jogador a iniciar o jogo.
void PrimeiroAJogar(Jogador *jogador, Jogador *bot);

// Lan�a os dados
void LancarDados(int *dados, int numeroTotalDeDados);

// Define as possivies jogadas do jogador.
void DefinirJogadas(int *dados, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

// Inicia o turno do jogador
void IniciarTurnoDoJogador(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

// Inicia o turno do bot
void IniciarTurnoDoBot(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

// Muda o turno 
void MudarTurno(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

#endif
