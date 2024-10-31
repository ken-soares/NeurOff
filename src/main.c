#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include "couche.h"
#include "reseau.h"
#define TAILLE 3

int main() {
    srand(time(NULL));

    /*
    // Test d'initialisation d'un neurone avec 3 entrées
    Neurone neurone = InitNeur(TAILLE);

    int entrees[TAILLE] = {1,2,3};

    // Affichage des poids et du biais
    printf("Poids du neurone:\n");
    for (int i = 0; i < neurone.nbPoids; i++) {
        printf("Poids %d: %d\n", i, neurone.poids[i]);
    }
    printf("Biais: %d\n\n", neurone.biais);

    printf("Valeur de retour: %d\n", Outneurone(entrees, &neurone));

    // Initialisation d'une couche avec 3 neurones, chacun ayant 3 entrées
    Couche couche = InitCouche(3, TAILLE);
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

    int sortiesCouche[TAILLE];
    OutCouche(&couche, entrees, sortiesCouche);

    for(int i = 0; i < TAILLE; i++) {
        printf("sortie neurone[%d]:%d\n", i, sortiesCouche[i]);
    }
*/

    //////////////////////////////////////////////////////////////
    //test partie 3
    // Définition de la structure du réseau (exemple avec 3 couches)
    int nombre_couches = 3;
    int liste_neurones[] = {3, 2, 1}; // 3 neurones dans la première couche, 2 dans la deuxième, 1 dans la troisième

    // Création du réseau de neurones
    ResNeur reseau = CreerResNeur(nombre_couches, liste_neurones, TAILLE);
    if (reseau.couches == 0) {
        printf("Échec de l'initialisation du réseau de neurones.\n");
        return 1;
    }

    // Affichage des détails du réseau
    for (int i = 0; i < reseau.nbCouches; i++) {
        printf("Couche %d:\n", i + 1);
        for (int j = 0; j < reseau.couches[i].nbNeurones; j++) {
            printf("  Neurone %d:\n", j + 1);
            for (int k = 0; k < reseau.couches[i].neurones[j].nbPoids; k++) {
                printf("    Poids %d: %d\n", k, reseau.couches[i].neurones[j].poids[k]);
            }
            printf("    Biais: %d\n", reseau.couches[i].neurones[j].biais);
        }
    }

    // Libération de la mémoire allouée au réseau
    FreeResNeur(&reseau);

    return 0;
}
