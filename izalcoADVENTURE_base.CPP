#include "src/statementsALL.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Variables globales
string tipoPupusa;
string nombrePupusa;
int vidaJugador = 100;
int vidaEnemigo = 120;
int defensa = 0;
int ataqueExtra = 0;
bool salvaCola = true;
bool choripanes = true;
bool kolashanpan = true;



// Función principal
// Esta es la función que se ejecuta al iniciar el programa
// Llama a las otras funciones en el orden correcto
// y maneja la lógica del juego.
int main() {
    pantallaSeleccion();
    mapaVolcanJuego();
    batalla();
    
    return 0;
}