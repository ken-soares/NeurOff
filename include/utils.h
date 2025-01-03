#ifndef HEADER_UTILS
#define HEADER_UTILS

#include "reseau.h"
#include "linkedlist.h"

// Fonction pour obtenir la première couche d'un réseau de neurones
// Prend en paramètre un réseau de neurones
// Retourne un pointeur vers la première couche
Couche* getCoucheFromNetwork(ResNeur reseau);

// Fonction pour obtenir le premier neurone d'une couche
// Prend en paramètre une couche
// Retourne un pointeur vers le premier neurone de la couche
Neurone* getNeuroneFromCouche(Couche* couche);

// Fonction pour obtenir la liste des poids d'un neurone
// Prend en paramètre un neurone
// Retourne un pointeur vers le premier nœud de la liste des poids
ListNode* getPoidsFromNeurone(Neurone* neurone);

// Fonction pour définir tous les poids d'un neurone à une valeur donnée
// Prend en paramètres un neurone et la valeur à définir
void setAllPoidsNeurone(Neurone* neurone, int value);

// Fonction pour obtenir le premier neurone du réseau de neurones
// Prend en paramètre un réseau de neurones
// Retourne un pointeur vers le premier neurone du réseau
Neurone* getNeuroneFromNetwork(ResNeur reseau);

#endif
