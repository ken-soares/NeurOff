# Partie 1: Neurone artificiel, fonction Outneurone

## Lexique
  Un neurone est un type structuré :
    poids X biais : Liste<Entier> X Entier

## Données:
- liste d'entiers e
- neurone n
- entier seuil (pour la fonction activation)

## Résultat
- entier : 0 ou 1


## algorithme:
```
fonction activation(x: Entier, seuil: Entier) : Entier
Début
	si x >= seuil alors
		activation <- 1
	sinon
		activation <- 0
	fin si
Fin

fonction Outneurone(e: liste<Entier>, n: neurone) : Entier
Début

	x: Entier <- 0
	
	tant que poids(n) /= indéfini ET e /= indéfini faire
		x <- x + poids(n) * val(e)
		poids(n) <- succ(poids(n))
		e <- succ(e)
	fait
	
	Outneurone <- activation(x, seuil(n))
Fin
```
