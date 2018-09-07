#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H
#include <string>
#include<stdlib.h>

enum sincro {blocking,nonblocking,prueba_de_llegada};
enum address{explicito,implicito,estatico,dinamico};
enum direc{directo,indirecto};//parte de address
enum format {fijo,variable};
enum colas  {fifo,prioridad,error};

typedef struct sincro__{
    sincro send_;
    sincro recv_;
}sincro_;
typedef  struct address__{
    direc tipo_;
    address method;

}adrdess_ ;
typedef  struct format__{

  std::string contenido;
  format format_;
  long long size;

}format_;


#endif // PRIMITIVAS_H
