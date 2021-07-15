#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemListaInt.h"
#include"C:\Users\Alan\Desktop\AyEdd\Lista\Lista.h"
#include"C:\Users\Alan\Desktop\AyEdd\DicBin\DicBin.h"


Lista ListaInOrder(DicBin a, Lista l){
     if(!esvacioAB(a)){
        InOrder(izquierdo(a));
        l=cons(raiz(a),l);//ImpElem(raiz(d));
        InOrder(derecho(a));
     }
}

void nesimos(DicBin a, int n){
    Lista l,b;
    l= ListaInOrder(a,vacia());
    b = InvierteLista(l);
    ImpLista(l);
    ImpLista(b);
}

int main(){

    Elem  x=6;
    Lista l,t;

    l=cons(1,cons(3,cons(5,cons(7,vacia()))));
    t=InvierteLista(l);
    int r;
    DicBin a = vacioAB();
    while(r!=0){
        puts("Ingresa un numero:");
        fflush(stdin);
        scanf("%d",&r);
        if(r==0) break;
        a=insord(r,a);
    }
    puts("------------------------");
    int n;
    /*puts("Ingresa el valor de n:");
    scanf("%d",&n);
    puts("------------------------");
    */
   //ImpNivelPorNivelAB(a);
    InOrder(a);
    puts("Lista: ");
    nesimos(a,3);
    return 0;
}
