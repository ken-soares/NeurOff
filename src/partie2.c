#include <stdlib.h>
#include "couche.h"
#include "neurone.h"
#include "linkedlist.h"
#include <stdio.h>

// Initialise une couche avec un nombre donné de neurones et d'entrées par neurone
Couche InitCouche(int nombre_neurones, int nombre_entrees) {
    Couche couche;
    couche.neurones = createLinkedList();
    couche.nbNeurones = 0; // Initialize the neuron count
    if (!couche.neurones) {
        return (Couche){0};
    }

    for (int i = 0; i < nombre_neurones; i++) {
        Neurone* neurone = (Neurone*)malloc(sizeof(Neurone));
        if (!neurone) {
            fprintf(stderr, "Erreur d'allocation pour le neurone.\n");
            FreeCouche(&couche);
            return (Couche){0};
        }
        *neurone = InitNeur(nombre_entrees);
        // Check if initialization was successful
        if (neurone->poids == NULL) {
            fprintf(stderr, "Erreur lors de l'initialisation du neurone.\n");
            free(neurone);
            FreeCouche(&couche);
            return (Couche){0};
        }
        if (!appendLinkedList(couche.neurones, neurone)) {
            fprintf(stderr, "Erreur lors de l'ajout du neurone à la couche.\n");
            FreeNeur(neurone);
            free(neurone);
            FreeCouche(&couche);
            return (Couche){0};
        }
        couche.nbNeurones++; // Increment the neuron count
    }
    return couche;
}

void FreeCouche(Couche* couche) {
    if (couche->neurones) {
        ListNode* current = couche->neurones->head;
        while (current) {
            Neurone* neurone = (Neurone*)current->data;
            FreeNeur(neurone);
            free(neurone);
            current = current->next;
        }
        freeLinkedList(couche->neurones);
        couche->neurones = NULL;
        couche->nbNeurones = 0;
    }
}

LinkedList* OutCouche(Couche* couche, LinkedList* entrees) {
    LinkedList* sorties = createLinkedList();
    if (!sorties) {
        return NULL;
    }

    ListNode* current_neurone = couche->neurones->head;
    while (current_neurone) {
        Neurone* neurone = (Neurone*)current_neurone->data;
        int sortie = Outneurone(entrees, neurone);
        int* sortie_ptr = (int*)malloc(sizeof(int));
        if (!sortie_ptr) {
            fprintf(stderr, "Erreur d'allocation pour la sortie du neurone.\n");
            freeLinkedList(sorties);
            return NULL;
        }
        *sortie_ptr = sortie;
        if (!appendLinkedList(sorties, sortie_ptr)) {
            fprintf(stderr, "Erreur lors de l'ajout de la sortie à la liste.\n");
            free(sortie_ptr);
            freeLinkedList(sorties);
            return NULL;
        }
        current_neurone = current_neurone->next;
    }

    return sorties;
}
