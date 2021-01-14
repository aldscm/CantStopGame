#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para usar o sleep() no bot

#include "Constants.h"
#include "Interface.h"
#include "Funcoes.h"
#include "Jogador.h"
#include "Jogo.h"

int main() {
	int option = 0, flagSair = 0;
	Jogador jogador, bot;
	
	int dados[NUMERO_DE_DADOS];	
	int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA];
	
	system("MODE con cols=200 lines=60");
	srand((int)time(NULL));

	do
    {
       if (option == 0) 
	   {
       	 MostrarMenu(&option);
       }

        switch (option)
        {
            // Novo jogo
            case 1:
            {
                if (IniciarNovoJogo(&option, &jogador, &bot, dados, matrizJogadas) == 1) 
				{
					// Começa o jogo
                	Jogar(&jogador, &bot, dados, matrizJogadas);	
				} 
			
				// Renicia a variavel para manter no menu principal
				option = 0;
                break;
            }
            // Carregar jogo
            case 2:
            {
            	// Carrega os dados do ficheiro
                if (CarregarJogo(&jogador, &bot) == 1) 
				{
					// Retoma o jogo
                	Jogar(&jogador, &bot, dados, matrizJogadas);	
				}
				
      			// Renicia a variavel para manter no menu principal
                option = 0;
                break;
            }
            // Descrição do jogo
            case 3:
            {
                if (MostrarDescricao() == 1) 
				{
					// Renicia a variavel para manter no menu principal
					option = 0;
				} 
				else 
				{
					// É para sair da aplicação
					system("cls");
					option = 4;
				}
				
                break;
            }
            // Sair
            case 4: 
            {
                // Liberta os vetores criados através do "malloc" antes de sair
			    free(jogador.percurso);
			    free(jogador.percursoAvancado);
				free(bot.percurso);
			    free(bot.percursoAvancado);
			    
				flagSair = 1;
			    exit(1);
            }
            default:
                break;
        }
        
     // Só sai do loop quando o utilizador selecionar a opção 4 - Sair.
    } while (flagSair == 0);
    
	return 1;
}
