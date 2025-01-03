#include <stdlib.h>
#include "couche.h"
#include "neurone.h"
#include "linkedlist.h"
#include <stdio.h>

// Initialise une couche avec un nombre donné de neurones et d'entrées par neurone
Couche InitCouche(int nombre_neurones, int nombre_entrees) {
    Couche couche;
    // Crée une liste chaînée pour stocker les neurones
    couche.neurones = createLinkedList();
    couche.nbNeurones = 0;
    if (!couche.neurones) {
        return (Couche){0};
    }

    for (int i = 0; i < nombre_neurones; i++) {
        // Alloue de la mémoire pour chaque neurone
        Neurone* neurone = (Neurone*)malloc(sizeof(Neurone));
        if (!neurone) {
            fprintf(stderr, "Erreur d'allocation pour le neurone.\n");
            FreeCouche(&couche);
            return (Couche){0};
        }
        // Initialise le neurone avec le nombre d'entrées spécifié
        *neurone = InitNeur(nombre_entrees);
        if (neurone->poids == NULL) {
            fprintf(stderr, "Erreur lors de l'initialisation du neurone.\n");
            free(neurone);
            FreeCouche(&couche);
            return (Couche){0};
        }
        // Ajoute le neurone à la couche
        if (!appendLinkedList(couche.neurones, neurone)) {
            fprintf(stderr, "Erreur lors de l'ajout du neurone à la couche.\n");
            FreeNeur(neurone);
            free(neurone);
            FreeCouche(&couche);
            return (Couche){0};
        }
        couche.nbNeurones++;
    }
    return couche;
}

// Libère la mémoire allouée pour une couche
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

// Calcule les sorties d'une couche en fonction des entrées
LinkedList* OutCouche(Couche* couche, LinkedList* entrees) {
    LinkedList* sorties = createLinkedList();
    if (!sorties) {
        return NULL;
    }

    ListNode* current_neurone = couche->neurones->head;
    while (current_neurone) {
        Neurone* neurone = (Neurone*)current_neurone->data;
        // Calcule la sortie pour chaque neurone
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
