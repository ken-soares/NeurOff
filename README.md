# NeurOff
Projet de LO21 sur les réseaux de neuronnes en C
Voir [énoncé](enonce.md)

### Prérequis logiciels
- CMake (version récente pour utiliser FetchContent nécéssaire au front-end)
- Make
- Un compilateur c/c++

### explication des dossiers
```
    src: code source en C
    include: fichiers d'en-tête
    algos: algorithmes implémentés par la suite en C
    front: dossier source pour la visualisation graphique du projet (ne fonctionne pas sur WSL)
```

### Commandes de compilation
```
git clone https://github.com/ken-soares/NeurOff.git
cd NeurOff/
cmake .
cmake --build .
./projet
```
