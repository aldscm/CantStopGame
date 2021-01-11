#ifndef ESTRUTURAS_H // protectes from multiple including...
#define ESTRUTURAS_H // ... needs an #endif at bottom

#define MAX_PLAYER_NAME_INPUT 50
#define JOGADOR_TIPO_HUMANO 1
#define JOGADOR_TIPO_BOT 2
#define MEU_TURNO 1
#define NAO_E_MEU_TURNO 0

typedef struct jogador
{
    char nome[MAX_PLAYER_NAME_INPUT]; // Tipo de jogador.
    int tipo;
    int *percurso; // Array que guarda a o percurso do jogador
    int *percursoAvancado; // Array que guarda o percurso avan�ado a cada jogada 
	int turno; // 1: � o meu turno | 0: N�o � o meu turno.
} Jogador;

#endif
