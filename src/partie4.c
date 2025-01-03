#include "utils.h"
#include "couche.h"
#include "reseau.h"
#include "linkedlist.h"
#include <stdio.h>

// Fonction utilitaire pour définir une valeur à 1
void setToOne(void* a){
    *(int*)a = 1;
}

// Initialise un réseau de neurones pour l'opération ET
ResNeur InitResET(int n) {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);

    // Crée le réseau avec une seule couche et un neurone
    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Neurone* neur = getNeuroneFromNetwork(reseau);
    
    // Définit le biais du neurone à n
    neur->biais = n;
    // Définit tous les poids du neurone à 1
    setAllPoidsNeurone(neur, 1);
    
    return reseau;
}

// Initialise un réseau de neurones pour l'opération OU
ResNeur InitResOU(int n) {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);

    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Neurone* neur = getNeuroneFromNetwork(reseau);
    
    // Définit le biais du neurone à 1
    neur->biais = 1;
    // Définit tous les poids du neurone à 1
    setAllPoidsNeurone(neur, 1);
    
    return reseau;
}

// Initialise un réseau de neurones pour l'opération NOT
ResNeur InitResNOT() {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);

    ResNeur reseau = CreerResNeur(1, liste_nb_neur, 1);
    Neurone* neur = getNeuroneFromNetwork(reseau);

    // Définit le poids unique du neurone à -1
    *(int*)neur->poids->head->data = -1;
    // Définit le biais du neurone à 0
    neur->biais = 0;
    
    return reseau;
}
