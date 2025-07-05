#include "fun.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
extern int vidaJugador;
extern int vidaEnemigo;
extern int defensa;
extern int ataqueExtra;
extern bool salvaCola;
extern bool choripanes;
extern bool kolashanpan;

void batalla() {
    srand(time(0));
    vidaJugador = 100;
    vidaEnemigo = 120;
    defensa = 0;
    ataqueExtra = 0;
    salvaCola = true;
    choripanes = true;
    kolashanpan = true;

    cout << "\nCOMIENZA LA BATALLA!" << endl;
    cout << "Tu Pokemon: Torogoz del Bosque\nEnemigo: Dragon Tlaloc\n";

    torogos_perpectiva_1();
    Sleep(1500);
    Dragon_BATALLA();
    Sleep(2000);

    while (vidaJugador > 0 && vidaEnemigo > 0) {
        cout << "\n== Tu turno ==" << endl;
        cout << "1. Ataque 1: Ala Tornado" << endl;
        cout << "2. Ataque 2: Canto Cuscatleco" << endl;
        cout << "3. Ataque 3: Pico Flameante" << endl;
        cout << "4. Ataque 4: Furia Tropical" << endl;
        cout << "5. Mochila" << endl;
        cout << "Elige una opcion: ";

        int opcion;
        cin >> opcion;
        int dano = 0;

        switch (opcion) {
            case 1: dano = 15 + ataqueExtra; break;
            case 2: dano = 10 + rand() % 10 + ataqueExtra; break;
            case 3: dano = 20 + ataqueExtra; break;
            case 4: dano = 5 + rand() % 25 + ataqueExtra; break;
        }

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ataque realizado. Daño: " << dano << endl;
            vidaEnemigo -= dano;
        } else if (opcion == 5) {
            cout << "\n== Mochila ==" << endl;
            if (salvaCola) cout << "1. Salva Cola (restaura vida)" << endl;
            if (choripanes) cout << "2. Choripanes (aumenta defensa)" << endl;
            if (kolashanpan) cout << "3. Kolashanpan (aumenta ataque)" << endl;
            cout << "0. Cancelar" << endl;
            cin >> opcion;
            switch (opcion) {
                case 1: if (salvaCola) { vidaJugador = min(100, vidaJugador + 30); salvaCola = false; cout << "Salva Cola usada!" << endl; } break;
                case 2: if (choripanes) { defensa += 5; choripanes = false; cout << "Choripanes usados!" << endl; } break;
                case 3: if (kolashanpan) { ataqueExtra += 5; kolashanpan = false; cout << "Kolashanpan usada!" << endl; } break;
                default: cout << "Nada usado." << endl; break;
            }
        }

        ataqueExtra = 0;
        if (vidaEnemigo > 0) {
            int danoEnemigo = rand() % 20 + 5 - defensa;
            if (danoEnemigo < 0) danoEnemigo = 0;
            vidaJugador -= danoEnemigo;
            cout << "El enemigo ataca y te hace " << danoEnemigo << " de daño. Tu vida: " << vidaJugador << endl;
        }
    }

    if (vidaJugador <= 0)
        cout << "\nPerdiste la batalla... A la vuelta esta la parada de buses pa que te vayas." << endl;
    else
        cout << "\nGanaste la batalla! Encontraste la salsa y el curtido majestuoso." << endl;
}