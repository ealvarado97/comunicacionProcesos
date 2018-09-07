#ifndef COLECCIONES_H
#define COLECCIONES_H

#include "proceso.h"

class colecciones{

public:

    colecciones(){}
    virtual bool insertar(proceso*)=0;
    virtual proceso* executar()=0;
    virtual ~colecciones(){}

};

#endif // COLECCIONES_H
