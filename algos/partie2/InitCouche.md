# Partie 2: Couche de neurones, fonction InitCouche

## Description
La fonction `InitCouche` permet de créer une couche de neurones et d'initialiser chacun de ses neurones. Elle prend en paramètres le nombre de neurones dans la couche ainsi que le nombre d’entrées de chaque neurone. Tous les neurones d’une couche ont le même nombre d’entrées. Cette fonction réutilise l’opération `InitNeur` pour initialiser chaque neurone.

## Données
- `nombre_neurones` : Entier (nombre de neurones dans la couche)
- `nombre_entrees` : Entier (nombre d’entrées de chaque neurone)

## Résultat
- `couche` : Une liste contenant des neurones initialisés

## Algorithme
```
Fonction InitCouche(nombre_neurones: Entier, nombre_entrees: Entier) : Liste<Neurone>
Début
    couche: Liste<Neurone> <- CreerListeVide()
    tete : Liste<Neurone> <- couche
    i : Entier
    newNeurone : Neurone
    pour i allant de 0 à nombre_neurones - 1 faire
        newNeurone <- InitNeur(nombre_entrees)
        valeur(tete) <- newNeurone
        tete <- suivant(tete)
    fait
    InitCouche <- couche
Fin
```