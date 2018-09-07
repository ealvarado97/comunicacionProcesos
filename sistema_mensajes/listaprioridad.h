#ifndef LISTAPRIORIDAD_H
#define LISTAPRIORIDAD_H

#include "colecciones.h"

class listaPrioridad:public colecciones{

public:

    listaPrioridad();
    bool insertar(proceso*);
    proceso* executar();
    ~listaPrioridad(){}

private:

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

#endif // LISTAPRIORIDAD_H
