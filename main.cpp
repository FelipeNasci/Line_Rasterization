#include "main.h"

void Eq_Reta_Test();
void DDA_Test();
void Bresenham_Test();
void draw_Triangle_Test();

//-----------------------------------------------------------------------------

void MyGlDraw(void) {

    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //************************************************************************


      Bresenham_Test();
    //  Eq_Reta_Test();
    //  DDA_Test();
    //  draw_Triangle_Test();

    //drawTriangle();
    //drawCirculo(512, 255, 255);

    //  pixel();
    //  line();
      triangle();


}


void Eq_Reta_Test()
{

    Point  p1, p2;

    Point axis, axis1;

    axis1.color.r = 0;

    /////////////////////////////////
    //          EIXO X             //
    /////////////////////////////////
    axis.x = 0;
    axis.y = IMAGE_HEIGHT / 2;
    axis1.x = IMAGE_WIDTH;
    axis1.y = IMAGE_HEIGHT / 2;
    equacao_geral_reta(axis,axis1);

    /////////////////////////////////
    //          EIXO Y             //
    /////////////////////////////////
    axis.x = IMAGE_WIDTH / 2;
    axis.y = 0;
    axis1.x = IMAGE_WIDTH / 2;
    axis1.y = IMAGE_HEIGHT;
    equacao_geral_reta(axis,axis1);


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


void DDA_Test()
{

Point  p1, p2;

    Point axis, axis1;

    axis1.color.r = 0;

    /////////////////////////////////
    //          EIXO X             //
    /////////////////////////////////
    axis.x = 0;
    axis.y = IMAGE_HEIGHT / 2;
    axis1.x = IMAGE_WIDTH;
    axis1.y = IMAGE_HEIGHT / 2;
    equacao_geral_reta(axis,axis1);

    /////////////////////////////////
    //          EIXO Y             //
    /////////////////////////////////
    axis.x = IMAGE_WIDTH / 2;
    axis.y = 0;
    axis1.x = IMAGE_WIDTH / 2;
    axis1.y = IMAGE_HEIGHT;
    equacao_geral_reta(axis,axis1);


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


void Bresenham_Test()
{
    Point axis, axis1;
    Point  p1, p2;

    /////////////////////////////////
    //          EIXO X             //
    /////////////////////////////////
    axis.x = IMAGE_WIDTH / 2;
    axis.y = IMAGE_HEIGHT / 2;

    //  COR
    axis.color.r = 0;
    axis.color.g = 255;
    axis.color.b = 255;

    axis1.x = IMAGE_WIDTH;
    axis1.y = IMAGE_HEIGHT / 2;

    //  COR
    axis1.color.r = 0;
    axis1.color.g = 0;
    axis1.color.b = 255;

    drawLine(axis,axis1);       //  DESENHA A LINHA

    axis1.x = 0;
    axis1.y = IMAGE_HEIGHT / 2;

    drawLine(axis,axis1);

    /////////////////////////////////
    //            EIXO Y           //
    /////////////////////////////////

    axis.x = IMAGE_WIDTH / 2;
    axis.y = IMAGE_HEIGHT / 2;

    axis1.x = IMAGE_WIDTH / 2;
    axis1.y = IMAGE_HEIGHT;

    drawLine(axis,axis1);

    axis1.x = IMAGE_WIDTH / 2;
    axis1.y = 0;

    drawLine(axis,axis1);


    //////////////////////////////////
    //  SEPARACAO DE QUADRANTES     //
    //////////////////////////////////

    p1.color.r = 0;
    p1.color.g = 150;
    p1.color.b = 255;

    p2.color.r = 180;
    p2.color.g = 255;
    p2.color.b = 0;

    p1.x = IMAGE_WIDTH / 2;
    p1.y = IMAGE_HEIGHT / 2;


    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT;
    drawLine(p1,p2);

    p2.x = 0;
    p2.y = 0;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = 0;
    drawLine(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT;
    drawLine(p1,p2);

    ///////////////////////////////////
    //  SEPARACAO DE OCTANTES        //
    //////////////////////////////////

    p2.x = IMAGE_WIDTH / 4;
    p2.y = 0;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH / 4;
    p2.y = IMAGE_HEIGHT;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = 0;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH / 4 + IMAGE_WIDTH / 2;
    p2.y = IMAGE_HEIGHT;
    drawLine(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4;
    drawLine(p1,p2);

    p2.x = 0;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    drawLine(p1,p2);

    p2.x = IMAGE_WIDTH;
    p2.y = IMAGE_HEIGHT / 4 + IMAGE_HEIGHT / 2;
    drawLine(p1,p2);

}

void draw_Triangle_Test()
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

    drawTriangle(point1, point2, point3, 1);    //Preenche
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


        drawTriangle(point1, point2, point3, 0 );

    //------------------------------------------

    //  TERCEIRO TRIANGULO

        point1.x = 300;
        point1.y = 20;

        point2.x = 300;
        point2.y = 240;

        point3.x = 400;
        point3.y = 110;

        drawTriangle(point1, point2, point3, 1 );

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


