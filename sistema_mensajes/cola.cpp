#include "cola.h"

bool Cola::insertar(proceso* p){

    nodo* aux=new nodo();

    aux->dato=p;

    if(size_==0)
        primero=aux;
    else
        ultimo->next=aux;

    ultimo=aux;
    size_++ ;

    return true;
}
proceso* Cola::executar( ){

    proceso *temp;

    if(size_==0)
        return  nullptr;

    nodo* aux=primero;
    temp=aux->dato;

    primero=aux->next;

    if(ultimo==aux)
        ultimo=primero;

    delete  aux;

    size_--;

    return  temp;
}
 proceso * Cola::topExecutar(){


}
