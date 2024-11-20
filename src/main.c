#include <stdio.h>

#include "linkedlist_int.h"

int main() {
    IntLinkedList* list = createIntList();

    appendInt(list, 10);
    appendInt(list, 20);
    appendInt(list, 30);
    displayIntList(list);

    insertInt(list, 15, 1);
    displayIntList(list);

    deleteInt(list, 20);
    displayIntList(list);

    freeIntList(list);
    return 0;
}

/*

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
    int nombre_couches = 3;
    int liste_neurones[] = {3,2,1}; // 1 neuron in the output layer

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
*/