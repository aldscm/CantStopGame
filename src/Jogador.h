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

// Seleciona a jogada para o Bot
char BotSelecionaJogada(Jogador *bot);

// Decide se o Bot continua a jogar ou finaliza o turno
char BotDecideSeContinuaAJogar(Jogador *bot);

#endif
