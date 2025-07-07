#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
using namespace std;

struct Personaje {
    string nombre;
    int vida;
    int maxVida;
};

struct Mochila {
    int pociones;
};

int generarDanio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void mostrarEstado(const Personaje& p1, const Personaje& p2) {
    cout << "\n======= ESTADO =======\n";
    cout << p1.nombre << " - Vida: " << p1.vida << endl;
    cout << p2.nombre << " - Vida: " << p2.vida << endl;
    cout << "======================\n";
}

void mostrarArte(const string& nombre, bool perspectiva) {
    cout << "\n------ PERSONAJE ------\n";
    if (nombre == "garrobo") {
        if (perspectiva) {
            cout << R"(#####     
                         ###### -   
                       ###+======== 
                     *###===-=======
                     ###============
                   ###==-=======+=
                 ####++==+=======++ 
            ####+==+++==-===-=-   
       ###==+++=++=======------   
    ##+++==+===+===========-----    
  ###===+===========-:--====+===-=  
 ####+===--=====------- ===  +=+=== 
#####    +====           +===+      
===      +=====           +=====    
+====       +               +       
  +##***               #*=++        
     ##+======+##
)";
        } else {
            cout << R"(%#*###@@@@@                              
  #++=+@*=+@@@@                             
   +=+++++=+%@@@                            
    %+=-=++++%@@@                           
      *=++++==+#@@@@                        
       +==++=====*%@@                       
       +=+=======++@@@       %#+##*%  
       #+==============*#@@@      @@%#++#@  
       #++=-===============+++%%+=+#%+%   
       #++%+=-=+=++===========+*%#++#%@     
       #++#++#==+#=========+==+%#         
       #+=*   %+=+% %%##++*%        
     %+%##*+=+               %@         
         @  @@%#@
)";
        }
    }
    else if (nombre == "torogoz") {
        if (perspectiva) {
            cout << R"(---------=                                       
                   ---====------=+#                                    
                 ---=======++%%%%#                                   
                 ---==========%@%%###%%%#######                       
               ---==========%++===-#@@@@@@@@@@%%#                     
                --=================----                                  
              -----===============--=-                                   
            -----===============---                                    
             -------==========+====--                                   
           -=---=====-==============-
)";
        } else {
            cout << R"(
            
            @@@@@@                    
      @@@@@%@@@##*%                  
            -+%%+%                  
           @@#++%                
           %+++++++#               
           @+++++++*@              
            #++++++++@             
            @%#+++++#++*             
              %#+++++*#            
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
)";
        }
    }
    else if (nombre == "cangrejo") {
        if (perspectiva) {
            cout << R"(
    @@@  @@                        @@  @@@    
   @@ @  @@@@                    @@ @  @ @@   
   @@ @@@@  @                    @  @@@@ @@   
   @@       @@                  @@       @@   
    @@      @    @@@@@@@@@@@@    @      @@    
      @@@    @@@              @@@    @@@      
           @@@     @@     @@    @@@           
           @@     @@@    @@@     @@           
     @@@   @@                     @   @@@     
    @  @@  @@       @@  @@       @@@ @@  @    
    @ @@@@ @@@@       @@         @@@@ @@ @ @    
       @@ @  @@@@            @@@@  @@ @       
       @ @@ @ @@   @@@@@@@@   @@ @  @ @       
       @ @  @ @@               @ @  @@@       
            @@@                @@@
)";
        } else {
            
        }
    }
    cout << endl;
}

void mostrarMenuAtaques(const string& nombre) {
    cout << "\nElige tu ataque:\n";
    cout << "1. Ataque rápido (10-20 daño)\n";
    cout << "2. Ataque poderoso (15-25 daño)\n";
    // Ataques especiales según Pokémon
    if (nombre == "garrobo")
        cout << "3. Llama Solar (18-35 daño)\n";
    else if (nombre == "torogoz")
        cout << "3. Pico Relampago(18-25 daño, pero se cura 10 HP)\n";
    else if (nombre == "cangrejo")
        cout << "3. Ola Rocosa (20-32 daño)\n";
}

Personaje seleccionarPokemon(int jugadorN) {
    int opcion;
    cout << "Jugador " << jugadorN << ", ¡Elige tu Pokémon!\n";
    cout << "1. garrobo\n";
    cout << "2. torogoz\n";
    cout << "3. cangrejo\n";
    cout << "Selecciona (1-3): ";
    cin >> opcion;
    // Todos con vida igualada (120)
    if (opcion == 1) return {"garrobo", 120, 120};
    if (opcion == 2) return {"torogoz", 120, 120};
    return {"cangrejo", 120, 120};
}

void usarMochila(Personaje& jugador, Mochila& mochila) {
    cout << "\nMochila:\n";
    cout << "1. Poción de vida (" << mochila.pociones << " disponibles)\n";
    cout << "2. Cancelar\n";
    cout << "¿Qué deseas usar? ";
    int eleccion;
    cin >> eleccion;

    if (eleccion == 1 && mochila.pociones > 0) {
        int curacion = 20;
        jugador.vida += curacion;
        if (jugador.vida > jugador.maxVida)
            jugador.vida = jugador.maxVida;
        mochila.pociones--;
        cout << " Usaste una poción y recuperaste " << curacion << " de vida.\n";
    }
    else {
        cout << " Acción cancelada o sin objetos disponibles.\n";
    }
}

void turnoJugador(Personaje& atacante, Personaje& defensor, Mochila& mochila, bool perspectiva) {
    cout << "\nTurno de " << atacante.nombre << ":\n";
    cout << "1. Atacar\n";
    cout << "2. Usar Mochila\n";
    cout << "Elige opción: ";
    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        mostrarMenuAtaques(atacante.nombre);
        int ataque;
        cin >> ataque;

        int danio = 0;
        if (ataque == 1) {
            danio = generarDanio(10, 20);
            cout << atacante.nombre << " usó Ataque rápido.\n";
        }
        else if (ataque == 2) {
            danio = generarDanio(15, 25);
            cout << atacante.nombre << " usó Ataque poderoso.\n";
        }
        else if (ataque == 3) {
            // Ataque especial personalizado
            if (atacante.nombre == "garrobo") {
                danio = generarDanio(18, 35);
                cout << atacante.nombre << " lanzó ¡Llama Solar! \n";
            }
            else if (atacante.nombre == "torogoz") {
                danio = generarDanio(18, 25);
                atacante.vida += 15;
                if (atacante.vida > atacante.maxVida)
                    atacante.vida = atacante.maxVida;
                cout << atacante.nombre << " invocó ¡Vendaval Tropical!  y se curó 15 HP.\n";
            }
            else if (atacante.nombre == "cangrejo") {
                danio = generarDanio(20, 32);
                cout << atacante.nombre << " usó ¡Ola Rocosa! \n";
            }
        }
        else {
            cout << "Opción de ataque no válida. Pierdes el turno.\n";
            return;
        }

        defensor.vida -= danio;
        cout << "Le hiciste " << danio << " de daño a " << defensor.nombre << ".\n";
        if (defensor.vida < 0) defensor.vida = 0;

        mostrarArte(atacante.nombre, perspectiva);
    }
    else if (opcion == 2) {
        usarMochila(atacante, mochila);
    }
}

void multiplayer() {
    srand(time(0));

    Personaje jugador1 = seleccionarPokemon(1);
    Personaje jugador2 = seleccionarPokemon(2);

    Mochila mochila1 = {3};
    Mochila mochila2 = {3};

    cout << "\nJugador 1:";
    mostrarArte(jugador1.nombre, true);
    cout << "\nJugador 2:";
    mostrarArte(jugador2.nombre, true);

    bool turnoJ1 = true;

    while (jugador1.vida > 0 && jugador2.vida > 0) {
        mostrarEstado(jugador1, jugador2);

        if (turnoJ1) {
            turnoJugador(jugador1, jugador2, mochila1, true);
        } else {
            turnoJugador(jugador2, jugador1, mochila2, false);
        }

        turnoJ1 = !turnoJ1;
    }

    cout << "\n==== FIN DE LA BATALLA ====\n";
    if (jugador1.vida <= 0)
        cout << jugador2.nombre << " ha ganado la batalla.\n";
    else
        cout << jugador1.nombre << " ha ganado la batalla.\n";

    cout << "\nPresiona ENTER para regresar al menú principal...";
    cin.ignore();
    cin.get();

}
