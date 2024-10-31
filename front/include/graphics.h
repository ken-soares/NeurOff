#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h>
#include "reseau.h"

// Function to initialize and run the graphical interface
int RunGraphics(HINSTANCE hInstance, ResNeur* reseau);

// Window Procedure Callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif // GRAPHICS_H