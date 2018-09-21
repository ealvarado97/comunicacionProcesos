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
     proceso * topExecutar();
   ~Cola(){}




};

#endif // COLA_H
