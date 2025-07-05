#include "fun.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

extern std::string tipoPupusa;
extern std::string nombrePupusa;

void mapaVolcan() {
    const int altura = 10;
    char mapa[altura][2 * altura + 1];
    int jugadorY = altura - 1;
    int jugadorX = altura;

    for (int i = 0; i < altura; i++)
        for (int j = 0; j < 2 * altura + 1; j++)
            mapa[i][j] = ' ';

    for (int i = 0; i < altura; i++)
        for (int j = altura - i; j <= altura + i; j++)
            mapa[i][j] = '.';

    mapa[0][altura] = 'X';

    bool llego = false;
    while (!llego) {
        system("cls");
        cout << "============ IZALCO ADVENTURES ============" << endl;
        cout << "Pupusa: " << nombrePupusa << " | Tipo: " << tipoPupusa << endl;
        cout << "------------------------------------------" << endl;

        mapa[jugadorY][jugadorX] = '@';
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < 2 * altura + 1; j++)
                cout << mapa[i][j];
            cout << endl;
        }
        mapa[jugadorY][jugadorX] = '.';

        cout << "\nEstas subiendo el volcan de Izalco..." << endl;
        cout << "Usa W (arriba), A (izquierda), D (derecha) para moverte.\n";

        char input;
        cin >> input;
        input = tolower(input);

        switch (input) {
            case 'w': if (jugadorY > 0 && mapa[jugadorY - 1][jugadorX] != ' ') jugadorY--; break;
            case 'a': if (jugadorX > 0 && mapa[jugadorY][jugadorX - 1] != ' ') jugadorX--; break;
            case 'd': if (jugadorX < 2 * altura && mapa[jugadorY][jugadorX + 1] != ' ') jugadorX++; break;
        }

        if (jugadorY == 0 && jugadorX == altura) llego = true;
    }

    cout << "\nLlegaste a la cima del volcan. El Cipitillo te espera..." << endl;
    Sleep(2000);
}