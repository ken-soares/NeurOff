#include "graphics.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LAYER_SPACING 200
#define NEURON_RADIUS 20
#define HORIZONTAL_SPACING 150

static ResNeur* g_reseau = NULL;

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
                for (int i = 0; i < g_reseau->nbCouches; i++) {
                    Couche couche = g_reseau->couches[i];
                    int nb_neurones = couche.nbNeurones;
                    int spacing_y = (nb_neurones > 1) ? WINDOW_HEIGHT / (nb_neurones + 1) : WINDOW_HEIGHT / 2;
                    
                    for (int j = 0; j < nb_neurones; j++) {
                        int x = LAYER_SPACING + i * LAYER_SPACING;
                        int y = spacing_y * (j + 1);
                        
                        // Draw neuron
                        DrawNeuron(hdc, x, y, j);
                        
                        // Draw bias below neuron
                        char bias_label[20];
                        sprintf(bias_label, "B:%d", couche.neurones[j].biais);
                        TextOutA(hdc, x - 15, y + NEURON_RADIUS + 5, bias_label, strlen(bias_label));
                        
                        // Draw weights from previous layer
                        if (i > 0) {
                            Couche prev_couche = g_reseau->couches[i - 1];
                            for (int k = 0; k < prev_couche.nbNeurones; k++) {
                                int prev_x = LAYER_SPACING + (i - 1) * LAYER_SPACING;
                                int prev_y = (prev_couche.nbNeurones > 1) ? WINDOW_HEIGHT / (prev_couche.nbNeurones + 1) * (k + 1) : WINDOW_HEIGHT / 2;
                                
                                int weight = couche.neurones[j].poids[k];
                                DrawWeight(hdc, prev_x + NEURON_RADIUS, prev_y, x - NEURON_RADIUS, y, weight);
                            }
                        }
                    }
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