#include <stdlib.h>
#include <stdio.h>
#include "reseau.h"

// Fonction pour créer un réseau de neurones
ResNeur CreerResNeur(int nombre_couches, int* liste_neurones, int nombre_poids_entree) {
    ResNeur reseau;
    reseau.nbCouches = nombre_couches;
    reseau.couches = (Couche*)malloc(nombre_couches * sizeof(Couche));
    
    if (!reseau.couches) {
        // Gestion de l'erreur d'allocation
        reseau.nbCouches = 0;
        return reseau;
    }


    for (int i = 0; i < nombre_couches; i++) {
        int nombre_entrees = (i == 0) ? nombre_poids_entree : liste_neurones[i - 1];
        reseau.couches[i] = InitCouche(liste_neurones[i], nombre_entrees);
    }

    return reseau;
}

// Fonction pour libérer la mémoire allouée pour un réseau de neurones
void FreeResNeur(ResNeur* reseau) {
    if (reseau->couches) {
        for (int i = 0; i < reseau->nbCouches; i++) {
            FreeCouche(&reseau->couches[i]);
        }
        free(reseau->couches);
        reseau->couches = 0;
        reseau->nbCouches = 0;
    }
}