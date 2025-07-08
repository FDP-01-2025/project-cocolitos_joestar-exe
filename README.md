[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [IZALCO AVENTURE]

## DESCRIPCION DEL JUEGO:

**IZALCO ADVENTURES** es un juego tipo RPG desarrollado en **C++** para consola, que combina la esencia de los clásicos juegos como Pokémon con elementos únicos de la cultura salvadoreña.
En este juego, tomas el papel de ser una pupusa viviente que debe escalar el gran Volcán de Izalco para combatir contra criaturas míticas como El Cipitío y Al Dragon Tlaloc. Con su estilo divertido y lleno de referencias a la cultural salvadoreña, el juego retoma las mecánicas tradicionales de los juegos RPG con su estilo clásico, un toque único y autentico

## Concepto y Estilo

El juego está diseñado para ofrecer una experiencia nostálgica de los RPG por turnos, pero con un giro salvadoreño:

**Personajes inspirados en la cultura local:**
- Tu personaje es una pupusa con vida.
- Tus aliados son criaturas como el Torogoz, el Garrobo y el Cadejo animales que se ven en las calles de El Salvador.
- El jefe final es el legendario Dragón Tlaloc, acompañado del Cipitío.

**Objetos y referencias auténticas:**
- Pociones como Salva Cola y Sopa Gallina India.
- Mejoras como Choripanes (aumentan defensa) y Kolashanpan (aumentan ataque).
- NPCs con diálogos bien divertidos y frases típicas.

**Combates estratégicos**
- Sistema de batallas por turnos.
- Ataques especiales basados en criaturas salvadoreñas.
- Captura de Cuscamones (versión local de los Pokémon).

## **Mecánica Principal**

Sistema de **RPG por turnos** con:
- Captura de "Cuscamones" (versión local de Pokémon)
- Combates estratégicos con ataques especiales
- Inventario de objetos inspirados en la cultura salvadoreña

## **jugabilidad**

1. **Exploración**:
    - Mapa de pueblo y volcán con movimiento WASD
    - Diálogos con NPCs que usan jerga local
2. **Combate**:
    - Sistema de turnos al estilo Pokémon
    - 3 Cuscamones iniciales (Torogoz, Garrobo, Cangrejo)
3. **Progresión**:
    - Derrotar al Dragón Tlaloc en la cima del volcán
  
## **Instalación y Ejecución**

1. **Requisitos**:
    - Compilador de C++ (g++, MinGW, Visual Studio).
    - Sistema Windows (por el uso de `<windows.h>`).
2. **Pasos para ejecutar**
    
    bash
    
    ```
    g++ .\main.cpp .\src\*.cpp -o startGAME
    ```
    

## **Aplicación de Temas Vistos**

### **1. Estructuras de Datos**

```cpp
struct Cuscamon {
    string nombre;  // "Torogoz"
    int vida;       // 100 HP
    string tipo;    // "Volador"
};

```
Uso: Almacenar atributos de cada criatura.

### **2. Archivos**

```cpp
ofstream archivo("save.txt");
archivo << jugador.nombre;  // Guarda "Pupusa de Queso"

```
Uso: Sistema de guardado de partidas.

### **3. POO Básica**

```cpp
class Batalla {
public:
    void iniciar();  // Gestiona turnos
};

```
Uso: Controlar flujo de combates.

### **4. Manejo de Strings**

```cpp
string mensaje = "¡" + nombrePupusa + " usó Choripán!";
// Ejemplo: "¡Pupusa de Queso usó Choripán!"

```
Uso: Diálogos dinámicos.

### **5. Aleatoriedad**

```cpp
int danio = rand() % 20 + 10;  // Daño entre 10-29

```
Uso: Cálculo de daño en ataques.

## ** Consideraciones Técnicas**

- **Plataforma**: Consola de Windows (CMD)
- **Dependencias**:
    - `<windows.h>` para colores (azul, verde, rojo)
    - `<conio.h>` para leer teclas sin presionar Enter
- **Limitaciones**:
    - No compatible con Linux/macOS (por dependencias de Windows)
    - Gráficos ASCII básicos

---

## ** Imágenes del Juego**

### **Pantalla de Inicio**

```
      _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _     
 (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_) 
 (_)                                                                      (_)
 (_)  ___ _____   _    _      ____ ___                                    (_)
 (_) |_ _|__  /  / |   | |   / ___/ _  |                                  (_)
 (_)  | |  / /  / _ |  | |  | |  | | | |                                  (_)
 (_)  | | / /_ / ___ | |__| |__| |_| |                                    (_)
 (_) |___/____/_/___| || ___| ____|___/ _____ _   _ ____  _____ ____      (_)
 (_)    / /   |  _ / /   /  / ____| |  ||_   _| | | |  _ /| ____/ __|     (_)
 (_)   / _ /  | | | / / / / |  _| |  | |  | | | | | | | |_) |  _| | __    (_)
 (_)  / ___ / | |_| |/ V /  | |___| ||  | | | | |_| |  _ <| |___ ___)     (_)
 (_) /_/   /_/____/ |   /_/ |_____|_| | | |_|  |___/|_| | ______|____/    (_)
 (_) _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _     (_)
 (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_)(_) 

          Bienvenido a Izalco Adventures
  1. Nueva partida
  2. Cargar partida
  3. Salir

```

### **Mapa del laboratorio**

```
void mapaLaboratorio() {
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
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
```

# Equipo

- **Nombre del equipo:** [Cocolitos_Joestar.exe]

### Integrantes del equipo

1. **Nombre completo:** [Daniel Eduardo Ibarra Aguirre]  
   **Carnet:** [00136225]

2. **Nombre completo:** [Ashley Nicole Hernández Polío]  
   **Carnet:** [00078125]

3. **Nombre completo:** [Andres Enrique Lima Perez]  
   **Carnet:** [00184825]
