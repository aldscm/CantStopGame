#include <stdio.h>
#include <stdlib.h>

#include "Interface.h"

// Mostra o menu principal
void MostrarMenu(int *option)
{
    int flag = 0;

    // Limpa o ecra
    system("cls");

    printf(" ================================================\n");
    printf(" CAN'T STOP by Ana Marinho, 72991 Eng.Informatica\n");
    printf(" ================================================\n\n");

    printf(" 1 - Novo Jogo\n");
    printf(" 2 - Carregar partida \n");
    printf(" 3 - Descricao do Jogo\n");
    printf(" 4 - Sair\n\n");

    do
    {
        // volta a inicializar a zero a flag
        flag = 0;
        
        printf(" Selecione a opcao: ");
        fflush(stdin);
        // Como a variavel option é um apontador, não preciso usar o & (endereço)
        // Basta passar a variavel option sem o *, ou seja, a o endereço para onde o apontador está a apontar.
        scanf("%d", option); 

        if (*option != 1 && *option != 2 && *option != 3 && *option != 4)
        {
            printf("\n ERRO: Opcao invalida\n\n", *option);
            flag++;
        }

        // Apenas sai do ciclo se for uma opção válida 
    } while (flag != 0);

    // Limpa o ecra.
    system("cls");
}

// Mostra o submenu dentro da opção 1 - Novo jogo
int MostrarSubMenu()
{
    int flag = 0, subMenu = 0;

    printf("\n\n -------------------\n");
    printf(" 1 - Menu Principal\n");
    printf(" 2 - Sair\n");
    printf(" -------------------\n");

    do
    {
        // renicializa a flag
        flag = 0;

        printf("\n Selecione a opcao: ");
        fflush(stdin);
        scanf("%d", &subMenu);

        if (subMenu != 1 && subMenu != 2)
        {
            printf("\n ERRO: Opcao invalida\n", subMenu);
            flag++;
        }

        // Só sai do loop se a opção for válida.
    } while (flag != 0);

    if (subMenu == 1)
    {
    	return 1;
    } 
	
	return 0;
}

// Mostra o titulo no jogo dentro da opção 1 - Novo jogo
void MostrarTituloJogo()
{
    printf(" =======================\n");
    printf(" CAN'T STOP - NOVO JOGO\n");
    printf(" =======================\n\n");
}

// Mostra a descrição do jogo. opção 3 - Descricao do Jogo
int MostrarSubMenuJogo()
{
    int flag = 0, subMenu = 0;

    printf("\n\n -------------------\n");
    printf(" 1 - Menu Principal\n");
    printf(" 2 - Continuar\n");
    printf(" -------------------\n");

    do
    {
        flag = 0;

        printf("\n Selecione opcao: ");
        fflush(stdin);
        fflush(stdin);
        scanf("%d", &subMenu);

        if (subMenu < 1 || subMenu > 2)
        {
            printf("\n ERRO: Opcao invalida\n");
            flag++;
        }
    } while (flag != 0);

    if (subMenu == 2)
    {
    	return 1;
    }
    
    return 0;
}

int MostrarDescricao()
{
	// Limpa o ecra
    system("cls");
    
    printf(" ================\n");
    printf(" JOGO CAN'T STOP\n");
    printf(" ================\n\n");

    printf(" Jogo competitivo onde varios alpinistas procuram alcancar o topo da montanha.\n\n");

    printf(" Este jogo encarna dois velhos ditados populares portugueses:'\n");
    printf("  - 'Quem nao arrisca nao petisca';\n");
    printf("  - 'Quem tudo quer, tudo perde'.\n\n");
    printf(" Ha que gerir o equilibrio entre os dois.\n\n\n");

    printf(" OBJECTIVO\n");
    printf(" ---------\n\n");
    printf(" O objetivo do jogo e alcancar o topo da montanha em tres pistas diferentes no final do seu turno(assinaladas por numeros de 2 ate 12) atraves da escalada das equipas de alpinistas decada jogador.\n\n\n");

    printf(" PREPARACAO DO JOGO\n");
    printf(" ------------------\n\n");
    printf(" Colocar o tabuleiro.\n");
    printf(" Boa disposicao para jogar.\n\n\n");

    printf(" DESENROLAR DO JOGO\n");
    printf(" ------------------\n\n");
    printf(" O primeiro jogador lanca os 4 dados.\n\n");
    printf(" De seguida soma-os dois a dois de forma a obter 2 resultados(que estarao no intervalo de 2 a 12).\n\n");
    printf(" E possivel fazer 3 combinacoes diferentes agrupando os dados dois-a-dois.\n\n");
    printf(" Para cada uma das somas obtidas, se o jogador ainda nao tem marcadores na(s) pista(s) desse(s) numero(s) coloca os alpinistas que tem na mao, sobre a casa de partida das pistas dos numeros obtidos com os pares de dados escolhidos.\n\n");
    printf(" Se o resultado for igual nos dois pares, sobe o alpinista 2 casas nessa pista.\n\n");
    printf(" Caso ja possua um marcador nessa pista o alpinista e colocado na casa seguinte a do marcador.\n\n");
    printf(" Em seguida o jogador decide se quer continuar a jogar ou parar.\n\n");
    printf(" Quando decide parar, substitui os alpinistas por marcadores da sua cor, ou se ja tiver um marcador nessa pista, sobe esse marcador para o local onde parou com o alpinista.\n\n");
    printf(" E passa os dados e os alpinistas para o jogador que estiver a sua esquerda.\n\n");
    printf(" No caso de decidir continuar a jogar, lanca novamente os dados e repete o processo;\n");
    printf(" Se conseguir obter pelo menos 1 par de dados com um resultado que permita subir um dos seus tres alpinistas(ou colocar um em jogo se ainda o tiver por colocar no tabuleiro), pode continuar a jogar;\n");
    printf(" Caso contrario, se os numeros obtidos nao corresponderem a um dos 3 numeros dos alpinistas que estao a escalar, o jogador e forcado a parar e perde qualquer tipo de progresso atingido nesse turno, passando os dados ao jogador da esquerda.\n\n");
    printf(" Sempre que um jogador chega ao topo da montanha num ou mais numeros e decide parar, conquista o respetivo local do cume;\n");
    printf(" Todos os jogadores que tenham marcadores nesse numero sao obrigados a retira-los e essa pista deixa de estar disponivel para ser escalada!\n\n\n");

    printf(" FIM DO JOGO\n");
    printf(" -----------\n\n");
    printf(" O primeiro jogador a alcancar e fixar o topo de tres pistas da montanha e o vencedor!\n");

    return MostrarSubMenu();
}

