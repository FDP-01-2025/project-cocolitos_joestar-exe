#include <iostream>
#include <cstdlib>
#include <ctime>
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
            cout << R"(@@@@@@                    
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
            cout << R"(@@@  @@                        @@  @@@    
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
            cout << R"(%*=---:::.:. . .                  
              --====..::#=:...::               
            :=++==*#=::-:. ...-- +               
   .:::...:+=++*-:::...                    
=++==-=+##+++++++==-:::-::.:=                
++=-+=+###*=++++++++==++-:=                    
=+==++++++#+=+===++++++                        
=++++++++++++++++======+                         
++++=++=+                          
***********###+=##*=+                          
##########*#%%#    ***
)";
        }
    }
    cout << endl;
}

void mostrarMenuAtaques(const string& nombre) {
    cout << "\n Elige tu ataque:\n";
    cout << "1. Ataque rápido (10-20 daño)\n";
    cout << "2. Ataque poderoso (15-25 daño)\n";
}

Personaje seleccionarPokemon(int jugadorN) {
    int opcion;
    cout << "Jugador " << jugadorN << ", ¡Elige tu Pokémon!\n";
    cout << "1. garrobo\n";
    cout << "2. torogoz\n";
    cout << "3. cangrejo\n";
    cout << "Selecciona (1-3): ";
    cin >> opcion;
if (opcion == 1) return {"garrobo", 100, 100};
    if (opcion == 2) return {"torogoz", 110, 110};
    return {"cangrejo", 120, 120};
}

void usarMochila(Personaje& jugador, Mochila& mochila) {
    cout << "\n Mochila:\n";
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

