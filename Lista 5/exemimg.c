#include "procimg.h"


int main () {
    int nLin = 4, nCol = 6;
    
    // Q01: Aloca imagem em tons de cinza
    imgGray picture1 = alocaImagemGray(nLin, nCol);
    if (picture1.img == NULL) {
        printf("Erro ao alocar memoria para img cinza\n");
    }
    else {
        printf("Imagem cinza alocada com sucesso\n");
    }

    int error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            picture1.img[i][j] = 10;
            if (picture1.img[i][j] != 10) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
            }
        }
    }

    if (!error) {
        printf("Valores atribuidos com sucesso\n");
    }

    //Libera memoria alocada para a imagem em tons de cinza
    freeImagemGray(&picture1);


    // Q02: Aloca imagem em RGB
    imgRGB picture2 = alocaImagemRGB(nLin, nCol);
    if (picture2.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
        // return 1;
    }
    else {
        printf("\nImagem RGB alocada com sucesso\n");
    }

    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            picture2.img[i][j].R = 11;
            picture2.img[i][j].G = 22;
            picture2.img[i][j].B = 33;
        }
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture2.img[i][j].R != 11 || picture2.img[i][j].G != 22 || picture2.img[i][j].B != 33) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                // return 1;
            }
        }
    }

    if (!error) {
        printf("Valores atribuidos com sucesso\n");
    }

    //Libera memoria alocada para a imagem em RGB
    freeImagemRGB(&picture2);


    // Q03: Preenche a imagem em tons de cinza com um valor de pixel
    printf("\nQuestao 3:\n");
    uchar pixel = 100;

    imgGray picture3 = alocaImagemGray(nLin, nCol);
    if (picture3.img == NULL) {
        printf("\nErro ao alocar memoria para img cinza\n");
    }

    if (geraImgGrayFull(picture3, pixel)) {
        printf("Imagem cinza preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem cinza\n");
    }

    // verificar se todos os pixels da imagem estão com o valor 100
    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture3.img[i][j] != 100) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com %u\n", pixel);
    }
    
    freeImagemGray(&picture3);


    // Q04: Preenche a imagem em RGB com um valor de pixel
    printf("\nQuestao 4:\n");

    tRGB pixelRGB = {200, 150, 100};

    imgRGB picture4 = alocaImagemRGB(nLin, nCol);
    if (picture4.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    if (geraImgRGBFull(picture4, pixelRGB)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture4.img[i][j].R != 200 || picture4.img[i][j].G != 150 || picture4.img[i][j].B != 100) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com R=%u, G=%u, B=%u\n", pixelRGB.R, pixelRGB.G, pixelRGB.B);
    }

    freeImagemRGB(&picture4);


    // Q05: Preenche a imagem em tons de cinza com o valor 0 (preto)
    printf("\nQuestao 5:\n");

    imgGray picture5 = alocaImagemGray(nLin, nCol);
    if (picture5.img == NULL) {
        printf("\nErro ao alocar memoria para img Gray\n");
    }

    if (geraImgGrayB(picture5)) {
        printf("Imagem Gray preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem Gray\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture5.img[i][j] != 0) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com valor 0 (preto)\n");
    }

    freeImagemGray(&picture5);


    // Q06: Preenche a imagem em RGB com o valor (0, 0, 0) (preto)
    printf("\nQuestao 6:\n");

    imgRGB picture6 = alocaImagemRGB(nLin, nCol);
    if (picture6.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    if (geraImgRGBB(picture6)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture6.img[i][j].R != 0 || picture6.img[i][j].G != 0 || picture6.img[i][j].B != 0) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com R=0, G=0, B=0 (preto)\n");
    }

    freeImagemRGB(&picture6);


    // Q07: Preenche a imagem em tons de cinza com o valor 255 (branco)
    printf("\nQuestao 7:\n");

    imgGray picture7 = alocaImagemGray(nLin, nCol);
    if (picture7.img == NULL) {
        printf("\nErro ao alocar memoria para img Gray\n");
    }

    if (geraImgGrayW(picture7)) {
        printf("Imagem Gray preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem Gray\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture7.img[i][j] != 255) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com valor 255 (branco)\n");
    }

    freeImagemGray(&picture7);


    // Q08: Preenche a imagem em RGB com o valor (255, 255, 255) (branco)
    printf("\nQuestao 8:\n");

    imgRGB picture8 = alocaImagemRGB(nLin, nCol);
    if (picture8.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    if (geraImgRGBW(picture8)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            if (picture8.img[i][j].R != 255 || picture8.img[i][j].G != 255 || picture8.img[i][j].B != 255) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com R=255, G=255, B=255 (branco)\n");
    }

    freeImagemRGB(&picture8);


    // Q09: Preenche a imagem em tons de cinza com valores aleatórios
    printf("\nQuestao 9:\n");

    imgGray picture9 = alocaImagemGray(nLin, nCol);
    if (picture9.img == NULL) {
        printf("\nErro ao alocar memoria para img Gray\n");
    }

    int tipo = 1; // Defina o tipo conforme necessário
    if (geraImgGray(picture9, tipo)) {
        printf("Imagem Gray preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem Gray\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            // Verifica se o valor do pixel está dentro do intervalo esperado (0-255)
            if (picture9.img[i][j] < 0 || picture9.img[i][j] > 255) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com valores aleatorios dentro do intervalo 0-255\n");
    }

    freeImagemGray(&picture9);
    

    // Q10: Preenche a imagem em RGB com valores aleatórios
    printf("\nQuestao 10:\n");

    imgRGB picture10 = alocaImagemRGB(nLin, nCol);
    if (picture10.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    tipo = 1; // Defina o tipo conforme necessário (rever depois)
    if (geraImgRGB(picture10, tipo)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    error = 0;
    for (int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++) {
            // Verifica se o valor do pixel está dentro do intervalo esperado (0-255)
            if (picture10.img[i][j].R < 0 || picture10.img[i][j].R > 255 ||
                picture10.img[i][j].G < 0 || picture10.img[i][j].G > 255 ||
                picture10.img[i][j].B < 0 || picture10.img[i][j].B > 255) {
                printf("Erro ao atribuir valor ao pixel na posição [%d, %d]\n", i, j);
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        printf("Todos os pixels foram preenchidos com valores aleatórios dentro do intervalo 0-255\n");
    }

    freeImagemRGB(&picture10);


    // Q11: Pixel maximo e minimo
    printf("\nQuestao 11:\n");
    
    imgGray imagem = alocaImagemGray(2, 2); // Imagem 2x2
    
    // Preencher a imagem com valores simples
    imagem.img[0][0] = 10;
    imagem.img[0][1] = 10;
    imagem.img[1][0] = 30;
    imagem.img[1][1] = 40;

    int maxPixel = pixelGrayMax(imagem);
    printf("Maior pixel: %d\n", maxPixel);

    int minPixel = pixelGrayMin(imagem);
    printf("Menor pixel: %d\n", minPixel);

    freeImagemGray(&imagem);


    // Q12: Encontra a maior e menor intensidade de pixel em uma imagem RGB
    printf("\nQuestao 12:\n");

    imgRGB picture12 = alocaImagemRGB(nLin, nCol);
    if (picture12.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    tipo = 1; // Defina o tipo conforme necessário
    if (geraImgRGB(picture12, tipo)) {
        printf("Imagem RGB preenchida com sucesso\n");
    } else {
        printf("Erro ao preencher imagem RGB\n");
    }

    tRGB maxPixelRGB = pixelRGBMax(picture12);
    tRGB minPixelRGB = pixelRGBMin(picture12);

    printf("Maior intensidade de pixel - R: %d, G: %d, B: %d\n", maxPixelRGB.R, maxPixelRGB.G, maxPixelRGB.B);
    printf("Menor intensidade de pixel - R: %d, G: %d, B: %d\n", minPixelRGB.R, minPixelRGB.G, minPixelRGB.B);

    freeImagemRGB(&picture12);


    // Q13: Calcula a soma dos elementos de cada linha e coluna em uma imagem em tons de cinza
    printf("\nQuestao 13:\n");
    
    imgGray picture13 = alocaImagemGray(nLin, nCol);
    if (picture13.img == NULL) {
        printf("\nErro ao alocar memoria para img Gray\n");
    }
    
    tipo = 1; // Defina o tipo conforme necessário
    if (geraImgGray(picture13, tipo)) {
        printf("Imagem Gray preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem Gray\n");
    }
    
    int* somaLinhas = somaPorLinhasGray(picture13);
    int* somaColunas = somaPorColunasGray(picture13);
    
    if (somaLinhas != NULL && somaColunas != NULL) {
        printf("Soma dos elementos de cada linha:\n");
        for (int i = 0; i < nLin; i++) {
            printf("Linha %d: %d\n", i, somaLinhas[i]);
        }
    
        printf("Soma dos elementos de cada coluna:\n");
        for (int j = 0; j < nCol; j++) {
            printf("Coluna %d: %d\n", j, somaColunas[j]);
        }
    
        free(somaLinhas);
        free(somaColunas);
    } else {
        printf("Erro ao calcular a soma dos elementos\n");
    }
    
    freeImagemGray(&picture13);


    // Q14: Calcula a soma dos elementos de cada linha e coluna em cada canal de cor em uma imagem RGB
    printf("\nQuestao 14:\n");

    imgRGB picture14 = alocaImagemRGB(nLin, nCol);
    if (picture14.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    tipo = 1; // Defina o tipo conforme necessário
    if (geraImgRGB(picture14, tipo)) {
        printf("Imagem RGB preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem RGB\n");
    }

    tRGB* somaLinhasRGB = somaPorLinhasRGB(picture14);
    tRGB* somaColunasRGB = somaPorColunasRGB(picture14);

    if (somaLinhasRGB != NULL && somaColunasRGB != NULL) {
        printf("Soma dos elementos de cada linha (R, G, B):\n");
        for (int i = 0; i < nLin; i++) {
            printf("Linha %d: R=%d, G=%d, B=%d\n", i, somaLinhasRGB[i].R, somaLinhasRGB[i].G, somaLinhasRGB[i].B);
        }

        printf("Soma dos elementos de cada coluna (R, G, B):\n");
        for (int j = 0; j < nCol; j++) {
            printf("Coluna %d: R=%d, G=%d, B=%d\n", j, somaColunasRGB[j].R, somaColunasRGB[j].G, somaColunasRGB[j].B);
        }

        free(somaLinhasRGB);
        free(somaColunasRGB);
    } else {
        printf("Erro ao calcular a soma dos elementos\n");
    }

    freeImagemRGB(&picture14);


    // Q15: Calcula a soma total dos elementos de uma imagem em tons de cinza
    printf("\nQuestao 15:\n");

    imgGray picture15 = alocaImagemGray(nLin, nCol);
    if (picture15.img == NULL) {
        printf("\nErro ao alocar memoria para img Gray\n");
    }

    tipo = 1; // Defina o tipo conforme necessário
    if (geraImgGray(picture15, tipo)) {
        printf("Imagem Gray preenchida com sucesso\n");
    }
    else {
        printf("Erro ao preencher imagem Gray\n");
    }

    int somaTotal = somaTotalGray(picture15);

    if (somaTotal != -1) {
        printf("Soma total dos elementos da imagem: %d\n", somaTotal);
    } else {
        printf("Erro ao calcular a soma total dos elementos\n");
    }

    freeImagemGray(&picture15);


    // Q16: Calcula a soma dos elementos por canal em uma imagem RGB
    printf("\nQuestao 16:\n");

    imgRGB picture16 = alocaImagemRGB(nLin, nCol);
    if (picture16.img == NULL) {
        printf("\nErro ao alocar memoria para img RGB\n");
    }

    tipo = 1; // Defina o tipo conforme necessário
    if (geraImgRGB(picture16, tipo)) {
        printf("Imagem RGB preenchida com sucesso\n");
    } else {
        printf("Erro ao preencher imagem RGB\n");
    }

    tRGB somaRGB = somaTotalRGB(picture16);

    printf("Soma total dos pixels - R: %d, G: %d, B: %d\n", somaRGB.R, somaRGB.G, somaRGB.B);

    freeImagemRGB(&picture16);


    // Q17: Contagem de pixels com intensidade específica
    printf("\nQuestao 17:\n");

    imgGray imagem2 = alocaImagemGray(2, 2); // Imagem 2x2
    
    // Preencher a imagem com valores simples
    imagem2.img[0][0] = 10;
    imagem2.img[0][1] = 20;
    imagem2.img[1][0] = 10; 
    imagem2.img[1][1] = 30;

    int quantidade = quantosPixelsGrayNaInt(imagem2, 10);

    printf("Quantidade de pixels com intensidade 10: %d", quantidade);
    if (quantidade  == 2) printf(" (Correto)\n");
    else printf(" (Incorreto)\n");

    freeImagemGray(&imagem2);

    // Q18: Contagem de pixels RGB com intensidade específica
    printf("\nQuestao 18:\n");
    
    imgRGB imagemRGB = alocaImagemRGB(2, 2); // Imagem 2x2
    
    // Preencher a imagem com valores RGB simples
    imagemRGB.img[0][0] = (tRGB){255, 0, 0}; // Vermelho
    imagemRGB.img[0][1] = (tRGB){0, 255, 0}; // Verde
    imagemRGB.img[1][0] = (tRGB){255, 0, 0}; // Vermelho
    imagemRGB.img[1][1] = (tRGB){0, 0, 255}; // Azul

    tRGB corDesejada = {255, 0, 0}; // Cor que queremos contar (vermelho)
    quantidade = quantosPixelsRGBNaInt(imagemRGB, corDesejada);
    printf("Quantidade de pixels vermelhos: %d", quantidade); // Deve imprimir 2
    if (quantidade == 2) printf(" (Correto)\n");
    else printf(" (Incorreto)\n");

    return 0;
}