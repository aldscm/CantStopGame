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
    int *percursoAvancado; // Array que guarda o percurso avançado a cada jogada 
	int turno; // 1: É o meu turno | 0: Não é o meu turno.
} Jogador;

#endif
