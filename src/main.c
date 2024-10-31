#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include "couche.h"

#define TAILLE 3

int main() {
    srand(time(NULL));

    // Test d'initialisation d'un neurone avec 3 entrées
    Neurone neurone = InitNeur(TAILLE);
    int entrees[TAILLE] = {3,4,5};

    // Affichage des poids et du biais
    printf("Poids du neurone:\n");
    for (int i = 0; i < neurone.nbPoids; i++) {
        printf("Poids %d: %d\n", i, neurone.poids[i]);
    }
    printf("Biais: %d\n\n", neurone.biais);

    printf("Valeur de retour: %d\n", Outneurone(entrees, &neurone));

    // Initialisation d'une couche avec 2 neurones, chacun ayant 3 entrées
    Couche couche = InitCouche(3, TAILLE+4);
    if (couche.neurones == NULL) {
        printf("Échec de l'initialisation de la couche.\n");
        return 1;
    }

    // Affichage des poids et des biais de chaque neurone dans la couche
    for (int i = 0; i < couche.nbNeurones; i++) {
        printf("Couche - Neurone %d:\n", i);
        for (int j = 0; j < couche.neurones[i].nbPoids; j++) {
            printf("  Poids %d: %d\n", j, couche.neurones[i].poids[j]);
        }
        printf("  Biais: %d\n\n", couche.neurones[i].biais);
    }

    // Définition des entrées pour la couche
    int entreesCouche[TAILLE] = {1, 2, 3};

    // Définition du seuil d'activation
    int seuil = 1;


    return 0;
}
