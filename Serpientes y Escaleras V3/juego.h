#ifndef juego_h
#define juego_h

#include "tablero.h"

class juego {
    public:
        juego();
        void iniciar(int, int);
        void manual();
        void automatico();
    protected:
        int cantatras, cantadelante;
        int numjugador, cantturnos;
        string nom, clav;
    private:
        vector <jugadores*> jugador;
        tablero tab;
};

juego::juego(){

}

void juego::iniciar(int numjugador, int cantturnos){
    this -> numjugador = numjugador;
    this -> cantturnos = cantturnos;
    
    for(int i = 0; i < numjugador; i++) {
        cout << "Ingrese nombre de jugador\n";
        cin >> nom;
        cout << "Ingrese clave de jugador\n";
        cin >> clav;
        cout << endl;
        jugador.push_back(new jugadores(nom, clav));
    }
}

void juego::manual(){
    char cont = '-';
    int dado;

    // Se crea el tablero.
    tablero tab;
    tab.crear();
    
    cout << endl << "Empieza juego" << endl;
    tab << jugador;
    int t = 1;
    while(cont != 'f'){
        int i = 0;
        cout << "Numero de turno: " << t << endl;
        while(i < numjugador){
            cout << "Turno de: " << jugador[i] -> getnombre() << endl;
            dado = jugador[i] -> tirardado();
            cout << "El jugador tiro: " << dado << endl << endl;
            *jugador[i] + dado;
            if(jugador[i] -> getposicion() > (tab.getrengcol() - 1)) {
                cout << "Gananador: " << jugador[i] -> getnombre();
                cont = 'f';
                break;
            }
            tab << jugador;
            cout << endl << "Continuar o Finalizar. C/F" << endl;
            cin >> cont;
            cont = tolower(cont);
            cout << endl;
            while(cont != 'c' && cont != 'f'){
                cout << "Opcion no validad ingrese C/F" << endl;
                cont = tolower(cont);
                cin >> cont;
                cout << endl;
            }
            i++;
        }
        t++;
        if(t > cantturnos){
            cout << "Empate se acabaron los turnos.";
            cont = 'f';
        }
    }  

    jugador.clear();
}

void juego::automatico(){
    char cont = '-';
    int dado;

    // Se crea el tablero.
    tablero tab;
    tab.crear();
    
    cout << endl << "Empieza juego" << endl;
    tab << jugador;
    int t = 1;
    while(cont != 'f'){
        int i = 0;
        cout << "Numero de turno: " << t << endl;
        while(i < numjugador){
            cout << "Turno de: " << jugador[i] -> getnombre() << endl;
            dado = jugador[i] -> tirardado();
            cout << "El jugador tiro: " << dado << endl << endl;
            *jugador[i] + dado;
            if(jugador[i] -> getposicion() > (tab.getrengcol() - 1)) {
                cout << "Gananador: " << jugador[i] -> getnombre();
                cont = 'f';
                break;
            }
            tab << jugador;
            i++;
        }
        t++;
        if(t > cantturnos){
            cout << "Empate se acabaron los turnos.";
            cont = 'f';
        }
    }
        
    jugador.clear();
}

#endif