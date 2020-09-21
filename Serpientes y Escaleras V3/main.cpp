#include <iostream>
#include <fstream>

#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::srand;
using std::rand;
using std::tolower;
using std::round;

#include "juego.h"

int main() {
    int numjugador, cantturnos;
    char continuar, modo;
    juego SerpYEsc;

    while(continuar != 'n'){
        
        cout << "Creando juego..." << endl;

        // Se seleccionan la cantidad de jugadores.
        cout << "Eliga cantidad de jugadores. Minimo 2. Maximo 6.\n";
        cin >> numjugador;
        while (numjugador < 2 || numjugador > 6){
            cout << "Numero invalido.\n" << "\nEliga cantidad de jugadores. Minimo 2. Maximo 6.\n";
            cin >> numjugador;
        }
        cout << endl;

        // Elige el numero de turnos. No ingrese letra o el juego entrara en un loop infinito.
        cout << "Eliga cantidad de turnos. Numero mayor a 0.\n";
        cin >> cantturnos;
        while (cantturnos < 0){
            cout << "Numero invalido.\n" << "\nEliga cantidad de turnos. Numero mayor a 0.\n";
            cin >> numjugador;
        }
        cout << endl;

        // Se selecciona el modo.
        cout << "Eliga el modo den juego. Manual o automatico. M/A.\n";
        cin >> modo;
        modo = tolower(modo);
        while (modo != 'm' && modo != 'a'){
            cout << "Modo invalido.\n" << "\nEliga el modo de juego. Manual o automatico. M/A\n";
            cin >> modo;
            modo = tolower(modo);
        }
        cout << endl;

        SerpYEsc.iniciar(numjugador,cantturnos);

        if(modo == 'm'){
            SerpYEsc.manual();
        } else if (modo == 'a'){
            SerpYEsc.automatico();
        }

        cout << endl << "Volver a jugar. S/N." << endl;
        cin >> continuar;
        continuar = tolower(continuar);
    }
    return 0;
}