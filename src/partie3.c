#include <stdlib.h>
#include <stdio.h>
#include "reseau.h"

// Fonction pour créer un réseau de neurones
ResNeur CreerResNeur(int nombre_couches, int* liste_neurones, int nombre_poids_entree) {
    ResNeur reseau;
    reseau.couches = createLinkedList();
    reseau.nbCouches = 0; // Initialize the layer count
    if (!reseau.couches) {
        // Gestion de l'erreur d'allocation
        return (ResNeur){0};
    }

    for (int i = 0; i < nombre_couches; i++) {
        int nombre_entrees = (i == 0) ? nombre_poids_entree : liste_neurones[i - 1];
        Couche* couche = (Couche*)malloc(sizeof(Couche));
        if (!couche) {
            fprintf(stderr, "Erreur d'allocation pour la couche.\n");
            FreeResNeur(&reseau);
            return (ResNeur){0};
        }
        *couche = InitCouche(liste_neurones[i], nombre_entrees);
        // Check if initialization was successful
        if (couche->neurones == NULL) {
            fprintf(stderr, "Erreur lors de l'initialisation de la couche.\n");
            free(couche);
            FreeResNeur(&reseau);
            return (ResNeur){0};
        }
        if (!appendLinkedList(reseau.couches, couche)) {
            fprintf(stderr, "Erreur lors de l'ajout de la couche au réseau.\n");
            FreeCouche(couche);
            free(couche);
            FreeResNeur(&reseau);
            return (ResNeur){0};
        }
        reseau.nbCouches++; // Increment the layer count
    }

    return reseau;
}

// Fonction pour libérer la mémoire allouée pour un réseau de neurones
void FreeResNeur(ResNeur* reseau) {
    if (reseau->couches) {
        ListNode* current = reseau->couches->head;
        while (current) {
            Couche* couche = (Couche*)current->data;
            FreeCouche(couche);
            free(couche);
            current = current->next;
        }
        freeLinkedList(reseau->couches);
        reseau->couches = NULL;
        reseau->nbCouches = 0;
    }
}

// Fonction pour propager les entrées à travers le réseau et obtenir les sorties
LinkedList* Propagate(ResNeur* reseau, LinkedList* entrees) {
    LinkedList* current_entrees = entrees;
    ListNode* current_couche = reseau->couches->head;

    while (current_couche) {
        Couche* couche = (Couche*)current_couche->data;
        LinkedList* sorties = OutCouche(couche, current_entrees);
        if (!sorties) {
            if (current_entrees != entrees) {
                freeLinkedList(current_entrees);
            }
            return NULL;
        }
        if (current_entrees != entrees) {
            freeLinkedList(current_entrees);
        }
        current_entrees = sorties;
        current_couche = current_couche->next;
    }

    return current_entrees;
}