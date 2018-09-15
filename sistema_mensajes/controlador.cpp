#include "controlador.h"


void controlador::printLogGui(void *object){

   //ingresa el log de un proceso en un componente de  la gui

    //controladorProceso->printLogsGui(p,object);
    controladorProceso->printLogsGui(nullptr);
}
bool controlador::insertarNuevoProceso(proceso *p){

    bool bandera=false;
    bandera=controladorProceso->insertarNuevoProceso(p);

    return  bandera;
}
