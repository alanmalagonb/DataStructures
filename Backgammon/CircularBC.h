#include"BiCola.h"

typedef BiCola Circular;

Circular nuevaC(){return nuevaBC();}
Circular formarC(Circular c, Elem e){return formarDerBC(c,e);}
int esnuevaC(Circular c){return esnuevaBC(c);}
Elem primeroC(Circular c){return izquierdoBC(c);}
void aumentarPrimeroC(){}
void disminuirPrimeroC(){}
Circular desformarC(Circular c){return desformarIzqBC(c);}
Circular rotaIzq(Circular c){
    return desformarIzqBC(formarDerBC(c,izquierdoBC(c)));
}
Circular rotaDer(Circular c){
    return desformarDerBC(formarIzqBC(derechoBC(c),c));
}
void disminuir(Circular c){
    c->izq->dato = primeroC(c)-1;
}
void aumentar(Circular c){
    c->izq->dato = primeroC(c)+1;
}