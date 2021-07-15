#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"

int main(){
    Elem i, j=0;
    Circular c=nuevaC();

    for(i='A';i<='Z';i++)
       c=formarC(c,i);

    while(!esnuevaC(c)){
       for(i='A';i<='Z'-j;i++){
          ImpElem(primeroC(c));
          c=rotar(c);
       }
       j++;
       c=desformarC(c);
       c=rotar(c);
       putchar('\n');
    }

    return 0;
}
