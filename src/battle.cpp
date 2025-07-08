#include "battle.h"
#include "cuscamon.h"
#include "object.h"
#include "utilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "defs.h"
using namespace std;

// ====== BUFFS/DEBUFFS GLOBALES ======
int boostAtaqueJugador = 0;
int boostDefensaJugador = 0;
int debuffDefensaEnemigo = 0;

// --- Prototipo adaptado ---
void mochilaMenuBatalla(int & pokeActual);

// ====== SISTEMA DE BATALLA ======
void batalla(int idEnemigo, bool esSalvaje, bool legendario) {
    int enemigoHP = pokedex[idEnemigo].vidaMax;
    int pokeActual = equipo[0]; // slot del primer cuscamón en el equipo
    bool huido = false, atrapado = false;
    srand(time(0));
    pokesVistos[idEnemigo] = 1;

    // Resetea buffs para esta batalla
    boostAtaqueJugador = 0;
    boostDefensaJugador = 0;
    debuffDefensaEnemigo = 0;

    while (enemigoHP > 0 && !huido && !atrapado) {
        system("cls");
        // Info combate
        setColor(12);
        cout << pokedex[idEnemigo].nombre << " | HP: " << enemigoHP << "/" << pokedex[idEnemigo].vidaMax << endl;
        setColor(7);
        cout << pokedex[idEnemigo].ascii << endl;
        setColor(10);
        // Mostrando el cuscamón actual correctamente:
        cout << pokedex[pokeActual].nombre << " | HP: " << pokedex[pokeActual].vida << "/" << pokedex[pokeActual].vidaMax << endl;
        setColor(7);
        cout << pokedex[pokeActual].ascii << endl;

        // Opciones de menú
        cout << "\n1. " << pokedex[pokeActual].ataques[0].nombre;
        cout << "\n2. " << pokedex[pokeActual].ataques[1].nombre;
        cout << "\n3. " << pokedex[pokeActual].ataques[2].nombre;
        cout << "\n4. " << pokedex[pokeActual].ataques[3].nombre;
        cout << "\n5. Cambiar cuscamón";
        if (esSalvaje) cout << "\n6. Usar Cuscaball";
        cout << "\n7. Mochila";
        cout << "\n8. Huir\n";
        int op;
        while (true)
        {
            cout << "Elige opción: ";
            if (cin >> op)
            {
                if (op >= 1 && op <= 8)
                    break;
                cout << "Opción fuera de rango.\n";
            }
            else
            {
                cout << "Entrada inválida, ingresa un número.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

        if (op >= 1 && op <= 4) {
            int power = pokedex[pokeActual].ataques[op-1].poder + boostAtaqueJugador;
            cout << "\n¡" << pokedex[pokeActual].nombre << " usó " << pokedex[pokeActual].ataques[op-1].nombre << "!";
            if (power > 0) {
                int defensa = debuffDefensaEnemigo;
                int danio = (power - defensa);
                if (danio < 1) danio = 1;
                enemigoHP -= danio; // Aplica boost/debuffs
                if (enemigoHP < 0) enemigoHP = 0;
                cout << " (-" << danio << "HP)";
            }
            cout << endl; Sleep(800);
        } else if (op == 5) {
            // Selección por slot (índice en el equipo)
            int nuevoSlot = -1;
            while (true) {
                cout << "\nSelecciona un Cuscamon de tu equipo:\n";
                for (int i = 0; i < numEquipo; i++) {
                    cout << (i+1) << ". " << pokedex[equipo[i]].nombre
                         << " (HP: " << pokedex[equipo[i]].vida << "/" << pokedex[equipo[i]].vidaMax << ")\n";
                }
                cout << "Opción: ";
                int slot;
                cin >> slot;
                if (slot >= 1 && slot <= numEquipo && pokedex[equipo[slot-1]].vida > 0) {
                    nuevoSlot = equipo[slot-1];
                    break;
                } else {
                    cout << "Cuscamon invalido o debilitado. Intenta de nuevo.\n";
                }
            }
            pokeActual = nuevoSlot;
            continue;
        } else if (esSalvaje && op == 6) {
            int idx = buscarObjeto("Cuscaball");
            if (idx == -1 || mochila[idx].cantidad <= 0) {
                cout << "¡No tienes Cuscaballs!\n"; Sleep(900); continue;
            }
            cout << "¡Lanzas una Cuscaball!\n";
            mochila[idx].cantidad--;
            int chance = 30 + rand()%45; // base
            if (legendario && enemigoHP > 50) chance = 5;
            else if (legendario) chance = 35;
            if (enemigoHP <= 20) chance += 30;
            if (rand()%100 < chance) {
                cout << "¡Atrapalo ahora!\n";
                atrapado = true;
                pokedex[idEnemigo].atrapado = true;
                if (numEquipo < MAX_EQUIPO)
                    equipo[numEquipo++] = idEnemigo;
                else
                    cout << "Equipo lleno enviado al PC imaginario xD\n";
            } else {
                cout << "¡Oh no! ¡El cuscamon escapo!\n";
            }
            Sleep(1200);
            continue;
        } else if (op == 7) {
            mochilaMenuBatalla(pokeActual); // Cambiado para pasar pokeActual por referencia
            continue;
        } else if (op == 8) {
            cout << "¡Escapaste de la batalla!\n";
            huido = true; Sleep(1000);
            continue;
        } else {
            cout << "Opción no valida.\n";
            Sleep(700);
            continue;
        }

        // Turno enemigo (si sigue vivo)
        if (enemigoHP > 0) {
            int a = rand()%4;
            int poder = pokedex[idEnemigo].ataques[a].poder;
            cout << pokedex[idEnemigo].nombre << " usó " << pokedex[idEnemigo].ataques[a].nombre << "!";
            if (poder > 0) {
                int danio = poder - boostDefensaJugador;
                if (danio < 1) danio = 1;
                pokedex[pokeActual].vida -= danio;
                if (pokedex[pokeActual].vida < 0) pokedex[pokeActual].vida = 0;
                cout << " (-" << danio << "HP)\n";
            } else cout << " (no fue muy efectivo...)\n";
            Sleep(900);
            if (pokedex[pokeActual].vida <= 0) {
                cout << pokedex[pokeActual].nombre << " se debilito.\n";
                bool todosDebil = true;
                for (int i=0; i<numEquipo; i++) if (pokedex[equipo[i]].vida > 0) todosDebil = false;
                if (todosDebil) {
                    cout << "¡Todos tus cuscamones estan fuera de combate!\n";
                    Sleep(2000); return;
                }
                // Selecciona el siguiente cuscamón disponible
                int siguiente = -1;
                for (int i=0; i<numEquipo; i++) {
                    if (pokedex[equipo[i]].vida > 0) {
                        siguiente = equipo[i];
                        break;
                    }
                }
                pokeActual = siguiente;
                cout << "\n¡Elige tu siguiente Cuscamon!\n";
                Sleep(1000);
            }
        }
    }
    if (enemigoHP <= 0) {
        cout << "\n¡Ganaste la batalla!\n";
        pokedex[idEnemigo].atrapado = true;
        Sleep(1000);
        if (idEnemigo == 6) {
            for (int i = 0; i < numEquipo; i++) pokedex[equipo[i]].vida = pokedex[equipo[i]].vidaMax;
            cout << "El curtido legendario ha curado a todo tu equipo.\n";
        }
    }
    if (atrapado) cout << "¡Cuscamon atrapado!\n";
    pausa();
}

// ====== MENÚ MOCHILA EN BATALLA ======
void mochilaMenuBatalla(int & pokeActual) {
    while (true) {
        system("cls");
        cout << "== MOCHILA EN BATALLA ==\n";
        for (int i = 0; i < MAX_OBJETOS; i++) {
            if (mochila[i].cantidad > 0 && (
                i == 1 || // Salva Cola
                i == 3 || // Kolashanpan
                i == 4 || // Choripán
                i == 5 || // Chilillo
                i == 6
            )) {
                cout << i+1 << ". " << mochila[i].nombre << " (" << mochila[i].cantidad << "): " << mochila[i].desc << endl;
            }
        }
        cout << "0. Cancelar\n";
        int item;
        while (true)
        {
            cout << "Elige objeto: ";
            if (cin >> item)
            {
                if (item >= 0 && item <= MAX_OBJETOS)
                    break;
                cout << "Opción fuera de rango.\n";
            }
            else
            {
                cout << "Entrada invalida, ingresa un numero.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

        if (item == 0) break;

        // Salva Cola
        if (item == 2 && mochila[1].cantidad > 0) {
            if (pokedex[pokeActual].vida == pokedex[pokeActual].vidaMax) {
                cout << "Ese cuscamón ya tiene toda su vida.\n"; Sleep(900);
                continue;
            }
            pokedex[pokeActual].vida += 30;
            if (pokedex[pokeActual].vida > pokedex[pokeActual].vidaMax)
                pokedex[pokeActual].vida = pokedex[pokeActual].vidaMax;
            mochila[1].cantidad--;
            cout << "¡Salva Cola usada! +30HP\n"; Sleep(900); break;
        }
        // Kolashanpan (Aumenta ataque del jugador +10 solo durante batalla)
        else if (item == 4 && mochila[3].cantidad > 0) {
            boostAtaqueJugador += 10;
            mochila[3].cantidad--;
            cout << "¡Kolashanpan bebida! Ataque aumentado (+10)\n"; Sleep(900); break;
        }
        // Choripán (Aumenta defensa del jugador +10 solo durante batalla)
        else if (item == 5 && mochila[4].cantidad > 0) {
            boostDefensaJugador += 10;
            mochila[4].cantidad--;
            cout << "¡Choripan comido! Defensa aumentada (+10)\n"; Sleep(900); break;
        }
        // Chilillo (Baja defensa del enemigo -10 solo durante batalla)
        else if (item == 6 && mochila[5].cantidad > 0) {
            debuffDefensaEnemigo += 10; // Es un debuff, pero suma en negativo
            mochila[5].cantidad--;
            cout << "¡Chilillo lanzado! Defensa del enemigo disminuida (-10)\n"; Sleep(900); break;
        }
        // Sopa Gallina India (cura todo el HP del cuscamón actual)
        else if (item == 7 && mochila[6].cantidad > 0) {
            if (pokedex[pokeActual].vida == pokedex[pokeActual].vidaMax) {
                cout << "Tu cuscamon ya tiene toda la vida.\n";
                Sleep(900);
                continue;
            }
            pokedex[pokeActual].vida = pokedex[pokeActual].vidaMax;
            mochila[6].cantidad--;
            cout << "¡Sopa de Gallina India! HP completamente restaurado\n";
            Sleep(900);
            break;
        }
        else {
            cout << "No puedes usar ese objeto o ya no tienes.\n"; Sleep(900);
        }
    }
}
