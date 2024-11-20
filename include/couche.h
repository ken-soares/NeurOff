#ifndef NEUROFF_COUCHE_H
#define NEUROFF_COUCHE_H
#include "neurone.h"
#include "linkedlist.h" // Assuming a generic linked list implementation

// Structure représentant une couche de neurones artificiels
typedef struct
{
    LinkedList* neurones; // Liste de neurones
    int nbNeurones;       // Nombre de neurones dans la couche
} Couche;

// Fonction pour initialiser une couche avec un nombre donné de neurones et d'entrées par neurone
// Prend en paramètres le nombre de neurones et le nombre d'entrées par neurone
// Retourne une structure Couche initialisée ou NULL si l'allocation échoue
Couche InitCouche(int nombre_neurones, int nombre_entrees);

// Fonction pour libérer la mémoire allouée pour une couche
// Prend en paramètre un pointeur vers la couche
void FreeCouche(Couche* couche);

// Fonction pour calculer les sorties d'une couche en fonction des entrées et d'un seuil
// Prend en paramètres la couche, la liste des entrées et la liste des sorties
// Retourne une liste d'entiers représentant les sorties de chaque neurone
LinkedList* OutCouche(Couche* couche, LinkedList* entrees);

#endif // NEUROFF_COUCHE_H
