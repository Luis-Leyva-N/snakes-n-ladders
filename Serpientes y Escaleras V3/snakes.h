#ifndef snakes_h
#define snakes_h

#include "tiles.h"

class snakes: public tiles {
    public:
        snakes();
        snakes(int);
        int getmov();
        string gettype();
};

snakes::snakes(){

}

snakes::snakes(int mov){
    this -> mov = -mov;
}

int snakes::getmov(){
    return mov;
}

string snakes::gettype(){
    return "S";
}

#endif