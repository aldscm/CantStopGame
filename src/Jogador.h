#ifndef JOGADOR_H // protectes from multiple including...
#define JOGADOR_H // ... needs an #endif at bottom

// Cria um novo jogador humano
void NovoJogador(Jogador *jogador);

// Cria um novo bot
void NovoBot(Jogador *bot);

// Inicializa os percurso a zero
void InicializarPercursos(Jogador *jogador);

// Copiar percurso avançado para percurso
void CopiarPercursoAvancadoParaPercurso(Jogador *jogador);

// Faz reset ao percurso avançado
void ResetPercursoAvancado(Jogador *jogador);

#endif
