#include "utilities.h"
#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;

// ============= COLORES =============
void setColor(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }

// ============= PAUSA =============
void pausa() {
    cout << "\n(Presiona ENTER para continuar)";
    cin.ignore();
    cin.get();
}

// ============= LIMPIAR BUFFER =============
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ============= ANIMACIÓN DE CARGA =============
void animacionCarga() {
    cout << "Cargando";
    for (int i = 0; i < 3; i++) {
        Sleep(400);
        cout << ".";
    }
    cout << endl;
    Sleep(500);
    system("cls");
}

// ============= MENSAJE NPC =============
void mensajeNPC(string s) {
    setColor(11);
    cout << "\n[NPC]: " << s << "\n";
    setColor(7);
    Sleep(900);
}
