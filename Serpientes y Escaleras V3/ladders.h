#ifndef ladders_h
#define ladders_h

#include "tiles.h"

class ladders: public tiles{
    public:
        ladders();
        ladders(int);
        int getmov();
        string gettype();
};

ladders::ladders(){

}

ladders::ladders(int mov){
    this -> mov = mov;
}

int ladders::getmov(){
    return mov;
}

string ladders::gettype(){
    return "E";
}

#endif