#include "listaprioridad.h"

listaPrioridad::listaPrioridad()
{

}
bool listaPrioridad::insertar(proceso *p){

    unsigned int prioridad =p->getPrioridad();

    nodo *aux=new nodo();
    aux->dato=p;

    if(size_==0)
        primero=aux;
    else{

        nodo *temp =primero;
        nodo *aux2=nullptr;

        while(temp!=nullptr &&prioridad >temp->dato->getPrioridad()){

            aux2=temp;
            temp=temp->next;
        }

        if(aux2==nullptr){

            aux->next=primero;
            primero=aux;

        }else if(temp==nullptr){

            aux2->next=aux;

        }else if(prioridad<temp->dato->getPrioridad()){

            aux2->next=aux;
            aux->next=temp;
        }
    }
    size_++;
    return  true;
}
proceso* listaPrioridad::executar( ){

    int i=0;


    if(size_==0)
        return  nullptr;

    nodo *aux=primero;

    while (i!=procesoActual){

        aux=aux->next;
        i++;
    }
    procesoActual++;

    return  aux->dato;
}
 proceso * listaPrioridad::topExecutar(){

     int i=0;


     if(size_==0)
         return  nullptr;

     nodo *aux=primero;

     while (i!=procesoActual){

         aux=aux->next;
         i++;
     }

     return  aux->dato;
}
