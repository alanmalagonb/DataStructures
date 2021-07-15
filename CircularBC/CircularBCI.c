#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\CircularBC\CircularBC.h"

int main(){
    int i;
    Circular d=nuevaC();

    for(i='A';i<='D';i++) d=formarC(d,i);
    while(1){
        ImpElem(primeroC(d));
        //d=rotaIzq(d);
        d=rotaDer(d); 
        puts("------------------");
        getchar();
    }


    return 0;
}