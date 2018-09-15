#ifndef COLECCIONES_H
#define COLECCIONES_H

#include "proceso.h"

class controlador_proceso;


class colecciones{

    friend class controlador_proceso; //permite acceder a los miembro protegidos para recorrer la lista, en la funcion printLogsGui

public:

    colecciones(){}
    virtual bool insertar(proceso*)=0;
    virtual proceso* executar()=0;
    virtual ~colecciones(){}

protected:

    class nodo{

    public:
        nodo(){dato=nullptr;next=nullptr;}
        proceso* dato;
        nodo *next;

    };

    nodo *primero;
    nodo *ultimo;
    unsigned int size_;

};

#endif // COLECCIONES_H
