#include <stdlib.h>
#include <time.h>
#include "neurone.h"

// Initialise un neurone avec des poids et un biais aléatoires
Neurone InitNeur(int nombreEntrees) {
    Neurone n;
    n.biais = rand() % 10;

    n.poids = 0;
    n.nbPoids = nombreEntrees;

    n.poids = (int*)malloc(nombreEntrees * sizeof(int));
    if (!n.poids) {
        free(n.poids);
        return (Neurone){0};
    }
    for (size_t i = 0; i < nombreEntrees; i++)
    {
        n.poids[i] = rand() % 10; // Valeur aléatoire entre 0
    }
    
    return n;
}

void FreeNeur(Neurone* neurone) {
    if (neurone->poids) {
        free(neurone->poids);
        neurone->poids = NULL;
    }
}



int activation(int x, int seuil) {
    if (x >= seuil) {
        return 1;
    } else {
        return 0;
    }
}


int Outneurone(int *e, Neurone *n) {
    int x;
    for(int i = 0; i < n->nbPoids; i++) {
        x += n->poids[i] * e[i];
    }

    return activation(x, n->biais);
}
