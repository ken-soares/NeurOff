#include <stdlib.h>
#include "couche.h"
#include "neurone.h"
// Initialise une couche avec un nombre donné de neurones et d'entrées par neurone
Couche InitCouche(int nombre_neurones, int nombre_entrees)
{
    Couche couche;
    couche.neurones = 0;
    couche.nbNeurones = nombre_neurones;


    couche.neurones = (Neurone *)malloc(nombre_neurones * sizeof(Neurone));
    if (!couche.neurones)
    {
        return (Couche){0};
    }
    for (int i = 0; i < nombre_neurones; i++)
    {
        couche.neurones[i] = InitNeur(nombre_entrees);
    }
    return couche;
}

void OutCouche(Couche *couche, int *entrees, int *sorties) {
    for(int i = 0; i < couche->nbNeurones;i++) {
        sorties[i] = Outneurone(entrees, &(couche->neurones[i]));
    }
}
