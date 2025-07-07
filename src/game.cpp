
#include "game.h"
#include "maps.h"
#include "cuscamon.h"
#include "object.h"
#include "battle.h"
#include "utilities.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include "defs.h"
using namespace std;


// Variables que solo se usan en esta parte (externas si se usan fuera)
extern string tipoPupusa, nombrePupusa;
extern bool salirAlMenu, vencioTlaloc, starterYaEscogido;

// ================== PANTALLA DE INICIO ==================
int menuPrincipal() {
    setColor(10);
    cout << R"(
    _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _     
 (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_) 
 (_)                                                                      (_)
 (_)  ___ _____   _    _      ____ ___                                    (_)
 (_) |_ _|__  /  / |   | |   / ___/ _  |                                  (_)
 (_)  | |  / /  / _ |  | |  | |  | | | |                                  (_)
 (_)  | | / /_ / ___ | |__| |__| |_| |                                    (_)
 (_) |___/____/_/___| || ___| ____|___/ _____ _   _ ____  _____ ____      (_)
 (_)    / /   |  _ / /   /  / ____| |  ||_   _| | | |  _ /| ____/ __|     (_)
 (_)   / _ /  | | | / / / / |  _| |  | |  | | | | | | | |_) |  _| | __    (_)
 (_)  / ___ / | |_| |/ V /  | |___| ||  | | | | |_| |  _ <| |___ ___)     (_)
 (_) /_/   /_/____/ |   /_/ |_____|_| | | |_|  |___/|_| | ______|____/    (_)
 (_) _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _     (_)
 (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_) 


            @@@@@@                    
      @@@@@%@@@##***%                  
            -+***%%+*%                 
           @@#*++*****%                
           %*++**+++++*#               
           @*+++***++++*@              
            #+++++***+++*@             
            @%#*+++++*#++*             
              %*#*+++++***#            
                @%#*+++===%            
                   @*====%@@           
                     @@@@@@@           
                      +=#              
                      *==              
                      *==%             
                      *==+             
                      *==+@            
                       @@%%@@@         
                            @@               

     Bienvenido a Izalco Adventures
    )" << endl;
    setColor(7);

    cout << "\n1. Nueva partida";
    cout << "\n2. Cargar partida";
    cout << "\n3. Salir\n";
    cout << "Selecciona una opción: ";

    int op = 0;
    while (op < 1 || op > 3) {
        cin >> op;
        if (op < 1 || op > 3) cout << "Opción no válida. Intenta de nuevo: ";
    }
    system("cls");
    return op;
}
void pantallaSeleccion() {
    system("cls");
    setColor(14);
    // ... (arte de pupusa y menú)
        cout << R"(
         ##*******##                         ##****#####
        #****+*****##                      #**+++++++++++**##  
    ##***################                 ##*++++++++++++++++*#
   ##***##########*********##            #++++++++++***++++++*#
  #********++++****++**####             #*+++*#+++**==+*++++++*#
    /##*++++=++===++++==+*#            ##++#+==+++====+++++**+++*#
   /#+++++++++=====+*++==*#           ##++*===+=============*++++*#
  /#+=+++==+++====++++=+++##          #++*====()*=====*()====+*+++*#
  *+++==++*()===+*#()+====+*         #++#==++++++*===+++++====*+++*#
  #*+++====+++===+++=++++++*#         #+#==++======++===++====*+++*#
  #*=++==+++++*****+=++++=+##        ##*+#====================+*+++# 
 ####++++========++=====+++*###       ###++*===================**#++##
 ## #*+++++=++=========+++*####        #+#**=================**++*+*#
 %####+=++==+++===++++=+*###           ##+**+=============+*+**###
  ####**+==+++++==+++*####             ####  #*++======+*   #####
        #####*****####                ##       #########       ##
         ###       ###                         ###   ##
        ###         ###                      ###       ###
    )" << endl;
    setColor(7);
    cout << "============== SELECCIONA TU PUPUSA ==============\n";
    cout << "1. Pupusa de Maíz\n";
    cout << "2. Pupusa de Arroz\n";
    int op = 0;
    while (op != 1 && op != 2) {
        cout << "\nElige (1 o 2): ";
        cin >> op;
        if (op == 1) tipoPupusa = "Pupusa de Maiz";
        else if (op == 2) tipoPupusa = "Pupusa de Arroz";
        else cout << "Opción no válida. Intenta de nuevo.\n";
    }

    do {
        cout << "\n¡Perfecto! Ahora nombra a tu pupusa (máx 12 caracteres, sin espacios): ";
        cin >> nombrePupusa;
        if (nombrePupusa.length() > 12)
            cout << "El nombre es muy largo, intenta de nuevo.\n";
    } while (nombrePupusa.empty() || nombrePupusa.length() > 12);

    animacionCarga();
}
/ ============ FLUJO PRINCIPAL DEL JUEGO ============
void iniciarJuego() {
    srand(time(0));
    bool salir = false;
    bool postGame = false;
    bool quetzalPendiente = false;

    while (!salir) {
        // Reinicia datos al empezar cada nueva partida
        inicializarDatos();
        salirAlMenu = false;
        vencioTlaloc = false;
        starterYaEscogido = false;
        postGame = false;
        quetzalPendiente = false;

        int op = menuPrincipal();

        if (op == 1) { // Nueva partida
            setColor(13);
            cout << R"(
        *            *++++++++                    
         *            *+#+=+*++                   
          ++          ++===++**                  
           +++         +=+++*#                   
          ++*++    +-=**++*##==+                
          **++==  ==-==**#*+++--=               
           +=----=-=--+***+------+              
             +-------=+***+--=---=              
              +=--==-+****+=-==---+             
                  +--=###*=---=---=             
                  =--=**+*=--=---=              
                  =--=++++=-==-==               
                  ---++*++=-----=               
                 +=--+++++=-----=               
                 ===-+++++=--====              
                 =---+++++=-----=              
                    ++++++++++                 
                    ++++*+++++                 
                    ++++*+++++   
    )" << "\n";
            cout << "Prof. Mondongo: ¡Bienvenido a El Salvador, este mundo maravilloso donde los Cuscamones y humanos conviven en un mismo vivir!\n";
            setColor(7);
            pausa();
            system("cls");
            pantallaSeleccion();
            animacionCarga();

            while (!postGame && !salirAlMenu) {
                mapaCiudad();
                if (salirAlMenu) break;
                if (vencioTlaloc && !postGame) {
                    quetzalPendiente = true;
                    break;
                }
            }

            if (salirAlMenu) continue;

            // Postgame: Quetzal, y luego menú
            if (quetzalPendiente) {
                int resultadoQuetzal = encuentroQuetzal();
                postGame = (resultadoQuetzal == 1);
            }

            while (postGame) {
                setColor(10);
                cout << "\n¡Felicidades! Terminaste la beta de Izalco Adventures.\n";
                cout << "¡Gracias por jugar!\n";
                setColor(7);

                int opcionPostGame = 0;
                do {
                    cout << "\n¿Qué deseas hacer ahora?\n";
                    cout << "1. Ver Pokedex\n";
                    cout << "2. Ver Mochila\n";
                    cout << "3. Volver al Menú Principal\n";
                    cout << "Elige opción: ";
                    cin >> opcionPostGame;
                    switch(opcionPostGame) {
                        case 1: pokedexMenu(); break;
                        case 2: mochilaMenu(); break;
                        case 3: cout << "Regresando al menú principal...\n"; Sleep(1000); postGame = false; break;
                        default: cout << "Opción no válida.\n";
                    }
                } while(opcionPostGame != 3);
                system("cls");
                continue;
            }
        }
        else if (op == 2)
        { // Cargar partida
            if (cargarPartida())
            {
                if (cargarPartida())
                {
                    if (enVolcan)
                    {
                        mapaVolcan();
                    }
                    else
                    {
                        mapaCiudad();
                    }
                }
                setColor(10); cout << "¡Partida cargada!\n"; setColor(7);
                pausa();
                // Si la partida cargada ya venció a Tlaloc pero no Quetzal, hacer batalla Quetzal primero.
                if (vencioTlaloc && !pokedex[5].atrapado) {
                    int resultadoQuetzal = encuentroQuetzal();
                    if (resultadoQuetzal == 1) {
                        // Postgame menu
                        bool postGame = true;
                        while (postGame) {
                            setColor(10);
                            cout << "\n¡Felicidades! Terminaste la beta de Izalco Adventures.\n";
                            cout << "¡Gracias por jugar!\n";
                            setColor(7);

                            int opcionPostGame = 0;
                            do {
                                cout << "\n¿Qué deseas hacer ahora?\n";
                                cout << "1. Ver Pokedex\n";
                                cout << "2. Ver Mochila\n";
                                cout << "3. Volver al Menú Principal\n";
                                cout << "Elige opción: ";
                                cin >> opcionPostGame;
                                switch(opcionPostGame) {
                                    case 1: pokedexMenu(); break;
                                    case 2: mochilaMenu(); break;
                                    case 3: cout << "Regresando al menú principal...\n"; Sleep(1000); postGame = false; break;
                                    default: cout << "Opción no válida.\n";
                                }
                            } while(opcionPostGame != 3);
                            system("cls");
                        }
                        continue;
                    }
                }
                while (!vencioTlaloc && !salirAlMenu) {
                    mapaCiudad();
                    if (salirAlMenu) break;
                }
                if (salirAlMenu) continue;

                // Si venció a Tlaloc y atrapó a Quetzal (o tras el evento), menú postgame
                if (vencioTlaloc && pokedex[5].atrapado) {
                    bool postGame = true;
                    while (postGame) {
                        setColor(10);
                        cout << "\n¡Felicidades! Terminaste la beta de Izalco Adventures.\n";
                        cout << "¡Gracias por jugar!\n";
                        setColor(7);

                        int opcionPostGame = 0;
                        do {
                            cout << "\n¿Qué deseas hacer ahora?\n";
                            cout << "1. Ver Pokedex\n";
                            cout << "2. Ver Mochila\n";
                            cout << "3. Volver al Menú Principal\n";
                            cout << "Elige opción: ";
                            cin >> opcionPostGame;
                            switch(opcionPostGame) {
                                case 1: pokedexMenu(); break;
                                case 2: mochilaMenu(); break;
                                case 3: cout << "Regresando al menú principal...\n"; Sleep(1000); postGame = false; break;
                                default: cout << "Opción no válida.\n";
                            }
                        } while(opcionPostGame != 3);
                        system("cls");
                    }
                }
            }
            else
            {
                cout << "No hay partida guardada. Inicia una nueva.\n";
                pausa();
                continue;
            }
        }
        else if (op == 3) { // Salir
            cout << "¡Hasta pronto!\n";
            salir = true;
        }
    }
}
