# Partie 2 Couche de neurones, fonction Outcouche

## Description
Permet de calculer la liste des sorties d'une couche donnée en fonction
de la liste des entrées de chacun de ses neurones.
la liste des sorties est composée des sorties des différents neurones
de la couche. A noter que cette liste est la même pour chaque neurone de la 
couche. Cette Opération réutilise l'opération `Outneurone`

## Lexique
Une couche de neurones est définie par le une liste de neurones et le nombre de neurones dans la couche
- nombre_neurones X nombre_entrees : Entier X Entier
Une couche est définie par une liste de neurones
- couche : Liste<Neurone>

## Données
- `couche` une couche de neurones
- `liste_entrees` une liste d'entiers en entrée pour chaque neurone de la couche
- `liste_sorties` une liste d'entiers en entrée pour chaque neurone de la couche

## Résultat
- `liste_sorties` une liste de toutes les valeurs de sortie des neurones (qui
n'est pas renvoyé par le programme car c'est une procédure et non une fonction)

## Algorithme
```
procédure Outcouche(couche: Couche, liste_entrees: Liste<Entier>, liste_sorties: Liste<Entier>)
Début

    Tantque non estVide(liste(couche)) faire
        liste_sorties <- insererQueue(Outneurone(liste_entrees, val(liste(couche))))
    fait

Fin
```
