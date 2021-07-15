#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemPila.h"
#include"C:\Users\Alan\Desktop\AyEdd\Pila\Pila.h"

int main(int argc, char *argv[]){
    
    Pila a=push('H',push('o',push('l',push('a',empty()))));
    ImpElem(top(a));
    ImpElem(top(pop(a)));
    
    return 0;
}