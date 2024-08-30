#include "procimg.h"
#include <stdlib.h>
#include <math.h>

// 1: Função para gerar um pixel em tons de cinza com diferentes probabilidades
unsigned char geraPixelCinza(int tipo) {
    int valorAleatorio = rand() % 256; // Gera um valor entre 0 e 255

    if (tipo < 0) {
        // Intensidades mais escuras (0-127) têm maior probabilidade
        if (valorAleatorio < 128) {
            return (unsigned char)(valorAleatorio / 2); // Aumenta a probabilidade de valores menores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else if (tipo > 0) {
        // Intensidades mais claras (128-255) têm maior probabilidade
        if (valorAleatorio >= 128) {
            return (unsigned char)(128 + (valorAleatorio / 2)); // Aumenta a probabilidade de valores maiores
        } else {
            return (unsigned char)(valorAleatorio);
        }
    } else {
        // Todas as intensidades têm a mesma probabilidade
        return (unsigned char)(valorAleatorio);
    }
}

// 2: Função para preencher todos os pixels de uma imagem com um valor dado
void preencheImgCinza(unsigned char img[640][480], unsigned char pixel) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = pixel;
        }
    }
}

// 3: Função para preencher todos os pixels de uma imagem com o valor 0 (preto)
void preencheImgPreto(unsigned char img[640][480]) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = 0;
        }
    }
}

// 4: Função para preencher todos os pixels de uma imagem com o valor 255 (branco)
void preencheImgBranco(unsigned char img[640][480]) {
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = 255;
        }
    }
}






// 9: Função para encontrar a maior intensidade de pixel na imagem
int pixelMax(unsigned char img[640][480]) {
    int max = img[0][0]; // Inicializa o máximo com o primeiro pixel para coparar

    // for vai percorrer toda a matriz/imagem
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            // Se o pixel atual for maior que o máximo, atualiza o máximo 
            if (img[i][j] > max) {
                max = img[i][j];
            }
        }
    }
    return max;
}

// 10: Função para encontrar a menor intensidade de pixel na imagem
int pixelMin(unsigned char img[640][480]) {
    int min = img[0][0]; // Inicializa o mínimo com o primeiro pixel

    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            if (img[i][j] < min) {
                min = img[i][j]; // Atualiza o mínimo se encontrar um valor menor
            }
        }
    }

    return min;
}



// 11: Função para calcular a média e o desvio padrão
void calculardadosimagem(unsigned char img[LARGURA][ALTURA], double *media, double *desvioPadrao) {
    // Total de pixels na imagem
    int totalPixels = LARGURA * ALTURA;

    // Variáveis para acumular a soma dos valores dos pixels e a soma dos quadrados dos valores dos pixels
    double soma = 0;
    double somaquadrados = 0;

    // Percorre cada pixel da imagem
    for (int i = 0; i < ALTURA; i++) { // i representa a linha
        for (int j = 0; j < LARGURA; j++) { // j representa a coluna
            unsigned char pixel = img[i][j]; // Obtém o valor do pixel na posição [i][j]
            soma += pixel; // Acumula o valor do pixel
            somaquadrados += pixel * pixel; // Acumula o quadrado do valor do pixel
        }
    }

    // Calcula a média dos valores dos pixels
    *media = soma / totalPixels;

    // Calcula a média dos quadrados dos valores dos pixels
    double mediaquadrados = somaquadrados / totalPixels;

    // Calcula a variância e o desvio padrão
    double variancia = mediaquadrados - (*media * *media);
    *desvioPadrao = sqrt(variancia);
}

// 12: Função para gerar o histograma de cores
void imgHistogram(unsigned char img[LARGURA][ALTURA], int hist[256]) {
    // Inicializa o histograma com zeros
  // Desta forma o histograma é retornado na forma de um array de inteiros com 256 posições
    for (int i = 0; i < 256; i++) {
        hist[i] = 0;
    }

    // Percorre cada pixel da imagem
    for (int i = 0; i < ALTURA; i++) { // i representa a linha
        for (int j = 0; j < LARGURA; j++) { // j representa a coluna
            // Incrementa o contador correspondente ao valor de intensidade do pixel
            hist[img[i][j]]++;
        }
    }
}