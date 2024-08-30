#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função principal para testar preencheImgCinza, geraPixelCinza e preencheImgPreto
int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    unsigned char img[640][480];

    // Preenche a imagem com valores aleatórios usando rand()
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            img[i][j] = rand() % 256; // Gera valores entre 0 e 255
        }
    }

    // Testa a função preencheImgCinza
    unsigned char pixel = geraPixelCinza(0); // Gera um valor de pixel com probabilidade uniforme
    preencheImgCinza(img, pixel);
    printf("Pixel [0][0] aps preencheImgCinza: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgCinza: %u\n", img[639][479]);

    // Testa a função preencheImgPreto
    preencheImgPreto(img);
    printf("Pixel [0][0] apos preencheImgPreto: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgPreto: %u\n", img[639][479]);

    // Testa a função preencheImgBranco
    preencheImgBranco(img);
    printf("Pixel [0][0] apos preencheImgBranco: %u\n", img[0][0]);
    printf("Pixel [639][479] apos preencheImgBranco: %u\n", img[639][479]);



    // 9 e 10: Obtém o valor máximo e mínimo dos pixels
    int max = pixelMax(img);
    int min = pixelMin(img);

    // Exibe os resultados
    printf("\nMaior intensidade de pixel: %d\n", max);
    printf("Menor intensidade de pixel: %d\n", min);

    return 0;
}