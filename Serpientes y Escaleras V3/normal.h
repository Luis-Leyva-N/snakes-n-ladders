#ifndef normal_h
#define normal_h

#include "tiles.h"

class normal: public tiles{
    public:
        normal();
        int getmov();
        string gettype();
};

normal::normal(){
    mov = 0;
}

int normal::getmov(){
    return mov;
}

string normal::gettype(){
    return "N";
}

#endif