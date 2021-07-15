#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemDicBin.h"
#include"ArBin.h"

int main(){

    /*
                   5
                  / \
                 10 20
                   /
                  15
    */

    ArBin a=consAB(5,consAB(10,vacioAB(),vacioAB()),
                      consAB(20,consAB(15,vacioAB(),vacioAB()),vacioAB()));
    //IMPRIME TODOS LOS NIVELES 
    ImpNivelPorNivelAB(a);

    //IMPRIME EL ELEMENTO MAS A LA DERECHA
    ImpElem(ElemMasDerechoB(a));

    //IMPRIME EL ELEMENTO MAS A LA IZQUIERDA
    ImpElem(ElemMasIzquierdoB(a));

    //IMPRIME EL NUMERO DE ELEMENTOS
    ImpElem(NumElemsAB(a));

    //IMPRIME LA ALTURA DEL ARBOL
    ImpElem(Altura(a));
}