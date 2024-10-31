#ifndef NEUROFF_RESEAU_H
#define NEUROFF_RESEAU_H

#include "couche.h"

typedef struct {
    Couche* couches;     
    int nbCouches;       
} ResNeur;

ResNeur CreerResNeur(int nombre_couches, int* liste_neurones, int nombre_poids_entree);

#endif // NEUROFF_RESEAU_H