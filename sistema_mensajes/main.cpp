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




    proceso *p=new proceso(1,1,estadoProceso::BLOQUEADO);
    proceso *p2=new proceso(2,3,estadoProceso::BLOQUEADO);
    proceso *p3=new proceso(3,2,estadoProceso::EJECUTANDO);

    //c->insertar(p);
   // c->insertar(p2);
   // c->insertar(p3);

   // c->executar();
  //  c->executar();
   // c->executar();
  //  c->executar();

 //   c=new listaPrioridad();

 //   c->insertar(p3);
 //   c->insertar(p);
 //   c->insertar(p2);


 //   c->executar();
 //   c->executar();
  //  c->executar();
  //  c->executar();

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

    std::cout<<adress.method<<std::endl;

    p->nuevoRegistroLog("send p1");
    p->nuevoRegistroLog("recv p2");
    p->nuevoRegistroLog("send p3");
    p->nuevoRegistroLog("recv p10");


    p3->nuevoRegistroLog("send p100");
    p3->nuevoRegistroLog("recv p200");
    p3->nuevoRegistroLog("send p300");
    p3->nuevoRegistroLog("recv p1000d");

    p2->nuevoRegistroLog("recx");



    controller->insertarNuevoProceso(p3);
    controller->insertarNuevoProceso(p);
    controller->insertarNuevoProceso(p2);

    controller->printLogGui(nullptr);

    controller->printLogGui(nullptr);








   // std::cout<<controller->getSincroRecv(send.c_str())<<std::endl;
   // std::cout<<controller->getSincroSend(recv.c_str())<<std::endl;

   // std::cout<<controller->getAddressType()<<std::endl;
  //  std::cout<<controller->getAddressMethod()<<std::endl;





    return a.exec();
}
