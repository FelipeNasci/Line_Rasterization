#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define IMAGE_WIDTH  512 // n�mero de colunas da imagem.
#define IMAGE_HEIGHT 512 // n�mero de linhas da imagem.

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

unsigned char * FBptr;

typedef struct Color
{   //INTENSIDADE DAS CORES
    int r = 255;
    int g = 255;
    int b = 255;
    int a = 0;
} Color;

typedef struct Point
{
    int x;
    int y;

    struct Color color;

} Point;


//  FUNCOES SOLICITADAS PELO PROFESSOR

void drawLine(Point pointA, Point pointB);
void dxdy(Point pointA, Point pointB);
void dydx (Point pointA, Point pointB);

void drawTriangle(Point pointA, Point pointB, Point pointC, short fill_);


//  ALGORITMOS PARA RASTERIZAR LINHAS

void DDA (Point pointA, Point pointB);
void equacao_geral_reta(Point pointA, Point pointB);
void bresenham(Point pointA, Point pointB);


//  FUNCOES PARA ACENDER O PIXEL
unsigned int offset (Point point);
void putPixel (Point point);
void interpolaCor(Point *pointA, Point pointB);


//  EXTRAS
void fill_Triangle(Point pointA, Point pointB, Point PointC);
void drawCirculo(int xC, int yC, int r);


//  FUNCAO DE TESTE
void pixel();
void line();
void triangle();
void clearScreen(Color cor);



#endif // _DEFINITIONS_H_


