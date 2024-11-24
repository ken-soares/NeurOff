#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "reseau.h"
#include "linkedlist.h"
#include "graphics.h"

// Fonction de comparaison pour les entiers
int compareInts(void* a, void* b) {
    if (*(int*)a == *(int*)b) {
        return 0;
    }
    return 1;
}

// Fonction pour imprimer un entier (utilisée dans iterateLinkedList)
void printInt(void* data) {
    printf("%d ", *(int*)data);
}

int main() {
    srand(time(NULL));

    // Configuration du réseau
    int nombre_couches = 3;

    // Création de la liste des neurones par couche
    LinkedList* liste_nombre_neurones = createLinkedList();
    if (!liste_nombre_neurones) {
        fprintf(stderr, "Erreur lors de la création de la liste des neurones.\n");
        return EXIT_FAILURE;
    }

    // Ajout des neurones pour chaque couche
    int neurones_couche1 = 5;
    int neurones_couche2 = 3;
    int neurones_couche3 = 1;

    appendLinkedList(liste_nombre_neurones, &neurones_couche1);
    appendLinkedList(liste_nombre_neurones, &neurones_couche2);
    appendLinkedList(liste_nombre_neurones, &neurones_couche3);

    int nombre_poids_entree = 5;      // Nombre de poids d'entrée pour la première couche

    // Créer le réseau de neurones
    ResNeur reseau = CreerResNeur(nombre_couches, liste_nombre_neurones, nombre_poids_entree);
    if (reseau.couches == NULL) {
        fprintf(stderr, "Erreur lors de la création du réseau de neurones.\n");
        freeLinkedList(liste_nombre_neurones);
        return EXIT_FAILURE;
    }
    printf("Réseau de neurones créé avec %d couches.\n", reseau.nbCouches);

    // Préparer les entrées
    LinkedList* entrees = createLinkedList();
    if (!entrees) {
        fprintf(stderr, "Erreur lors de la création des entrées.\n");
        FreeResNeur(&reseau);
        freeLinkedList(liste_nombre_neurones);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < nombre_poids_entree; i++) {
        int* valeur = (int*)malloc(sizeof(int));
        if (!valeur) {
            fprintf(stderr, "Erreur d'allocation pour une entrée.\n");
            freeLinkedList(entrees);
            FreeResNeur(&reseau);
            freeLinkedList(liste_nombre_neurones);
            return EXIT_FAILURE;
        }
        *valeur = rand() % 10; // Valeur aléatoire entre 0 et 9
        if (!appendLinkedList(entrees, valeur)) {
            fprintf(stderr, "Erreur lors de l'ajout d'une entrée.\n");
            free(valeur);
            freeLinkedList(entrees);
            FreeResNeur(&reseau);
            freeLinkedList(liste_nombre_neurones);
            return EXIT_FAILURE;
        }
    }

    // Afficher les entrées
    printf("Entrées du réseau: ");
    iterateLinkedList(entrees, printInt);
    printf("\n");

    // Propager les entrées à travers le réseau
    LinkedList* sorties = Propagate(&reseau, entrees);
    if (!sorties) {
        fprintf(stderr, "Erreur lors de la propagation des entrées.\n");
        freeLinkedList(entrees);
        FreeResNeur(&reseau);
        freeLinkedList(liste_nombre_neurones);
        return EXIT_FAILURE;
    }

    // Afficher les sorties
    printf("Sorties du réseau: ");
    iterateLinkedList(sorties, printInt);
    printf("\n");   

    // Initialiser et exécuter l'interface graphique
    HINSTANCE hInstance = GetModuleHandle(NULL);
    if (RunGraphics(hInstance, &reseau) != 0) {
        fprintf(stderr, "Erreur lors de l'exécution de l'interface graphique.\n");
        freeLinkedList(entrees);
        freeLinkedList(sorties);
        FreeResNeur(&reseau);
        freeLinkedList(liste_nombre_neurones);
        return EXIT_FAILURE;
    }

    // Libérer la mémoire allouée
    freeLinkedList(entrees);
    freeLinkedList(sorties);
    FreeResNeur(&reseau);
    freeLinkedList(liste_nombre_neurones);

    return EXIT_SUCCESS;
}
