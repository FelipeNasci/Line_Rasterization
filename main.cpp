#include "main.h"

void Eq_Reta_Test();
void DDA_Test();
void Breseham_Test();

//-----------------------------------------------------------------------------

void MyGlDraw(void) {

    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //************************************************************************


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



      Eq_Reta_Test();
    //  DDA_Test();
    //  Breseham_Test();

    //  drawLine();
      drawTriangle();



}

void Eq_Reta_Test()
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


void DDA_Test()
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


void Breseham_Test()
{

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


