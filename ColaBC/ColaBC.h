#include"C:\Users\Alan\Desktop\AyEdd\BiCola\BiCola.h"

typedef BiCola Cola;

Cola nueva(){return nuevaBC();}
int esnueva(Cola q){return esnuevaBC(q);}
Cola formar(Cola q, Elem e){return formarIzqBC(e,q);}
Elem primero(Cola q){return derechoBC(q);}
Elem ultimo(Cola q){return izquierdoBC(q);}
Cola desformar(Cola q){return desformarDerBC(q);}