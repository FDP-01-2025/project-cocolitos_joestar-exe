#include "statementsALL.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h> // Para _getch() en Windows

using namespace std;

void mapaVolcanJuego()
{

    SetConsoleOutputCP(65001);

    cout << "BIENVENIDO AL VOLCÁN DE IZALCO" << endl;
    cout << "-----------------------------" << endl;
    cout << "Prepárate para escalar el volcán..." << endl;
    Sleep(2000);

    const int altura = 15;
    const int ancho = 2 * altura + 1;
    char mapa[altura][ancho];

    // Posición inicial del jugador
    int jugadorY = altura - 1;
    int jugadorX = altura;

    // Inicializar el mapa
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            // Crear bordes del volcán
            if (j == altura - i || j == altura + i)
            {
                mapa[i][j] = '#'; // Bordes del volcán
            }
            else if (j > altura - i && j < altura + i)
            {
                // Interior del volcán con diferentes texturas
                if (i % 3 == 0 && j % 2 == 0)
                {
                    mapa[i][j] = '~'; // Rocas
                }
                else
                {
                    mapa[i][j] = '.'; // Tierra
                }
            }
            else
            {
                mapa[i][j] = ' '; // Espacio vacío
            }
        }
    }

    // Cima del volcán con humo
    mapa[0][altura] = 'X'; // Cráter
    mapa[1][altura - 1] = '^';
    mapa[1][altura] = '^';
    mapa[1][altura + 1] = '^'; // Humo

    // Agregar algunos obstáculos
    for (int i = 3; i < 6; i++)
    {
        mapa[i][altura + 2] = 'O'; // Rocas grandes
        mapa[i][altura - 2] = 'O';
    }

    bool llego = false;
    int pasos = 0;

    while (!llego)
    {
        system("cls");
        cout << "============ VOLCAN DE IZALCO ============" << endl;
        cout << "Pasos: " << pasos << " | Altura: " << (altura - jugadorY) << "/" << altura << endl;
        cout << "------------------------------------------" << endl;

        // Dibujar el mapa con el jugador
        mapa[jugadorY][jugadorX] = '@';
        for (int i = 0; i < altura; i++)
        {
            // Agregar numeración de altura
            cout << (altura - i) << "\t";

            for (int j = 0; j < ancho; j++)
            {
                // Colores diferentes para elementos del mapa
                if (mapa[i][j] == '@')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo
                    cout << mapa[i][j];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Blanco
                }
                else if (mapa[i][j] == 'X' || mapa[i][j] == '^')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Amarillo
                    cout << mapa[i][j];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (mapa[i][j] == 'O')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // Gris
                    cout << mapa[i][j];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (mapa[i][j] == '#')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // Rojo oscuro
                    cout << mapa[i][j];
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                {
                    cout << mapa[i][j];
                }
            }
            cout << endl;
        }
        mapa[jugadorY][jugadorX] = '.'; // Restaurar posición

        // Mensajes contextuales
        if (altura - jugadorY < 3)
        {
            cout << "\n¡Casi llegas! Se siente el calor del volcán..." << endl;
        }
        else if (altura - jugadorY < altura / 2)
        {
            cout << "\nVas a buena altura. ¡Sigue ascendiendo!" << endl;
        }
        else
        {
            cout << "\nEstás en la base del volcán. El camino es largo..." << endl;
        }

        cout << "Controles: W (arriba), A (izquierda), D (derecha)" << endl;
        cout << "Presiona Q para salir." << endl;

        // Movimiento del jugador (sin esperar Enter)
        char input = _getch();
        input = tolower(input);

        switch (input)
        {
        case 'w':
            if (jugadorY > 0 && mapa[jugadorY - 1][jugadorX] != ' ')
            {
                jugadorY--;
                pasos++;
            }
            break;
        case 'a':
            if (jugadorX > 0 && mapa[jugadorY][jugadorX - 1] != ' ')
            {
                jugadorX--;
                pasos++;
            }
            break;
        case 'd':
            if (jugadorX < ancho - 1 && mapa[jugadorY][jugadorX + 1] != ' ')
            {
                jugadorX++;
                pasos++;
            }
            break;
        case 'q':
            cout << "\n¡Decidiste retirarte del volcán!" << endl;
            Sleep(2000);
            return;
        }

        // Verificar si llegó a la cima
        if (jugadorY == 0 && jugadorX == altura)
        {
            llego = true;
        }

        // Pequeña animación de humo en la cima
        static int anim = 0;
        anim++;
        if (anim % 3 == 0)
        {
            mapa[1][altura] = '^';
        }
        else if (anim % 3 == 1)
        {
            mapa[1][altura - 1] = '^';
            mapa[1][altura + 1] = '^';
        }
        else
        {
            mapa[2][altura] = '^';
        }
    }

    // Animación de llegada
    for (int i = 0; i < 3; i++)
    {
        system("cls");
        cout << "¡Llegaste a la cima del volcán!" << endl;
        cout << "Pasos totales: " << pasos << endl;
        cout << "    \\|/" << endl;
        cout << "   --X--" << endl;
        cout << "    /|\\" << endl;
        if (i % 2 == 0)
        {
            cout << "  ^^^^^^^" << endl;
        }
        else
        {
            cout << " ^^^^^^^^" << endl;
        }
        Sleep(500);

        cout << "\nHAZ LLEGADO A LA SIMA DEL VOLCAN" << endl;
        cout << "¡PREPARATE PARA LA BATALLA!" << endl;
    }
}
