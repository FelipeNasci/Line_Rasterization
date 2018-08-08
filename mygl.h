
#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas





void interpolaCor(Point *pointA, Point pointB)
{

    Color cor_aux;

    int dx = pointB.x - pointA -> x;            //  Distancia do ponto x inicial ate o final
    int dy = pointB.y - pointA -> y;            //  Distancia do ponto y inicial ate o final

    float distance;

        if( abs(dx) >= abs(dy) )                //  Em alguns casos (dependendo do angulo da reta)
            distance = (float) abs(dx);         //  dy ou dx podem assumir valores negativos
        else                                    //  O que prejudica a interpolacao de algumas retas
            distance = (float) abs(dy);


    /************************************************************************/
    /*****                  A COR AUXILIAR E IGUAL A:                   *****/
    /*****  ( COR_PONTO_A - COR_PONTO_B ) / DISTANCIA ENTRE OS PONTOS   *****/
    /************************************************************************/

    cor_aux.r = nearbyint( ( pointB.color.r - pointA -> color.r ) / distance );
    cor_aux.g = nearbyint( ( pointB.color.g - pointA -> color.g ) / distance );
    cor_aux.b = nearbyint( ( pointB.color.b - pointA -> color.b ) / distance );
    cor_aux.a = nearbyint( ( pointB.color.a - pointA -> color.a ) / distance );

    /************************************************************************/
    /*****  SE A COR NO PONTO_A FOR NEGATIVA OU MAIOR QUE 255 SIGNIFICA *****/
    /*****  QUE FOI ESTRAPOLADO O LIMITE DE BYTES NA MEMORIA, OU SEJA,  *****/
    /*****          GERA DISCREPANCIA DE CORES NA INTERPOLACAO          *****/
    /************************************************************************/

    if (pointA ->color.r < 0 || pointA -> color.r > 255)
        pointA -> color.r = pointB.color.r;
    else
        pointA -> color.r += cor_aux.r;

    if (pointA ->color.g < 0 || pointA -> color.g > 255)
        pointA -> color.g = pointB.color.g;
    else
        pointA -> color.g += cor_aux.g;

    if (pointA ->color.b < 0 || pointA -> color.b > 255)
        pointA -> color.b = pointB.color.b;
    else
        pointA -> color.b += cor_aux.b;

    if (pointA ->color.a < 0 || pointA -> color.a > 255)
        pointA -> color.a = pointB.color.b;
    else
        pointA -> color.a += cor_aux.a;

}


/******************************************************/
/*******       DESENHA TRIANGULOS NA TELA       *******/
/******************************************************/

void drawTriangle()
{

    Color cor;
    Point point1, point2, point3;

    // PRIMEIRO TRIANGULO

    point1.x = 40;
    point1.y = 10;

    point2.x = 20;
    point2.y = 120;

    point3.x = 60;
    point3.y = 120;

    fill_Triangle(point1, point2, point3);

//  drawLine(point1, point2);
//  drawLine(point1, point3);
//  drawLine(point2, point3);
//------------------------------------------

    point1.color.r = 255;
    point1.color.g = 0;
    point1.color.b = 255;

    point2.color.r = 100;
    point2.color.g = 0;
    point2.color.b = 100;

    point3.color.r = 150;
    point3.color.g = 0;
    point3.color.b = 0;


    //  SEGUNDO TRIANGULO

        point1.x = 70;
        point1.y = 10;

        point2.x = 110;
        point2.y = 10;

        point3.x = 90;
        point3.y = 120;


//        fill_Triangle(point1, point2, point3);

        drawLine(point1, point2);
        drawLine(point1, point3);
        drawLine(point2, point3);

    //------------------------------------------

    //  TERCEIRO TRIANGULO

        point1.x = 300;
        point1.y = 20;

        point2.x = 300;
        point2.y = 240;

        point3.x = 400;
        point3.y = 110;

        fill_Triangle(point1, point2, point3);

//        drawLine(point1, point2);
//        drawLine(point1, point3);
//        drawLine(point2, point3);

}


/******************************************************/
/*******  ALGORITMO DE BRESENHAM - PONTO MEDIO  *******/
/*******    PARA RASTERIZAR LINHAS UTILIZANDO   *******/
/*******          APENAS NUMEROS INTEIROS       *******/
/******************************************************/

void drawLine(Point pointA, Point pointB)
{

    if( pointA.x > pointB.x ){

        drawLine(pointB, pointA);
        return;
    }

    int dx, dy, inc_E, inc_NE, d_new;
    short slope = 1;

    dy = pointB.y - pointA.y;
    dx = pointB.x - pointA.x;

    if( abs(dx) >= abs(dy))             //  |dx|>|dy| nos 02 quadrantes
    {
        if( dy < 0){                    //  RESPONSAVEL PELA
            slope = -slope;             //  MUDANCA DE QUADRANTE
            dy = -dy;                   //  FAZ y DECREMENTAR
        }

        /*************************************/
        /** APENAS UMA SITUACAO É RELEVANTE **/
        /**     PARA DECISAO SITUACOES:     **/
        /**                                 **/
        /**  dx > dy; F(x + 1 , y + 1/2)    **/
        /**           desicao = 2dy - dx    **/
        /**           inc_e   = 2dx         **/
        /**           inc_NE  = 2*(dy - dx) **/
        /*************************************/

        d_new = 2*dy - dx;                          //  FUNCAO DE DECISAO
        inc_E = 2*dy;                               //  y PERMANECE
        inc_NE = 2*dy - 2*dx;                       //  y AVANCA UM PIXEL

        while(pointA.x <= pointB.x){

            putPixel(pointA);
            pointA.x++;

            if (d_new < 0)
                d_new += inc_E;
            else{
                d_new += inc_NE;
                pointA.y += slope;
            }

            interpolaCor (&pointA, pointB);

        }
    }
    else
    {
        if(dy > 0)                          //  slope FUNCIONA COMO UM SINAL
            slope = -1;                     //  DE ACORDO COM A INCLINACAO DA RETA

                                            /*********************************/
        d_new = dy + slope * 2*dx;          /** MODIFICACOES FEITAS PARA    **/
        inc_E = slope * 2*dx;               /**     DIMINUIR QUANTIDADE DE  **/
        inc_NE = 2*dy + slope * 2*dx;       /**             CODIGO          **/
                                            /*********************************/

        /**************************************************************************/
        /**                           02 SITUACOES:                              **/
        /**                                                                      **/
        /**  dy > 0; F(x + 1/2 , y - 1)     ****  dy < 0; F(x + 1/2 , y + 1)     **/
        /**          desicao = dy - 2dx     ****          desicao = dy + 2dx     **/
        /**          inc_e   = -2dx         ****          inc_e   = 2dx          **/
        /**          inc_NE  = 2*(dy - dx)  ****          inc_NE  = 2*(dy + dx)  **/
        /**                                 ****                                 **/
        /**************************************************************************/

        if(slope < 0){                      //  INVERTE OS SINAIS PARA DECISAO DO
            inc_E = -inc_E;                 //  INCREMENTO DE x - ISTO INFLUI NA
            inc_NE = -inc_NE;               //  DECISAO
        }

        while(pointA.y != pointB.y){

            putPixel(pointA);
            pointA.y += -slope;

            if (d_new < 0)
                d_new += inc_E;
            else{
                d_new += inc_NE;
                pointA.x ++;            //  Y INCREMENTA OU DECREMENTA (DEPENDE DE dy)
            }

            interpolaCor (&pointA, pointB);
        }
    }

}

/******************************************************/
/*******     PREENCHE UM TRIANGULO DADO         *******/
/*******            DETERMINADA COR             *******/
/******************************************************/

void fill_Triangle( Point pointA, Point pointB, Point pointC )
{

if( pointB.x > pointC.x ){

        fill_Triangle(  pointA, pointC, pointB );
        return;
    }

    drawLine(pointA, pointB);

    int dx, dy, inc_E, inc_NE, d_new;
    short slope = 1;

    dy = pointC.y - pointB.y;
    dx = pointC.x - pointB.x;

    if( abs(dx) >= abs(dy))
    {
        if( dy < 0){
            slope = -slope;
            dy = -dy;
        }

        d_new = 2*dy - dx;
        inc_E = 2*dy;
        inc_NE = 2*dy - 2*dx;

        while(pointB.x <= pointC.x){


            pointB.x++;

            if (d_new < 0)
                d_new += inc_E;
            else{
                d_new += inc_NE;
                pointB.y += slope;
            }
                drawLine(pointA, pointB);

        }
    }
    else
    {
        if(dy > 0)
            slope = -1;

        d_new = dy + slope * 2*dx;
        inc_E = slope * 2*dx;
        inc_NE = 2*dy + slope * 2*dx;


        if(slope < 0){
            inc_E = -inc_E;
            inc_NE = -inc_NE;
        }

        while(pointB.y != pointC.y){

            pointB.y += -slope;

            if (d_new < 0)
                d_new += inc_E;
            else{
                d_new += inc_NE;
                pointB.x ++;
            }

           drawLine(pointA, pointB);
        }
    }


}

/******************************************************/
/*******     PLOTA O PIXEL DE DETERMINADA       *******/
/*******            COR NA TELA                 *******/
/******************************************************/

void putPixel(Point point)
{

    FBptr[offset(point) + RED] = point.color.r;
    FBptr[offset(point) + GREEN] = point.color.g;
    FBptr[offset(point) + BLUE] = point.color.b;
    FBptr[offset(point) + ALPHA] = point.color.a;
}


/******************************************************/
/*******  RETORNA A POSICAO NO COLOR_BUFFER DE  *******/
/*******        ACORDO COM AS COORDENADAS       *******/
/******************************************************/

unsigned int offset(Point point)
{
    return point.x * 4 + point.y * IMAGE_WIDTH * 4;
}


/******************************************************/
/*******  RASTERIZA LINHAS A PARTIR DA EQUACAO  *******/
/*******    DA RETA - (NAO USUAL EM PROJETOS)   *******/
/******************************************************/

void equacao_geral_reta( Point pointA, Point pointB )
{
    /*******************************/
    /**     y - y0 = m(x - x0)    **/   //x0 e y0 sao o ponto inicial
    /**     y - y0 = mx + (-mx0)  **/
    /**     y = mx + (-mx0 + y0)  **/
    /**     y = mx + b            **/   //Equacao Reduzida da reta
    /*******************************/

    GLfloat dx, dy, b, m;

    if( pointA.x > pointB.x ){
        equacao_geral_reta( pointB,  pointA);
        return;
    }

    dy = pointB.y - pointA.y;
    dx = pointB.x - pointA.x;

    //Angulo da reta = 90º -> RETA VERTICAL

    if(dx == 0){

        while (pointA.y <= pointB.y)
        {
            putPixel(pointA);
            pointA.y++;
        }
        return;
    }


    //Angulo da reta < 1

    if(dx > dy){

        m = dy / dx;
        b = pointA.y - ( m * pointA.x );

            while (pointA.x < pointB.x)
            {
                putPixel(pointA);

                pointA.x++;
                pointA.y = round( ( m * pointA.x ) + b );

            }

    } else {

        m = dx / dy;
        b = pointA.x - ( m * pointA.y );

            while (pointA.y < pointB.y)
            {

                putPixel(pointA);

                pointA.y++;
                pointA.x = round( (m * pointA.y) + b ) ;

            }
    }

}


/******************************************************/
/*******        DDA - RASTERIZA LINHAS SEM      *******/
/*******          NECESSIDADE DE EQUACOES       *******/
/******************************************************/

void DDA (Point pointA, Point pointB)
{

    /***************    EXPLICACAO  ***************

    //  AO CONTRARIO DA EQUACAO GERAL DA RETA, ESTE
    //  ALGORITMO NAO UTILIZA DE UMA 'FORMULA' PARA
    //  ENCONTRAR O PROXIMO PIXEL A SER LIGADO.

    //  INCREMENTA-SE X ATE CHEGAR AO X_FINAL E
    //  AO MESMO TEMPO ADICIONA-SE A INCLICACAO DA
    //  RETA A Y.

    //  NESTE CASO UTILIZAMOS UMA VARIAVEL AUXILIAR
    //  PARA SER ADICIONADA A INCLINACAO, POIS 'Y'
    //  EH UMA VARIAVEL INTEIRA E A INCLINACAO UM
    //  NUMERO REAL.

    //  ESTE CODIGO TEM VANTAGEM SOBRE A EQUACAO GERAL
    //  DA RETA, POIS NAO EH NECESSARIO REALIZAR DIVERSAS
    //  MULTIPLICACOES (O QUE FAZ DA EQ. DA RETA UM
    //  ALGORITMO CARO).

    //  POREM ESTE ALGORITMO AINDA PODE SER MELHORADO
    //  TENDO EM VISTA QUE ELE AINDA TRABALHA COM NUMEROS
    //  REAIS E ARREDONDAMENTOS

    ********************************************************/


    if(pointA.y > pointB.y){
        DDA(pointB, pointA);
        return;
    }

    Color color;
    color.b = 0;
    color.g = 100;

    GLfloat dx, dy, slope;
    GLfloat aux = 0;            //  PONTO_FLUTUANTE PARA AUXILAR SE Y INCREMENTA

    dx = pointB.x - pointA.x;
    dy = pointB.y - pointA.y;

    if( abs(dx) >= abs(dy) ){

        slope = dy / dx;

        if(pointA.x <= pointB.x){

            while (pointA.x <= pointB.x)
            {
                putPixel(pointA);

                pointA.x++;
                aux += slope;

                if (aux >= 0.5){
                    aux -= 1;
                    pointA.y++;
                }
            }

        }else{

            while(pointA.x > pointB.x)
            {
                putPixel(pointA);
                pointA.x--;
                aux += slope;

                if(aux < 0.5){
                    aux += 1;
                    pointA.y ++;
                }
            }

        }

    }
    else{

        slope = dx / dy;

        while(pointA.y <= pointB.y){

            putPixel(pointA);
            pointA.y++;
            aux += slope;

            if(aux < 0.5){
                aux += 1;
                pointA.x --;
            }
            else {
                aux -= 1;
                pointA.x ++;
            }

        }

    }


}


/******************************************************/
/*******     TESTE DA FUNCAO PUT_PIXEL()        *******/
/*******     IMPRESSAO DE VARIOS PONTOS         *******/
/******************************************************/


void pixel()
{
    int limite = 999999;                        //GERA 10000 PONTOS

    Point a;

    Color cor;

    cor.g = 0;
    cor.b = 0;
    cor.r = 0;

    srand( (unsigned) time(NULL));          //GERA NUMEROS ALEATORIOS

    clearScreen(cor);

     for (int i = 0; i < limite; i++)
     {
        a.x = rand() % IMAGE_WIDTH;
        a.y = rand() % IMAGE_HEIGHT;

        a.color.r = rand() % 255;
        a.color.g = rand() % 255;
        a.color.b = rand() % 255;
        a.color.a = rand() % 255;

        putPixel(a);

     }
}

/******************************************************/
/*******     TESTE DA FUNCAO DRAWLINE()         *******/
/*******     IMPRESSAO DE VARIAS RETAS          *******/
/******************************************************/

void line(){

    Point pointA, pointB;

    srand( (unsigned) time(NULL));          //GERA NUMEROS ALEATORIOS

    int limite = 150;                        //  Limite de retas por frame

    Color cor;
    cor.r = 0;
    cor.g = 20;
    cor.b = 90;

    clearScreen(cor);

    for (int i = 0; i < limite; i++)
    {
        //pointA.x = IMAGE_WIDTH / 2;
        //pointA.y = IMAGE_HEIGHT/ 2;
        pointA.x = rand() % IMAGE_WIDTH;
        pointA.y = rand() % IMAGE_HEIGHT;

        pointA.color.r = rand() % 255;
        pointA.color.g = rand() % 255;
        pointA.color.b = rand() % 255;
        pointA.color.a = rand() % 255;

        pointB.x = rand() % IMAGE_WIDTH;
        pointB.y = rand() % IMAGE_HEIGHT;

        pointB.color.r = rand() % 255;
        pointB.color.g = rand() % 255;
        pointB.color.b = rand() % 255;
        pointB.color.a = rand() % 255;

        drawLine(pointA, pointB);

     }

}


/******************************************************/
/*******     LIMPA A TELA COM UMA COR           *******/
/*******            PREDEFINIDA                 *******/
/******************************************************/

void clearScreen(Color cor){

    Point p;

    p.color = cor;

    for(p.x = 0; p.x < IMAGE_WIDTH; p.x++)
        for (p.y = 0; p.y < IMAGE_HEIGHT; p.y++)
            putPixel(p);

}

#endif // _MYGL_H_


