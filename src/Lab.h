#ifndef LAB_H // protectes from multiple including...
#define LAB_H // ... needs an #endif at bottom

//changes both foreground and background colors
void setColor(int foreGround, int backGround);

//changes foreground color while keeping background color
void setForeColor(int foreGround);

//changes background color while keeping foreground color
void setBackColor(int backGround);

//Colors reset: foreground white, background black
void resetColor();

//allows to place the cursor at any given position
void gotoxy(int x, int y);

//allows to draw a rectangle (double lines) at any given position
void showRectAt(int x, int y, int width, int height);

//allows to draw a rectangle (double lines) at any given position, rotated by 90? 
void show90RectAt(int x, int y, int width, int height);

//show a char at a designated position
void showCharAt(int x, int y, char c);

//write a 'string' verticaly at a designated position
void showVerticalWordAt(int x, int y, char c[], int charNumber);

//write an horizontal 'string' at a designated position
void printfAt(int x, int y, char c[]);

// print the ascii table in two locale Modes 
// usage sample: printAscii(174, 223, 4);
void printAscii(int N0, int N, int col);

#endif
