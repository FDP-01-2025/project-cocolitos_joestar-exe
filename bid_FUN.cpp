#include "fun.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Variables globales   

extern std::string tipoPupusa;
extern std::string nombrePupusa;
extern int vidaJugador;
extern int vidaEnemigo;
extern int defensa;
extern int ataqueExtra;
extern bool salvaCola;
extern bool choripanes;
extern bool kolashanpan;


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

    mostrarTorogozASCII();
    Sleep(1500);
    mostrarDragonASCII();
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















void mostrarTorogozASCII() {
    cout << R"(
                                                                                                     
                                                                                        
                                            ---------=                                       
                                         ---====------=+#                                    
                                       ---=======++*%*%%%#                                   
                                     ---==========*%@%%###%%%#######*                       
                                    ---==========*%*++===-#@@@@@@@@@@%%#                     
                                    ---=================----                                  
                                   -----===============--=-                                   
                                   -----===============---                                    
                                  -------==========+====--                                   
                                  -=---=====-==============-                                  
                                 -==----=--=================--                                
                                --==------==================--                                
                               --===-----=====+=====++++==+=-:-                               
                              --====----=====+=====++=++==+=---                               
                       
     Torogoz del Bosque
    )" << endl;
}










void mostrarDragonASCII() {
    cout << R"(
                                                                                                                          
                                  
                              @                  @.
                        *@@@@@@                  %@@@@@@+
                    @@@@@@@@@@@           * -     @@@@@@@@@@@-
                 #@@@@@@@@@@@@@           @::     @@@@@@@@@@@@@@.
               @@@@@@@@@@@@@@@@       =@@@@@@     @@@@@@@@@@@@@@@@
             .@@@@@@@@@@@@@@@@@@     @@@= @@@-    @@@@@@@@@@@@@@@@@%
            %@@@@@@@@@@@@@@@@@@@+   @@@@    *@:  @@@@@@@@@@@@@@@@@@@@
           @@@@@@@@@@@@@@@@@@@@@@@  @@@@@-      @@@@@@@@@@@@@@@@@@@@@@=
         -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ +@@@@@@@@@@@@@@@@@@@@@@@@@@
        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-=%
       :     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-
              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
              @@@@@@@*   =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:   #@@@@@@@
              @@@@@@@%     @@@= =@@@@@@@@@@@@@@@+.:@@@+     -@@@@@@@
              @@   @@@      *     @ -@@@@@@@@%@     ::      @@@@  :@
              @    .@@                #@@@@-                @@-
                    -@@                +@@@@               @@
                      @@                +@@@@             @@
                       .%                =@@@*          =*
                               @@%=#@#    =@@@
                             :@-     .@    @@@=
                             @@  -@   @    @@@=
                             @@    @@@.    @@@
                             -@@          %@@+
                              *@@:      .@@@-
                                @@@@@@@@@@#
                                   .==:                                                                      
                                                                                                                   
             Dragon Tlaloc
    )" << endl;
}




