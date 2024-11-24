#ifndef NEUROFF_RESEAU_H
#define NEUROFF_RESEAU_H

#include "couche.h"
#include "linkedlist.h"

typedef struct {
    LinkedList* couches;
    int nbCouches;
} ResNeur;

// Create a neural network
ResNeur CreerResNeur(int nombre_couches, LinkedList* liste_neurones, int nombre_poids_entree);

// Free the neural network memory
void FreeResNeur(ResNeur* reseau);

// Propagate inputs through the network and obtain outputs
LinkedList* Propagate(ResNeur* reseau, LinkedList* entrees);

#endif // NEUROFF_RESEAU_H