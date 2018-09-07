#ifndef COTROLADOR_CONFIGURACION_H
#define COTROLADOR_CONFIGURACION_H

#include "primitivas.h"
#include "controlador_cargaFile.h"
#include<iostream>

class cotrolador_configuracion{
public:
    cotrolador_configuracion(){

         controller_config=new controlador_CargaConfi("conf.txt");


    }

    sincro__ &getSincro();
    address__ &getAddress();
    format__ &getFormat();
    colas getCola();


private:

    controlador_CargaConfi *controller_config;




};

#endif // COTROLADOR_CONFIGURACION_H
