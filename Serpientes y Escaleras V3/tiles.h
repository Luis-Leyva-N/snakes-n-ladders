#ifndef tiles_h
#define tiles_h

#include "jugadores.h"

class tiles: public jugadores{
    public:
        tiles();
        virtual int getmov() = 0;
        virtual string gettype() = 0;
    protected:
        int mov;
};

tiles::tiles(){

}

#endif