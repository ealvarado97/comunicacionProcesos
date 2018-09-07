#include <QCoreApplication>
#include "colecciones.h"
#include "cola.h"
#include "listaprioridad.h"
#include "proceso.h"
#include "controlador.h"

#include <string>

#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    colecciones *c=nullptr;

    c=new Cola();

    proceso *p=new proceso(1,1,estadoProceso::BLOQUEADO);
    proceso *p2=new proceso(2,3,estadoProceso::BLOQUEADO);
    proceso *p3=new proceso(3,2,estadoProceso::BLOQUEADO);

    c->insertar(p);
    c->insertar(p2);
    c->insertar(p3);

    c->executar();
    c->executar();
    c->executar();
    c->executar();

    c=new listaPrioridad();

    c->insertar(p3);
    c->insertar(p);
    c->insertar(p2);


    c->executar();
    c->executar();
    c->executar();
    c->executar();

    controlador *controller =new controlador();

    sincro__ sincro=controller->getSincro();
    address__ adress =controller->getAddress();
    format__ format =controller->getFormat();
    colas  cola =controller->getCola();




    std::cout<<format.size<<std::endl;
    std::cout<<sincro.recv_<<std::endl;

    if(cola==colas::fifo)
        std::cout<<"fifo"<<std::endl;
    else if(cola==colas::prioridad)
        std::cout<<"prioridad"<<std::endl;




   // std::cout<<controller->getSincroRecv(send.c_str())<<std::endl;
   // std::cout<<controller->getSincroSend(recv.c_str())<<std::endl;

   // std::cout<<controller->getAddressType()<<std::endl;
  //  std::cout<<controller->getAddressMethod()<<std::endl;





    return a.exec();
}
