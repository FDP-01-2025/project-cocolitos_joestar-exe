#include "maps.h"
#include "cuscamon.h"
#include "battle.h"
#include "object.h"
#include "utilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "defs.h"

using namespace std;

// ================== MAPA LABORATORIO ==================
void mapaLaboratorio() {
    const int filas = 10;
    const int columnas = 20;
    char lab[filas][columnas] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', '#'},
        {'#', ' ', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '=', '=', ' ', ' ', 'A', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int px = 1, py = filas - 2; // Posición inicial
    char input;
    extern bool starterYaEscogido;
    extern int equipo[], numEquipo;
    bool habloConMondongo = false;

    while (true) {
        system("cls");
        cout << "LABORATORIO DEL PROFESOR MONDONGO\n";
        cout << "Controles: WASD (moverse), Q (salir)\n";
        if (starterYaEscogido && numEquipo > 0)
            cout << "Cuscamon: " << pokedex[equipo[0]].nombre << "\n";

        // Dibujar mapa y colores
        for (int y = 0; y < filas; y++) {
            for (int x = 0; x < columnas; x++) {
                if (y == py && x == px) { setColor(10); cout << '@'; setColor(7); }
                else if (lab[y][x] == 'A') { setColor(14); cout << 'A'; setColor(7); }
                else if (lab[y][x] == 'O') { setColor(11); cout << 'O'; setColor(7); }
                else if (lab[y][x] == 'D') { setColor(12); cout << 'D'; setColor(7); }
                else if (lab[y][x] == '=') { setColor(6); cout << '='; setColor(7); }
                else cout << lab[y][x];
            }
            cout << endl;
        }

        input = tolower(_getch());
        int nx = px, ny = py;
        if (input == 'w') ny--;
        else if (input == 's') ny++;
        else if (input == 'a') nx--;
        else if (input == 'd') nx++;
        else if (input == 'q') return;

        // Movimiento válido
        if (lab[ny][nx] == ' ' || lab[ny][nx] == 'A' || lab[ny][nx] == 'O' || lab[ny][nx] == 'D' || lab[ny][nx] == '=') {
            px = nx; py = ny;
        }

        // Hablar con Mondongo
        if (lab[py][px] == 'A') {
            setColor(13);
            cout << "\nPROF. MONDONGO: ¡Bienvenido! Elige tu Cuscamon para iniciar tu aventura.\n";
            setColor(7); Sleep(1200);
            habloConMondongo = true;
        }
        // Elegir pokémon
        if (lab[py][px] == 'O' && !starterYaEscogido && habloConMondongo) {
            int pid;
            cout << "\nElige tu Cuscamon (1) Torogoz, (2) Cangrejo, (3) Garrobo: ";
            cin >> pid;
            pid--;
            if (pid >= 0 && pid < 3) {
                cout << "\n¡Has elegido a " << pokedex[pid].nombre << "!\n";
                equipo[numEquipo++] = pid;
                pokedex[pid].atrapado = true;
                starterYaEscogido = true;
                Sleep(1200);
            } else {
                cout << "Opcion no valida.\n"; Sleep(800);
            }
        } else if (lab[py][px] == 'O' && starterYaEscogido) {
            cout << "\nYa elegiste tu Cuscamon.\n"; Sleep(1000);
        } else if (lab[py][px] == 'O' && !habloConMondongo) {
            cout << "\nHabla primero con el Profesor Mondongo (A).\n"; Sleep(1000);
        }

        // Puerta de salida solo si ya elegiste starter
        if (lab[py][px] == 'D') {
            if (starterYaEscogido) {
                cout << "\n¡Felicidades! Has completado el laboratorio. Tu aventura comienza ahora...\n";
                system("pause");
                return;
            } else {
                cout << "\nPROFESOR MONDONGO: ¡Espera! Primero elige tu Cuscamon.\n";
                Sleep(1000);
            }
        }
    }
}

// ================== MAPA CIUDAD ==================
void mapaCiudad() {
    const int H = 12, W = 25;
    char mapa[H][W+1] = {
        "#########################",
        "#@  N         L     N   #",
        "#   #    T        #     #",
        "#   #    #   #    N     #",
        "#   #   A    #    #     #",
        "#       #  #    N   #   #",
        "#   T      #      #   N #",
        "#   #    #   #   ##     #",
        "#   C         N   #     #",
        "#         N        #    #",
        "#      N     #          #",
        "#########################"
    };
    int px = (enCiudad ? ciudad_px : 1);
    int py = (enCiudad ? ciudad_py : 1);
    enCiudad = false;
    bool entroLab = false, salio = false;

    extern string nombrePupusa, tipoPupusa;
    extern bool salirAlMenu;
    extern bool vencioTlaloc;
    extern bool starterYaEscogido;

    while (!entroLab && !salio && !salirAlMenu) {
        system("cls");
        cout << "Pupusa: " << nombrePupusa << " | Tipo: " << tipoPupusa << " | [I]Mochila  [P]Pokedex  [G]Guardar  [E]Exit\n";
        cout << "Usa WASD para moverte. Entra al laboratorio (L) o sal (C).\n";
        for (int y=0; y<H; y++) {
            for (int x=0; x<W; x++) {
                if (x==px && y==py) setColor(14), cout << "@", setColor(7);
                else cout << mapa[y][x];
            }
            cout << endl;
        }
        // Mensajes al interactuar
        if (mapa[py][px]=='N') {
            int r = rand()%5;
            if (r==0) mensajeNPC("Ten cuidado entrenador, dicen que por el volcán aparece el Cipitillo y la Ciguanaba.");
            else if (r==1) mensajeNPC("Hola cipote cara de ayote.");
            else if (r==2) mensajeNPC("Mi hermano dice que Sanchez Ceren se aparece en el volcán... que miedoo.");
            else if (r==3) mensajeNPC("¿Ya comiste sopa de pata?");
            else mensajeNPC("Dicen que hay un dragón en el volcán. ¿Será cierto?");
        }
        if (mapa[py][px]=='T') mensajeNPC("A este tronco le llaman Darwin Cerén porque no se mueve.");

        char t = tolower(_getch());
        int nx=px, ny=py;
        if (t=='w') ny--;
        else if (t=='s') ny++;
        else if (t=='a') nx--;
        else if (t=='d') nx++;
        else if (t=='i') { mochilaMenu(); continue; }
        else if (t=='p') { pokedexMenu(); continue; }
        else if (t=='g') {
            enCiudad = true;
            ciudad_px = px;
            ciudad_py = py;
            guardarPartida();
            continue;
        }
        else if (t=='e') {
            setColor(12);
            cout << "\n¿Seguro que quieres volver al menú principal? (Y/N): ";
            setColor(7);
            char resp;
            while (true) {
                resp = _getch();
                resp = tolower(resp);
                if (resp == 'y') {
                    salirAlMenu = true;
                    system("cls"); 
                    break;
                } else if (resp == 'n') {
                    cout << "\n¡Continuando aventura!\n";
                    Sleep(700);
                    break;
                }
            }
            if (salirAlMenu) break;
            continue;
        }

        if (t == 'q') { salirAlMenu = true; break; } // También puede funcionar como emergencia

        // Limites y colisiones
        if (mapa[ny][nx]!='#') { px=nx; py=ny; }
        // Laboratorio
        if (mapa[py][px]=='L') { entroLab=true; animacionCarga(); mapaLaboratorio(); break; }
        // Salida a volcán
        if (mapa[py][px]=='C') {
            if (numEquipo==0) {
                mensajeNPC("¡Ve primero al laboratorio y elige tu Cuscamón!");
                Sleep(1100);
                continue;
            } else if (!vencioTlaloc) {
                salio=true; animacionCarga(); mapaVolcan(); break;
            } else {
                mensajeNPC("Ya venciste al jefe del volcán. ¡Ve a explorar más!");
                Sleep(1100);
                continue;
            }
        }
    }
    if (salirAlMenu) return;
}

// ================== MAPA VOLCÁN NUEVO ==================
void mapaVolcan() {
    // === MAPA DE TU COMPAÑERA ===
    const int altura = 15;
    const int ancho = 2 * altura + 1;
    char mapa[altura][ancho];

    // Inicializar el mapa visual bonito
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < ancho; j++) {
            if (j == altura - i || j == altura + i)
                mapa[i][j] = '#';
            else if (j > altura - i && j < altura + i) {
                if (i % 3 == 0 && j % 2 == 0)
                    mapa[i][j] = '~';
                else
                    mapa[i][j] = '.';
            }
            else
                mapa[i][j] = ' ';
        }
    }
    // Cima del volcán con humo y cráter
    mapa[0][altura] = 'X'; // Cráter
    mapa[1][altura - 1] = '^';
    mapa[1][altura] = '^';
    mapa[1][altura + 1] = '^'; // Humo

    // Obstáculos
    for (int i = 3; i < 6; i++) {
        mapa[i][altura + 2] = 'O';
        mapa[i][altura - 2] = 'O';
    }

    // === LÓGICA DEL JUGADOR ===
    int px = (enVolcan ? volcan_px : altura); // Usa la posición guardada si aplica
    int py = (enVolcan ? volcan_py : altura - 1);
    enVolcan = false; // Resetea el flag al entrar
    extern bool salirAlMenu;
    bool encontroPok = false; // Solo un encuentro aleatorio por subida
    bool subiendo = true;

    while (subiendo && !salirAlMenu) {
        system("cls");
        // == MENÚ SUPERIOR ==
        cout << "== Volcán Izalco ==   [I] Mochila   [P] Pokedex   [G] Guardar   [E] Exit\n";
        cout << "Controles: W (arriba), S (abajo), A (izquierda), D (derecha)\n";
        cout << "------------------------------------------\n";
        cout << "Pasos desde la base: " << (altura - py) << " / " << altura << "\n";
        cout << "------------------------------------------\n";

        // Mostrar mapa y jugador
        mapa[py][px] = '@';
        for (int i = 0; i < altura; i++) {
            cout << (altura - i) << "\t";
            for (int j = 0; j < ancho; j++) {
                if (mapa[i][j] == '@') { setColor(12); cout << '@'; setColor(7); }
                else if (mapa[i][j] == 'X' || mapa[i][j] == '^') { setColor(6); cout << mapa[i][j]; setColor(7); }
                else if (mapa[i][j] == 'O') { setColor(8); cout << mapa[i][j]; setColor(7); }
                else if (mapa[i][j] == '#') { setColor(4); cout << mapa[i][j]; setColor(7); }
                else cout << mapa[i][j];
            }
            cout << endl;
        }
        mapa[py][px] = '.'; // Restaurar el piso

        // Mensajes contextuales
        if (altura - py < 3)
            cout << "\n¡Casi llegas! Se siente el calor del volcán...\n";
        else if (altura - py < altura / 2)
            cout << "\nVas a buena altura. ¡Sigue ascendiendo!\n";
        else
            cout << "\nEstás en la base del volcán. El camino es largo...\n";

        // == ENCUENTRO ALEATORIO DE CUSCAMON ==
        // Solo ocurre UNA VEZ en toda la subida (puedes cambiar condición para más)
        if (!encontroPok && py <= altura / 2 && px > altura - 4 && px < altura + 4 && rand() % 4 == 0) {
            int cual = (rand() % 2 == 0) ? 3 : 4; // 3: Cadejo/Cangrejo, 4: Tacuazín
            string msg = (cual == 4) ? "Uhhhh algo te está acechando uhhhh..." : "¡Un cuscamón salvaje ha aparecido!";
            setColor(13); cout << "\n" << msg << "\n"; setColor(7); Sleep(1000);
            batalla(cual, true, false); // ¡Usa tus funciones originales!
            encontroPok = true;
        }

        // == CONTROLES ==
        char t = tolower(_getch());
        int nx = px, ny = py;
        if (t == 'w' && py > 0 && mapa[py - 1][px] != ' ') ny--;
        else if (t == 's' && py < altura - 1 && mapa[py + 1][px] != ' ') ny++;
        else if (t == 'a' && px > 0 && mapa[py][px - 1] != ' ') nx--;
        else if (t == 'd' && px < ancho - 1 && mapa[py][px + 1] != ' ') nx++;
        else if (t == 'i') { mochilaMenu(); continue; }
        else if (t == 'p') { pokedexMenu(); continue; }
        else if (t == 'g') {
            enVolcan = true;
            volcan_px = px;
            volcan_py = py;
            guardarPartida();
            continue;
        }
        else if (t == 'e') {
            setColor(12);
            cout << "\n¿Seguro que quieres volver al menú principal? (Y/N): ";
            setColor(7);
            char resp;
            while (true) {
                resp = _getch();
                resp = tolower(resp);
                if (resp == 'y') {
                    salirAlMenu = true;
                    system("cls");
                    break;
                } else if (resp == 'n') {
                    cout << "\n¡Continuando aventura!\n";
                    Sleep(700);
                    break;
                }
            }
            if (salirAlMenu) break;
            continue;
        }
        else if (t == 'q') {
            system("cls");
            return;
        }

        // Limites (se puede mover mientras sea piso)
        if (mapa[ny][nx] != ' ') { px = nx; py = ny; }

        // Llega a la cima (boss)
        if (py == 0 && px == altura) {
            setColor(12);
            cout << "\nEl Cipitillo te espera en la cima...\n";
            setColor(7); Sleep(1200);
            setColor(14);
            cout << "¡Cipitillo ha sacado a Dragon Tlaloc!\n";
            setColor(7); Sleep(1000);
            batalla(6, false, false); // Boss
            if (!pokedex[5].atrapado) {
                animacionCarga();
                encuentroQuetzal();
                return; // Vuelve a ciudad después del Quetzal
            }
            subiendo = false;
        }
    }

    if (salirAlMenu) return;

    // Después del volcán, vuelve a la ciudad
    if (!salirAlMenu) {
        animacionCarga();
        mapaCiudad();
    }
}
// ================== ENCUENTRO QUETZAL ==================
int encuentroQuetzal() {
    setColor(14);
    cout << "\n¡NO PUEDE SER, ESTE CUSCAMON ES DE OTRA REGION!\n";
    setColor(7); Sleep(3000);
    batalla(5, true, true); // Quetzal legendario

    setColor(10);
    cout << "\n¡Felicidades! Terminaste la beta de Izalco Adventures.\n";
    cout << "¡Gracias por jugar!\n";
    setColor(7);
    cout << "\n(Presiona ENTER para regresar al mapa principal)";
    cin.ignore();
    cin.get();
    animacionCarga();
    mapaCiudad(); // Te devuelve a la ciudad

    // Devuelve 1 si atrapaste o venciste a Quetzal, 0 si no.
    if (pokedex[5].atrapado) return 1;
    return 0;
}
