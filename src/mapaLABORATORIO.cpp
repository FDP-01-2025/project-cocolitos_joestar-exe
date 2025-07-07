#include "statementsALL.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

bool habloConMondongo = false;
bool eligioPokemon = false;
string pokemonElegido;

void interact_ConMondongo()
{
    system("cls");
    cout << R"( 
         
                 *            *++++++++                    
                  *            *+#+=+*++                   
                   ++          ++===++**                   
                    +++         +=+++*#                    
                   ++*++    +-=**++*##==+                  
                   **++==  ==-==**#*+++--=                 
                    +=----=-=--+***+------+               
                      +-------=+***+--=---=               
                       +=--==-+****+=-==---+              
                           +--=###*=---=---=              
                           =--=**+*=--=---=               
                           =--=++++=-==-==                
                           ---++*++=-----=                
                          +=--+++++=-----=                
                          ===-+++++=--====                
                          =---+++++=-----=                
                             ++++++++++                   
                             ++++*+++++                   
                             ++++*+++++   
                             
            Bienvenido a El Salvador joven entrenador Soy el profesor Mondongo
            ¡Tu aventura esta a punto de comenzar!
    )" << "\n\n";
    system("pause");
    habloConMondongo = true;
}

void elegirPokemon()
{
    if (!habloConMondongo)
    {
        system("cls");
        cout << "\nPROFESOR MONDONGO: ¡No tan rapido! Primero habla conmigo (A).\n";
        system("pause");
        return;
    }

    system("cls");
    cout << "\nEn esta mesa hay tres Cusca esferas:\n";
    cout << R"(
     (1) [O] Torogoz colorido
     (2) [O] Cangrejo de La Libertad
     (3) [O] Garrobo Caliente
    )";

    int eleccion;
    while (true)
    {
        cout << "\nElige a tu Cuscamon (1-3): ";
        cin >> eleccion;
        if (eleccion == 1)
        {
            cout << "\nHas elegido a Torogoz colorido. Un pajaro de fuego ancestral.\n";
            eligioPokemon = "CuscaTori";
            break;
        }
        else if (eleccion == 2)
        {
            cout << "\nHas elegido al Cangrejo. Rapido y resistente.\n";
            eligioPokemon = "Cangrejo de La Libertad";
            break;
        }
        else if (eleccion == 3)
        {
            cout << "\nHas elegido al Garrobo. ¡Cuidado que quema!\n";
            eligioPokemon = "Garrobo Caliente";
            break;
        }
        else
        {
            cout << "\nOpcion no valida. Intenta de nuevo.\n";
        }
    }

    cout << "\n¿Estas seguro de tu eleccion? (s/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 's' || confirm == 'S')
    {
        cout << "\n¡Perfecto! " << eligioPokemon << " ahora es tu companero.\n";
        pokemonElegido = true;
    }
    else
    {
        elegirPokemon();
    }
    system("pause");
}

void Mapa_Laboratorio()
{
    const int filas = 10;
    const int columnas = 20;
    char lab[filas][columnas] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', '#'},
        {'#', ' ', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '=', '=', ' ', ' ', 'A', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    int px = 1, py = filas - 2; // Posición inicial abajo a la izquierda
    char input;

    do
    {
        system("cls");
        cout << "LABORATORIO DEL PROFESOR MONDONGO\n";
        cout << "Controles: WASD (moverse), Q (salir)\n";
        if (eligioPokemon)
            cout << "Cuscamon: " << pokemonElegido << "\n";

        // Dibujar mapa
        for (int y = 0; y < filas; y++)
        {
            for (int x = 0; x < columnas; x++)
            {
                if (y == py && x == px)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Verde
                    cout << '@';
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                {
                    // Colorear elementos especiales
                    if (lab[y][x] == 'A')
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Amarillo
                    }
                    else if (lab[y][x] == 'O')
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Cyan
                    }
                    else if (lab[y][x] == 'D')
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo
                    }
                    else if (lab[y][x] == '=')
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Marrón
                    }

                    cout << lab[y][x];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            }
            cout << endl;
        }

        input = _getch();
        int newX = px, newY = py;

        switch (tolower(input))
        {
        case 'w':
            newY--;
            break;
        case 's':
            newY++;
            break;
        case 'a':
            newX--;
            break;
        case 'd':
            newX++;
            break;
        }

        // Verificar movimiento válido
        if (lab[newY][newX] == ' ' || lab[newY][newX] == 'A' ||
            lab[newY][newX] == 'O' || lab[newY][newX] == 'D')
        {
            px = newX;
            py = newY;
        }

        // Interacciones
        if (lab[py][px] == 'A')
        {
            interact_ConMondongo();
        }

        if (lab[py][px] == 'O')
        {
            elegirPokemon();
        }

        if (lab[py][px] == 'D' && eligioPokemon)
        {
            cout << "\n¡Felicidades! Has completado el laboratorio.\n";
            cout << "Tu aventura con " << pokemonElegido << " comienza ahora...\n";
            cout << "¡Suerte en tu viaje por El Salvador!\n";
            cout << "Presiona cualquier tecla para salir.\n";
            
            system("pause");
            break;
        }
        else if (lab[py][px] == 'D')
        {
            cout << "\nPROFESOR MONDONGO: ¡Espera! Primero elige tu Cuscamon.\n";
            system("pause");
        }

    } while (input != 'q');
}