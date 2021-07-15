#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCola.h"
#include"C:\Users\Alan\Desktop\AyEdd\ColaBC\ColaBC.h"

void ImpCola(Cola q){
   if(!esnueva(q)){
       ImpElem(primero(q));
       ImpCola(q=desformar(q));
   }
}

int main(){

    Cola q=formar(formar(formar(nueva(),'a'),'b'),'c');
    puts("Primero:");
    ImpElem(primero(q));
    puts("Ultimo:");
    ImpElem(ultimo(q));
    puts("Cola:");
    ImpCola(q);
    return 0;
}