#include "zpixel/zpixel.h"
#include "arbre/arbre.h"


int main() {
    zpixel_t *zp1;
    zp1 = initNewZPixel();
    newZPixel(zp1,2, 10, 5, noir, 458, -24, 132);

    printf("taille : %d\n", zp1->size);
    printf("position : (%d,%d)\n", zp1->position.xCoinSupG, zp1->position.yCoinSupG);
    printf("%d\n", zp1->type);
    printf("r : %d g : %d b : %d\n", zp1->valCouleurs.x, zp1->valCouleurs.y, zp1->valCouleurs.z);

    printf("----------\n");

    zpixel_t *zp2;
    zp2 = initNewZPixel();
    newZPixel(zp2, 4, 2, 5, blanc, 54, 4576, 54);

    printf("taille : %d\n", zp2->size);
    printf("position : (%d,%d)\n", zp2->position.xCoinSupG, zp2->position.yCoinSupG);
    printf("%d\n", zp2->type);
    printf("r : %d g : %d b : %d\n", zp2->valCouleurs.x, zp2->valCouleurs.y, zp2->valCouleurs.z);

    printf("----------\n");

    zpixel_t *zp3;
    zp3 = initNewZPixel();
    newZPixel(zp3, 9, 2, 2, couleur, -87, 28, 7867);

    printf("taille : %d\n", zp3->size);
    printf("position : (%d,%d)\n", zp3->position.xCoinSupG, zp3->position.yCoinSupG);
    printf("%d\n", zp3->type);
    printf("r : %d g : %d b : %d\n", zp3->valCouleurs.x, zp3->valCouleurs.y, zp3->valCouleurs.z);

    printf("----------\n");
    
    double dist1 = calculDist(zp1, zp2);
    printf("dist zp1 zp2 : %f\n", dist1);
    double dist2 = calculDist(zp1, zp3);
    printf("dist zp1 zp3 : %f\n", dist2);
    double dist3 = calculDist(zp2, zp3);
    printf("dist zp2 zp3 : %f\n", dist3);

    printf("----------\n");

    int lumStaZP1 = calculLumSat(zp1);
    printf("zp1 lum : %d sat : %d\n", zp1->luminosite, zp1->saturation);
    int lumStaZP2 = calculLumSat(zp2);
    printf("zp2 lum : %d sat : %d\n", zp2->luminosite, zp2->saturation);
    int lumStaZP3 = calculLumSat(zp3);
    printf("zp3 lum : %d sat : %d\n", zp3->luminosite, zp3->saturation);

    printf("----------\n");

    pixelsImage_t *pi;
    pi = initTab(20, 10, 20*3+10);
    fillTab(pi);
    printTab(pi);

    printf("\n");
    projection(zp2, pi);
    printTab(pi);

    // TESTS ZPIXEL DEPASSE

    printf("----------\n");
    printf("----------\n");
    
    GNode *tree = construireArbreZPixel(0, 0, 3);

    // pixelsImage_t *pi2;
    // pi2 = initTab(20, 10, 20*3+10);
    // pi2->pixelColor = calloc(1, pi2->columns * pi2->rowstride);

    int degradationMax = 10;

    parcourirArbre(tree, pi, degradationMax);

    printTab(pi);
}
