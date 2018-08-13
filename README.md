# T1 ICG - Rasterização de Linhas

## Introdução

  Este trabalho tem como objetivo apresentar alguns algoritmos para rasterização de linhas em um monitor gráfico diretamente e memória de video, como os sistema operacionais modernos impedem acesso direto a memória de vídeo, foi utilizado um framework para realizar esta simulação.

  Mas antes, devemos tomar conhecimento do que são primitivas, rasterização, como rasterizar primitivas gráficas e o funcionamento em um monitor gráfico.
  
## Rasterização

  Primitivas em computação gráfica são elementos básicos, como pontos e retas. A rasterização é responsável por capturar estas primitivas e transformá-las em novas imagens, ou seja, é justamente o que acontece em monitores, displays, e até mesmo impressoras.

## Monitores

  Inicialmente devemos imaginar o display como uma matriz _(grid)_ bidimensional, composto por **_m linhas_** e **_n colunas_**, onde no centro de cada posição da matriz existe um ponto com um par de coordenadas _(x,y)_. 
  
![Matriz-Grid](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/grids.png?raw=true)

  Note, nas figuras acima o Ponto _(0,0)_ está situado no topo a esquerda, e o Ponto _(m-1, n-1)_ está posicionado no canto inferior direito. Assim estão dispostos os pontos em um display.
  
  Outro fato a se observar é a figura "Grid - 2" é uma abstração de "Grid - 1", e esta servirá de modelo para os próximos exemplos.
  
## Pixel
  Um Pixel é um ponto luminoso no monitor, formando uma imagem a partir de um conjunto de pixels. 
  
  É composto por três canais de cores - Vermelho, Verde e Azul, e mais um canal para tratar a transparência destas cores, chamamos este canal de alpha, compondo um sistema chamado RGBA.
  
  ![Disposição_Pixel](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/Disposi%C3%A7%C3%A3o_Pixel.png?raw=true)
  
  Estas cores são armazenadas em uma região de memória chamada _Color_Buffer_ , que é responsável por armazenar informações da imagem que será rasterizada na tela.
  
  ![ColorBuffer](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/ColorBuffer.png?raw=true)
  
  _OBS: Caso o computador não possua uma placa de vídeo dedicada, o Color_Buffer utiliza parte da memória RAM._
  
  ![ColorBuffer](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/ColorBuffer2.png?raw=true)

  Tendo em vista que o color buffer é uma região de memória, e a única informação que temos são as coordenadas no monitor, utilizamos uma função offset para encontrar a informação para determinada coordenada do monitor.

>   offset = 4 * (x + y * IMAGE_WIDTH)

_OBS: O _offset_ encontra a posição de memória de determinado ponto _(x,y)_ , para que seja selecionada uma cor se faz necessário acessar os canais correspondente a cor desejada e informar sua intensidade (0 até 255), como é demonstrado na função putPixel()._

````C
void putPixel(Point point)
{
    FBptr[offset(point) + RED] = point.color.r;		  //RED   == 0
    FBptr[offset(point) + GREEN] = point.color.g;		//GREEN == 1
    FBptr[offset(point) + BLUE] = point.color.b;		//BLUE  == 2
    FBptr[offset(point) + ALPHA] = point.color.a;		//ALPHA == 3
}
````
## Rasterização de linhas

Após entender a interação entre monitores e computadores, os algoritmos para traçar retas serão entendidos sem maiores dificuldades.

Antes de iniciar, assumimos que:

>   Δx ≥ Δy, ou seja, 0 <= angulo_reta <= 1
>   Nosso grid tem apenas coordenadas positivas (maior ou igual a 0)
    >P(x0,y0) = (0,0)
>A distância entre cada pixel é 1

Note que retas que possuem ângulos iguais a 0°, 45° e 90° são triviais de serem rasterizados.

![angulos_triviais](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/Pixel%20angulos%200%2090%2045.png?raw=true)

Porém, retas com angulações diferentes demandam um maior esforço para serem desenhadas. A seguir são demonstrados alguns algoritmos para realizar esta tarefa.

### Equação geral da reta

Podemos representar uma reta _r_ do plano cartesiano por meio de uma equação. Essa equação pode ser obtida a partir de um ponto A(xA, yA) e do coeficiente angular _m_ dessa reta.

Considere uma reta r não-vertical, de coeficiente angular m, que passa pelo ponto A(xA, yA). Vamos obter a equação dessa reta, tomando um ponto _P(x, y)_ tal que P ≠ A.

Este é o meio mais trivial de se obter uma reta através de dois pontos. Vajamos a seguir seu desenvolvimento.

````
y - y0 = m * (x - x0)  
y - y0 = (m * x) + (-m * x0)
     y = (m * x) + (-m * x0)  + y0
     y = (m * x) + [ (-m * x0)  + y0 ]
     y = m * x + b
````
![Eq_Geral_Reta](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/Equa%C3%A7%C3%A3o%20Geral.png?raw=true)

Através desta equação podemos encontrar qualquer reta.
OBS: _Devemos nos atentar nos casos em que:_
````
Δx = 0 (pois inviabiliza a divisão Δy/Δx).
Δx > Δx, isso nos obriga a trocar o valor dos pontos.
````
A equação geral da reta é ineficiente em meios computacionais pois, para executá-la é necessário realizar multiplicações e arredondamentos de números reais a cada ponto que percorremos e isso torna o processamento lento.

### DDA

Uma alternativa mais leve é o Digital Differential Analyzer (DDA), o mesmo deriva da Equação Geral da Reta, porém, ao contrario da _Equação Geral da Reta_ , não é necessário realizar multiplicações a cada ponto encontrado.

O algoritmo trabalha de forma incremental, adicionando a _y_ (encontrado na iteração anterior) o _Coeficiente Angular_ da reta. Vejamos seu desenvolvimento:


Seja P(xi,yi) Um ponto a ser plotado no display.
````
P(x0,y0) = y0 = m * xi + b      //Equação_Geral_Reta
````

Então...
````
yi + 1 = m * (xi + 1) + b
yi + 1 = m * xi + m + b
yi + 1 = (m * xi +  b) + m
yi + 1 = y_anterior + m
yi + 1 = y + m
````
**O próximo valor de 'y' é: valor_'y'_anterior adicionado ao 'coeficiente_angular_da_reta'**

![DDA](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/dda.png?raw=true)

Este algoritmo ainda não é o ideal pois são necessários muitos arredondamentos de números reais. A seguir será apresentado uma solução melhor aplicável.

### Algoritmo de Bresenham

Também conhecido como algoritmo do ponto médio, é utilizado para traçar retas de forma incremental, trabalhando apenas com números inteiros.

A ideia do algoritmo é bastante simples, ele utiliza a equação implícita da reta como uma função de decisão, para identificar qual o próximo pixel a ser ativado. Esta função é utilizada de forma incremental em cada pixel. Veja abaixo o desenvimento da Equação Implícita da Reta.

````
y = mx + b                            //  Partimos da Equação Reduzida da Reta
y = (dy/dx)* x + b                    //  Destrinchando 'm' obtemos '(dy/dx)'
y * dx = dy * x + b * dx              //  Multiplicando a equação por 'dx'
dy * x + (-y * dx) + b * dx = 0       //  Igualando a equação a 0
````

Realizando as modificações abaixo para melhor entendimento posterior:

````
α = dy
ß = -dx
c = b * dx
````

Obtemos:
````
decisão = f(x,y) = αx + ßy + c = 0
````

Se aplicarmos um ponto na equação implícita e obtivemos 0 como resultado, significa que o ponto está sobre a reta.

![Efeito_Eq_Implicita](https://github.com/FelipeNasci/Line_Rasterization/blob/master/images/Efeito%20Equa%C3%A7%C3%A3o%20Impl%C3%ADcita.png?raw=true)

Seja m = (x0 + 1, y0 + 1/2) o ponto médio entre os pixels  (x0 + 1, y0 + 1) e  (x0 + 1, y0), iremos utilizar a função de decisão para avaliar qual pixel acender.

