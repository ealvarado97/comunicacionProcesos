#include <QCoreApplication>
#include "colecciones.h"
#include "cola.h"
#include "listaprioridad.h"
#include "proceso.h"
#include "controlador.h"
#include "mensaje.h"

#include <string>

#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);




    proceso *p=new proceso(1,1,estadoProceso::EJECUTANDO);
    proceso *p2=new proceso(2,2,estadoProceso::EJECUTANDO);
    proceso *p3=new proceso(3,3,estadoProceso::EJECUTANDO);


    controlador *controller =new controlador();

    sincro__ sincro=controller->getSincro();
    address__ adress =controller->getAddress();
    format__ format =controller->getFormat();
    colas  cola =controller->getCola();

   // p->nuevoRegistroLog("send p1");
   // p->nuevoRegistroLog("recv p2");
   // p->nuevoRegistroLog("send p3");
    //p->nuevoRegistroLog("recv p10");


    //p3->nuevoRegistroLog("send p100");
    //p3->nuevoRegistroLog("recv p200");
    //p3->nuevoRegistroLog("send p300");
    //p3->nuevoRegistroLog("recv p1000d");

    ///p2->nuevoRegistroLog("recx");


   // s//witch (format.format_) {  messagePassing::Recv

    //case format::fijo:{

    //copiar el texto send la gui a la variable dato de mesanje strcpy


   // }

    //}




    controller->insertarNuevoProceso(p3);
    controller->insertarNuevoProceso(p);
    controller->insertarNuevoProceso(p2);

    mensaje *m=new mensaje();

    m->destino=p3;
    m->origen=p;

    mensaje *m2=new mensaje();
    m2->destino=new proceso(7,7,estadoProceso::EJECUTANDO);
    m2->origen=new proceso(9,8,estadoProceso::EJECUTANDO);

    mensaje *m3=new mensaje();

    m3->destino=p;
    m3->origen=p3;


    //controller->send(p3,m);
   // controller->send(p2,m2);

    //controller->recv(p,m3);
    //cola p1,p2,p3

    controller->recv(p3,m);
    controller->send(p2,m2);
    //controller->send(p,m3);







    return a.exec();
}
