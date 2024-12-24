#ifndef HEADER_UTILS
#define HEADER_UTILS

#include "reseau.h"
#include "linkedlist.h"

Couche* getCoucheFromNetwork(ResNeur reseau);

Neurone* getNeuroneFromCouche(Couche* couche);

ListNode* getPoidsFromNeurone(Neurone* neurone);

void setAllPoidsNeurone(Neurone* neurone, int value);

Neurone* getNeuroneFromNetwork(ResNeur reseau);



#endif
