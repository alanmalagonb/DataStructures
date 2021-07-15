#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemAVL.h"
#include"C:\Users\Alan\Desktop\AyEdd\AVL\AVL.h"

int main(){

    //DicBin a=insord(300, insord(150,insord(200,insord(50,insord(100,vacioAB())))));
    //DicBin a=insord(19, insord(28,insord(10,insord(23,insord(17,vacioAB())))));
    DicBin a=vacioAB();
    EsAVL(a)?puts("Si"):puts("No");
    a=insord(5, insord(11,insord(8,insord(19,insord(13,vacioAB())))));
    //InOrder(a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    //a=insord(125,a);
    //a=insord(21,a);
    a=insord(12,a);
    
    printf("Factor de balanceo +insord: %d.\n",FactBal(a));
    EsAVL(a)?puts("Si"):puts("No");
    
    a=rotaIzqDer(a);
    puts("-----IzqDer------");
    printf("Factor de balanceo raiz: %d.\n",FactBal(a));
    printf("Factor de balanceo izq: %d.\n",FactBal(izquierdo(a)));
    printf("Factor de balanceo der: %d.\n",FactBal(derecho(a)));
    InOrder(a);
 /*
    a=insord(10,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=rotaDer(a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(40,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(150,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(300,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(400,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=rotaIzq(a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    printf("Factor de balanceo: %d.\n",FactBal(izquierdo(a)));
    printf("Factor de balanceo: %d.\n",FactBal(derecho(a)));
    puts("----------");
    a=insord(60,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(80,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(78,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(90,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=insord(95,a);
    printf("Factor de balanceo: %d.\n",FactBal(a));
    a=rotaDerIzq(a);
    printf("Factor de balanceo: %d.\n",FactBal(a));


    printf("El arbol izq tiene %d elementos.\n",NumElemsAB(izquierdo(a)));
    printf("El arbol der tiene %d elementos.\n",NumElemsAB(derecho(a)));
    puts("Recorrido del arbol en inorder:");
    InOrder(a);
    printf("Altura de a es: %d.\n",Altura(a));
*/
    return 0;
}

