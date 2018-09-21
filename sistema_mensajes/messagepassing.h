#ifndef MESSAGEPASSING_H
#define MESSAGEPASSING_H

#include "controlador_proceso.h"
#include "cotrolador_configuracion.h"
#include "primitivas.h"
#include<list>
#include "mensaje.h"
#include<iterator>
class messagePassing{

public:
    messagePassing();

    void send(proceso *,mensaje *);
    void recv(proceso *,mensaje*);



private:
    controlador_proceso *procesos;
    cotrolador_configuracion *confi;

    void link(proceso*,mensaje * );

    void Send_(proceso*,mensaje *);
    void Recv_(proceso*, mensaje*);
    std::list<mensaje> *mensajesPendientes;
};

#endif // MESSAGEPASSING_H
