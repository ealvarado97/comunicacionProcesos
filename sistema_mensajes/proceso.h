#ifndef PROCESO_H
#define PROCESO_H

 enum estadoProceso{EJECUTANDO,BLOQUEADO,SUSPENDIDO};

class proceso{

public:

    unsigned int pID;
    unsigned int prioridad;
    estadoProceso estado;

    proceso(unsigned int Pid_,unsigned int prioridad_,estadoProceso estado_):pID(Pid_),prioridad(prioridad_),
                                                                    estado(estado_){}

};
#endif // PROCESO_H
