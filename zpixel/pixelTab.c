#include "pixelTab.h"


pixelsImage_t *initTab(int width, int height, int rowstride) {
    pixelsImage_t *pi;
    pi = (pixelsImage_t *)malloc(sizeof(pixelsImage_t));
    pi->pixelColor = (int *)malloc(pi->rowstride*pi->rows*3 * sizeof(int));
    
    pi->rows = height;
    pi->columns = width;
    pi->rowstride = rowstride;

    return pi;
}

void printTab(pixelsImage_t *pi) {
    for(int i=0; i<pi->rows; i++) {
        for(int j=0; j<pi->columns; j++) {
            int position = i*pi->rowstride+j*3;
            printf("(%d %d %d) ", pi->pixelColor[position], pi->pixelColor[position+1], pi->pixelColor[position+2]);
        }
        printf("\n");
    }
}

void fillTab(pixelsImage_t *pi) {
    for(int i=0; i<pi->rows; i++) {
        for(int j=0; j<pi->columns; j++) {
            int position = i*pi->rowstride+j*3;
            pi->pixelColor[position] = 0;
            pi->pixelColor[position+1] = 0;
            pi->pixelColor[position+2] = 255;
        }
    }
}
