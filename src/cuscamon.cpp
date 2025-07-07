#include "cuscamon.h"
#include "utilities.h"
#include <iostream>
#include "defs.h"
using namespace std;

// ====== Definición de variables globales ======
Cuscamon pokedex[MAX_CUSCAMON];
int pokesVistos[MAX_CUSCAMON] = {0};
int equipo[MAX_EQUIPO];
int numEquipo = 0;

// ====== INICIALIZAR DATOS ======
void inicializarDatos() {
    // 0 - Torogoz
    pokedex[0].nombre = "Torogoz";
    pokedex[0].tipo = "Volador";
    pokedex[0].desc = "Ave nacional agil y valiente sus colores son magicos y brillan en la oscuridad hay que cuidarlos";
    pokedex[0].vidaMax = 100;
    pokedex[0].idPokedex = 0;
    pokedex[0].ataques[0].nombre = "Pico Relampago";
    pokedex[0].ataques[0].desc = "Un picotazo veloz como el rayo.";
    pokedex[0].ataques[0].poder = 20;
    pokedex[0].ataques[0].tipo = "Volador";

    pokedex[0].ataques[1].nombre = "Ala Veloz";
    pokedex[0].ataques[1].desc = "Golpea con alas de luz.";
    pokedex[0].ataques[1].poder = 18;
    pokedex[0].ataques[1].tipo = "Volador";

    pokedex[0].ataques[2].nombre = "Canto Celestial";
    pokedex[0].ataques[2].desc = "Emite un canto que asusta.";
    pokedex[0].ataques[2].poder = 0;
    pokedex[0].ataques[2].tipo = "Normal";

    pokedex[0].ataques[3].nombre = "Vendaval Tropical";
    pokedex[0].ataques[3].desc = "Genera un viento fuerte.";
    pokedex[0].ataques[3].poder = 25;
    pokedex[0].ataques[3].tipo = "Volador";
    pokedex[0].ascii = R"(
        ---------=                                       
      ---====------=+#                                  
   ---=======++*%*%%%#                                  
 ---==========*%@%%###%%%#######*                       
 ---==========*%*++===-#@@@@@@@@@@%%#                   
--=================----                                 
-----===============--=-                                
-----===============---                                 
-------==========+====--                                
-=---=====-==============-     
)";
    pokedex[0].atrapado = false;

    // 1 - Cangrejo
    pokedex[1].nombre = "Cangrejo";
    pokedex[1].tipo = "Agua";
    pokedex[1].desc = "Pinzas de acero veloz en la playa le gustan las minutas del puerto de la Libertad";
    pokedex[1].vidaMax = 105;
    pokedex[1].idPokedex = 1;
    pokedex[1].ataques[0].nombre = "Pinza Martillo";
    pokedex[1].ataques[0].desc = "Golpea con fuerza brutal.";
    pokedex[1].ataques[0].poder = 22;
    pokedex[1].ataques[0].tipo = "Agua";

    pokedex[1].ataques[1].nombre = "Burbuja Veloz";
    pokedex[1].ataques[1].desc = "Lanza burbujas rápidas.";
    pokedex[1].ataques[1].poder = 18;
    pokedex[1].ataques[1].tipo = "Agua";

    pokedex[1].ataques[2].nombre = "Mordisco Salino";
    pokedex[1].ataques[2].desc = "Mordida con sabor a mar.";
    pokedex[1].ataques[2].poder = 17;
    pokedex[1].ataques[2].tipo = "Agua";

    pokedex[1].ataques[3].nombre = "Ola Rocosa";
    pokedex[1].ataques[3].desc = "Provoca una ola de rocas.";
    pokedex[1].ataques[3].poder = 24;
    pokedex[1].ataques[3].tipo = "Agua";
    pokedex[1].ascii = R"(
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
 @ @@@@ @@@@       @@         @@@@ @@ @   
    @@ @  @@@@@@@@@@@@@@@@@@@@@@ @   
)";
    pokedex[1].atrapado = false;

    // 2 - Garrobo
    pokedex[2].nombre = "Garrobo";
    pokedex[2].tipo = "Fuego";
    pokedex[2].desc = "Lagarto ardiente de los volcanes se la pasa molestando en las duralitas de las casas";
    pokedex[2].vidaMax = 110;
    pokedex[2].idPokedex = 2;
    pokedex[2].ataques[0].nombre = "Cola Ardiente";
    pokedex[2].ataques[0].desc = "Golpea con la cola en llamas.";
    pokedex[2].ataques[0].poder = 20;
    pokedex[2].ataques[0].tipo = "Fuego";

    pokedex[2].ataques[1].nombre = "Mordida Sonica";
    pokedex[2].ataques[1].desc = "Muerde y grita a la vez.";
    pokedex[2].ataques[1].poder = 17;
    pokedex[2].ataques[1].tipo = "Fuego";

    pokedex[2].ataques[2].nombre = "Llama Solar";
    pokedex[2].ataques[2].desc = "Rafaga de fuego solar.";
    pokedex[2].ataques[2].poder = 26;
    pokedex[2].ataques[2].tipo = "Fuego";

    pokedex[2].ataques[3].nombre = "Rugido Infernal";
    pokedex[2].ataques[3].desc = "Rugido que baja defensa.";
    pokedex[2].ataques[3].poder = 0;
    pokedex[2].ataques[3].tipo = "Fuego";
    pokedex[2].ascii = R"(                         
                     ###### -   
                   ###+======== 
                 *###===-=========
                 ###================
               #*##==-=======*+=
             ####++==+=======++ 
        ####**+==+++==-===-=-   
   #*#*#==+++=++=======------   
##+++==+===+===========-----    
###===+===========-:--====+===-=  
####+===--=====------- ===  +=+=== 
)";
    pokedex[2].atrapado = false;

    // 3 - Tacuazín
    pokedex[3].nombre = "Tacuazin";
    pokedex[3].tipo = "Normal";
    pokedex[3].desc = "Es travieso y mañoso le llega el karma cada que cruza las calles de la capital";
    pokedex[3].vidaMax = 90;
    pokedex[3].idPokedex = 3;
    pokedex[3].ataques[0].nombre = "Mordida Traviesa";
    pokedex[3].ataques[0].desc = "Muerde jugando.";
    pokedex[3].ataques[0].poder = 14;
    pokedex[3].ataques[0].tipo = "Normal";

    pokedex[3].ataques[1].nombre = "Rasguno Fugitivo";
    pokedex[3].ataques[1].desc = "Rasguna y corre.";
    pokedex[3].ataques[1].poder = 13;
    pokedex[3].ataques[1].tipo = "Normal";

    pokedex[3].ataques[2].nombre = "Cola Saltarina";
    pokedex[3].ataques[2].desc = "Golpea con la cola.";
    pokedex[3].ataques[2].poder = 12;
    pokedex[3].ataques[2].tipo = "Normal";

    pokedex[3].ataques[3].nombre = "Manosada";
    pokedex[3].ataques[3].desc = "Hace trampa y no se deja atrapar facil.";
    pokedex[3].ataques[3].poder = 0;
    pokedex[3].ataques[3].tipo = "Normal";
    pokedex[3].ascii = R"(
                  %*=---:::.:. . .                  
              --===*=..::#*=:...::               
            :=++==*#=::-:. ...-- +               
   .:::...:+=****++*-:::...                    
=+*+==-=+##*+++++**++==-:::-::.:=                
++=-+=+*###**=++++++++==++-:=                    
=+==*++++++*#+=+===++++++                        
=++++++++++++++++======+                         
+*********++****+=+*+=+                          
************#*##+=##*=+                          
###**#######*#%%#    ***        
)";
    pokedex[3].atrapado = false;

    // 4 - Cadejo
    pokedex[4].nombre = "Cadejo";
    pokedex[4].tipo = "Fantasma/Siniestro";
    pokedex[4].desc = "Espiritu que acecha a los viajeros lo consideran una leyenda y es amigo fiel de los brujos de izalco";
    pokedex[4].vidaMax = 120;
    pokedex[4].idPokedex = 4;
    pokedex[4].ataques[0].nombre = "Sombra Fétida";
    pokedex[4].ataques[0].desc = "Lanza sombras que asustan.";
    pokedex[4].ataques[0].poder = 21;
    pokedex[4].ataques[0].tipo = "Fantasma";

    pokedex[4].ataques[1].nombre = "Aullido Oscuro";
    pokedex[4].ataques[1].desc = "Aúlla y baja ataque rival.";
    pokedex[4].ataques[1].poder = 0;
    pokedex[4].ataques[1].tipo = "Siniestro";

    pokedex[4].ataques[2].nombre = "Lengua Fantasma";
    pokedex[4].ataques[2].desc = "Ataca con lengua invisible.";
    pokedex[4].ataques[2].poder = 23;
    pokedex[4].ataques[2].tipo = "Fantasma";

    pokedex[4].ataques[3].nombre = "Paso Espectral";
    pokedex[4].ataques[3].desc = "Cruza el campo causando miedo.";
    pokedex[4].ataques[3].poder = 18;
    pokedex[4].ataques[3].tipo = "Fantasma";
    pokedex[4].ascii = R"(
   /^ ^\
  / > < \
  V\ Y /V
    / - \
   |  v  |
  (|  _  |)
   ||(__)||
  /_|    |_\
)";
    pokedex[4].atrapado = false;

    // 5 - Quetzal
    pokedex[5].nombre = "Quetzal";
    pokedex[5].tipo = "Volador/Legendario";
    pokedex[5].desc = "El ave sagrada simbolo de libertad viene de la region de guatemala muy pocas veces visto";
    pokedex[5].vidaMax = 150;
    pokedex[5].idPokedex = 5;
    pokedex[5].ataques[0].nombre = "Pluma Sagrada";
    pokedex[5].ataques[0].desc = "Golpea con plumas divinas.";
    pokedex[5].ataques[0].poder = 30;
    pokedex[5].ataques[0].tipo = "Volador";

    pokedex[5].ataques[1].nombre = "Viento Esmeralda";
    pokedex[5].ataques[1].desc = "Tormenta de viento verde.";
    pokedex[5].ataques[1].poder = 28;
    pokedex[5].ataques[1].tipo = "Volador";

    pokedex[5].ataques[2].nombre = "Canto Ancestral";
    pokedex[5].ataques[2].desc = "Canto que estremece el alma.";
    pokedex[5].ataques[2].poder = 0;
    pokedex[5].ataques[2].tipo = "Legendario";

    pokedex[5].ataques[3].nombre = "Alas de Luz";
    pokedex[5].ataques[3].desc = "Cega con destello brillante.";
    pokedex[5].ataques[3].poder = 25;
    pokedex[5].ataques[3].tipo = "Volador";
    pokedex[5].ascii = R"(
    __
  /( @>
 /  )\
/  /  \
)";
    pokedex[5].atrapado = false;

    // 6 - Tlaloc
    pokedex[6].nombre = "Tlaloc";
    pokedex[6].tipo = "Dragon/Agua";
    pokedex[6].desc = "El guardian ancestral del volcan Izalco el unico que pudo atraparlo fue el cipitillo y lo apodo Tlaloc por su abuelo";
    pokedex[6].vidaMax = 180;
    pokedex[6].idPokedex = 6;
    pokedex[6].ataques[0].nombre = "Aliento Volcanico";
    pokedex[6].ataques[0].desc = "Sopla fuego y vapor hirviente.";
    pokedex[6].ataques[0].poder = 32;
    pokedex[6].ataques[0].tipo = "Fuego";

    pokedex[6].ataques[1].nombre = "Lluvia Mistica";
    pokedex[6].ataques[1].desc = "Cura y ataca con agua sagrada.";
    pokedex[6].ataques[1].poder = 20;
    pokedex[6].ataques[1].tipo = "Agua";

    pokedex[6].ataques[2].nombre = "Cola Sismica";
    pokedex[6].ataques[2].desc = "Un coletazo que sacude la tierra.";
    pokedex[6].ataques[2].poder = 28;
    pokedex[6].ataques[2].tipo = "Tierra";

    pokedex[6].ataques[3].nombre = "Mirada Ancestral";
    pokedex[6].ataques[3].desc = "Reduce el ataque del rival.";
    pokedex[6].ataques[3].poder = 0;
    pokedex[6].ataques[3].tipo = "Dragon";
    pokedex[6].ascii = R"(                                                                    
                                                                          --^^^#####//      \\#####^^^--_
                                                                       -^##########// (    ) \\##########^-_
                                                                     -############//  |\^^/|  \\############-
                                                                    /############//   (@::@)   \\############\_
                                                                  /#############((     \\//     ))#############\
                                                                 -###############\\    (oo)    //###############-
                                                                -#################\\  / "" \  //#################-
                                                               -###################\\/  (_) \/###################-
                                                               #/|##########/\######(   "/"   )######/\##########|\#_
                                                              |/ |#/\#/\#/\/  \#/\##\  ! ' !  /##/\#/  \/\#/\#/\#| \|
                                                                 |/  V  V '   V  \\#\  ! ' !  /#/  V   '  V  V  \|  '
                                                                 '   '  '      '   /#| ! ' ! |#\   '      '  '   '
                                                                                  (##/ ! ' ! \##)
                                                                                  |||   ! '   |||
                                                                                  |||   ! '   |||
                                                                                  |||   ! '   |||
                                                                                  |||   ! '   |||               
)";
    pokedex[6].atrapado = false;

    // Restablecer la vida de todos los Cuscamones al iniciar
for (int i = 0; i < MAX_CUSCAMON; i++) {
    pokedex[i].vida = pokedex[i].vidaMax;
}

    // Inicializar equipo a slots vacíos
    for (int i = 0; i < MAX_EQUIPO; i++)
        equipo[i] = -1;
    numEquipo = 0;
}
// ====== ELECCIÓN DE CUSCAMON ======
int elegirCuscamonEquipo(bool soloSanos) {
    cout << "Selecciona un Cuscamón del equipo:\n";
    for (int i = 0; i < numEquipo; i++) {
        int id = equipo[i];
        cout << i+1 << ". " << pokedex[id].nombre;
        cout << " (HP: " << pokedex[id].vida << "/" << pokedex[id].vidaMax << ")\n";
    }
    int op = 0;
    while (true) {
        cout << "Opción: "; cin >> op;
        if (op >= 1 && op <= numEquipo) {
            int id = equipo[op-1];
            if (soloSanos && pokedex[id].vida <= 0) {
                cout << "Ese Cuscamón está debilitado, elige otro.\n";
            } else return id;
        }
    }
}

// ====== POKEDEX MENU ======
void pokedexMenu() {
    system("cls");
    setColor(11);
    cout << "========== POKEDEX CUSCATLECA ==========\n";
    setColor(7);
    for (int i = 0; i < MAX_CUSCAMON; i++) {
        if (pokesVistos[i] || pokedex[i].atrapado) {
            cout << "[" << i+1 << "] " << pokedex[i].nombre;
            if (pokedex[i].atrapado)
                cout << " (ATRAPADO)";
            else
                cout << " (VISTO)";
            cout << " | Tipo: " << pokedex[i].tipo << endl;
            cout << pokedex[i].ascii << endl;
            cout << pokedex[i].desc << "\n\n";
        }
    }
    cout << "(Se muestran los Cuscamones que has visto o atrapado)\n";
    pausa();
}
