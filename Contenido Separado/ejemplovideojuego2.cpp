#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bot {
private:
    string nombre;
    int vida;
    vector<string> ataques;
    vector<int> danoAtaque;

public:
    Bot(string nombreBot) {
        nombre = nombreBot;
        vida = 100;
        ataques = {"Puño de hierro", "Patada giratoria", "Rayo láser", "Explosión oscura", "Golpe fantasma"};
        danoAtaque = {10, 15, 20, 25, 30};
    }

    bool estaVivo() {
        return vida > 0;
    }

    int obtenerVida() {
        return vida;
    }

    void recibirDano(int dano) {
        vida -= dano;
        if (vida < 0) vida = 0;
    }

    void atacar() {
        int index = rand() % ataques.size();
        cout << nombre << " usa: " << ataques[index] << " y causa " << danoAtaque[index] << " de daño." << endl;
    }

    int obtenerDano() {
        int index = rand() % danoAtaque.size();
        return danoAtaque[index];
    }
};

// Simula una batalla simple contra el bot
int main() {
    srand(time(0)); // Semilla para aleatoriedad

    Bot enemigo("OmegaBot");

    int vidaJugador = 100;

    cout << "¡Batalla contra " << enemigo.obtenerVida() << " de vida comienza!" << endl;

    while (enemigo.estaVivo() && vidaJugador > 0) {
        // Turno del jugador
        int danoJugador;
        cout << "\nTu turno. Ingresa el daño que causarás: ";
        cin >> danoJugador;

        enemigo.recibirDano(danoJugador);
        cout << "El bot tiene ahora " << enemigo.obtenerVida() << " de vida." << endl;

        // Turno del bot si sigue vivo
        if (enemigo.estaVivo()) {
            cout << "\nTurno del bot..." << endl;
            enemigo.atacar();
            int dano = enemigo.obtenerDano();
            vidaJugador -= dano;
            if (vidaJugador < 0) vidaJugador = 0;
            cout << "Tu vida ahora es: " << vidaJugador << endl;
        }
    }

    if (vidaJugador <= 0)
        cout << "\n¡Has perdido contra el bot!" << endl;
    else
        cout << "\n¡Has vencido al bot!" << endl;

    return 0;
}
