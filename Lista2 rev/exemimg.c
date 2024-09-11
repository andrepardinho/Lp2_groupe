#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Declaração das variáveis
    unsigned char linha[LARGURA];
    unsigned char img[ALTURA][LARGURA];

    // QUESTAO 1: Teste da função geraLinha com tipo = 0 (aleatório)
    geraLinha(linha, 0);
    printf("Primeiros 10 valores de linha: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", linha[i]);
    }
    printf("\n");

    // QUESTAO 2: Teste da função geraImgGreyFull_R, preenchendo todos os pixeis com o valor predeterminado 100
    geraImgGreyFull_R(img, 100);
    printf("Primeiros 10 valores de img após geraImgGreyFull_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 3: Teste da função geraImgGreyB_R, retornando uma imagem preta
    geraImgGreyB_R(img);
    printf("Primeiros 10 valores de img após geraImgGreyB_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 4: Teste da função geraImgGreyW_R, retornando uma imagem branca
    geraImgGreyW_R(img);
    printf("Primeiros 10 valores de img após geraImgGreyW_R: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    // QUESTAO 5: Teste da função geraImgGrey, o parametro altera a probablilidade do tom do pixel.
    geraImgGrey(img, 1);
    printf("Primeiros 10 valores de img após geraImgGrey: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", img[0][i]);
    }
    printf("\n");

    return 0;
}



/* 
// Q06 e Q07
int main (void) {

    srand(time(NULL));

    unsigned char img[480][640];

    for (int i = 0; i < 480; i++) {
        for (int j = 0; j < 640; j++) {
            img[i][j] = rand() % 256;
        }
    }

    int pixel_max = pixelMax_R(img);
    int pixel_min = pixelMin_R(img);

    printf("Pixel de maior intensidade: %d\n", pixel_max);
    printf("Pixel de menor intensidade: %d\n", pixel_min);

    return 0;
}
*/


/*
// Q11 a Q13
int main() {
    // Declara uma imagem com dimensões 480x640
    unsigned char img[480][640];

    // Preenche a imagem com valores de exemplo (aqui, todos os pixels com valor 128)
    for(int i = 0; i < 480; i++) {
        for(int j = 0; j < 640; j++) {
            img[i][j] = 128; // Pode preencher com outros valores ou carregar uma imagem real
        }
    }

    unsigned char intensidade = 128; // Intensidade de exemplo

    // Testa a função para contar pixels com intensidade específica
    int resultado = quantosPixelsNaInt_R(img, intensidade);
    printf("Pixels com intensidade %d: %d\n", intensidade, resultado);

    // Testa a função para contar pixels abaixo de uma intensidade
    resultado = quantosPixelsAbaixoDeInt_R(img, intensidade);
    printf("Pixels com intensidade menor que %d: %d\n", intensidade, resultado);

    // Testa a função para contar pixels acima de uma intensidade
    resultado = quantosPixelsAcimaDeInt_R(img, intensidade);
    printf("Pixels com intensidade maior que %d: %d\n", intensidade, resultado);

    return 0;
}
*/
