#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Estruturas.h"
#include "Interface.h"
#include "Jogo.h"

int main() {
	int option = 0, flagSair = 0;
	Jogador jogador, bot;
	
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
                NovoJogo(&option, &jogador, &bot);
                break;
            }
            // Descrição do jogo
            case 3:
            {
                MostrarDescricao(&option);
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
    } while (flagSair == 0); // Só sai do loop quando o utilizador selecionar a opção 4 - Sair.
    
	return 1;
}
