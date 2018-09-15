#ifndef COTROLADOR_CONFIGURACION_H
#define COTROLADOR_CONFIGURACION_H

#include "primitivas.h"
#include "controlador_cargaFile.h"
#include<iostream>

class cotrolador_configuracion{

public:


    sincro__ &getSincro();
    address__ &getAddress();
    format__ &getFormat();
    colas getCola();

    static cotrolador_configuracion *getInstancia();


private:

    cotrolador_configuracion(){}
    static void crearInstancia();

    controlador_CargaConfi *controller_config=new controlador_CargaConfi("conf.txt"); //nombre correcto controlador_CargaConfi
    static cotrolador_configuracion *instancia;

};

#endif // COTROLADOR_CONFIGURACION_H
