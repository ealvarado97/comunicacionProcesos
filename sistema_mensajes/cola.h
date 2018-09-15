#ifndef COLA_H
#define COLA_H

#include "colecciones.h"

class iterador;

class Cola:public colecciones {

    friend class iterador;

public:

    Cola(){}//primero=nullptr;ultimo=nullptr;size_=0;}
    bool insertar(proceso*);
    proceso*executar();
   ~Cola(){}


/*private:

    class nodo{

    public:
        nodo(){dato=nullptr;next=nullptr;}
        proceso* dato;
        nodo *next;

    };

    nodo *primero;
    nodo *ultimo;
    unsigned int size_;

*/



};

#endif // COLA_H
