#include <stdlib.h>
#include <time.h>
#include "neurone.h"

// Initialise un neurone avec des poids et un biais aléatoires
Neurone* InitNeur(int nombreEntrees) {
    // Crée et initialise le neurone
    Neurone* n = (Neurone*)malloc(sizeof(Neurone));
    if (!n) return 0;

    // Alloue la mémoire pour les poids (creer une liste)
    n->poids = (int*)malloc(nombreEntrees * sizeof(int));
    if (!n->poids) {
        free(n);
        return 0;
    }
    n->nbPoids = nombreEntrees;

    // Initialise le biais aléatoire
    n->biais = rand() % 10; // Valeur aléatoire entre 0-9

    // Initialise les poids aléatoires
    for (int i = 0; i < nombreEntrees; i++) {
        n->poids[i] = rand() % 10; // Valeur aléatoire entre 0-9
    }

    return n;
}