#include "graphics.h"
#include <stdio.h>
#include <string.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LAYER_SPACING 200
#define NEURON_RADIUS 20
#define HORIZONTAL_SPACING 150

static ResNeur* g_reseau = NULL;

// Structure to hold neuron positions for drawing connections
typedef struct {
    int x;
    int y;
} NeuronPosition;

// Helper function to draw a neuron
void DrawNeuron(HDC hdc, int x, int y, int neuronIndex) {
    // Draw circle
    Ellipse(hdc, x - NEURON_RADIUS, y - NEURON_RADIUS, x + NEURON_RADIUS, y + NEURON_RADIUS);
    
    // Draw neuron label
    char label[10];
    sprintf(label, "N%d", neuronIndex + 1);
    TextOutA(hdc, x - 10, y - 7, label, strlen(label));
}

// Helper function to draw a line with intensity based on weight
void DrawWeight(HDC hdc, int x1, int y1, int x2, int y2, int weight) {
    // Calculate color intensity (assuming weight ranges from 1 to 10)
    BYTE intensity = (BYTE)(255 * weight / 10); // 0 to 255
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(intensity, 0, 0)); // Red intensity
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);
    
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

// Window Procedure Callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            if (g_reseau) {
                ListNode* current_couche_node = g_reseau->couches->head;
                int couche_index = 0;

                // Array to store neuron positions of the previous layer
                NeuronPosition* prev_positions = NULL;
                int prev_neurons = 0;

                while (current_couche_node) {
                    Couche* couche = (Couche*)current_couche_node->data;
                    int nb_neurones = couche->nbNeurones;
                    int spacing_y = (nb_neurones > 1) ? WINDOW_HEIGHT / (nb_neurones + 1) : WINDOW_HEIGHT / 2;

                    // Allocate memory to store current layer's neuron positions
                    NeuronPosition* current_positions = (NeuronPosition*)malloc(sizeof(NeuronPosition) * nb_neurones);
                    if (!current_positions) {
                        fprintf(stderr, "Erreur : Impossible d'allouer de la mémoire pour les positions des neurones.\n");
                        if (prev_positions) free(prev_positions);
                        break;
                    }

                    ListNode* current_neurone_node = couche->neurones->head;
                    int neuron_index = 0;

                    // Iterate through neurons in the current layer
                    while (current_neurone_node) {
                        Neurone* neurone = (Neurone*)current_neurone_node->data;
                        int x = LAYER_SPACING + couche_index * LAYER_SPACING;
                        int y = spacing_y * (neuron_index + 1);

                        // Draw neuron
                        DrawNeuron(hdc, x, y, neuron_index);

                        // Draw bias below neuron
                        char bias_label[20];
                        sprintf(bias_label, "B:%d", neurone->biais);
                        TextOutA(hdc, x - 15, y + NEURON_RADIUS + 5, bias_label, strlen(bias_label));

                        // Store the neuron's position for drawing connections
                        current_positions[neuron_index].x = x;
                        current_positions[neuron_index].y = y;

                        neuron_index++;
                        current_neurone_node = current_neurone_node->next;
                    }

                    // After drawing neurons, draw weights from previous layer if not the first layer
                    if (couche_index > 0 && prev_positions && prev_neurons > 0) {
                        current_neurone_node = couche->neurones->head;
                        neuron_index = 0;

                        while (current_neurone_node) {
                            Neurone* neurone = (Neurone*)current_neurone_node->data;

                            // Traverse the weights linked list
                            ListNode* current_poids_node = neurone->poids->head;
                            int weight_index = 0;

                            int current_x = current_positions[neuron_index].x;
                            int current_y = current_positions[neuron_index].y;

                            while (current_poids_node && weight_index < prev_neurons) {
                                int weight = *((int*)current_poids_node->data);
                                int prev_x = prev_positions[weight_index].x;
                                int prev_y = prev_positions[weight_index].y;

                                // Draw weight line
                                DrawWeight(hdc, prev_x + NEURON_RADIUS, prev_y, current_x - NEURON_RADIUS, current_y, weight);

                                current_poids_node = current_poids_node->next;
                                weight_index++;
                            }

                            neuron_index++;
                            current_neurone_node = current_neurone_node->next;
                        }
                    }

                    // Free the previous layer's positions and update to current
                    if (prev_positions) {
                        free(prev_positions);
                    }
                    prev_positions = current_positions;
                    prev_neurons = nb_neurones;

                    couche_index++;
                    current_couche_node = current_couche_node->next;
                }

                // Free the last layer's positions
                if (prev_positions) {
                    free(prev_positions);
                }
            }
            
            EndPaint(hwnd, &ps);
        }
        return 0;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

// Function to initialize and run the graphical interface
int RunGraphics(HINSTANCE hInstance, ResNeur* reseau) {
    g_reseau = reseau;
    
    const char CLASS_NAME[] = "NeuralNetworkWindowClass";
    
    WNDCLASS wc = {0};
    
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }
    
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Neural Network Visualization",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }
    
    ShowWindow(hwnd, SW_SHOW);
    
    // Message Loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}