#include <stdio.h>
#include <stdlib.h>

#include "Interface.h"
#include "Estruturas.h"
#include "Jogador.h"
#include "Funcoes.h"
#include "Tabuleiro.h"
#include "Jogo.h"

// Iniciar um novo jogo
void NovoJogo(int *option, Jogador *jogador, Jogador *bot)
{   
    MostrarTituloJogo();
    NovoJogador(jogador);
    NovoBot(bot);
    PrimeiroAJogar(jogador, bot);
    
    if (MostrarSubMenuJogo(option) == 1)
    {
		DesenharTabuleiro(jogador, bot);
		
		system("pause");
    }
}

// Define quem é o jogador a iniciar o jogo.
void PrimeiroAJogar(Jogador *jogador, Jogador *bot)
{
    int dados = 2;
    int DadosJogador[] = {0, 0}, ResultadoDadosJogador = 0;
    int DadosBot[] = {0, 0}, ResultadoDadosBot = 0;

    system("cls");
    MostrarTituloJogo();

    printf("A lancar os dados...\n\n");

    do
    {
        LancarDados(DadosJogador, dados);
        LancarDados(DadosBot, dados);

        ResultadoDadosJogador = SomaDados(DadosJogador, dados);
        ResultadoDadosBot = SomaDados(DadosBot, dados);

        // Continua a lancar ate existir um vencedor
    } while (ResultadoDadosJogador == ResultadoDadosBot);

    printf("%s saiu o %d e o %d.\n\n", jogador->nome, DadosJogador[0], DadosJogador[1]);
    printf("%s saiu o %d e o %d.\n\n", bot->nome, DadosBot[0], DadosBot[1]);

    if (ResultadoDadosJogador > ResultadoDadosBot)
    {
        jogador->turno = MEU_TURNO;
        bot->turno = NAO_E_MEU_TURNO;

        printf("%s e o primeiro a jogar!!\n\n", jogador->nome);
    }
    else
    {
        jogador->turno = NAO_E_MEU_TURNO;
        bot->turno = MEU_TURNO;

        printf("%s e o primeiro a jogar!!\n", bot->nome);
    }
}

