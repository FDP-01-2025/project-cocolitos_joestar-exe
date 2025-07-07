#pragma once
#include <string>
using namespace std;

struct Ataque {
    std::string nombre, desc, tipo;
    int poder;
};

struct Cuscamon {
    std::string nombre, tipo, desc, ascii;
    int vidaMax, vida, idPokedex;
    Ataque ataques[4];
    bool atrapado;
};

struct SlotEquipo {
    int idPokedex; // Referencia a la entrada en la pokedex
    int vida;      // Vida ACTUAL de este cuscamón
};

extern Cuscamon pokedex[];
extern int pokesVistos[];
extern int equipo[];
extern int numEquipo;

void inicializarDatos();
int elegirCuscamonEquipo(bool soloSanos = false);
void pokedexMenu();
