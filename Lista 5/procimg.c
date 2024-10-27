#include "procimg.h"

void freeImagemGray(imgGray *picture) {
    if (picture->img != NULL) {
        free(picture->img);
        picture->img = NULL;
    }

    if (picture->_img != NULL) {
        free(picture->_img);
        picture->_img = NULL;
    }
}

void freeImagemRGB(imgRGB *picture) {
    if (picture->img != NULL) {
        free(picture->img);
        picture->img = NULL;
    }

    if (picture->_img != NULL) {
        free(picture->_img);
        picture->_img = NULL;
    }
}

// Q01: Função que aloca uma imagem em tons de cinza
imgGray alocaImagemGray(int nLin, int nCol) {
    imgGray picture;
    picture.nLin = nLin;
    picture.nCol = nCol;

    // Alocando meroria para array unidimensional
    picture._img = (uchar *) malloc(nLin * nCol * sizeof(uchar));
    if (picture._img == NULL) {
        picture.img = NULL; // 
        return picture;
    }

    // Alocando memoria para array de ponteiros
    picture.img = (uchar **) malloc(nLin * sizeof(uchar *));
    if (picture.img == NULL) {
        free(picture._img); //libera mem q foi alocada para o array unidimensional
        picture._img = NULL;
        return picture;
    }
    
    //Mapear a matriz guardada como array em picture._img. no array de ponteiros em picture.img
    for (int i = 0; i < nLin; i++) {
        picture.img[i] = &picture._img[i * nCol];
    }

    return picture;
}

// Q02: Função que aloca uma imagem em RGB
imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB picture;
    picture.nLin = nLin;
    picture.nCol = nCol;

    // Alocando meroria para array unidimensional
    picture._img = (tRGB *) malloc(nLin * nCol * sizeof(tRGB));
    if (picture._img == NULL) {
        picture.img = NULL; // 
        return picture;
    }

    // Alocando memoria para array de ponteiros
    picture.img = (tRGB **) malloc(nLin * sizeof(tRGB *));
    if (picture.img == NULL) {
        free(picture._img);
        picture._img = NULL;
        return picture;
    }

    for (int i = 0; i < nLin; i++) {
        picture.img[i] = &picture._img[i * nCol];
    }

    return picture;
}

// Q03: Preenche a imagem em tons de cinza com um valor de pixel
int geraImgGrayFull(imgGray img, uchar pixel) {
    if (img.img == NULL) {
        return false;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel;
        }
    }

    return true;
}

// Q04: Preenche a imagem em RGB com um valor de pixel
int geraImgRGBFull(imgRGB img, tRGB pixel) {
    if (img.img == NULL) {
        return false;
    }

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel;
        }
    }

    return true;
}


// Q11: Função para encontrar o pixel de maior intensidade em uma imagem cinza
int pixelGrayMax(imgGray img) {
    if (img.img == NULL) return -1; // Verifica se a imagem é nula

    int max = 0; // Inicializa o máximo
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] > max) {
                max = img.img[i][j]; // Atualiza o máximo se encontrar um valor maior
            }
        }
    }
    return max; // Retorna o valor máximo encontrado
}

// Função para encontrar o pixel de menor intensidade em uma imagem cinza
int pixelGrayMin(imgGray img) {
    if (img.img == NULL) return -1; // Verifica se a imagem é nula

    int min = 255;// Inicializa o mínimo
    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] < min) {
                min = img.img[i][j]; // Atualiza o mínimo se encontrar um valor menor
            }
        }
    }
    return min; // Retorna o valor mínimo encontrado
}

// Q17: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em tons de cinza
int quantosPixelsGrayNaInt(imgGray img, uchar inten) {
    int count = 0;

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j] == inten) {
                count++; // Incrementa o contador se o pixel tiver a intensidade desejada
            }
        }
    }
    return count; // Retorna a quantidade de pixels com a intensidade específica
}


// Q18: Função para contar quantos pixels possuem uma intensidade específica em uma imagem em RGB
 int quantosPixelsRGBNaInt(imgRGB img, tRGB inten) {
    int count = 0;

    for (int i = 0; i < img.nLin; i++) {
        for (int j = 0; j < img.nCol; j++) {
            if (img.img[i][j].R == inten.R &&
                img.img[i][j].G == inten.G &&
                img.img[i][j].B == inten.B) {
                count++; // Incrementa o contador se o pixel RGB tiver a intensidade desejada
            }
        }
    }
    return count; // Retorna a quantidade de pixels com a intensidade RGB específica
}