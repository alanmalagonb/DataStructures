#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemLista.h"
#include"C:\Users\Alan\Desktop\AyEdd\ListaBC\ListaBC.h"

void ImpLista(Lista l){
   if(!esvacia(l)){
       ImpElem(cabeza(l));
       ImpLista(resto(l));
   }
}

int main(){

    Lista a=cons('a',cons('b',cons('c',cons('d',vacia()))));

    ImpElem(cabeza(a));

    ImpLista(a);

    return 0;
}