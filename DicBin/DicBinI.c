#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemDicBin.h"
#include"C:\Users\Alan\Desktop\AyEdd\DicBin\DicBin.h"

int main(){
    DicBin a=insord(100, insord(300,insord(20, insord(75,insord(150,vacioAB())))));
    ImpElem(raiz(a));
    ImpElem(raiz(izquierdo(a)));
    ImpElem(raiz(derecho(a)));

    printf("El arbol tiene %d elementos.\n",NumElemsAB(a));
    printf("El arbol izq tiene %d elementos.\n",NumElemsAB(izquierdo(a)));
    printf("El arbol der tiene %d elementos\n",NumElemsAB(derecho(a)));
    puts("Recorrido del arbol inorder:");
    InOrder(a);
    puts("Recorrido del arbol preorder:");
    PreOrder(a);
    puts("Recorrido del arbol postorder:");
    PostOrder(a);
    printf("El arbol tiene %d de altura\n",Altura(a));
    return 0;
}
