#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"

int main() {
    srand(time(NULL));

    // Test d'initialisation d'un neurone avec 3 entrées
    Neurone* neurone = InitNeur(3);
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


    return 0;
}
