#ifndef ESTRUTURAS_H // protectes from multiple including...
#define ESTRUTURAS_H // ... needs an #endif at bottom

typedef struct jogador
{
    char nome[MAX_PLAYER_NAME_INPUT]; // Tipo de jogador.
    int tipo;
    int *percurso; // Array que guarda a o percurso do jogador
    int *percursoAvancado; // Array que guarda o percurso avançado a cada jogada 
	int turno; // 1: É o meu turno | 0: Não é o meu turno.
} Jogador;

#endif
