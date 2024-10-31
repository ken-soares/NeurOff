#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"

#define TAILLE 3

int main() {
    srand(time(NULL));

    // Test d'initialisation d'un neurone avec 3 entrées
    Neurone* neurone = InitNeur(TAILLE);
    int entrees[TAILLE] = {3,4,5};

    if (neurone == NULL) {
        printf("Erreur lors de l'initialisation du neurone\n");
        return 1;
    }

    // Affichage des poids et du biais
    printf("Poids du neurone:\n");
    for (int i = 0; i < neurone->nbPoids; i++) {
        printf("Poids %d: %d\n", i, neurone->poids[i]);
    }
    printf("Biais: %d\n\n", neurone->biais);

    printf("Valeur de retour: %d\n", Outneurone(entrees, neurone));

    return 0;
}
