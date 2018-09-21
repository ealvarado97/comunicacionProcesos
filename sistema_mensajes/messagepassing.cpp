#include "messagepassing.h"

messagePassing::messagePassing(){


    procesos=controlador_proceso::getInstancia(); //info de los procesos
    confi=cotrolador_configuracion::getInstancia(); //info de la conf del sistema
    mensajesPendientes =new std::list<mensaje>();


}
void messagePassing::send(proceso* direccionDestino,mensaje* msj){

    Send_(direccionDestino,msj);
}

void messagePassing::Send_(proceso* p,mensaje *msj){

    //send

    switch (confi->getSincro().send_) {

    case  sincro::blocking:link(p,msj);break;
    case  sincro::nonblocking:link_noBlocking(p,msj,true);
                              procesos->executarProcesoActual();
                              break;
    }
}
void messagePassing::recv(proceso *p,mensaje *msj){

    Recv_(p,msj);
}
void messagePassing::Recv_(proceso *p,mensaje *m){

    switch (confi->getSincro().recv_) {

    case  sincro::blocking:link(p,m);break;
    case  sincro::nonblocking:link_noBlocking(p,m,false);break;

    }

}
void messagePassing::link(proceso *direccionDestino,mensaje *msj){

    std::list<mensaje>::iterator it =mensajesPendientes->begin();

    unsigned int actual=procesos->getProcesoActual()->getPid();
    bool bandera=false;

    for(it ; (it!=mensajesPendientes->end())&(bandera==false); it++){

        unsigned int origen=it->origen->getPid();
        unsigned int destino=it->destino->getPid();


        if((direccionDestino->getPid()==origen)&(actual==destino)){

            it->origen->setEstadoProceso(estadoProceso::EJECUTANDO);
            mensajesPendientes->erase(it);
            it=mensajesPendientes->end();
            bandera=true;
        }

     }
    if(bandera==false){
        procesos->executarProcesoActual()->setEstadoProceso(estadoProceso::BLOQUEADO);
        mensajesPendientes->push_back(*msj);
    }
}
void messagePassing::link_noBlocking(proceso *direccionDestino,mensaje *msj,bool llamadaSend){


    std::list<mensaje>::iterator it =mensajesPendientes->begin();

    unsigned int actual=procesos->getProcesoActual()->getPid();
    bool bandera=false;

    for(it ; (it!=mensajesPendientes->end())&(bandera==false); it++){

        unsigned int origen=it->origen->getPid();
        unsigned int destino=it->destino->getPid();


        if((direccionDestino->getPid()==origen)&(actual==destino)){

            it->origen->setEstadoProceso(estadoProceso::EJECUTANDO);
            mensajesPendientes->erase(it);
            it=mensajesPendientes->end();
            bandera=true;
        }

     }
    if(bandera==false){

        if(llamadaSend==false) //send no se bloquea
             procesos->executarProcesoActual()->setEstadoProceso(estadoProceso::BLOQUEADO);

        mensajesPendientes->push_back(*msj);
    }

}
