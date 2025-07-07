
#include "utilities.h"
#include <iostream>
#include <string>
#include <windows.h>
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
