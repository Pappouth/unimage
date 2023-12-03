#ifndef _ZPIXEL_H_
#define _ZPIXEL_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "pixelTab.h"


typedef enum {
    noir,
    blanc,
    couleur
} zpixelType_t;

typedef struct {
    int size, luminosite, saturation;
    float degradation;
    struct { int xCoinSupG, yCoinSupG; } position;
    zpixelType_t type;
    /* x, y et z représentent respectivement r, g et b */
    struct { int x, y, z; } valCouleurs;
}zpixel_t;

/* allocation de la mémoire pour un zpixel */
zpixel_t *initNewZPixel();

/* création d'un nouveau zpixel x, y et z représentent respectivement r, g et b */
void newZPixel(zpixel_t *zp, int size, int xCoinSupG, int yCoinSupG, zpixelType_t typeZPixel, int x, int y, int z);

/* calcul de la luminosité et de la saturation d’un zpixel */
int calculLumSat(zpixel_t *zp);

/* calcul de la distance entre les couleurs de 2 zpixels (distance cartésienne en considérant les composantes de couleurs comme coordonnées)*/
double calculDist(zpixel_t *zp1, zpixel_t *zp2);

/* projection d’un zpixel sur un tableau de pixels images */
void projection(zpixel_t *zp, pixelsImage_t *piOrigine);

#endif
