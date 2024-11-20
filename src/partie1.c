#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include <stdio.h>
#include "linkedlist.h"

// Initialise un neurone avec des poids et un biais aléatoires
Neurone InitNeur(int nombreEntrees) {
    Neurone n;
    n.biais = rand() % 100 + 1;
    n.nbPoids = nombreEntrees;

    n.poids = createLinkedList();
    if (!n.poids) {
        return (Neurone){0};
    }
    for (int i = 0; i < nombreEntrees; i++) {
        int* poids = (int*)malloc(sizeof(int));
        if (!poids) {
            fprintf(stderr, "Erreur d'allocation pour le poids.\n");
            FreeNeur(&n);
            return (Neurone){0};
        }
        *poids = rand() % 10 + 1; // Valeur aléatoire entre 1 et 10
        if (!appendLinkedList(n.poids, poids)) {
            fprintf(stderr, "Erreur lors de l'ajout du poids à la liste.\n");
            free(poids);
            FreeNeur(&n);
            return (Neurone){0};
        }
    }

    return n;
}

void FreeNeur(Neurone* neurone) {
    if (neurone->poids) {
        // Optionally, free the individual poids if they were dynamically allocated
        ListNode* current = neurone->poids->head;
        while (current) {
            free(current->data); // Assuming data was dynamically allocated
            current = current->next;
        }
        freeLinkedList(neurone->poids);
        neurone->poids = NULL;
    }
}

int activation(int x, int seuil) {
    return (x >= seuil) ? 1 : 0;
}

int Outneurone(LinkedList* entrees, Neurone* n) {
    int x = 0;
    ListNode* current_poids = n->poids->head;
    ListNode* current_entrees = entrees->head;

    while (current_poids && current_entrees) {
        x += *((int*)current_poids->data) * *((int*)current_entrees->data);
        current_poids = current_poids->next;
        current_entrees = current_entrees->next;
    }

    return activation(x, n->biais);
}
