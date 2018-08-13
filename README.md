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

  Tendo em vista que o color buffer é uma região de memória, e a única informação que temos são as coordenadas no monitor, utilizamos um offset para encontrar a informação para determinada coordenada do monitor.

>>offset = 4 * (x + y * IMAGE_WIDTH)
  
