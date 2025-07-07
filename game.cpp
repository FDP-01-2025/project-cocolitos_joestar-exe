
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
