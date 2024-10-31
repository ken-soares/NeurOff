#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "neurone.h"
#include "couche.h"
#include "reseau.h"
#include "graphics.h"

#define TAILLE 2 // Number of input neurons

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(NULL));

    // Define the network structure: 2 input neurons, 1 output neuron
    int nombre_couches = 5;
    int liste_neurones[] = {1,10,22,33,1}; // 1 neuron in the output layer

    // Create the neural network
    ResNeur reseau = CreerResNeur(nombre_couches, liste_neurones, TAILLE);
    if (reseau.couches == NULL) {
        MessageBox(NULL, "Failed to initialize the neural network.", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    // Run the graphical interface
    printf("Launching graphical interface...\n");
    int gfxResult = RunGraphics(hInstance, &reseau);
    printf("Graphical interface exited with result: %d\n", gfxResult);

    // Free the neural network memory
    FreeResNeur(&reseau);

    return gfxResult;
}
