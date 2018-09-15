#include "cotrolador_configuracion.h"

cotrolador_configuracion* cotrolador_configuracion::instancia=nullptr;

sincro__ &cotrolador_configuracion ::getSincro(){

    sincro__ *temp=new sincro__();

    std::string send =controller_config->getSincroSendRecv("send");
    std::string recv=controller_config->getSincroSendRecv("recv");


    if(send.compare("blocking")==0)
        temp->send_=sincro::blocking;
    else if(send.compare("nonblocking")==0)
        temp->send_=sincro::nonblocking;
    else if(send.compare("prueba_de_llegada")==0)
        temp->send_=sincro::prueba_de_llegada;


    if(recv.compare("blocking")==0)
        temp->recv_=sincro::blocking;
    else if(recv.compare("nonblocking")==0)
        temp->recv_=sincro::nonblocking;
    else if(send.compare("prueba_de_llegada")==0)
        temp->recv_=sincro::prueba_de_llegada;



    return  *temp;
}
address__ &cotrolador_configuracion::getAddress(){

    address__ *temp=new address__();

    std::string types= controller_config-> getAddressType();
    std::string method=controller_config->getAddressMethod();

    if(types.compare("directo")==0){

        temp->tipo_=direc::directo;

        if(method.compare("explicito")==0)
            temp->method=address::explicito;
        else if(method.compare("implicito")==0)
            temp->method=address::implicito;

    }
    else if(types.compare("indirecto")==0){

        temp->tipo_=direc::indirecto;

    if(method.compare("estatico")==0)
        temp->method=address::explicito;
    else if(method.compare("dinamico")==0)
        temp->method=address::implicito;
    }

    return  *temp;
}
format__ &cotrolador_configuracion::getFormat(){

    format__ *temp=new format__();

    std::string contenido=controller_config->getContenido();

    std::string longitudType=controller_config->getTypeSize();

    if(longitudType.compare("variable")==0){

        temp->format_=format::fijo;
        temp->size=-1;

    }
    else if(longitudType.compare("fijo")==0){

        temp->format_=format::variable;

        long long size_=controller_config->getLargo();

        if(size_!=0)
            temp->size=size_;
        else
            temp->size=-2;
    }
    return  *temp;
}
colas cotrolador_configuracion::getCola(){

    std::string colaType=controller_config->getColaType();

    if(colaType.compare("fifo")==0)
        return  colas::fifo;
    else if(colaType.compare("prioridad")==0)
        return  colas::prioridad;

    return  colas::error;
}
cotrolador_configuracion *cotrolador_configuracion::getInstancia(){

    if(cotrolador_configuracion::instancia==nullptr)
        crearInstancia();
    return cotrolador_configuracion::instancia;
}
void cotrolador_configuracion::crearInstancia(){

    if(cotrolador_configuracion::instancia==nullptr)
        cotrolador_configuracion::instancia=new cotrolador_configuracion();
}
