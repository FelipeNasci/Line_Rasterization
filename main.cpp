#include "main.h"

void teste1();
void test2();
void test3();

int x = 512, y = 0;
int incx = 0, incy = 1;
int a = 1;

//-----------------------------------------------------------------------------

void MyGlDraw(void) {

    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //************************************************************************

/*
    Point axis, axis1;

    axis1.color.r = 0;

    /////////////////////////////////
    //          EIXO X             //
    /////////////////////////////////
    axis.x = 0;
    axis.y = IMAGE_HEIGHT / 2;
    axis1.x = IMAGE_WIDTH;
    axis1.y = IMAGE_HEIGHT / 2;
    bresehan(axis,axis1);

    /////////////////////////////////
    //          EIXO Y             //
    /////////////////////////////////
    axis.x = IMAGE_WIDTH / 2;
    axis.y = 0;
    axis1.x = IMAGE_WIDTH / 2;
    axis1.y = IMAGE_HEIGHT;
    bresehan(axis,axis1);

*/

    //teste1();
    //test2();
    //test3();
    //test();

    drawLine();
    //drawTriangle();



}

void teste1()
{

    Point  p1, p2;

    //////////////////////////////////
    //  SEPARACAO DE QUADRANTES     //
    //////////////////////////////////

    p1.x = IMAGE_WIDTH / 2;
    p1.y = IMAGE_HEIGHT / 2;
    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT;
    equacao_geral_reta(p1,p2);

    p2.x = 0;
    p2.y = 0;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = 0;
    equacao_geral_reta(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT;
    equacao_geral_reta(p1,p2);

    ///////////////////////////////////
    //  SEPARACAO DE OCTANTES        //
    //////////////////////////////////

    p2.x = IMAGE_WIDTH / 4;
    p2.y = 0;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH / 4;
    p2.y = IMAGE_HEIGHT;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = 0;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = IMAGE_HEIGHT;
    equacao_geral_reta(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4;
    equacao_geral_reta(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    equacao_geral_reta(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    equacao_geral_reta(p1,p2);

}


void test2()
{

Point  p1, p2;

    //////////////////////////////////
    //  SEPARACAO DE QUADRANTES     //
    //////////////////////////////////

    p1.x = IMAGE_WIDTH / 2;
    p1.y = IMAGE_HEIGHT / 2;
    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT;
    DDA(p1,p2);

    p2.x = 0;
    p2.y = 0;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = 0;
    DDA(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT;
    DDA(p1,p2);

    ///////////////////////////////////
    //  SEPARACAO DE OCTANTES        //
    //////////////////////////////////

    p2.x = IMAGE_WIDTH / 4;
    p2.y = 0;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH / 4;
    p2.y = IMAGE_HEIGHT;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = 0;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = IMAGE_HEIGHT;
    DDA(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4;
    DDA(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    DDA(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    DDA(p1,p2);


}


void test3()
{

/*

Point  p1, p2;


    //////////////////////////////////
    //  SEPARACAO DE QUADRANTES     //
    //////////////////////////////////

    p1.x = IMAGE_WIDTH / 2;
    p1.y = IMAGE_HEIGHT / 2;
    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT;
    bresehan(p1,p2);

    p2.x = 0;
    p2.y = 0;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = 0;
    bresehan(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT;
    bresehan(p1,p2);

    ///////////////////////////////////
    //  SEPARACAO DE OCTANTES        //
    //////////////////////////////////

    p2.x = IMAGE_WIDTH / 4;
    p2.y = 0;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH / 4;
    p2.y = IMAGE_HEIGHT;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = 0;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = IMAGE_HEIGHT;
    bresehan(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4;
    bresehan(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    bresehan(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    bresehan(p1,p2);

*/


}

//-----------------------------------------------------------------------------

int main(int argc, char **argv) {

    // Inicializações.
    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;

    // Framebuffer scan loop.
    glutMainLoop();

    return 0;
}


