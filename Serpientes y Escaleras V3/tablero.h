#ifndef tablero_h
#define tablero_h

#include "normal.h"
#include "snakes.h"
#include "ladders.h"

class tablero: public normal, public ladders, public snakes{
    public:
        tablero();
        void crear();
        void operator <<(vector<jugadores*>);
        int getrengcol();
    private:
        int numserp, numesc, numnorm;
        int penalty, reward;
        int pos, a, b;
        int totcasillas;
    protected:
        vector<vector<tiles*>> Tablero;
        int reng, col;
};

tablero::tablero(){

}

void tablero::crear(){
    int total;
    Tablero.resize(reng, vector<tiles*>(col, 0));

    cout << "Base de juego creada" << endl;

    cout << "Ingrese el tamano del tablero por renglones y columnas. Minimo 20 casillas.\n";
    cin >> reng >> col;
    total = reng * col;
    while (total < 20){
        cout << "Cantidad Invalida.\n" << "\nEliga una cantidad de casillas mayor a 20. Ingres esta cantidad en renglones y columnas.\n";
        cin >> reng >> col;
        total = reng * col;
    }

    cout << endl << "Elegir cantidad de escaleras y serpientes" << endl;
    cout << endl << "Serpientes. Minimo " << round((reng*col)*.1) << ". Maximo " << round((reng*col)*.2) << endl;
    cin >> numserp;
    while ((numserp > (round((reng*col)*.2))) || (numserp < (round((reng*col)*.1)))){
        cout << "Numero invalido" << endl; 
        cout << "Serpientes. Minimo " << round((reng*col)*.1) << ". Maximo " << round((reng*col)*.2) << endl;
        cin >> numserp;
    }
    
    cout << endl << "Escaleras. Minimo " << round((reng*col)*.1) << ". Maximo " << round((reng*col)*.2) << endl;
    cin >> numesc;
    while ((numesc > (round((reng*col)*.2))) || (numesc < (round((reng*col)*.1)))){
        cout << "Numero invalido" << endl; 
        cout << "Escaleras. Minimo " << round((reng*col)*.1) << ". Maximo " << round((reng*col)*.2) << endl;
        cin >> numesc;
    }

    numnorm = (reng * col) - (numesc + numserp);
    cout << endl << "Numero de casillas normales: " << numnorm << endl;

    cout << endl << "Penalty. Minimo " << round((reng*col)*.05) << ". Maximo " << round((reng*col)*.15) << endl;
    cin >> penalty;
    while ((penalty > (round((reng*col)*.15))) || (penalty < (round((reng*col)*.05)))){
        cout << "Numero invalido" << endl; 
        cout << "Penalty. Minimo " << round((reng*col)*.05) << ". Maximo " << round((reng*col)*.15) << endl;
        cin >> penalty;
    }

    cout << endl << "Reward. Minimo " << round((reng*col)*.05) << ". Maximo " << round((reng*col)*.15) << endl;
    cin >> reward;
    while ((reward > (round((reng*col)*.15))) || (reward < (round((reng*col)*.05)))){
        cout << "Numero invalido" << endl; 
        cout << "Reward. Minimo " << round((reng*col)*.05) << ". Maximo " << round((reng*col)*.15) << endl;
        cin >> reward;
    }

    // Se crea un esqueleto del tablero para despues asignar los objetos de las casillas.
    int r, s, e, n, k, a, b;
    n = 0;
    s = 0;
    e = 0;
    totcasillas = 0;

    string base[reng][col];

    srand(time(NULL));
    for(int i = 0; i < reng; i++){
        for(int j = 0; j < col; j++){
            if (s < numserp && e < numesc && n < numnorm){
                r = rand() % 3 + 1;
                if (r == 1){
                    base[i][j] = "N";
                    n++;
                } else if (r == 2) {
                    a = (totcasillas - penalty) / col;
                    b = (totcasillas - penalty) % col;
                    if(a < 0 || b < 0){
                        base[i][j] = "N";
                        n++;
                    } else if (base[a][b] != "N" || totcasillas < penalty){
                        base[i][j] = "N";
                        n++;
                    } else {
                        base[i][j] = "S";
                        s++;
                    }
                } else if (r == 3) {
                    a = (totcasillas - reward) / col;
                    b = (totcasillas - reward) % col;
                    if (base[a][b] == "E" || (a < 0 || b < 0)){ 
                        base[i][j] = "N";
                        n++;
                    } else {
                        base[i][j] = "E";
                        e++;
                    }
                }
            } else if (s < numserp && e == numesc && n < numnorm){
                r = rand() % 2 + 1;
                if (r == 1){
                    base[i][j] = "N";
                    n++;
                } else if (r == 2) {
                    a = (totcasillas - penalty) / col;
                    b = (totcasillas - penalty) % col;
                    if(a < 0 || b < 0){
                        base[i][j] = "N";
                        n++;
                    } else if (base[a][b] != "N" || totcasillas < penalty){
                        base[i][j] = "N";
                        n++;
                    } else {
                        base[i][j] = "S";
                        s++;
                    }
                }
            } else if (s == numserp && e < numesc && n < numnorm){
                r = rand() % 2 + 1;
                if (r == 1){
                    base[i][j] = "N";
                    n++;
                } else if (r == 2) {
                    a = (totcasillas - reward) / col;
                    b = (totcasillas - reward) % col;
                    if (base[a][b] == "E" || (a < 0 || b < 0)){ 
                        base[i][j] = "N";
                        n++;
                    } else {
                        base[i][j] = "E";
                        e++;
                    }
                }
            } else {
                base[i][j] = "N";
                n++;
            }
            totcasillas = n + s + e;  
        }
    }

    /* Las cantidades de serpientes y escaleras puenden tener una diferencia de +-1 debido
       a que el loop que las asigna aleatoriamente previene que se cree un loop inifinito entre
       las casillas. En algunos casos si son exactas los numeros de casillas.
    */
    for(int i = 0; i < reng; i++){
        for(int j = 0; j < col; j++){
            if(base[i][j] == "N"){
                Tablero[i].push_back(new normal);
            } else if(base[i][j] == "S"){
                Tablero[i].push_back(new snakes(penalty));
            } else if(base[i][j] == "E"){
                Tablero[i].push_back(new ladders(reward));
            }
        }
    }

    // Se crea el tablero con las cantidades especificadas de cada objeto
    cout << endl << "Tablero Creado\n" << endl;
    for(int i = 0; i < reng; i++){
        for(int j = 0; j < col; j++){
            cout << base[i][j] << " ";
        }
        cout << endl;
    }
}

void tablero::operator <<(vector<jugadores*> jugador){
    int num = jugador.size();
    for(int i = 0; i < reng; i++) {
        for(int j = 0; j < col; j++) {
            cout << Tablero[i][j] -> gettype() << "-";
            for(int k = 0; k < num; k++) {
                pos = jugador[k] -> getposicion();
                a = pos / col;
                b = pos % col;
                if (a == i && b == j) {
                    cout << jugador[k] -> getclave();
                } else {
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }

    cout << endl;
    for(int l = 0; l < num; l++){
        pos = jugador[l] -> getposicion();
        a = pos / col;
        b = pos % col;
        if(Tablero[a][b] -> gettype() == "E"){
            *jugador[l] + (Tablero[a][b] -> getmov());
            cout << "El jugador cayo en escalera se mueve " << Tablero[a][b] -> getmov() << " lugares" << endl <<  endl;
            if(jugador[l] -> getposicion() > ((reng * col)-1)){
                break;
            }
            for(int i = 0; i < reng; i++) {
                for(int j = 0; j < col; j++) {
                    cout << Tablero[i][j] -> gettype() << "-";
                    for(int k = 0; k < num; k++) {
                        pos = jugador[k] -> getposicion();
                        a = pos / col;
                        b = pos % col;
                        if (a == i && b == j) {
                            cout << jugador[k] -> getclave();
                        } else {
                            cout << " ";
                        }
                    }
                    cout << " ";
                }
            cout << endl;
            }
        } else if(Tablero[a][b] -> gettype() == "S"){
            *jugador[l] + (Tablero[a][b] -> getmov());
            cout << "El jugador cayo en serpiente se mueve " << Tablero[a][b] -> getmov() << " lugares" << endl <<  endl;
            for(int i = 0; i < reng; i++) {
                for(int j = 0; j < col; j++) {
                    cout << Tablero[i][j] -> gettype() << "-";
                    for(int k = 0; k < num; k++) {
                        pos = jugador[k] -> getposicion();
                        a = pos / col;
                        b = pos % col;
                        if (a == i && b == j) {
                            cout << jugador[k] -> getclave();
                        } else {
                            cout << " ";
                        }
                    }
                    cout << " ";
                }
            cout << endl;
            }
        }
    }
}

int tablero::getrengcol(){
    return (reng * col);
}

#endif