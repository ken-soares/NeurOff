# Partie 2: Couche de neurones, fonction InitCouche


## Description
La fonction `InitCouche` permet de créer une couche de neurones et d'initialiser chacun de ses neurones. Elle prend en paramètres le nombre de neurones dans la couche ainsi que le nombre d’entrées de chaque neurone. Tous les neurones d’une couche ont le même nombre d’entrées. Cette fonction réutilise l’opération `InitNeur` pour initialiser chaque neurone.

## Lexique
Une couche de neurones est définie par le une liste de neurones et le nombre de neurones dans la couche
- nombre_neurones X nombre_entrees : Entier X Entier
Une couche est définie par une liste de neurones
- couche : Liste<Neurone>

## Données
- `nombre_neurones` : Entier (nombre de neurones dans la couche)
- `nombre_entrees` : Entier (nombre d’entrées de chaque neurone)

## Résultat
- `couche` : Une liste contenant des neurones initialisés

## Algorithme
```
Fonction InitCouche(nombre_neurones: Entier, nombre_entrees: Entier) : Liste<Neurone>
Début
    // Création d'une liste vide pour la couche de neurones
    couche: Liste<Neurone> <- CreerListeVide()
    
    // Initialisation de chaque neurone dans la couche
    i : Entier
    pour i allant de 0 à nombre_neurones - 1 faire
        // Initialiser un nouveau neurone avec le nombre d'entrées spécifié
        newNeurone : Neurone <- InitNeur(nombre_entrees)
        
        // Ajouter le neurone initialisé à la couche
        couche <- insererQueue(newNeurone)
    fait
    
    // Retourner la couche de neurones initialisée
    InitCouche <- couche
Fin
```