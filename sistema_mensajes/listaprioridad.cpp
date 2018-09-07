#include "listaprioridad.h"

listaPrioridad::listaPrioridad()
{

}
bool listaPrioridad::insertar(proceso *p){

    unsigned int prioridad =p->prioridad;

    nodo *aux=new nodo();
    aux->dato=p;

    if(size_==0)
        primero=aux;
    else{

        nodo *temp =primero;
        nodo *aux2=nullptr;

        while(temp!=nullptr &&prioridad >temp->dato->prioridad){

            aux2=temp;
            temp=temp->next;
        }

        if(aux2==nullptr){

            aux->next=primero;
            primero=aux;

        }else if(temp==nullptr){

            aux2->next=aux;

        }else if(prioridad<temp->dato->prioridad){

            aux2->next=aux;
            aux->next=temp;
        }
    }
    size_++;
    return  true;
}
proceso* listaPrioridad::executar(){


    proceso *temp;

    if(size_==0)
        return  nullptr;

    nodo *aux=primero;
    temp=aux->dato;

    primero=aux->next;

    delete  aux;
    size_--;

    return  temp;
}
