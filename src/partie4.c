#include "utils.h"
#include "couche.h"
#include "reseau.h"
#include "linkedlist.h"
#include <stdio.h>

void setToOne(void* a){
    *(int*)a = 1;
}

ResNeur InitResET(int n) {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);

    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Neurone* neur = getNeuroneFromNetwork(reseau);
    
    // set le biais du neurone à n
    neur->biais = n;
    setAllPoidsNeurone(neur, 1);
    
    return reseau;
}

ResNeur InitResOU(int n) {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);


    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Neurone* neur = getNeuroneFromNetwork(reseau);
    
    // set le biais du neurone à 1
    neur->biais = 1;
    
    // Set all weights to 1 using the new function
    setAllPoidsNeurone(neur, 1);
    
    return reseau;
}

ResNeur InitResNOT() {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);


    ResNeur reseau = CreerResNeur(1, liste_nb_neur, 1);
    Neurone* neur = getNeuroneFromNetwork(reseau);

    // comme il n'y a qu'un seul poids, on set directement sa valeur 1 -1
    *(int*)neur->poids->head->data = -1;

    // set le biais du neurone à 0
    neur->biais = 0;
    
    return reseau;
}
