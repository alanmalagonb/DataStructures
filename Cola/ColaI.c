#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCola.h"
#include"C:\Users\Alan\Desktop\AyEdd\Lista\Lista.h"
#include"C:\Users\Alan\Desktop\AyEdd\Cola\Cola.h"

int NumElemsCola(Cola);
int EstaEnC(Elem, Cola);

int main(){

    Cola q=nueva();

    q=formar(formar(formar(q,'b'),'c'),'d');
    ImpElem(primero(q));
    printf("La cola tiene %d elementos.\n",NumElemsCola(q));
    desformar(q);
    ImpElem(primero(q));
    printf("La cola tiene %d elementos.\n",NumElemsCola(q));
    EstaEnC('c',q)?puts("Si."):puts("No.");

    return 0;
}

int NumElemsCola(Cola q){
     int i=0; Lista t=vacia();
     while(!esnueva(q)){
            t=cons(primero(q),t);
            q=desformar(q);
     }
     i=NumElems(t);
     t=InvierteLista(t);
     while(!esvacia(t)){
            q=formar(q,cabeza(t));
            t=resto(t);
     }
     return i;
};

int EstaEnC(Elem e, Cola q){
    int i=0; Lista t=vacia();
     while(!esnueva(q)){
            t=cons(primero(q),t);
            q=desformar(q);
     }
     i=EstaEn(e,t);
     t=InvierteLista(t);
     while(!esvacia(t)){
            q=formar(q,cabeza(t));
            t=resto(t);
     }
     return i;
};
