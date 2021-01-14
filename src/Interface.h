#ifndef INTERFACE_H // protectes from multiple including...
#define INTERFACE_H // ... needs an #endif at bottom

// Mostra o menu principal
void MostarMenu(int *option);

// Mostra o submenu dentro da op��o 3 - Mostrar descri��o do jogo
int MostrarSubMenu();

// Mostra o submenu dentro da op��o 1 - Novo jogo
int MostrarSubMenuJogo();

// Mostra o titulo no jogo dentro da op��o 1 - Novo jogo
void MostrarTituloJogo();

// Mostra a descri��o do jogo. op��o 3 - Descricao do Jogo
int MostrarDescricao();

#endif
