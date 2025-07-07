#pragma once
#include <string>

extern std::string tipoPupusa;
extern std::string nombrePupusa;
extern bool salirAlMenu;
extern bool vencioTlaloc;
extern bool starterYaEscogido;
extern bool vencioQuetzal;
extern int volcan_px, volcan_py; // posición del jugador en el volcán
extern bool enVolcan;  // indicador para guardar la posición de donde estuvimos la ultima vez en el volcán 
extern bool enCiudad;  // indicador para guardar la posición de donde estuvimos la ultima vez en la ciudad
extern int ciudad_px, ciudad_py;

#define MAX_CUSCAMON 7
#define MAX_EQUIPO 6
#define MAX_OBJETOS 7
