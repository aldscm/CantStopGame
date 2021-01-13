#include <stdio.h>
#include <stdlib.h>

#include "Jogo.h"

// Iniciar um novo jogo
void NovoJogo(int *option, Jogador *jogador, Jogador *bot, int *dados, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA])
{   
    MostrarTituloJogo();
    NovoJogador(jogador);
    NovoBot(bot);
    PrimeiroAJogar(jogador, bot);
    
    if (MostrarSubMenuJogo(option) == 1)
    {
		if (jogador->turno == MEU_TURNO) 
		{
			IniciarTurnoDoJogador(jogador, bot, dados, matrizJogadas);	
		} 
		else 
		{
			IniciarTurnoDoBot(jogador, bot, dados, matrizJogadas);	
		}
    }
}

// Define quem é o jogador a iniciar o jogo.
void PrimeiroAJogar(Jogador *jogador, Jogador *bot)
{
    int dadosJogador[NUMERO_DE_DADOS], resultadoDadosJogador = 0;
    int dadosBot[NUMERO_DE_DADOS], resultadoDadosBot = 0;

    system("cls");
    MostrarTituloJogo();

    printf("A lancar os dados...\n\n");

    do
    {
        LancarDados(dadosJogador, NUMERO_DE_DADOS);
        LancarDados(dadosBot, NUMERO_DE_DADOS);

        resultadoDadosJogador = SomaDados(dadosJogador, NUMERO_DE_DADOS);
        resultadoDadosBot = SomaDados(dadosBot, NUMERO_DE_DADOS);

        // Continua a lancar ate existir um vencedor
    } while (resultadoDadosJogador == resultadoDadosBot);

    printf("%s lancou %d, %d, %d e %d.\n\n", jogador->nome, dadosJogador[0], dadosJogador[1], dadosJogador[2], dadosJogador[3]);
    printf("%s lancou %d, %d, %d e %d.\n\n", bot->nome, dadosBot[0], dadosBot[1], dadosBot[2], dadosBot[3]);

    if (resultadoDadosJogador > resultadoDadosBot)
    {
        jogador->turno = MEU_TURNO;
        bot->turno = NAO_E_MEU_TURNO;

        printf("%s lancou um total de %d, joga primeiro!!\n\n", jogador->nome, resultadoDadosJogador);
    }
    else
    {
        jogador->turno = NAO_E_MEU_TURNO;
        bot->turno = MEU_TURNO;

        printf("%s lancou um total de %d, joga primeiro!!\n", bot->nome, resultadoDadosBot);
    }
}

// Lança os dados
void LancarDados(int *dados, int numeroTotalDeDados)
{
    int i;

    for (i = 0; i < numeroTotalDeDados; i++)
    {
        dados[i] = NumAleatorio(DADO_MIN_NUMBER, DADO_MAX_NUMBER);
    }
}

// Define as possivies jogadas do jogador.
void DefinirJogadas(int *dados, int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]) 
{
	// dados A, B, C e D. 
	// Associação A + B e C + D na posição 0
	matrizJogadas[0][0] = dados[0] + dados[1];
	matrizJogadas[0][1] = dados[2] + dados[3];
	
	// Associação A + C e B + D na posição 0	
	matrizJogadas[1][0] = dados[0] + dados[2];
	matrizJogadas[1][1] = dados[1] + dados[3];
	
	// Associação A + D e B + C na posição 0	
	matrizJogadas[2][0] = dados[0] + dados[3];
	matrizJogadas[2][1] = dados[1] + dados[2];
}

// Inicia o turno do jogador
void IniciarTurnoDoJogador(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]) 
{
	char jogadaSelecionada, escolha;
	int continuar = 1;
	
	while (continuar == 1)
	{
		system("cls");
		
		// Desenha o tabuleiro
		DesenharTabuleiro(jogador, bot);
		
		// Desenha no tabuleiro as fichas para o percurso avancado do jogador
		DesenharFichasDoPercursoAvancado(jogador);	 
					
		// Lança os dados
		LancarDados(dados, NUMERO_DE_DADOS);
		
		// Define a nova matriz de jogadas
		DefinirJogadas(dados, matrizJogadas);
		
		// Desenha o menu de possiveis jogadas
		setColor(0, 15);			
		showRectAt(100, 4, 80, 14);
		setColor(15, 0);
		
		// Desenha um quadrado com a cor do jogador (vermelho)
		gotoxy(104, 6);
		setColor(12, 12);			
		showRectAt(104, 5, 1, 1);
		resetColor();
		
		gotoxy(104, 6);
		printf(" %s escolha onde quer avancar: ", jogador->nome);
		gotoxy(104, 8);
		printf(" 1- Avancar em %d e %d ", matrizJogadas[0][0], matrizJogadas[0][1]);
		gotoxy(104, 10);
		printf(" 2- Avancar em %d e %d ", matrizJogadas[1][0], matrizJogadas[1][1]);
		gotoxy(104, 12);
		printf(" 3- Avancar em %d e %d ", matrizJogadas[2][0], matrizJogadas[2][1]);
		resetColor();
		
    	do 
		{
			gotoxy(104,14);	
			printf("Insira 1 a 3: ");
			fflush(stdin);
	    	gets(&jogadaSelecionada);
	    	fflush(stdin);
		} while(jogadaSelecionada != '1' && jogadaSelecionada != '2' && jogadaSelecionada != '3');
   		   	
	   	switch(jogadaSelecionada)
		{
	        case '1':
        	{
        		jogador->percursoAvancado[matrizJogadas[0][0] - 2]++;
	            jogador->percursoAvancado[matrizJogadas[0][1] - 2]++;
	            break;
			}
	        case '2':
			{
				jogador->percursoAvancado[matrizJogadas[1][0] - 2]++;
	            jogador->percursoAvancado[matrizJogadas[1][1] - 2]++;
	            break;
			}
	        case '3': 
			{
	        	jogador->percursoAvancado[matrizJogadas[2][0] - 2]++;
	            jogador->percursoAvancado[matrizJogadas[2][1] - 2]++;
	            break;;
			}
	        default: 
			{
				printf("Opcao invalida..");
				break;
			}
	    }
	     
	    do 
		{
			gotoxy(104,14);	
	    	printf("Quer continuar a jogar (s/n): ");
		    fflush(stdin);
	    	gets(&escolha);
	    	fflush(stdin);
		} while(escolha != 's' && escolha != 'n');
	        	
		switch(escolha)
		{
	        case 's': 
			{
	        	continuar = 1;
				break;
			}
	        case 'n': 
			{
	        	continuar = 0;
	            
				// Passa a vez ao Bot
				MudarTurno(jogador, bot, dados, matrizJogadas);
				
	        	break;	
			}
	        default: 
			{
	        	printf("Escolha invalida..");
				break;
			}
	    }
	}
}

// Iniciar o turno do Bot
void IniciarTurnoDoBot(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]) 
{
	char jogadaSelecionada, escolha;
	int continuar = 1;
	
	while (continuar == 1)
	{
		system("cls");
		
		// Desenha o tabuleiro
		DesenharTabuleiro(jogador, bot);
		
		// Desenha no tabuleiro as fichas para o percurso avancado do bot
		DesenharFichasDoPercursoAvancado(bot);	 
					
		// Lança os dados
		LancarDados(dados, NUMERO_DE_DADOS);
		
		// Define a nova matriz de jogadas
		DefinirJogadas(dados, matrizJogadas);
			
		// Desenha o menu de possiveis jogadas
		setColor(0, 15);			
		showRectAt(100, 4, 80, 14);
		setColor(15, 0);
		
		// Desenha um quadrado com a cor do bot (azul)
		gotoxy(104, 6);
		setColor(11, 11);			
		showRectAt(104, 5, 1, 1);
		resetColor();
		
		gotoxy(104, 6);
		printf(" %s escolha onde quer avancar: ", bot->nome);
		gotoxy(104, 8);
		printf(" 1- Avancar em %d e %d ", matrizJogadas[0][0], matrizJogadas[0][1]);
		gotoxy(104, 10);
		printf(" 2- Avancar em %d e %d ", matrizJogadas[1][0], matrizJogadas[1][1]);
		gotoxy(104, 12);
		printf(" 3- Avancar em %d e %d ", matrizJogadas[2][0], matrizJogadas[2][1]);
		resetColor();
		
		// O bot vai selecionar uma das jogadas
		jogadaSelecionada = BotSelecionaJogada(bot);
		
    	switch(jogadaSelecionada)
		{
	        case '1': 
			{
				bot->percursoAvancado[matrizJogadas[0][0] - 2]++;
	            bot->percursoAvancado[matrizJogadas[0][1] - 2]++;
	            break;
			}	            
	        case '2': 
			{		
	        	bot->percursoAvancado[matrizJogadas[1][0] - 2]++;
	            bot->percursoAvancado[matrizJogadas[1][1] - 2]++;
	            break;	
			}
	        case '3': 
			{
	        	bot->percursoAvancado[matrizJogadas[2][0] - 2]++;
	            bot->percursoAvancado[matrizJogadas[2][1] - 2]++;
	            break;	
			}
	        default: 
			{
				printf("Opcao invalida..");
				break;
			}
	    }
	    
		// O bot vai decidir se continua ou para por aqui   	 
	    escolha = BotDecideSeContinuaAJogar(bot);
	    
		switch(escolha)
		{
	        case 's': 
			{
	        	continuar = 1;
				break;
			}
	        case 'n': 
			{
	        	continuar = 0;
	            
				// Passa a vez ao Bot
				MudarTurno(jogador, bot, dados, matrizJogadas);	
	        	break;	
			}
	        default: 
			{
	        	printf("");
				break;
			}
	    }
	}
}

// Muda o turno 
void MudarTurno(Jogador *jogador, Jogador *bot, int *dados,  int matrizJogadas[MATRIZ_JOGADAS_LINHA][MATRIZ_JOGADAS_COLUNA]) 
{
	// Era o turno do jogador, muda para o Bot
	if (jogador->turno == MEU_TURNO) 
	{
		jogador->turno = NAO_E_MEU_TURNO;	 
		bot->turno = MEU_TURNO;
		
		// Guarda o percurso avançado como defenitivo
		CopiarPercursoAvancadoParaPercurso(jogador);
		
		// Faz reset ao percurso avançado
		ResetPercursoAvancado(jogador);
		
		// Passa a vez ao Bot
		IniciarTurnoDoBot(jogador, bot, dados, matrizJogadas);
	} 
	else // Era o turno do Bot, muda para o Jogador.
	{
		jogador->turno = MEU_TURNO;	 
		bot->turno = NAO_E_MEU_TURNO;
		
		// Guarda o percurso avançado como defenitivo
		CopiarPercursoAvancadoParaPercurso(bot);
		
		// Faz reset ao percurso avançado
		ResetPercursoAvancado(bot);
		
		// Passa a vez ao Jogador
		IniciarTurnoDoJogador(jogador, bot, dados, matrizJogadas);
	}
}


