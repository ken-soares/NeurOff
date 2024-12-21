#include "utils.h"

Couche* getCoucheFromNetwork(ResNeur reseau) {
    return (Couche*)(reseau.couches->head->data);
}

Neurone* getNeuroneFromCouche(Couche* couche) {
    return (Neurone*)(couche->neurones->head->data);
}

ListNode* getPoidsFromNeurone(Neurone* neurone) {
    return neurone->poids->head;
}

void setAllPoidsNeurone(Neurone* neurone, int value) {
    ListNode* current = neurone->poids->head;
    while (current) {
        *(int*)current->data = value;
        current = current->next;
    }
}


Neurone* getNeuroneFromNetwork(ResNeur reseau) {
    Couche* couche = getCoucheFromNetwork(reseau);
    return getNeuroneFromCouche(couche);
}

