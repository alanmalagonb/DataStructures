#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemBiCola.h"
#include"C:\Users\Alan\Desktop\AyEdd\BiCola\BiCola.h"

int main(){
    BiCola b;
    b = nuevaBC();
    esnuevaBC(b)?puts("Es nueva"):puts("No es nueva");
    b = formarIzqBC('a',b);
    esnuevaBC(b)?puts("Es nueva"):puts("No es nueva");
    b = formarDerBC(b,'b');
    ImpElem(izquierdoBC(b));
    ImpElem(derechoBC(b));
    b = formarIzqBC('x',b);
    ImpElem(izquierdoBC(b));
    b = formarDerBC(b,'y');
    ImpElem(derechoBC(b));
    b = desformarDerBC(b);
    ImpElem(derechoBC(b));


    return 0;
}