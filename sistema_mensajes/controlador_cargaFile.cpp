#include "controlador_cargaFile.h"

std::string controlador_CargaConfi::getSincroSendRecv(const char* sendRecv){

    getline(archivo,linea);

    if(getsincro()){

        std::getline(archivo,linea);

        if(linea.compare(sendRecv)==0)
            getline(archivo,linea);

        else{
            getline(archivo,linea);
            while(linea.compare(sendRecv)!=0)
                getline(archivo,linea);

            getline(archivo,linea);
        }
    }else{

        while (getsincro()==false)
            getline(archivo,linea);

        getline(archivo,linea);
        while(linea.compare(sendRecv)!=0)
            getline(archivo,linea);

        getline(archivo,linea);
    }
    archivo.seekg(std::ios_base::beg);
    return  linea;

}
std::string controlador_CargaConfi::getAddressType(){

    getline(archivo,linea);

    if(getAddress())
        getline(archivo,linea);

    else{

        getline(archivo,linea);

        while (getAddress()==false)
            getline(archivo,linea);


        getline(archivo,linea);

        if((linea.compare("direccto")!=0) && linea.compare("indirecto")!=0)
            return  " ";

    }
    std::string temp(linea);
    getline(archivo,linea);
    return  temp;
}
std::string controlador_CargaConfi::getAddressMethod(){

    if((linea.compare("explicito")!=0)&&(linea.compare("implicito")!=0)
            &&(linea.compare("estatico")!=0)&&(linea.compare("explicito")!=0))
        return "";

    std::string temp(linea);
    getline(archivo,linea);

    archivo.seekg(std::ios_base::beg);
    return  temp;

}
std::string controlador_CargaConfi::getContenido(){

    getline(archivo,linea);

    if(getFormat())
        getline(archivo,linea);

    else{

        while(getFormat()==false)
            getline(archivo,linea);

        getline(archivo,linea);

    }
    return  linea;
}
std::string controlador_CargaConfi::getTypeSize(){

    getline(archivo,linea);

    if(linea.compare("fijo")==0){

        std::string temp(linea);
        return temp;

    }else if(linea.compare("variable")==0){

        std::string temp(linea);
        return  temp;
    }
    return  " ";
}
long long controlador_CargaConfi::getLargo(){

    getline(archivo,linea);


    long long temp =atoll(linea.c_str());
    archivo.seekg(std::ios_base::beg);

    return  temp;

}
std::string controlador_CargaConfi::getColaType(){

    getline(archivo,linea);

    if(getColas())
        getline(archivo,linea);
    else{

        getline(archivo,linea);

        while(getColas()==false)
            getline(archivo,linea);


        getline(archivo,linea);
    }
    if((linea.compare("fifo")!=0)&&(linea.compare("prioridad")!=0))
        return  " ";

    archivo.seekg(std::ios_base::beg);
    return  linea;
}
