#ifndef CONTROLADOR_PROCESO_H
#define CONTROLADOR_PROCESO_H

#include "proceso.h"
#include <iterator>
#include "colecciones.h"
#include "cola.h"
#include "listaprioridad.h"
#include "cotrolador_configuracion.h"


class controlador_proceso{


public:


    void printLogsGui(proceso *,void*);
    void printLogsGui(void*);
    static controlador_proceso *getInstancia();
    bool insertarNuevoProceso( proceso*);
    proceso *getProcesoActual();
    proceso * executarProcesoActual();


private:

    controlador_proceso(){}
    static controlador_proceso *instancia;
    static void crearInstancia();


    colecciones *procesos=nullptr;//lista de procesos sea fifo o prioridad
    void initListaProcesos();


};

#endif // CONTROLADOR_PROCESO_H
