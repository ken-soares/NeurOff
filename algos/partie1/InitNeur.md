# Partie 1: Neurone artificiel, fonction InitNeur

## Description
Cette fonction permet d'initialiser un neurone artificiel avec un nombre d'entrées donné. Elle génère aléatoirement les poids associés à chaque entrée ainsi que le biais du neurone.

## Données
- nombre_entrees : Entier (nombre d'entrées du neurone à créer)

## Résultat 
- neurone : Structure contenant:
  - poids : Liste d'entiers (poids associés à chaque entrée)
  - biais : Entier (seuil d'activation du neurone)

## Algorithme
```
Fonction InitNeur(nombreEntrées: Entier) : Neurone
Début
    // Création et initialisation du neurone
    n : Neurone <- CreerUnNeurone()
    poids(n) : Liste<Entier> <- ListeDeTaille(nombreEntrées)

    // Initialisation aléatoire du biais
    biais(n) <- NombreAléatoire()
    
    // Initialisation aléatoire des poids
    p : Liste<Entier> <- poids(n)
    tant que p /= indéfini faire
        val(p) <- NombreAléatoire()
        p <- succ(p)
    fait
    
    InitNeur <- n
Fin
```