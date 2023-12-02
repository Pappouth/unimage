#include "arbre.h"


noeud_t *newNode(zpixel_t *zp) {
    noeud_t *node;
    node = (noeud_t *)malloc(sizeof(noeud_t));
    node->zp = zp;
    return node;
}

GNode *construireArbreZPixel(int x, int y, int taille) {
    if(x<0 || y<0 /*|| x>largeur image || y>hauteur image*/) {
        return NULL;
    }

    zpixel_t *zp = initNewZPixel();
    noeud_t *initNode = g_new(noeud_t, 1);
    GNode *node = g_node_new(initNode);

    if(taille == 1) {

    } else {

    }

    return node;
}
