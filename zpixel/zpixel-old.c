#include "zpixel-old.h"


zpixel_t *newZPixel(int size, int xCoinSupG, int yCoinSupG, zpixelType_t zpixelType, int x, int y, int z) {
    zpixel_t *zp;
    zp = (zpixel_t *)malloc(sizeof(zpixel_t));

    zp->size = size;
    zp->position.xCoinSupG = xCoinSupG;
    zp->position.yCoinSupG = yCoinSupG;

    zp->type = zpixelType;

    switch(zp->type) {
        case noir:
            zp->valCouleurs.x = zp->valCouleurs.y = zp->valCouleurs.z = 0;
            break;
        case blanc:
            zp->valCouleurs.x = zp->valCouleurs.y = zp->valCouleurs.z = 255;
            break;
        case couleur:
            zp->valCouleurs.x = (x<=0) ? x=0 : ((x>=255) ? x=255 : x);
            zp->valCouleurs.y = (y<=0) ? y=0 : ((y>=255) ? y=255 : y);
            zp->valCouleurs.z = (z<=0) ? z=0 : ((z>=255) ? z=255 : z);
            break;
        default:
            printf("erreur : type invalide\n");
            break;
    }
    
    return zp;
}

int calculLumSat(zpixel_t *zp) {
    int resLum, resSat;
    double max = (double)((zp->valCouleurs.x > zp->valCouleurs.y) ? ((zp->valCouleurs.x > zp->valCouleurs.z) ? zp->valCouleurs.x : zp->valCouleurs.z) : ((zp->valCouleurs.y > zp->valCouleurs.z) ? zp->valCouleurs.y : zp->valCouleurs.z));
    double min = (double)((zp->valCouleurs.x < zp->valCouleurs.y) ? ((zp->valCouleurs.x < zp->valCouleurs.z) ? zp->valCouleurs.x : zp->valCouleurs.z) : ((zp->valCouleurs.y < zp->valCouleurs.z) ? zp->valCouleurs.y : zp->valCouleurs.z));

    resLum = (max + min)/2;

    if(resLum < 128) {
        resSat = 255 * (max-min / max+min);
    } else {
        resSat = 255 * (max-min / (511-max+min));
    }

    zp->luminosite = resLum;
    zp->saturation = resSat;

    return 1;
}

double calculDist(zpixel_t *zp1, zpixel_t *zp2) {
    int carx = (zp2->valCouleurs.x - zp1->valCouleurs.x)*(zp2->valCouleurs.x - zp1->valCouleurs.x);
    int cary = (zp2->valCouleurs.y - zp1->valCouleurs.y)*(zp2->valCouleurs.y - zp1->valCouleurs.y);
    int carz = (zp2->valCouleurs.z - zp1->valCouleurs.z)*(zp2->valCouleurs.z - zp1->valCouleurs.z);

    return sqrt(carx + cary + carz);
}

void projection(zpixel_t *zp, pixelsImage_t *piOrigine) {
    // position pixel dans piOrigine : y*rowstride+x*3
    int zpX = zp->position.xCoinSupG;
    int zpY = zp->position.yCoinSupG;
    
    for(int i=zpY; i<zpY+zp->size; i++) {
        for(int j=zpX; j<zpX+zp->size; j++) {
            int position = i*piOrigine->rowstride+j*3;
            // printf("%d %d %d\n", i, j, position);
            piOrigine->pixelColor[position] = zp->valCouleurs.x;
            piOrigine->pixelColor[position+1] = zp->valCouleurs.y;
            piOrigine->pixelColor[position+2] = zp->valCouleurs.z;
        }
        // printf("\n");
    }
}
