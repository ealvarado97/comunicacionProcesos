#include "controlador_proceso.h"
#include<iostream>


controlador_proceso * controlador_proceso::instancia=nullptr;
//imprese los datos de un proceso que es pasado por parametro
void controlador_proceso::printLogsGui(proceso *p,void *objectGui){


    std::list<const char*> lista=p->getRegistrosLog();


    for(auto it=lista.cbegin();it!=lista.cend();++it){

        std::string nuevo(*it);
        //muestra en gui el log del proceso
        std::cout<<nuevo<<std::endl;
    }

}
//Impreme todos los procesos que estan en la lista de procesos
void controlador_proceso::printLogsGui(void *objectGui){

    void *temp=procesos->primero; //apunta a la cabeza de la lista
    proceso *p=nullptr;

    while (procesos->primero!=nullptr) {

        p=procesos->primero->dato;
        procesos->primero=procesos->primero->next; //pasa a la siguiente caja de las lista

        printLogsGui(p,nullptr);//impreme los datos de un solo proceso

    }

    procesos->primero=reinterpret_cast<colecciones::nodo*>(temp);// restablece la cabeza de la lista

}
//Inserta un proceso a la lista de procesos del sistema
bool controlador_proceso::insertarNuevoProceso( proceso *p){

    if(procesos==nullptr)
        initListaProcesos();

   //aqui la comparacion
   // if(procesos->size_<=x){


    bool bandera=procesos->insertar(p);
    return  bandera;

    //return false //cola esta llena

}
//se establece si la lista es fifo o prioridad de acuerdo a los parametros generales
//del sistema,
void controlador_proceso::initListaProcesos(){
    // se crea la cola de procesos

    cotrolador_configuracion *conf;
    conf=cotrolador_configuracion::getInstancia();


    switch (conf->getCola()) {

    case colas::fifo:procesos=new Cola();break;
    case colas::prioridad:procesos=new listaPrioridad(); break;
    default:break;

    }
}
proceso * controlador_proceso::getProcesoActual(){

    procesos->topExecutar();//consulta el proceso actual sin eliminarlo;
}
proceso* controlador_proceso::executarProcesoActual(  ){

    procesos->executar();//regresa un proceso y avanza en la lista
}
controlador_proceso *controlador_proceso::getInstancia(){

    if(controlador_proceso::instancia==nullptr)
        crearInstancia();
    return  controlador_proceso::instancia;
}
void controlador_proceso::crearInstancia(){

    if (controlador_proceso::instancia==nullptr)
        controlador_proceso::instancia=new controlador_proceso();
}
