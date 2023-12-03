#include "arbre.h"


node_t *newNode(zpixel_t *zp) {
    node_t *node;
    node = (node_t *)malloc(sizeof(node_t));
    node->zp = zp;
    return node;
}

GNode *construireArbreZPixel(int x, int y, int taille) {
    if(x<0 || y<0 /*|| x>largeur image || y>hauteur image*/) {
        return NULL;
    }

    zpixel_t *zp = initNewZPixel();
    node_t *initNode = g_new(node_t, 1);
    initNode->zp = zp;
    GNode *node = g_node_new(initNode);

    if(taille == 1) {
        initialiserCouleurZpixelNoeud(node, x, y);
    } else {
        GNode *filsGaucheHaut = construireArbreZPixel(x, y, taille/2);
        ajouterFils(node, filsGaucheHaut);

        GNode *filsDroiteHaut = construireArbreZPixel(x+taille/2, y, taille/2);
        ajouterFils(node, filsDroiteHaut);

        GNode *filsGaucheBas = construireArbreZPixel(x, y+taille/2, taille/2);
        ajouterFils(node, filsGaucheBas);

        GNode *filsDroiteBas = construireArbreZPixel(x+taille/2, y+taille/2, taille/2);
        ajouterFils(node, filsDroiteBas);

        calculerCouleurEtDegradationZpixel(initNode->zp, x, y, taille);
    }

    return node;
}

void initialiserCouleurZpixelNoeud(GNode *node, int x, int y) {
    node_t *nodeData = (node_t *)node->data;
    zpixel_t *zp = nodeData->zp;

    zp->valCouleurs.x = x % 256;
    zp->valCouleurs.y = y % 256;
    zp->valCouleurs.z = (x+y) % 256;
}

void ajouterFils(GNode *childNode, GNode *parentNode) {
    if(parentNode != NULL && childNode != NULL) {
        g_node_append(parentNode, childNode);
    }
}

void calculerCouleurEtDegradationZpixel(zpixel_t *zp, int x, int y, int taille) {
    zp->valCouleurs.x = x % 256;
    zp->valCouleurs.y = y % 256;
    zp->valCouleurs.z = (x+y) % 256;

    zp->degradation = (taille-1)*(1+abs(x-y));
}

void parcourirArbre(GNode *node, pixelsImage_t *pi, float degradationMax) {
    if (node == NULL) {
        return;
    }

    node_t *treeNode = (node_t *)node->data;
    zpixel_t *zp = treeNode->zp;

    printf("Position : (%d,%d), taille : %d, dégradation: %f\n", zp->position.xCoinSupG, zp->position.yCoinSupG, zp->size, zp->degradation);

    if (zp->degradation <= degradationMax) {
        projection(zp, pi);
    } else {
        GNode *childNode = node->children;
        while (childNode != NULL) {
            parcourirArbre(childNode, pi, degradationMax);
            childNode = childNode->next;
        }
    }
}
