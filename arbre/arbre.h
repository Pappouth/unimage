#ifndef _ARBRE_H_
#define _ARBRE_H_

#include <stdio.h>
#include <glib.h>

#include "../zpixel/zpixel.h"
#include "../zpixel/pixelTab.h"


typedef struct {
    zpixel_t *zp;
} node_t;

/* création d'un nouveau noeud */
node_t *newNode(zpixel_t *zp);

/* constronction de l'arbre de zpixels (https://docs.gtk.org/glib/struct.Node.html) */ // sudo apt-get install libglib2.0-dev
GNode *construireArbreZPixel(int x, int y, int taille);

/* initialisation de la couleur d'un noeud */
void initialiserCouleurZpixelNoeud(GNode *node, int x, int y);

/* ajout d'un noeud fils à un noeud parent */
void ajouterFils(GNode *parentNode, GNode *childNode);

void calculerCouleurEtDegradationZpixel(zpixel_t *zp, int x, int y, int taille);

/* parcourt de l'arbre de zpixels */
void parcourirArbre(GNode *node, pixelsImage_t *pi, float degradationMax);

#endif
