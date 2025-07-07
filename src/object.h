#pragma once
#include <string>
using namespace std;

struct Objeto {
    std::string nombre, desc;
    int cantidad;
};

extern Objeto mochila[];
extern const int MAX_OBJETOS;

void guardarPartida();
bool cargarPartida();
int buscarObjeto(std::string nombre);
void mochilaMenu();