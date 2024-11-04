
## Description
Permet de créer et initialiser un réseau de neurones avec un nombre donné de couches et une liste de neurones pour chaque couche.

## Lexique
Un réseau de neurones est défini par une structure contenant:
- nombre_couches X liste_neurones : Entier X Liste<Entier>

## Données
- `nombre_couches` un entier représentant le nombre de couches dans le réseau de neurones.
- `liste_neurones` une liste d'entiers représentant le nombre de neurones dans chaque couche.

## Résultat
- `reseau` un réseau de neurones initialisé avec le nombre de couches et de neurones spécifiés.

## Algorithme

```
Fonction CreerResNeur(nombre_couches: Entier, liste_neurones: Liste<Entier>, nombre_poids_entree: Entier) : ResNeur
Début
    // Création et initialisation du réseau de neurones
    reseau : ResNeur <- CreerUnResNeur()
    nbCouches(reseau) : Entier <- nombre_couches
    couches(reseau) : Liste<Couche> <- CreerListeVide()
    tete : Liste<Couche> <- couches(reseau)

    i : Entier
    couche : Couche <- INDEFINI

    nombre_neurones_couche : Entier <- INDEFINI
    nombre_neurones_couche_precedente : Entier <- INDEFINI


    pour i allant de 0 à nombre_couches - 1 faire
        nombre_neurones_couche <- valeur(liste_neurones)
        si i est égal à 0 alors
            nombre_neurones_couche_precedente <- nombre_poids_entree
        sinon
            nombre_neurones_couche_precedente <- nombre_neurones_couche
        fin si
        couche <- InitCouche(nombre_neurones_couche, nombre_neurones_couche_precedente)
        tete <- insererQueue(tete, couche)
        liste_neurones <- succ(liste_neurones)
    fait

    CreerResNeur <- reseau
Fin
```