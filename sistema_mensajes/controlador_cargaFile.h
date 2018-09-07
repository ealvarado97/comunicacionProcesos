#ifndef CONTROLADOR_CARGACONFI_H
#define CONTROLADOR_CARGACONFI_H

#include<iostream>
#include<fstream>
#include<stdlib.h>


class controlador_CargaConfi{


public:
    controlador_CargaConfi(std::string ruta_):ruta(ruta_){

        archivo.open(ruta,std::ifstream::in);
    }


    std::string getSincroSendRecv(const char* );   
    std::string getAddressType();
    std::string getAddressMethod();
    std::string getContenido();
    std::string getTypeSize();
    long long getLargo();
    std::string getColaType();

private:

    std::string ruta;
    std::fstream archivo;
    std::string linea;

    bool getsincro(){ return  linea.compare("sincro")==0;}
    bool getAddress(){ return  linea.compare("direccion")==0;}
    bool getFormat(){return  linea.compare("formato")==0;}
    bool getColas(){return  linea.compare("colas")==0;}

};

#endif // CONTROLADOR_CARGACONFI_H
