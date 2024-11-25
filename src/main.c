#include <stdio.h>
#include <stdlib.h>
#include "reseau.h"
#include "linkedlist.h"

#define N 3

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

    /* CREATION ET TEST DES RESEAUX ET/OU/NON */

    ResNeur et = InitResET(3);
    Couche cet = *(Couche*)(et.couches->head->data);
    Neurone net = *(Neurone*)(cet.neurones->head->data);
    puts("-- ENTREES ET | SEUIL ET --");
    iterateLinkedList(net.poids, printInt);
    printf(" | %d\n", net.biais);

    ResNeur ou = InitResOU(3);
    Couche cou = *(Couche*)(ou.couches->head->data);
    Neurone nou = *(Neurone*)(cou.neurones->head->data);
    puts("-- ENTREES OU | SEUIL OU --");
    iterateLinkedList(nou.poids, printInt);
    printf(" | %d\n", nou.biais);

    ResNeur non = InitResNOT();
    Couche cnon = *(Couche*)(non.couches->head->data);
    Neurone nnon = *(Neurone*)(cnon.neurones->head->data);

    puts("--ENTREE NON | SEUIL NON --");
    printf("%d", *(int*)nnon.poids->head->data);
    printf(" | %d\n", nnon.biais);

    FreeResNeur(&et);
    FreeResNeur(&ou);
    FreeResNeur(&non);

    return EXIT_SUCCESS;
}


/*
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

    // Libérer la mémoire allouée
    freeLinkedList(entrees);
    freeLinkedList(sorties);
    FreeResNeur(&reseau);
    freeLinkedList(liste_nombre_neurones);

    return EXIT_SUCCESS;
}

*/
