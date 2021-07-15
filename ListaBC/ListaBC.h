#include"C:\Users\Alan\Desktop\AyEdd\BiCola\BiCola.h"

typedef BiCola Lista;

Lista vacia(){return nuevaBC();}
Lista cons(Elem e, Lista l){return formarIzqBC(e,l);}
int esvacia(Lista l){return esnuevaBC(l);}
Elem cabeza(Lista l){return izquierdoBC(l);}
Lista resto(Lista l){return desformarIzqBC(l);}
