#ifndef NEUROFF_NEURONE_H
#define NEUROFF_NEURONE_H

#include "linkedlist.h"

// Structure représentant un neurone artificiel
typedef struct {
    LinkedList* poids;   // Liste des poids pour chaque entrée
    int nbPoids;         // Nombre de poids/entrées
    int biais;           // Valeur du biais/seuil
} Neurone;

// Fonction pour initialiser un neurone avec des poids et un biais aléatoires
// Prend en paramètre le nombre d'entrées
// Retourne une structure Neurone initialisée
Neurone InitNeur(int nombreEntrees);

// Fonction pour libérer la mémoire allouée pour un neurone
// Prend en paramètre un pointeur vers la structure Neurone
void FreeNeur(Neurone* neurone);

// Fonction pour calculer la sortie d'un neurone en fonction d'une liste d'entrées
// Prend en paramètre le neurone et la liste d'entrées
// Retourne la sortie du neurone
int Outneurone(LinkedList* entrees, Neurone* n);

#endif //NEUROFF_NEURONE_H
