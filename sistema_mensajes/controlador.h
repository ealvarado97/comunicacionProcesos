#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include"cotrolador_configuracion.h"
#include "controlador_proceso.h"
#include "proceso.h"
#include "messagepassing.h"
#include "mensaje.h"
#include <string>

class controlador
{
public:
    controlador(){

        controladorConfig=cotrolador_configuracion::getInstancia();
        controladorProceso=controlador_proceso::getInstancia();
        ms=new messagePassing();

    }

    sincro__ &getSincro()const {return  controladorConfig->getSincro();}
    address__ &getAddress()const {return  controladorConfig->getAddress();}
    format__ &getFormat()const {return  controladorConfig->getFormat();}
    colas getCola()const {return  controladorConfig->getCola();}

    void printLogGui(proceso* ,void *);
    void printLogGui(void *);
    bool insertarNuevoProceso( proceso*);
   // proceso *executarProcesoActual(){controladorProceso->executarProcesoActual();}
    void send(proceso *,mensaje *);
    void recv(proceso *,mensaje*);
private:

    cotrolador_configuracion *controladorConfig;
    controlador_proceso *controladorProceso;
    messagePassing *ms;

};

#endif // CONTROLADOR_H
