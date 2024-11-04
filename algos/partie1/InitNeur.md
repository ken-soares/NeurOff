# Partie 1: Neurone artificiel, fonction InitNeur

## Lexique
  Un neurone est un type structuré :
    poids X biais : Liste<Entier> X Entier

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
    poids(n) : Liste<Entier> <- ListVide()

    // Initialisation aléatoire du biais
    biais(n) <- NombreAléatoire()
    
    // Initialisation aléatoire des poids
    p : Liste<Entier> <- poids(n)
    p <- insererQueue(NombreAléatoire())
    tant que nombreEntrées > 0 faire
        p <- insererQueue(NombreAléatoire())
        nombreEntrées <- nombreEntrées - 1
    fait
    
    InitNeur <- n
Fin
```