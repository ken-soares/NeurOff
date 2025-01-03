#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "reseau.h"
#include "linkedlist.h"
#include "utils.h"
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
    // pour les A,B,C aléatoires
    srand(time(NULL));

    /* CREATION ET VERIF DES RESEAUX ET/OU/NON */
    /*
    ResNeur et1 = InitResET(3);
    ResNeur et2 = InitResET(2);
    ResNeur ou = InitResOU(2);
    ResNeur non = InitResNOT();

    Couche cet1 = *(Couche*)(et1.couches->head->data);
    Neurone net1 = *(Neurone*)(cet1.neurones->head->data);
    puts("-- ENTREES ET1 | SEUIL ET1 --");
    iterateLinkedList(net1.poids, printInt);
    printf(" | %d\n", net1.biais);

    Couche cet2 = *(Couche*)(et2.couches->head->data);
    Neurone net2 = *(Neurone*)(cet2.neurones->head->data);
    puts("-- ENTREES ET2 | SEUIL ET2 --");
    iterateLinkedList(net2.poids, printInt);
    printf(" | %d\n", net2.biais);


    Couche cou = *(Couche*)(ou.couches->head->data);
    Neurone nou = *(Neurone*)(cou.neurones->head->data);
    puts("-- ENTREES OU | SEUIL OU --");
    iterateLinkedList(nou.poids, printInt);
    printf(" | %d\n", nou.biais);

    Couche cnon = *(Couche*)(non.couches->head->data);
    Neurone nnon = *(Neurone*)(cnon.neurones->head->data);
    puts("--ENTREE NON | SEUIL NON --");
    printf("%d", *(int*)nnon.poids->head->data);
    printf(" | %d\n", nnon.biais);

    puts("-------");


    // CREATION DES ENTREES 
    int a = rand() % 2;
    int b = rand() % 2;
    int c = rand() % 2;

    printf("A: %d\n", a);
    printf("B: %d\n", b);
    printf("C: %d\n", c);

    puts("-------");


    // PROPAGATIONS
    

    LinkedList* sortie_et1 = createLinkedList();
    LinkedList* sortie_et2 = createLinkedList();
    LinkedList* sortie_globale = createLinkedList();



    // sortie_et1
    LinkedList* not_b = createLinkedList();
    appendLinkedList(not_b, &b);
    not_b = Propagate(&non, not_b);
    printf("SORTIE NON B: %d\n", *(int*)not_b->head->data);
    

    appendLinkedList(sortie_et1, not_b->head->data);
    appendLinkedList(sortie_et1, &a);
    appendLinkedList(sortie_et1, &c);

    sortie_et1 = Propagate(&et1, sortie_et1);
    printf("SORTIE BRANCHE 1: %d\n", *(int*)sortie_et1->head->data);


    // sortie_et2
    LinkedList* not_c = createLinkedList();
    appendLinkedList(not_c, &c);
    not_c = Propagate(&non, not_c);
    printf("SORTIE NON C: %d\n", *(int*)not_c->head->data);

    appendLinkedList(sortie_et1, not_c->head->data);
    appendLinkedList(sortie_et1, &a);

    sortie_et2 = Propagate(&et2, sortie_et2);
    printf("SORTIE BRANCHE 2: %d\n", *(int*)sortie_et2->head->data);

    // sortie_globale
    appendLinkedList(sortie_globale, sortie_et1->head->data);
    appendLinkedList(sortie_globale, sortie_et2->head->data);

    sortie_globale = Propagate(&ou, sortie_globale);

    printf("SORTIE GLOBALE DU RESEAU: %d\n", *(int*)sortie_globale->head->data);



    LinkedList* liste_nb_neur = createLinkedList();
    a = 2;
    b = 1;
    appendLinkedList(liste_nb_neur, &a);
    appendLinkedList(liste_nb_neur, &b);

    ResNeur reseau = CreerResNeur(2,liste_nb_neur, 3);
    //show poids
    // Afficher les poids du premier neurone du réseau
    Neurone* neurone = getNeuroneFromNetwork(reseau);
    ListNode* poids = getPoidsFromNeurone(neurone);
    printf("\nPoids du premier neurone:\n");
    while (poids) {
        printf("%d ", *(int*)poids->data);
        poids = poids->next;
    }
    printf("\n");

    // Afficher les poids du deuxième neurone du réseau
    Couche* premiere_couche = getCoucheFromNetwork(reseau);
    Neurone* deuxieme_neurone = (Neurone*)(premiere_couche->neurones->head->next->data);
    ListNode* poids2 = getPoidsFromNeurone(deuxieme_neurone);
    printf("\nPoids du deuxieme neurone:\n"); 
    while (poids2) {
        printf("%d ", *(int*)poids2->data);
        poids2 = poids2->next;
    }
    printf("\n");

    RunGraphics(&reseau);



    //SUPPR MEMOIRE DES RESEAUX ET/OU/NON 
    FreeResNeur(&et1);
    FreeResNeur(&et2);
    FreeResNeur(&ou);
    FreeResNeur(&non);

*/


    int num_networks;
    printf("Combien de réseaux voulez-vous créer? ");
    scanf("%d", &num_networks);

    for (int i = 0; i < num_networks; i++) {
        int num_layers, weight;
        printf("Réseau %d:\n", i + 1);
        printf("Nombre de couches: ");
        scanf("%d", &num_layers);

        LinkedList* liste_nb_neur = createLinkedList();
        
        // Allocate memory for each neuron count to persist through the loop
        for (int j = 0; j < num_layers; j++) {
            int* num_neurons = (int*)malloc(sizeof(int));
            if (!num_neurons) {
                fprintf(stderr, "Erreur d'allocation mémoire\n");
                continue;
            }
            
            printf("Nombre de neurones pour la couche %d: ", j + 1);
            scanf("%d", num_neurons);
            
            if (!appendLinkedList(liste_nb_neur, num_neurons)) {
                fprintf(stderr, "Erreur d'ajout à la liste\n");
                free(num_neurons);
                continue;
            }
        }

        printf("Nombre d'entrées pour le réseau: ");
        scanf("%d", &weight);

        ResNeur reseau = CreerResNeur(num_layers, liste_nb_neur, weight);

        // Display network info
        printf("\nStructure du réseau:\n");
        ListNode* current = liste_nb_neur->head;
        for (int j = 0; j < num_layers; j++) {
            printf("Couche %d: %d neurones\n", j + 1, *(int*)current->data);
            current = current->next;
        }

        // Visualize the network
        RunGraphics(&reseau);

        // Cleanup
        FreeResNeur(&reseau);
        
        // Free the liste_nb_neur and its contents
        current = liste_nb_neur->head;
        while (current) {
            free(current->data);
            current = current->next;
        }
        freeLinkedList(liste_nb_neur);
    }

    return EXIT_SUCCESS;
}
