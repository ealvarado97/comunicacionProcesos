#ifndef PROCESO_H
#define PROCESO_H
#include<list>

enum estadoProceso{EJECUTANDO,BLOQUEADO};

class proceso{

public:


    proceso(unsigned int Pid_,unsigned int prioridad_,estadoProceso estado_):pID(Pid_),prioridad(prioridad_),
                                                                    estado(estado_){}

    unsigned int getPid()const{return  pID;}
    unsigned int getPrioridad()const{return  prioridad;}
    estadoProceso getEstado()const{return  estado;}
    void setEstadoProceso(estadoProceso e){this->estado=e;}

    void nuevoRegistroLog(const char* reg){log.push_back(reg);}
    std::list<const char*>getRegistrosLog()const{return log;}


private:

    unsigned int pID;
    unsigned int prioridad;
    estadoProceso estado;
    std::list<const char*>log;

};
#endif // PROCESO_H
