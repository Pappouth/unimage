#ifndef _PIXELTAB_H_
#define _PIXELTAB_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int columns, rows, rowstride;
    int *pixelColor;
} pixelsImage_t;

/* initialise le tableau de pixels */
pixelsImage_t *initTab(int width, int height, int rowstride);

/* affiche le tableau de pixels (pour le test de projection) */
void printTab(pixelsImage_t *pi);

/* remplit le tableau de pixels (pour le test de projection) */
void fillTab(pixelsImage_t *pi);

#endif
