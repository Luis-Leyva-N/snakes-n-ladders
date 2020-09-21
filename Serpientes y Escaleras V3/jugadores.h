#ifndef jugadores_h
#define jugadores_h

class jugadores {
    public:
        jugadores();
        jugadores(string, string);
        string getnombre();
        string getclave();
        int getposicion();
        int tirardado();
        void operator +(int);
    private:
        string nombre;
        string clave;
        int posicion;
        int dado;
};

jugadores::jugadores(){

}

jugadores::jugadores(string nombre, string clave){
    this -> nombre = nombre;
    this -> clave = clave;
    posicion = 0;   
}

void jugadores::operator +(int num){
    posicion += num;
}

string jugadores::getnombre(){
    return nombre;
}

string jugadores::getclave(){
    return clave;
}

int jugadores::getposicion(){
    return posicion;
}

int jugadores::tirardado() {
    dado = rand() % 6 + 1;
    return dado;
}

#endif