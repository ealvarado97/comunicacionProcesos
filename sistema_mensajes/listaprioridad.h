#ifndef LISTAPRIORIDAD_H
#define LISTAPRIORIDAD_H

#include "colecciones.h"

//class proceso;

class listaPrioridad:public colecciones{

  //  friend class proceso;

public:

    listaPrioridad();
    bool insertar(proceso*);
    proceso* executar();
    ~listaPrioridad(){}



};

#endif // LISTAPRIORIDAD_H
