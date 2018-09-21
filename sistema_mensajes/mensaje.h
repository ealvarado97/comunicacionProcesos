#ifndef MENSAJE_H
#define MENSAJE_H
#include "proceso.h"

class mensaje{


public:

    mensaje(){}

    proceso *destino;
    proceso *origen;
    const char* dato;
    long long size;



};

#endif // MENSAJE_H
