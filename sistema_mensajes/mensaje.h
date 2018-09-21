#ifndef MENSAJE_H
#define MENSAJE_H
#include "proceso.h"

class mensaje{ //para procesos


public:

    mensaje(){}

    proceso *destino; //mailbox
    proceso *origen;
    const char* dato;
    long long size;



};

#endif // MENSAJE_H
