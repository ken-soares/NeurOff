#ifndef NEUROFF_RESEAU_H
#define NEUROFF_RESEAU_H

#include "couche.h"

typedef struct {
    Couche* couches;
    int nbCouches;
} ResNeur;

// Create a neural network
ResNeur CreerResNeur(int nombre_couches, int* liste_neurones, int nombre_poids_entree);

// Free the neural network memory
void FreeResNeur(ResNeur* reseau);

#endif // NEUROFF_RESEAU_H