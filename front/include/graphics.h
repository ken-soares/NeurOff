#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"
#include "reseau.h"

// Fonction pour initialiser et exécuter l'interface graphique
// Prend en paramètre un pointeur vers le réseau de neurones
// Retourne un entier indiquant le succès ou l'échec de l'exécution
int RunGraphics(ResNeur* reseau);

#endif // GRAPHICS_H

