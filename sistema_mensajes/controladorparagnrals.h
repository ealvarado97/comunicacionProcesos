#ifndef CONTROLADORPARAGNRALS_H
#define CONTROLADORPARAGNRALS_H


class ControladorParaGnrals{


public:
    ControladorParaGnrals(){
    }

    int get_largoCola(){
     return largoCola;
    }

   void set_largoCola(int largo){
        largoCola=largo;
    }



private:
    int largoCola;

};


#endif // CONTROLADORPARAGNRALS_H


