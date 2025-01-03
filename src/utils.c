#include "utils.h"

// renvoie la première couche d'un réseau de neurones
Couche* getCoucheFromNetwork(ResNeur reseau) {
    return (Couche*)(reseau.couches->head->data);
}

// renvoie le premier neurone d'une couche
Neurone* getNeuroneFromCouche(Couche* couche) {
    return (Neurone*)(couche->neurones->head->data);
}

// renvoie la liste des poids d'un neurone
ListNode* getPoidsFromNeurone(Neurone* neurone) {
    return neurone->poids->head;
}

// définit tous les poids d'un neurone à une valeur donnée
void setAllPoidsNeurone(Neurone* neurone, int value) {
    ListNode* current = neurone->poids->head;
    while (current) {
        *(int*)current->data = value;
        current = current->next;
    }
}

// renvoie le premier neurone d'un réseau de neurones
Neurone* getNeuroneFromNetwork(ResNeur reseau) {
    Couche* couche = getCoucheFromNetwork(reseau);
    return getNeuroneFromCouche(couche);
}

