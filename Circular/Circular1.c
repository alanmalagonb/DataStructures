#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"

int main(){
    int i;
    Circular c=nuevaC();

    c=formarC(c,'a');
    c=formarC(c,'b');
    c=formarC(c,'c');
    //c=formarC(formarC(formarC(formarC(c,'a'),'b'),'c'),'d');
    for(i=1;i<7;i++){
       ImpElem(primeroC(c));
       c=rotar(c);
    }
    puts("-------");
    c=formarC(c,'d');
    for(i=1;i<=12;i++){
       ImpElem(primeroC(c));
       c=rotar(c);
    }
    puts("-------");
    c=desformarC(c);

    for(i=1;i<=12;i++){
       ImpElem(primeroC(c));
       c=rotar(c);
    }

    return 0;
}
