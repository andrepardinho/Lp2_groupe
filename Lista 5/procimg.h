#ifndef PROCIMG_H
#define PROCIMG_H

// #include <procimg.c>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned char uchar;

// Estrutura de um pixel em RGB
typedef struct { 
    uchar R, G, B;
} tRGB;

// Estrutura de uma imagem em tons de cinza
typedef struct {
    uchar *_img; //ponteiro para um array unidimen que armazena os pixels da imagem em um único bloco de memória
    uchar **img; // ponteiro para um array de ponteiros que apontam para o início de cada linha da imagem. Matriz.
    int nLin, nCol;
} imgGray;

// Estrutura de uma imagem em RGB
typedef struct {
    tRGB *_img; // cada pixel é um tRGB e contem 3 componentes: R, G e B.
    tRGB **img;
    int nLin, nCol;
} imgRGB;

struct imagens {
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;

void freeImagemGray(imgGray *picture);
void freeImagemRGB(imgRGB *picture);

// Q01: Função que aloca uma imagem em tons de cinza
imgGray alocaImagemGray(int nLin, int nCol);

// Q02: Função que aloca uma imagem em RGB
imgRGB alocaImagemRGB(int nLin, int nCol);

// Q03: Função que preenche uma imagem em tons de cinza com um valor de pixel
int geraImgGrayFull(imgGray picture, uchar pixel);

// Q04: Função que preenche uma imagem em RGB com um valor de pixel
int geraImgRGBFull(imgRGB img, tRGB pixel);

// Q11: 
// Função para encontrar o pixel de maior intensidade em uma imagem cinza
int pixelGrayMax(imgGray img);
// Função para encontrar o pixel de menor intensidade em uma imagem cinza
int pixelGrayMin(imgGray img);

// Q17: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em tons de cinza
int quantosPixelsGrayNaInt(imgGray img, uchar inten);

// Q18: Função para contar quantos pixels possuem uma intensidade específica em uma imagem RGB
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten);


#endif