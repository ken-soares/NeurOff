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
    int liste_neurones[] = {5, 3, 1}; // 5 neurones dans la couche 1, 3 dans la couche 2, 1 dans la couche 3
    int nombre_poids_entree = 4;      // Nombre de poids d'entrée pour la première couche

    // Créer le réseau de neurones
    ResNeur reseau = CreerResNeur(nombre_couches, liste_neurones, nombre_poids_entree);
    if (reseau.couches == NULL) {
        fprintf(stderr, "Erreur lors de la création du réseau de neurones.\n");
        return EXIT_FAILURE;
    }
    printf("Réseau de neurones créé avec %d couches.\n", reseau.nbCouches);

    // Préparer les entrées
    LinkedList* entrees = createLinkedList();
    if (!entrees) {
        fprintf(stderr, "Erreur lors de la création des entrées.\n");
        FreeResNeur(&reseau);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < nombre_poids_entree; i++) {
        int* valeur = (int*)malloc(sizeof(int));
        if (!valeur) {
            fprintf(stderr, "Erreur d'allocation pour une entrée.\n");
            freeLinkedList(entrees);
            FreeResNeur(&reseau);
            return EXIT_FAILURE;
        }
        *valeur = rand() % 10; // Valeur aléatoire entre 0 et 9
        if (!appendLinkedList(entrees, valeur)) {
            fprintf(stderr, "Erreur lors de l'ajout d'une entrée.\n");
            free(valeur);
            freeLinkedList(entrees);
            FreeResNeur(&reseau);
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
        return EXIT_FAILURE;
    }

    // Libérer la mémoire allouée
    freeLinkedList(entrees);
    freeLinkedList(sorties);
    FreeResNeur(&reseau);

    return EXIT_SUCCESS;
}

/*

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include "couche.h"
#include "reseau.h"
#include "graphics.h"

#define TAILLE 2 // Number of input neurons

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(NULL));

    // Define the network structure: 2 input neurons, 1 output neuron
    int nombre_couches = 3;
    int liste_neurones[] = {3,2,1}; // 1 neuron in the output layer

    // Create the neural network
    ResNeur reseau = CreerResNeur(nombre_couches, liste_neurones, TAILLE);
    if (reseau.couches == NULL) {
        MessageBox(NULL, "Failed to initialize the neural network.", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    // Run the graphical interface
    printf("Launching graphical interface...\n");
    int gfxResult = RunGraphics(hInstance, &reseau);
    printf("Graphical interface exited with result: %d\n", gfxResult);

    // Free the neural network memory
    FreeResNeur(&reseau);

    return gfxResult;
}*/
