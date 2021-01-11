#ifndef TABULEIRO_H // protectes from multiple including...
#define TABULEIRO_H // ... needs an #endif at bottom

// Desenha no tabuleiro todas as peças do jogo
void DesenharTabuleiro();

// Desenha a linha do tabuleiro
void DesenharLinha(int num, int limite);

// Desenha as fichas para o percurso do jogador
void DesenharFichasDoPercurso(Jogador *jogador);

// Desenha as fichas para o percurso avancado do jogador
void DesenharFichasDoPercursoAvancado(Jogador *jogador);

#endif

