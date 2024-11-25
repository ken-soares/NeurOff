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

    // récupération des données qui nous intéressent
    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Couche couche = *(Couche*)(reseau.couches->head->data);
    Neurone* neur = (Neurone*)(couche.neurones->head->data);
    ListNode* l = neur->poids->head;


    // set le biais du neurone à n
    neur->biais = n;
   
    // remettre correctement tous les poids du neurone à 1
    while(l) {
        *(int*)l->data = 1;
        l = l->next;
    }
    
    return reseau;
}

ResNeur InitResOU(int n) {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);


    ResNeur reseau = CreerResNeur(1, liste_nb_neur, n);
    Couche couche = *(Couche*)(reseau.couches->head->data);
    Neurone* neur = (Neurone*)(couche.neurones->head->data);
    ListNode* l = neur->poids->head;

    // set le biais du neurone à 1
    neur->biais = 1;
    
    while(l) {
        *(int*)l->data = 1;
        l = l->next;
    }
    
    return reseau;
}

ResNeur InitResNOT() {
    // 1 neurone par couche et 1 couche
    LinkedList* liste_nb_neur = createLinkedList();
    int a = 1;
    appendLinkedList(liste_nb_neur, &a);


    ResNeur reseau = CreerResNeur(1, liste_nb_neur, 1);
    Couche couche = *(Couche*)(reseau.couches->head->data);
    Neurone* neur = (Neurone*)(couche.neurones->head->data);
    ListNode* l = neur->poids->head;

    // comme il n'y a qu'un seul poids, on set directement sa valeur 1 -1
    *(int*)l->data = -1;

    // set le biais du neurone à 0
    neur->biais = 0;
    
    return reseau;
}
