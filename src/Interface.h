#ifndef INTERFACE_H // protectes from multiple including...
#define INTERFACE_H // ... needs an #endif at bottom

// Mostra o menu principal
void MostarMenu(int *option);

// Mostra o submenu dentro da opção 3 - Mostrar descrição do jogo
int MostrarSubMenu();

// Mostra o submenu dentro da opção 1 - Novo jogo
int MostrarSubMenuJogo();

// Mostra o titulo no jogo dentro da opção 1 - Novo jogo
void MostrarTituloJogo();

// Mostra a descrição do jogo. opção 3 - Descricao do Jogo
int MostrarDescricao();

#endif
