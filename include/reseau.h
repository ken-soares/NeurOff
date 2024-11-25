#ifndef NEUROFF_RESEAU_H
#define NEUROFF_RESEAU_H

#include "couche.h"
#include "linkedlist.h"

typedef struct {
    LinkedList* couches;
    int nbCouches;
} ResNeur;

// Create a neural network
ResNeur CreerResNeur(int nombre_couches, LinkedList* liste_nombre_neurones_par_couche, int nombre_poids_entree);

// Free the neural network memory
void FreeResNeur(ResNeur* reseau);


LinkedList* Propagate(ResNeur* reseau, LinkedList* entrees);

ResNeur InitResET(int n);
ResNeur InitResOU(int n);
ResNeur InitResNOT();

#endif // NEUROFF_RESEAU_H
