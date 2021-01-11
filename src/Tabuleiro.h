#ifndef TABULEIRO_H // protectes from multiple including...
#define TABULEIRO_H // ... needs an #endif at bottom

// Desenha tabuleiro
void DesenharTabuleiro(Jogador *jogador, Jogador *bot);

// Desenha a linha do tabuleiro
void DesenharLinha(int num, int limite);

// Desenha as fichas para o percurso do jogador
void DesenharFichasDoPercurso(Jogador *jogador);

// Desenha as fichas para o percurso avancado do jogador
void DesenharFichasDoPercursoAvancado(Jogador *jogador);

// Desenhar menu de jogadas
void DesenharMenuDeJogadas(Jogador *jogador, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]);

#endif

