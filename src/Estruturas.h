#ifndef ESTRUTURAS_H // protectes from multiple including...
#define ESTRUTURAS_H // ... needs an #endif at bottom

typedef struct jogador
{
    char nome[MAX_PLAYER_NAME_INPUT]; // Tipo de jogador.
    int tipo;
    int *percurso; // Array que guarda a o percurso do jogador
    int *percursoAvancado; // Array que guarda o percurso avan�ado a cada jogada 
	int turno; // 1: � o meu turno | 0: N�o � o meu turno.
} Jogador;

#endif
