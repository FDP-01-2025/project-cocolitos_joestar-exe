#include "statementsALL.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Variables globales   

extern std::string tipoPupusa;
extern std::string nombrePupusa;


void pantallaSeleccion() {
    int opcion = 0;

    cout << "============== SELECCIONA TU PUPUSA ==============" << endl;
    cout << "   +----------------+       +----------------+" << endl;
    cout << "   |  PUPUSA MAIZ   |       |  PUPUSA ARROZ  |" << endl;
    cout << "   |   (O_o)  [MZ]  |       |   (^_^)  [AZ]   |" << endl;
    cout << "   |     Maiz       |       |     Arroz      |" << endl;
    cout << "   +----------------+       +----------------+" << endl;
    cout << "     Presiona 1               Presiona 2" << endl;

    while (opcion != 1 && opcion != 2) {
        cout << "\nIngresa 1 o 2: ";
        cin >> opcion;

        if (opcion == 1) {
            tipoPupusa = "Pupusa de Maiz";
        } else if (opcion == 2) {
            tipoPupusa = "Pupusa de Arroz";
        } else {
            cout << "Opcion invalida, intenta de nuevo." << endl;
        }
    }

    cout << "\nHas elegido: " << tipoPupusa << "!" << endl;
    cout << "\nAhora, ponle nombre a tu pupusa heroica: ";
    cin.ignore();
    getline(cin, nombrePupusa);
    cout << "\nPerfecto! Tu pupusa se llama: " << nombrePupusa << endl;
}