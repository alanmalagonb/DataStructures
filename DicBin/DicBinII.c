#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemAVL.h"
#include"C:\Users\Alan\Desktop\AyEdd\AVL\AVL.h"

int main(){
    Elem e;
    int i;
    DicBin a=vacioAB();

    do{
        printf("Dame un elemento (0 para salir)!!!");
        e=LeeElem();
        a=insord(e,a);
        ImpNivelPorNivelAB(a);
        puts("-----------");
    }while(e);

    while(1){
        ImpNivelPorNivelAB(a);
        puts("-----------");
        printf("Que elemento quieres eliminar?");
        e=LeeElem();
        a=ElimAVL(e,a);
    }


    return 0;
}