#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include <stdio.h>
#include "linkedlist.h"

// Initialise un neurone avec des poids et un biais aléatoires
Neurone InitNeur(int nombreEntrees) {
    Neurone n;
    // Génère un biais aléatoire entre 1 et 100
    n.biais = rand() % 100 + 1;
    n.nbPoids = nombreEntrees;

    // Crée une liste chaînée pour stocker les poids
    n.poids = createLinkedList();
    if (!n.poids) {
        return (Neurone){0};
    }
    for (int i = 0; i < nombreEntrees; i++) {
        // Alloue de la mémoire pour chaque poids
        int* poids = (int*)malloc(sizeof(int));
        if (!poids) {
            fprintf(stderr, "Erreur d'allocation pour le poids.\n");
            FreeNeur(&n);
            return (Neurone){0};
        }
        // Assigne une valeur aléatoire au poids entre 1 et 10
        *poids = rand() % 10 + 1;
        if (!appendLinkedList(n.poids, poids)) {
            fprintf(stderr, "Erreur lors de l'ajout du poids à la liste.\n");
            free(poids);
            FreeNeur(&n);
            return (Neurone){0};
        }
    }

    return n;
}

// Libère la mémoire allouée pour un neurone
void FreeNeur(Neurone* neurone) {
    if (neurone->poids) {
        // Libère chaque poids individuel
        ListNode* current = neurone->poids->head;
        while (current) {
            free(current->data);
            current = current->next;
        }
        // Libère la liste chaînée des poids
        freeLinkedList(neurone->poids);
        neurone->poids = NULL;
    }
}

// Fonction d'activation qui retourne 1 si x est supérieur ou égal au seuil 0 sinon
int activation(int x, int seuil) {
    return (x >= seuil) ? 1 : 0;
}

// Calcule la sortie d'un neurone en fonction des entrées et des poids
int Outneurone(LinkedList* entrees, Neurone* n) {
    int x = 0;
    ListNode* current_poids = n->poids->head;
    ListNode* current_entrees = entrees->head;

    // Calcule la somme pondérée des entrées
    while (current_poids && current_entrees) {
        x += *((int*)current_poids->data) * *((int*)current_entrees->data);
        current_poids = current_poids->next;
        current_entrees = current_entrees->next;
    }

    // Applique la fonction d'activation
    return activation(x, n->biais);
}
