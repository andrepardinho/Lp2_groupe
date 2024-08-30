#ifndef PROCIMG_H
#define PROCIMG_H

#define largura 640
#define altura 480

//1 a 4
unsigned char geraPixelCinza(int tipo);
void preencheImgCinza(unsigned char img[640][480], unsigned char pixel);
void preencheImgPreto(unsigned char img[640][480]);
void preencheImgBranco(unsigned char img[640][480]);

//9 e 10
int pixelMax(unsigned char img[640][480]);
int pixelMin(unsigned char img[640][480]);

//11 e 12
void calculardadosimagem(unsigned char img[largura][altura], double *media, double *desvioPadrao);
void imgHistogram(unsigned char img[largura][altura], int hist[256]);

#endif
