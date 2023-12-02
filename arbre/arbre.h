#ifndef _ARBRE_H_
#define _ARBRE_H_

#include <stdio.h>
#include <glib.h>

#include "../zpixel/zpixel.h"


typedef struct {
    zpixel_t *zp;
} noeud_t;

/* création d'un nouveau noeud */
noeud_t *newNode(zpixel_t *zp);

/* constronction de l'arbre de zpixels (https://docs.gtk.org/glib/struct.Node.html) */ // sudo apt-get install libglib2.0-dev
GNode *construireArbreZPixel(int x, int y, int taille);

#endif