#include "object.h"
#include "cuscamon.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "defs.h"
using namespace std;

// =================== MOCHILA GLOBAL ===================
Objeto mochila[MAX_OBJETOS] = {
    {"Cuscaball", "Pokeball cuscatleca para atrapar cuscamones.",10},
    {"Salva Cola", "Cura 30HP a tu cuscamón.", 2},
    {"Curtido Legendario", "Cura a todo el equipo tras vencer a Tlaloc.", 1},
    {"Kolashanpan", "Aumenta ataque de tu cuscamón (+10, batalla).", 2},
    {"Choripán", "Aumenta defensa de tu cuscamón (+10, batalla).", 2},
    {"Chilillo", "Baja defensa del enemigo (-10, batalla).", 2},
    {"Sopa Gallina India", "Restaura todo el HP de tu cuscamón (una vez).", 1}
};

// =================== BUSCAR OBJETO ===================
int buscarObjeto(string nombre) {
    for (int i=0; i<MAX_OBJETOS; i++)
        if (mochila[i].nombre == nombre) return i;
    return -1;
}

// =================== GUARDAR PARTIDA ===================
void guardarPartida() {
    ofstream file("partida.sv");
    if (!file) {
        cout << "Error al guardar la partida.\n";
        return;
    }
    extern string tipoPupusa, nombrePupusa;
    extern bool vencioTlaloc, starterYaEscogido;

    // Guardar pupusa
    file << tipoPupusa << endl << nombrePupusa << endl;
    // Guardar progreso
    file << vencioTlaloc << " " << starterYaEscogido << " " << vencioQuetzal << endl;
    // Guardar mochila
    for (int i = 0; i < MAX_OBJETOS; i++) file << mochila[i].cantidad << " ";
    file << endl;
    // Guardar equipo
    file << numEquipo << endl;
    for (int i = 0; i < numEquipo; i++) {
        int id = equipo[i];
        file << id << " " << pokedex[id].vida << " ";
    }
    file << endl;
    // Guardar atrapados/vistos
    for (int i = 0; i < MAX_CUSCAMON; i++) {
        file << pokedex[i].atrapado << " " << pokesVistos[i] << " ";
    }
    file << endl;
    // Al final de guardarPartida()
    file << enVolcan << " " << volcan_px << " " << volcan_py << endl;
    file.close();
    cout << "¡Partida guardada!\n";
    Sleep(800);
}

// =================== CARGAR PARTIDA ===================
bool cargarPartida() {
    ifstream file("partida.sv");
    if (!file) return false;
    extern string tipoPupusa, nombrePupusa;
    extern bool vencioTlaloc, starterYaEscogido;

    getline(file, tipoPupusa);
    getline(file, nombrePupusa);
    file >> vencioTlaloc >> starterYaEscogido >> vencioQuetzal;
    for (int i = 0; i < MAX_OBJETOS; i++) file >> mochila[i].cantidad;
    file >> numEquipo;
    for (int i = 0; i < numEquipo; i++) {
        int id, vida;
        file >> id >> vida;
        equipo[i] = id;
        pokedex[id].vida = vida;
        pokedex[id].atrapado = true;
    }
    for (int i = 0; i < MAX_CUSCAMON; i++) {
        file >> pokedex[i].atrapado >> pokesVistos[i];
    }

    file >> enVolcan >> volcan_px >> volcan_py;

    file.close();
    return true;
}

// =================== MENÚ MOCHILA EN CIUDAD ===================
void mochilaMenu() {
    system("cls");
    setColor(6);
    cout << "========== MOCHILA ==========\n";
    setColor(7);
    for (int i=0; i<MAX_OBJETOS; i++) {
        cout << mochila[i].nombre << " (" << mochila[i].cantidad << "): " << mochila[i].desc << endl;
    }
    pausa();
}
