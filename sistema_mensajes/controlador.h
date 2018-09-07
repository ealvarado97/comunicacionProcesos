#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include"cotrolador_configuracion.h"
#include <string>

class controlador
{
public:
    controlador(){

        controladorConfig=new cotrolador_configuracion();
    }
    sincro__ &getSincro()const {return  controladorConfig->getSincro();}
    address__ &getAddress()const {return  controladorConfig->getAddress();}
    format__ &getFormat()const {return  controladorConfig->getFormat();}
    colas getCola()const {return  controladorConfig->getCola();}
private:

    cotrolador_configuracion *controladorConfig;

};

#endif // CONTROLADOR_H
