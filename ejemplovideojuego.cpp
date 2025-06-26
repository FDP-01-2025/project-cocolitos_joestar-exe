#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructura para un ataque
struct Ataque {
    string nombre;
    int dano;
};

// Clase para una criatura (jugador o bot)
class Pokemon {
private:
    string nombre;
    int vida;
    vector<Ataque> ataques;

public:
    Pokemon(string nombreP, vector<Ataque> atks) {
        nombre = nombreP;
        vida = 100;
        ataques = atks;
    }

    string getNombre() { return nombre; }
    int getVida() { return vida; }
    bool estaVivo() { return vida > 0; }

    void recibirDano(int d) {
        vida -= d;
        if (vida < 0) vida = 0;
    }

    // Jugador elige ataque
    Ataque elegirAtaqueJugador() {
        cout << "\nElige tu ataque:" << endl;
        for (size_t i = 0; i < ataques.size(); i++) {
            cout << i + 1 << ". " << ataques[i].nombre << " (" << ataques[i].dano << " daño)" << endl;
        }
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > ataques.size()) {
            cout << "Opción inválida. Intenta de nuevo: ";
            cin >> opcion;
        }
        return ataques[opcion - 1];
    }

    // Bot elige ataque al azar
    Ataque elegirAtaqueBot() {
        int index = rand() % ataques.size();
        return ataques[index];
    }
};

int main() {
    srand(time(0));

    // Definir ataques
    vector<Ataque> ataquesJugador = {
        {"Llamarada", 25},
        {"Arañazo", 15},
        {"Embestida", 20},
        {"Cola de Hierro", 30}
    };

    vector<Ataque> ataquesBot = {
        {"Picotazo venenoso", 18},
        {"Mordida", 22},
        {"Rayo sombrío", 28},
        {"Golpe aéreo", 24}
    };

    // Crear Pokémon jugador y bot
    Pokemon jugador("el dedo", ataquesJugador);
    Pokemon bot("sanches ceren", ataquesBot);

    cout << "¡el " << bot.getNombre() << " salvaje apareció!\n";

    // Bucle de batalla
    while (jugador.estaVivo() && bot.estaVivo()) {
        // Turno del jugador
        Ataque atkJugador = jugador.elegirAtaqueJugador();
        cout << jugador.getNombre() << " usó " << atkJugador.nombre << " causando " << atkJugador.dano << " de daño!" << endl;
        bot.recibirDano(atkJugador.dano);
        cout << bot.getNombre() << " tiene " << bot.getVida() << " de vida.\n";

        if (!bot.estaVivo()) break;

        // Turno del bot
        Ataque atkBot = bot.elegirAtaqueBot();
        cout << bot.getNombre() << " usó " << atkBot.nombre << " causando " << atkBot.dano << " de daño!" << endl;
        jugador.recibirDano(atkBot.dano);
        cout << jugador.getNombre() << " tiene " << jugador.getVida() << " de vida.\n";
    }

    // Resultado
    if (jugador.estaVivo())
        cout << "\n¡Ganaste el combate!\n";
    else
        cout << "\n¡" << bot.getNombre() << " te derrotó!\n";

    return 0;
}


