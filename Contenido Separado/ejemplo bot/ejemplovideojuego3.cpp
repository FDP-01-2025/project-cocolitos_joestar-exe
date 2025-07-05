#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Estructura para representar a un personaje
struct Personaje {
    string nombre;
    int vida;
};

// Función que genera un daño aleatorio entre dos valores
int generarDanio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Función para mostrar estado actual
void mostrarEstado(Personaje jugador, Personaje cadejo, Personaje tlaloc) {
    cout << "\n ESTADO:\n";
    cout << jugador.nombre << " - Vida: " << jugador.vida << endl;
    cout << cadejo.nombre << " - Vida: " << cadejo.vida << endl;
    cout << tlaloc.nombre << " - Vida: " << tlaloc.vida << endl;
}

// Función principal
int main() {
    srand(time(0)); // Para que los números aleatorios sean diferentes cada vez

    // Definimos los personajes
    Personaje jugador = {"Jugador", 100};
    Personaje cadejo = {"El Cadejo", 80};
    Personaje tlaloc = {"Tlaloc", 90};

    // Bucle del juego
    while (jugador.vida > 0 && (cadejo.vida > 0 || tlaloc.vida > 0)) {
        mostrarEstado(jugador, cadejo, tlaloc);

        // TURNO DEL JUGADOR
        cout << "\n Turno del jugador:\n";
        int opcion;
        cout << "1. Atacar a El Cadejo\n";
        cout << "2. Atacar a Tlaloc\n";
        cout << "Selecciona tu objetivo: ";
        cin >> opcion;

        int daño = generarDanio(10, 25);
        if (opcion == 1 && cadejo.vida > 0) {
            cadejo.vida -= daño;
            cout << " Atacaste a El Cadejo y le hiciste " << daño << " de daño.\n";
        } else if (opcion == 2 && tlaloc.vida > 0) {
            tlaloc.vida -= daño;
            cout << " Atacaste a Tlaloc y le hiciste " << daño << " de daño.\n";
        } else {
            cout << " Objetivo inválido o ya derrotado.\n";
        }

        // TURNO DE LOS BOTS (si están vivos)
        if (cadejo.vida > 0) {
            int danioCadejo = generarDanio(5, 15);
            jugador.vida -= danioCadejo;
            cout << " El Cadejo te mordio!! y te hizo " << dañoCadejo << " de daño.\n";
        }

        if (tlaloc.vida > 0) {
            int danioTlaloc = generarDanio(8, 18);
            jugador.vida -= dañoTlaloc;
            cout << " Tlaloc te lanzó pencaso y causó " << dañoTlaloc << " de daño.\n";
        }
    }

    // RESULTADO FINAL
    cout << "\n🏁 FIN DE LA BATALLA\n";
    if (jugador.vida <= 0)
        cout << " Has sido derrotado por los enemigos.\n";
    else
        cout << " ¡Has derrotado a El Cadejo y a Tlaloc!\n";

    return 0;
}
