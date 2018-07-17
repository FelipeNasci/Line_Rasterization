#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define IMAGE_WIDTH  512 // número de colunas da imagem.
#define IMAGE_HEIGHT 512 // número de linhas da imagem.

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
void drawLine();
void drawTriangle();

//  ALGORITMOS PARA RASTERIZAR LINHAS
void bresehan(Point pointA, Point pointB);
void DDA (Point pointA, Point pointB);
void equacao_geral_reta(Point pointA, Point pointB);


//  FUNCOES PARA ACENDER O PIXEL
unsigned int offset (Point point);
void putPixel (Point point);
void interpolaCor (Point *pointA, Point pointB, Color *cor_aux);


//  FUNCOES AUXILIARES
short sinal(int value);
short between_0_1 (int value, int distance);

//  FUNCAO DE TESTE
void pixel();

#endif // _DEFINITIONS_H_


